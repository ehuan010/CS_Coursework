;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_GET_N_4800
; Input: (None)
; Postcondition: The subroutine has obtained an n value from the user
; Return Value (R1): The option selected: (0-15)
;----------------------------------------------------------------------------------------------------

.ORIG x4800

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_4800		; backup R0
 ST R2, BACKUP_R2_4800		; backup R2
 ST R3, BACKUP_R3_4800		; backup R3
 ST R4, BACKUP_R4_4800		; backup R4
 ST R5, BACKUP_R5_4800		; backup R5
 ST R6, BACKUP_R6_4800		; backup R6
 ST R7, BACKUP_R7_4800		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

LD R1, ZERO		; don't use R1 because it is the return value
LD R3, NEGATIVE_1	; R3 holds -1 which is a counter
LD R4, CHAR_TO_NUM2	; converting mask #-48 to convert the characters
	
; DO NOT IMPLEMENT ERROR CHECK!!!!!!!


;This FOR_LOOP takes in input from the user
FOR_LOOP
 GETC			; Get a character from the user and store it into R0
 OUT

 ST R0, VAL_R0		; first store the value of R0 into a label
 
 ;if you subtract 10 and the value is zero end the for loop
 LD R0, VAL_R0		; load R0 with VAL_R0
 ADD R0, R0, #-10	; R0 <-- R0 - 10
 BRz END_FOR_LOOP	; if (R0 = 0) go to END_FOR_LOOP because user entered ENTER

 ;otherwise normally continue the program and load VAL_R0 back into R0
 LD R0, VAL_R0		; load R0 with VAL_R0
 ADD R0, R0, R4		; R0 <- R0 + R4 (converts it to decimal) 

 LD R2, NINE		; loads R2 with the number nine
 ADD R3, R3, #1		; increments the counter from -1 to 0 (start), etc.
 BRp CONVERTER		; if (R3 > 0) then go to the converter

 ;otherwise put R0 into R1 for initial (IT WILL ONLY GO TO THESE TWO STATEMENTS ONCE)
 ADD R1, R1, R0		; puts R0 into R1
 BRzp SKIP		; if (R1 >= 0) 

 CONVERTER
  ST R1, VAL_R1		; store the value of R1 into VAL_R1
  LD R6, VAL_R1		; load R6 with VAL_R1

  ; multiplies the number in R1 and then appends the entered value in R0
  MULTIPLY_BY_10
   ADD R1, R1, R6	; R1 <- R1 + R6 (adds original value of R1)
   ADD R2, R2, #-1 	; R2 with 9 only want to add it to itself 9 times
   BRp MULTIPLY_BY_10	; if (R2 > 0) go to MULTIPLY_BY_10
   ADD R1, R1, R0	; R1 <- R1 + R0 (appends R0 to the multiplied value of R1
 END_CONVERTER

 SKIP
 
 REST_OF_PROG
  LD R0, VAL_R0		; load R0 with VAL_R0
  ADD R0, R0, #-10	; R0 <-- R0 - 10
  BRp FOR_LOOP		; if (R0 > 0) go to FOR_LOOP
END_FOR_LOOP




; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_4800		; restore R0
 LD R2, BACKUP_R2_4800		; restore R2
 LD R3, BACKUP_R3_4800		; restore R3
 LD R4, BACKUP_R4_4800		; restore R4
 LD R5, BACKUP_R5_4800		; restore R5
 LD R6, BACKUP_R6_4800		; restore R6
 LD R7, BACKUP_R7_4800		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_4800 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R2_4800 .BLKW #1
BACKUP_R3_4800 .BLKW #1
BACKUP_R4_4800 .BLKW #1
BACKUP_R5_4800 .BLKW #1
BACKUP_R6_4800 .BLKW #1
BACKUP_R7_4800 .BLKW #1

ZERO .FILL #0
NEGATIVE_1 .FILL #-1
NINE .FILL #9
VAL_R0 .FILL #0
VAL_R1 .FILL #0

CHAR_TO_NUM2 .FILL #-48
NEWLINE3 .FILL #10
VALIDATION3 .FILL #-49
VALIDATION4 .FILL #-55
FAILED_INPUT .STRINGZ "The number you entered was invalid!!!"
PROMPT_N .STRINGZ "Which machine do you want that status of (0-15): "

;----------------------------------------------------------------------------------------------------
