;=================================================
;
; Name: <Huang, Edward>
; Login id: ehuan010 (861026626)
;
; Assignment name: <assn 5>
; Lab section: <024>
; TA: Muzo Akbay
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

;------------
; Main Code
;------------
.ORIG x3000

LD R6, SUB_CONVERT_CHAR_3200
JSRR R6

ST R1, FIRST_NUMBER

LD R6, SUB_CONVERT_CHAR_3200
JSRR R6

ST R1, SECOND_NUMBER

LD R1, FIRST_NUMBER
LD R2, SECOND_NUMBER


HALT				; ends the program

;--------------------
; Data Block for main
;--------------------
SUB_CONVERT_CHAR_3200 .FILL x3200
FIRST_NUMBER .FILL #0
SECOND_NUMBER .FILL #0


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_CONVERT_CHAR_3200
; Input R0: Some numeric characters to convert into decimal
; Postcondition: Coverts number characters of R0 into their decimal value and store into R1
; Return Value: R1 holds the 5 digit numeric character typed in

.ORIG x3200

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3200		; backup R0
 ST R2, BACKUP_R2_3200		; backup R2
 ST R3, BACKUP_R3_3200		; backup R3
 ST R4, BACKUP_R4_3200		; backup R4
 ST R5, BACKUP_R5_3200		; backup R5
 ST R6, BACKUP_R6_3200		; backup R6
 ST R7, BACKUP_R7_3200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

RESTART
LD R1, ZERO		; don't use R1

LD R3, NEGATIVE_1	; R3 <- m[NEGATIVE_1] = #-1
LD R4, MASK		; R4 <-m[MASK] = #-48
;LD R5, P_N_CHECK	; (checks if number is + or -)

;pos then negative
LD R5, VALIDATION1
LD R6, VALIDATION2
	

; Resets the program when there is an error

LEA R0, PROMPT		; STORES ADDRESS OF THE PROMPT
PUTS			; outputs the PROMPT


;Check first character
GETC			; Get a character from the user and store it into R0
OUT			; output it to avoid ghost typing

ST R0, VAL_R0

;this checks if the first char is +
ADD R0, R0, R5		; + is #43 and - is #45...R5 should subtract 43
BRz CHAR_IS_P		; if (R0 = 0) the character must be + so go to CHAR_IS 

;reload R0
LD R0, VAL_R0		; R0 <- m[VAL_R0] = 1st character inputed by user

;this checks if the first char is -
ADD R0, R0, R6		; R6 should subtract 45 to check if it is a -
BRz CHAR_IS_N		; if (R0 = 0) the character must be - so go to CHAR_IS_N

;otherwise continue here because the char must be invalid
INVALID
 LD R0, NEWLINE		; R0 <- m[NEWLINE] = #10 (the enter char)
 OUT			; output the newline
 LEA R0, ERROR_MSG	; get the address of the ERROR_MSG
 PUTS			; output the ERROR_MSG string
 LD R0, NEWLINE		; get newline again
 OUT			; output newline
 ADD R0, R0, #0		; !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!NEWLINE IS POSITIVE SO MAKE IT BRp?
 BRnzp RESTART

CHAR_IS_P		; the character must be +
 LD R5, ZERO		; R5 <-- m[ZERO] = #0
 ST R5, VAL_R5		; m[VAL_R5] <- R5...this will be used later add + sign
 BRz FOR_LOOP		; if (R5 = 0) go to FOR_LOOP (it will be zero)

CHAR_IS_N		; the character must be -
 LD R5, NEGATIVE_1	; R5 <-- m[NEGATIVE_1] = #-1
 ST R5, VAL_R5		; m[VAL_R5] <- R5...this will be used later to add - sign
 BRn FOR_LOOP		; if (R5 < 0) go to FOR_LOOP (it will be negative)


;This FOR_LOOP takes in input from the user
FOR_LOOP
 GETC			; Get a character from the user and store it into R0
 OUT			; output the char to prevent ghost typing

 ST R0, VAL_R0		; first store the value of R0 into a label
 
 ;can reuse R5 and R6
 LD R5, VALIDATION3	; R5 <- m[VALIDATION3] = #-48
 LD R6, VALIDATION4	; R6 <- m[VALIDATION4] = #-57

 ADD R0, R0, R6		; subtract 57 to check upper bound
 BRnz CHECK_NEXT	; > 57 will go to INVALID2...<= to 57 go to CHECK_NEXT
 BRp INVALID2

 CHECK_NEXT
 LD R0, VAL_R0		; reload value of R0
 ADD R0, R0, R5		; subtract 48 to check lower bound
 BRzp CONTINUE		; < 57 will go to INVALID2...>= to 48 go to CONTINUE
 BRn INVALID2

 INVALID2
;IF I JUST ADD THIS WILL IT WORK??????????????????????????????/ 
;if you subtract 10 and the value is zero end the for loop
 LD R0, VAL_R0
 ADD R0, R0, #-10	; R0 <-- R0 - 10
 BRz END_FOR_LOOP


 LD R0, NEWLINE
 OUT
 LEA R0, ERROR_MSG
 PUTS
 LD R0, NEWLINE
 OUT
 ADD R0, R0, #0
 BRnzp RESTART
 
 CONTINUE

 ;if you subtract 10 and the value is zero end the for loop
 ;LD R0, VAL_R0
 ;ADD R0, R0, #-10	; R0 <-- R0 - 10
 ;BRz END_FOR_LOOP

 ;otherwise normally continue the program and load VAL_R0 back into R0
 
 LD R0, VAL_R0
 ADD R0, R0, R4

 LD R2, NINE
 ADD R3, R3, #1		; increments the counter from -1 to 0 (start), etc.
 BRp CONVERTER

 ;put it into R1 for initial
 ADD R1, R1, R0
 BRzp SKIP

 CONVERTER
  ST R1, VAL_R1
  LD R6, VAL_R1

  MULTIPLY_BY_10
   ADD R1, R1, R6
   ADD R2, R2, #-1 ; R5 with 9 only want to add it to itself 9 times
   BRp MULTIPLY_BY_10
   
  ADD R1, R1, R0
 END_CONVERTER

 SKIP
 
 REST_OF_PROG
  ;ADD R2, R2, #1		; R1 <-- R1 + 1 (increments to the next address x4001..etc)
  ;ADD R3, R3, #1		; R3 <-- R3 + 1 (adds 1 to the counter to determine size)
  ;ST R3, COUNTER		; m[COUNTER] <-- R3
  LD R0, VAL_R0
  ADD R0, R0, #-10	; R0 <-- R0 - 10
  BRp FOR_LOOP		; if(R0 > 0)
  ;Need another branch for if it exceeds the 6 available slots?
END_FOR_LOOP

LD R5, VAL_R5
BRz IS_P

IS_N
 NOT R1, R1
 ADD R1, R1, #1

IS_P
;DO NOTHING


; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3200		; restore R0
 LD R2, BACKUP_R2_3200		; restore R2
 LD R3, BACKUP_R3_3200		; restore R3
 LD R4, BACKUP_R4_3200		; restore R4
 LD R5, BACKUP_R5_3200		; restore R5
 LD R6, BACKUP_R6_3200		; restore R6
 LD R7, BACKUP_R7_3200		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3200 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R2_3200 .BLKW #1
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R5_3200 .BLKW #1
BACKUP_R6_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1

MASK .FILL #-48
VALIDATION1 .FILL #-43	; postive
VALIDATION2 .FILL #-45  ; negative
VALIDATION3 .FILL #-48	; 0 and 9 boundary cases
VALIDATION4 .FILL #-57
ZERO .FILL #0
NEGATIVE_1 .FILL #-1
P_N_CHECK .FILL #-45
NINE .FILL #9
VAL_R0 .FILL #0
VAL_R1 .FILL #0
VAL_R5 .FILL #0		; this will hold the sign
CHAR_INPUTED .FILL #0	; will hold the character inputed to see if it is valid or not
PROMPT .STRINGZ "Input a decimal number (max 5 digits in the range [-32767, +32767]) , preceded with +/‐, followed by ENTER key on keyboard: "
ERROR_MSG .STRINGZ "Not a valid input!!!"
NEWLINE .FILL #10
;----------------------------------------------------------------------------------------------------

.END		; end of all code

