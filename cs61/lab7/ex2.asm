;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 07
;-----------------------------------------------------------------------------------

;------------
; Main Code
;------------
.ORIG x3000

LD R0, START_OF_ARRAY

LD R7, SUB_GET_STRING_3200
JSRR R7

LD R0, START_OF_ARRAY
;PUTS

LD R7, SUB_IS_A_PALINDROME_3400
JSRR R7

LD R0, NEWLINE
OUT

ADD R4, R4, #0
BRz NOT_PALINDROME_PRINT

; or it is a palindrome
LEA R0, PALINDROME_PROMPT
PUTS
HALT

NOT_PALINDROME_PRINT
 LEA R0, NOT_PALINDROME_PROMPT
 PUTS
 HALT

;--------------------
; Data Block for main
;--------------------
SUB_GET_STRING_3200 .FILL x3200
SUB_IS_A_PALINDROME_3400 .FILL x3400
NOT_PALINDROME_PROMPT .STRINGZ "It is NOT a palindrome!!!"
PALINDROME_PROMPT .STRINGZ "It IS a palindrome!!!"
NEWLINE .FILL xA
START_OF_ARRAY .FILL x4000


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_GET_STRING_3200
; Parameter (R0): The address of where to start storing the string
; Postcondition: The subroutine has allowed the user to input a string,terminated by the [ENTER] key, and has stored it in an array that starts at (R0) and is NULL-terminated.
; Return Value: R5 The number of non-sentinel characters read from the user
;----------------------------------------------------------------------------------------------------

.ORIG x3200

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R1, BACKUP_R1_3200		; backup R1
 ST R2, BACKUP_R2_3200		; backup R2
 ST R3, BACKUP_R3_3200		; backup R3
 ST R4, BACKUP_R4_3200		; backup R4
 ST R6, BACKUP_R6_3200		; backup R6
 ST R7, BACKUP_R7_3200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

ST R0, START_ADDRESS		; store R0 in START_ADDRESS
LD R5, CHAR_COUNTER		; load R5 with CHAR_COUNTER

LEA R0, STRING_PROMPT		; load R0 with the starting address of STRING_PROMPT
PUTS				; output the STRING_PROMPT 

STRING_LOOP
 GETC				; get input from user
 OUT				; output character
 
 ADD R2, R0, #0			; puts R0 char into R2
 ADD R2, R2, #-10
 BRz END_STRING_LOOP		; if result is 0 end the string loop, otherwise continue
 ADD R2, R2, #10		; add back the ten

 ; this screws it up cause it keeps loading R0 with x4000
 LD R0, START_ADDRESS		; loads R0 with the start_address
 STR R2, R0, #0			; m[R0] <- R2

 ADD R0, R0, #1			; increment to the next address
 ST R0, START_ADDRESS		; so add this to make it store the incremented address
 ADD R5, R5, #1			; increment the counter
 BRp STRING_LOOP		; if the counter is positive go to STRING_LOOP

END_STRING_LOOP
 STR R2, R0, #0			; R2 will hold zero, so store zero into address pointed to by R0
 

; (3) Restore all modified registers except Return Values
 LD R1, BACKUP_R1_3200		; restore R1
 LD R2, BACKUP_R2_3200		; restore R2
 LD R3, BACKUP_R3_3200		; restore R3
 LD R4, BACKUP_R4_3200		; restore R4
 LD R6, BACKUP_R6_3200		; restore R6
 LD R7, BACKUP_R7_3200		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R1_3200 .BLKW #1	
BACKUP_R2_3200 .BLKW #1		;one for each register modified (except return val)
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R6_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1

CHAR_COUNTER .FILL #0
ENTER .FILL #10
MINUS_TEN .FILL #-10
START_ADDRESS .FILL #0
STRING_PROMPT .STRINGZ "Enter a string followed by ENTER to finish: "
;----------------------------------------------------------------------------------------------------

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_IS_A_PALINDROME_3400
; Parameter (R0): The address of a string
; Parameter (R5): The number of characters in the array.
; Postcondition: The subroutine has determined whether the string at (R0) is a palindrome or not 			 returned a flag indicating such.
;Return Value: R4 <-- {1 if the string is a palindrome, 0 otherwise}
;----------------------------------------------------------------------------------------------------

.ORIG x3400

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R1, BACKUP_R1_3400		; backup R1
 ST R2, BACKUP_R2_3400		; backup R2
 ST R3, BACKUP_R3_3400		; backup R3
 ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

; 0 means not a palindrome, 1 means is a palindrome (R4)
; if the two ends meet in the middle and you haven't returned false, then it is a palindrome
; need to stop the loop via a couter...just do n/2??

; first get the last address
ST R0, START_ADDRESS_2
;ST R5, SIZE_OF_ARRAY

; R0 holds the starting address
ADD R1, R0, R5 			; R1 holds address to the end of the array
ADD R1, R1, #-1			; need to subtract 1 to get to 1 less address

PALINDROME_LOOP
 LDR R2, R0, #0			; R2 will hold the value at array[0]
 LDR R3, R1, #0			; R3 will hold the value at array[n]
 
 ; increment/decrement the pointers R0/R1 respectively
 ADD R0, R0, #1			; increment R0 by 1
 ADD R1, R1, #-1		; decrement R1 by 1


 NOT R3, R3			; make one of the values negative...I chose R3
 ADD R3, R3, #1			; add 1 to get the inverse value
 ADD R6, R2, R3			; R6 <- R2 - R3 subtract them from each other (R6 just holds arithmetic)
 BRz CHECK_ADDRESS		; so far it is a palindrome so now check the address
 BRnp NOT_A_PALINDROME		; if result is negative OR positive then it isn't a palindrome
 
 CHECK_ADDRESS
 ; subtract the smaller one from the larger address
 NOT R0, R0			; flip the smaller address
 ADD R0, R0, #1			; add 1 to make it the inverse
 ADD R6, R1, R0			; R6 <- R1 - R0 subtracts the address
 BRnz IS_PALINDROME		; if the address hits zero or negative then it must be a palindrome now
 
 ; convert R0 back to original incremented value
 NOT R0, R0
 ADD R0, R0, #1
 BRnzp PALINDROME_LOOP		; check next characters/address

 
NOT_A_PALINDROME
 LD R4, ZERO_FLAG		; load R4 with the ZERO_FLAG when it is NOT_A_PALINDROME
 BRz END_PALINDROME_LOOP

IS_PALINDROME
 LD R4, ONE_FLAG
 BRp END_PALINDROME_LOOP

END_PALINDROME_LOOP
 

; check character and then do the address check

; (3) Restore all modified registers except Return Values
 LD R1, BACKUP_R1_3400		; restore R1
 LD R2, BACKUP_R2_3400		; restore R2
 LD R3, BACKUP_R3_3400		; restore R3
 LD R6, BACKUP_R6_3400		; restore R6
 LD R7, BACKUP_R7_3400		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R1_3400 .BLKW #1	
BACKUP_R2_3400 .BLKW #1		;one for each register modified (except return val)
BACKUP_R3_3400 .BLKW #1
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

ZERO_FLAG .FILL #0
ONE_FLAG .FILL #1
START_ADDRESS_2 .FILL #0
END_ADDRESS .FILL #0
;----------------------------------------------------------------------------------------------------

.END
