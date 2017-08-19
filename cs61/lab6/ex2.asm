;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 06
;-----------------------------------------------------------------------------------

;------------
; Main Code
;------------
.ORIG x3000

LEA R0, CHAR_INPUT_PROMPT		; loads address of CHAR_INPUT_PROMPT
PUTS					; outputs the prompt for single character input

GETC					; get single character and store in R0
ADD R6, R6, R0				; R6 <- R6 + R0 (gets R0 char's value and store it in R6)

LD R1, SUB_CONVERT_CHAR_3200		; R1 <- m[SUB_CONVERT_CHAR_3200] = x3200
JSRR R1					; jump to the address

LD R0, NEWLINE				; R0 <- m[NEWLINE] = #10 (stores a newline character)
OUT					; outputs the newline character
LEA R0, NUMBER_OF_ONES_MSG		; loads address of NUMBER_OF_ONES_MSG 
PUTS					; outputs the message stored at that address

LD R2, CONVERT_TO_CHAR			; R2 <- m[CONVERT_TO_CHAR] = #48 (convert decimal to char)
ADD R1, R1, R2				; R1 <- R1 + R2 (makes the dec in R1 into it's char)
ADD R0, R1, #0				; R0 <- R1 + #0 (gives R0 the value of R1)
OUT					; output that value

HALT					; end the program

;--------------------
; Data Block for main
;--------------------
CHAR_INPUT_PROMPT .STRINGZ "Input a single character from the keyboard: "
NUMBER_OF_ONES_MSG .STRINGZ "The number of 1's is: "
NEWLINE .FILL #10
SUB_CONVERT_CHAR_3200 .FILL x3200
CONVERT_TO_CHAR .FILL #48


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_CONVERT_CHAR_3200
; Input R6: Some character entered in from the user whose binary bits will be analyzed
; Postcondition: Counts the number of binary 1's in the character and stores it in another register
; Return Value: R5 holds the number of 1's counted

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
 ST R7, BACKUP_R7_3200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

;and it with 1000 0000 0000 0000...if z then don't update counter, otherwise update counter.
;reload R6's value and add it to itself to do a shift...store that new value into R6 to check again

LD R1, NUMBER_OF_ONES
LD R2, ZERO_OR_ONE_MASK
LD R3, SIXTEEN_COUNTER
ST R6, VALUE_OF_R6

BINARY_ONE_COUNTER_LOOP
 LD R6, VALUE_OF_R6

 AND R6, R6, R2
 BRz LEFT_SHIFT			; do nothing if it is zero

 ;otherwise add one to counter
 ADD_ONE
  ADD R1, R1, #1
  BRp LEFT_SHIFT

 LEFT_SHIFT
  LD R6, VALUE_OF_R6
  ADD R6, R6, R6		; add to itself to do left-shift
  ST R6, VALUE_OF_R6		; updates value of R6
  ADD R3, R3, #-1		; decrements the 16 loop counter
  BRp BINARY_ONE_COUNTER_LOOP



; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3200		; restore R0
 LD R2, BACKUP_R2_3200		; restore R2
 LD R3, BACKUP_R3_3200		; restore R3
 LD R4, BACKUP_R4_3200		; restore R4
 LD R5, BACKUP_R5_3200		; restore R5
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
BACKUP_R7_3200 .BLKW #1

ZERO_OR_ONE_MASK .FILL x8000
NUMBER_OF_ONES .FILL #0
VALUE_OF_R6 .FILL #0
SIXTEEN_COUNTER .FILL #16

;----------------------------------------------------------------------------------------------------

.END
