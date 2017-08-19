;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 05
;-----------------------------------------------------------------------------------

;------------
; Main Code
;------------
.ORIG x3000

LEA R0, PROMPT		; R0 <- m[PROMPT]
PUTS			; Prints out the string of PROMPT

LD R1, ITERATOR		; R1 <- m[ITERATOR] = #17
LD R3, IS_B		; R3 <- m[IS_B] = #-98
LD R4, COUNTER2		; R4 <- m[COUNTER2] = #-1
LD R5, IGNORE_SPACE	; R5 <- m[IGNORE_SPACE] = #-32

;LOOP TO GET INPUT
FOR_LOOP
 GETC
 OUT
 
;make a counter so it knows its the first letter? then afterwards skip the initiate check and keep checking for spaces
 ST R0, VAL_R0		; m[VAL_R0] <- R0 ( holds R0 into a label so it can be reloaded later)

 ADD R4, R4, #1		; counter that starts at -1...goes to 0 first time
 BRp VALID		; if it's positive go to continue (for now until I add other conditions)
 
 ;Otherwise it will perform this
 ADD R0, R0, R3		; R3 checks character b
 BRz CONTINUE		; if this is zero continue the program also
 
 ;otherwise it will cry and quit
 CRYING			; Cries
  LD R0, ENTER		; R0 <- m[ENTER] = newline char
  OUT			; display R0
  LEA R0, CRY		; R0 <- CRY address of CRY
  PUTS			; outputs the entire array of char's
  HALT			; end the program
 
 VALID			; Loop to check for valid inputs
  ;CHECKS FOR 1 character
  LD R6, VALIDATION	; R6 <- m[VALIDATION] = #-49
  LD R0, VAL_R0		; R0 <- m[VAL_R0] = char user entered
  ADD R0, R0, R6	; R0 <- R0 + R6 (will subtract 49 from R0)
  BRz CONTINUE		; if (R0 = 0) continue the program
  
  ;CHECKS FOR 0 character
  LD R6, VALIDATION2	; R6 <- m[VALIDATION] = #-48
  LD R0, VAL_R0		; R0 <- m[VAL_R0] = char user entered
  ADD R0, R0, R6	; R0 <- R0 + R6 (will subtract 48 from R0)
  BRz CONTINUE		; if (R0 = 0) continue the program
  
  ;CHECKS FOR A SPACE character
  IS_SPACE
  LD R0, VAL_R0		; R0 <- m[VAL_R0] = char user entered
  ADD R0, R0, R5	; R0 <- R0 + R5 (will subtract 32 from R0)
  BRz FOR_LOOP		; if (R0 = 0) so it is a space, start over and get new input

 ;otherwise output error and quit
 ERROR_QUIT
  LD R0, ENTER		; R0 <- m[ENTER] = newline char
  OUT			; display R0
  LEA R0, CRY		; R0 <- CRY address of CRY
  PUTS			; outputs the entire array of char's
  HALT
 
 ;if everything goes as expected then continue running the program
 CONTINUE
 LD R0, VAL_R0		; R0 <- m[VAL_R0] = char user entered

 LD R6, SUB_CONVERT_CHAR_3200
 JSRR R6
 ADD R1, R1, #-1	; R1 <- R1 - 1 (decrement 1)
 BRp FOR_LOOP		; if (R1 > 0) go back to FOR_LOOP
 
 LD R6, SUB_OUTPUT_BINARY_3400
 JSRR R6

HALT

;--------------------
; Data Block for main
;--------------------
PROMPT .STRINGZ "Enter the letter b, followed by a 16-bit binary number(in 1's and 0's): "
ITERATOR .FILL #17
MASK .FILL #-48
IS_B .FILL #-98
IGNORE_SPACE .FILL #-32
VAL_R0 .FILL #0
ENTER .FILL #10
COUNTER2 .FILL #-1
VALIDATION .FILL #-49
VALIDATION2 .FILL #-48
SUB_CONVERT_CHAR_3200 .FILL x3200
SUB_OUTPUT_BINARY_3400 .FILL x3400
CRY .STRINGZ "Q_Q you entered an invalid character. Now I'm dead D:"

; convert the char 1's and 0's to decimal 1 and 0 respectively and the shift the bits.
; rinse and repeat and make sure those bits are stored in R2. Once done, print out the ascii.


; Subroutine: SUB_COVERT_CHAR_3200
; Input R0: Some characters to convert into decimal
; Postcondition: Coverts 1's and 0's of R0 into their decimal value and store into R5
; Return Value: R2 holds the 16 bit binary number typed in

.ORIG x3200

;----------------------------------------------------------------------------------------------------
;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3200		; backup R0
 ST R3, BACKUP_R3_3200		; backup R3
 ST R4, BACKUP_R4_3200		; backup R4
 ST R7, BACKUP_R7_3200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform
 LD R3, MASK			; R3 <- m[MASK] = #-48
 LD R4, COUNTER			; R4 <- m[COUNTER] = #0
 BRz SKIP			; if (R4 = 0) go to SKIP

 ADD R0, R0, R3			; R0 <- R0 + R1 (convert char to decimal)

 ADD R2, R2, R0			; R2 <- R2 + R0 (store the value into R2)

 ADD R4, R4, #-16		; R4 <- R4 -16 (subtract 16 from value of R4)
 BRz SKIP			; if (R4 = 0) go to SKIP

 ADD R2, R2, R2			; R2 <- R2 + R2 (left shift)
 
 SKIP
 LD R4, COUNTER			; R4 <- m[COUNTER]
 ADD R4, R4, #1			; R4 <- R4 + 1 (increments R4 by 1)
 ST R4, COUNTER			; m[COUNTER] <- R4 (updates label with new value of R4)

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3200		; restore R0
 LD R3, BACKUP_R3_3200		; restore R3
 LD R4, BACKUP_R4_3200		; restore R4
 LD R7, BACKUP_R7_3200		; restore R7
; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3200 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1
MASK .FILL #-48
COUNTER .FILL #0




;------------------------------------------------------------------------------------------------



; Subroutine: SUB_OUTPUT_BINARY_3400
; Input R2: Some value to print the binary bits of
; Postcondition: Prints (R2) as a 16-bit binary number
; Return Value: No registers with a return value

.ORIG x3400

;----------------------------------------------------------------------------------------------------
;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3400		; backup R0
 ;ST R2, BACKUP_R2_3200		; backup R2
 ST R3, BACKUP_R3_3400		; backup R3
 ST R4, BACKUP_R4_3400		; backup R4
 ST R5, BACKUP_R5_3400		; backup R5
 ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform
	ST R2, SUB_DATA
	LD R2, SUB_DATA		; R1 <- m[NUM]
	;;;LDR R2, R1, #0
	LD R3, MASK2		; R2 <- m[MASK]
	LD R4, ITERATOR_2	; R3 <- m[ITERATOR]
	LD R5, SUB_DATA		; R4 <- m[NUM]
	;;;LDR R5, R1, #0
	LD R6, MAKE_SPACE	; R5 <- m[MAKE_SPACE]

	LD R0, NEWLINE
	OUT
	LD R0, CHAR_B
	OUT

FOR_LOOP_2
 	AND R2, R2, R3	; R1 <- R1 & R2 (AND's the first bit to get 0 or x8000)
 
 	BRz BIT_IS_0	; if(R1 == 0) output BIT_IS_0 otherwise go to BIT_IS_1

 	BIT_IS_1
  	 LD R0, ONE	; R0 <- m[ONE] = char 1
  	 OUT		; output value stored at R0

 
 	 ADD R5, R5, R5 ; R4 <- R4 + R4 (ADDS NUM to itself to shift bits to left)
 	 ST R5, SUB_DATA; m[NUM] <- R4 (stores left shifted value back into NUM)
	 LD R2, SUB_DATA; R1 <- m[NUM] (stores new value of NUM into R1)
 
	 ADD R6, R6, #-1
 	 BRz OUTPUT_SPACE

 	 ADD R4, R4, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
 	 BRzp FOR_LOOP_2	; if (R3 >= 0) go back to FOR_LOOP

 	BIT_IS_0
  	 LD R0, ZERO	; R0 <- m[ZERO] = char 0
  	 OUT		; output value stored at R0

 	 ADD R5, R5, R5	; R4 <- R4 + R4 (ADDS NUM to itself to shift bits to left)
	 ST R5, SUB_DATA; m[NUM] <- R4 (stores left shifted value back into NUM)
 	 LD R2, SUB_DATA; R1 <- m[NUM] (stores new value of NUM into R1)

 	 ADD R6, R6, #-1
 	 BRz OUTPUT_SPACE

 	 ADD R4, R4, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
 	 BRzp FOR_LOOP_2	; if (R3 >= 0) go back to FOR_LOOP

 	OUTPUT_SPACE
 	 LD R0, SPACE
 	 OUT
  	 LD R6, MAKE_SPACE
 	 ADD R4, R4, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
 	 BRzp FOR_LOOP_2	; if (R3 >= 0) go back to FOR_LOOP

	END_FOR_LOOP_2
	
	
; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3400		; restore R0
 ;LD R2, BACKUP_R2_3200		; restore R2
 LD R3, BACKUP_R3_3400		; restore R3
 LD R4, BACKUP_R4_3400		; restore R4
 LD R5, BACKUP_R5_3400		; restore R5
 LD R6, BACKUP_R6_3400		; restore R6
 LD R7, BACKUP_R7_3400		; restore R7
; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3400 .BLKW #1 	;one for each register modified (except return val).
;BACKUP_R2_3200 .BLKW #1
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R5_3400 .BLKW #1
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

;EX4 DATA
SUB_DATA .FILL #0	
MASK2 .FILL x8000
ITERATOR_2 .FILL #15
ZERO .FILL x30
ONE .FILL x31
CHAR_B .FILL x62
SPACE .FILL x20
MAKE_SPACE .FILL #4
NEWLINE .FILL #10

.END
