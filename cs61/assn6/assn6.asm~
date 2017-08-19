;=================================================
;
; Name: <Huang, Edward>
; Login id: ehuan010 (861026626)
;
; Assignment name: <assn 6>
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

LEA R0, INPUT_PROMPT		; STORES ADDRESS OF THE INPUT_PROMPT
PUTS				; outputs the PROMPT

LD R7, SUB_CONVERT_CHAR_3200	; load R7 with x3200
JSRR R7				; jump to x3200 and execute subroutine

LD R7, SUB_DECIMAL_TO_HEX_3400	; load R7 with x3400
JSRR R7				; jump to x3400 and execute subroutine

LD R0, BEG_OF_ARRAY		; stores address of BEG_OF_ARRAY
PUTS				; outputs array

HALT				; halts the program

;--------------------
; Data Block for main
;--------------------
INPUT_PROMPT .STRINGZ "Input a decimal number (max 5 digits in the range [0, 65535]), followed by ENTER key on keyboard: "
BEG_OF_ARRAY .FILL x4000
SUB_CONVERT_CHAR_3200 .FILL x3200
SUB_DECIMAL_TO_HEX_3400 .FILL x3400

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

LD R1, ZERO		; don't use R1 because it is the return value
LD R3, NEGATIVE_1	; R3 holds -1 which is a counter
LD R4, MASK		; converting mask #-48 to convert the characters
	
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

;LD R0, NEWLINE		; load R0 with a newline
;OUT			; output the newline

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
ZERO .FILL #0
NEGATIVE_1 .FILL #-1
NINE .FILL #9
VAL_R0 .FILL #0
VAL_R1 .FILL #0
NEWLINE .FILL #10
;----------------------------------------------------------------------------------------------------

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_DECIMAL_TO_HEX_3400
; Input (R1): A decimal number that will be converted to hexadecimal
; Input (R6): Pointer to the first block of an array
; Postcondition: Converts decimal number into hexadecimal and then stores the hex values in an array
; Return Value: R6 will point to the first block of the array

.ORIG x3400

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3400		; backup R0
 ST R2, BACKUP_R2_3400		; backup R2
 ST R3, BACKUP_R3_3400		; backup R3
 ST R4, BACKUP_R4_3400		; backup R4
 ST R5, BACKUP_R5_3400		; backup R5
 ;ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

; first load the 'x' into the array
LD R6, OUTPUT_ARRAY_START	; R6 will hold x4000
LD R2, CHAR_X			; R2 holds 'x'
STR R2, R6 , #0			; x4000 will hold the character 'x' (m[R6] <- R2)
ADD R6, R6, #1			; increment R6 to the next address (x4000 -> x4001)

;**************************************************************************************************

; This part gets the 16 bit hexadecimal number in each part and puts it in the array

; these initial ones need to be outside the two loops and before the branch statements
LD R2, NEG_SIXTEEN_P3		; loads R2 with -(16^3)
LD R3, HEX_COUNTER		; loads R3 with 0

ADD R1, R1, #0			; puts it inside itself so I can BR
BRzp POS_HEX_CONVERT		; if (R1 >= 0) go to POS_HEX_CONVERT
BRn NEG_HEX_CONVERT		; if (R1 < 0) go to NEG_HEX_CONVERT


; special checking for first 4 bits if the entered number is b/t [32768,65535]
NEG_HEX_CONVERT
 ADD R1, R1, R2			; subtracts R1 with R2
 ADD R3, R3, #1			; increment the counter
 ADD R1, R1, #0			; puts R1 into itself to check if it is still negative
 BRn NEG_HEX_CONVERT		; keeps looping the NEG_HEX_CONVERT if it is still negative

; this does the normal positive hexadecimal conversion
POS_HEX_CONVERT

; check the first 4 bits of R1, which holds the decimal number
CHECK_1ST_4_BITS
 ADD R1, R1, R2			; subtracts R1 with R2
 BRn END_CHECK_1ST_4_BITS	; if (R1 <= 0)???? go to END_CHECK_1ST_4_BITS 
 ADD R3, R3, #1			; otherwise increment the counter by 1
 BRp CHECK_1ST_4_BITS		; if (R3 > 0) go to CHECK_1ST_4_BITS

END_CHECK_1ST_4_BITS
 LD R2, POS_SIXTEEN_P3		; load R2 with (16^3)
 ADD R1, R1, R2			; make R1 back to its previous number
 STR R3, R6, #0			; m[R6] <- R3 (store R3 value into location pointed to by R6)
 ADD R6, R6, #1			; increment the array to the next address
 LD R3, HEX_COUNTER		; reload R3 counter back to zero

LD R2, NEG_SIXTEEN_P2		; loads R2 with -(16^2)

CHECK_2ND_4_BITS
 ADD R1, R1, R2			; subtracts R1 with R2
 BRn END_CHECK_2ND_4_BITS	; if (R1 <= 0)???? go to END_CHECK_2ND_4_BITS
 ADD R3, R3, #1			; otherwise increment the counter by 1
 BRp CHECK_2ND_4_BITS		; if (R3 > 0) go to CHECK_2ND_4_BITS

END_CHECK_2ND_4_BITS
 LD R2, POS_SIXTEEN_P2		; load R2 with (16^2)
 ADD R1, R1, R2			; make R1 back to its previous number
 STR R3, R6, #0			; m[R6] <- R3 (store R3 value into location pointed to by R6)
 ADD R6, R6, #1			; increment the array to the next address
 LD R3, HEX_COUNTER		; reload R3 counter back to zero

LD R2, NEG_SIXTEEN_P1		; loads R2 with -(16^1)

CHECK_3RD_4_BITS
 ADD R1, R1, R2			; subtracts R1 with R2
 BRn END_CHECK_3RD_4_BITS	; if (R1 <= 0)???? go to END_CHECK_3RD_4_BITS
 ADD R3, R3, #1			; otherwise increment the counter by 1
 BRp CHECK_3RD_4_BITS		; if (R3 > 0) go to CHECK_3RD_4_BITS

END_CHECK_3RD_4_BITS
 LD R2, POS_SIXTEEN_P1		; load R2 with (16^1)
 ADD R1, R1, R2			; make R1 back to its previous number
 STR R3, R6, #0			; m[R6] <- R3 (store R3 value into location pointed to by R6)
 ADD R6, R6, #1			; increment the array to the next address
 LD R3, HEX_COUNTER		; reload R3 counter back to zero

LD R2, NEG_SIXTEEN_P0		; loads R2 with -(16^0)

CHECK_4TH_4_BITS
 ADD R1, R1, R2			; subtracts R1 with R2
 BRn END_CHECK_4TH_4_BITS	; if (R1 <= 0)???? go to END_CHECK_4TH_4_BITS
 ADD R3, R3, #1			; otherwise increment the counter by 1
 BRp CHECK_4TH_4_BITS		; if (R3 > 0) go to CHECK_4TH_4_BITS

END_CHECK_4TH_4_BITS
 LD R2, POS_SIXTEEN_P0		; load R2 with (16^0)
 ADD R1, R1, R2			; make R1 back to its previous number
 STR R3, R6, #0			; m[R6] <- R3 (store R3 value into location pointed to by R6)
 ADD R6, R6, #1			; increment the array to the next address
 LD R3, HEX_COUNTER		; reload R3 counter back to zero
 BRz CONVERT_TO_HEX		; if (R3 = 0) which it will, go to CONVERT_TO_HEX

; ^ might not need the last 2 lines, cause it just continues afterwards

;**************************************************************************************************
; convert the 4 parts into their respective characters and restore them in the array

CONVERT_TO_HEX

 LD R6, OUTPUT_ARRAY_START	; load R6 with the start of the array
 ADD R6, R6, #1			; increment to next address x4001

; have a for loop to check the addresses??? make a counter
LD R5, HEX_TO_DEC_LOOP_COUNTER	; load R5 with the counter 4
LD R7, DEC_TO_CHAR_MASK		; load R7 with #48

DEC_TO_HEX_LOOP
 LDR R2, R6, #0			; R2 <- m[R6] now R2 is used to hold the value stored at m[R6]
 ADD R2, R2, #-9		; subtract 9 from R2
 BRnz CHANGE_TO_CHAR
 BRp CHECK_HEX_VALUE		; if (R2 > 0) go to CHECK_HEX_VALUE

 ;PERFORM_INCREMENT
 ;ADD R5, R5, #-1		; otherwise continue and decrement the counter
 ;BRp DEC_TO_HEX_LOOP		; if (R5 > 0) go to DEC_TO_HEX_LOOP
 ;BRz END_DEC_TO_HEX_LOOP

CHANGE_TO_CHAR
 ADD R2, R2, #9			; undo the -9 by adding 9
 ADD R2, R2, R7			; add R7 to convert R2 to the char representation
 STR R2, R6, #0			; m[R6] <- R2 (store the changed value into the array)
 ; increment to next address and update the counter
 ADD R6, R6, #1			; increment to the next address of the array
 ADD R5, R5, #-1		; decrement the counter
 BRp DEC_TO_HEX_LOOP		; if (R5 > 0) go to DEC_TO_HEX_LOOP
 BRz END_DEC_TO_HEX_LOOP	; if (R5 = 0) go to END_DEC_TO_HEX_LOOP


CHECK_HEX_VALUE
 ADD R2, R2, #9			; undo the -9 by adding 9
 ADD R2, R2, #-10		; subtract 10 from R2 
 BRz IS_A			; if (R2 = 0) then go to IS_A

 ADD R2, R2, #10		; undo -10 by adding 10
 ADD R2, R2, #-11		; subtract 11 from R2
 BRz IS_B			; if (R2 = 0) then go to IS_B

 ADD R2, R2, #11		; undo -11 by adding 11
 ADD R2, R2, #-12		; subtract 12 from R2
 BRz IS_C			; if (R2 = 0) then go to IS_C

 ADD R2, R2, #12		; undo -12 by adding 12
 ADD R2, R2, #-13		; subtract 13 from R2
 BRz IS_D			; if (R2 = 0) then go to IS_D

 ADD R2, R2, #13		; undo -13 by adding 13
 ADD R2, R2, #-14		; subtract 14 from R2
 BRz IS_E			; if (R2 = 0) then go to IS_E

 ADD R2, R2, #14		; undo -14 by adding 14
 ADD R2, R2, #-15		; subtract 15 from R2
 BRz IS_F			; if (R2 = 0) then go to IS_F

; don't need any BR after this because R2 must be one of the above

IS_A
 ; don't need R3 as hex counter anymore
 LD R3, LETTER_A		; load R3 with 'A'
 STR R3, R6, #0			; m[R6] <- R3 (replace contents m[R6] with R3)
 ; increment to next address and update the counter
 ADD R6, R6, #1			; increment to the next address of the array
 ADD R5, R5, #-1		; decrement the counter
 BRp DEC_TO_HEX_LOOP		; if (R5 > 0) go to DEC_TO_HEX_LOOP
 BRz END_DEC_TO_HEX_LOOP	; if (R5 = 0) go to END_DEC_TO_HEX_LOOP

IS_B
 ; don't need R3 as hex counter anymore
 LD R3, LETTER_B		; load R3 with 'B'
 STR R3, R6, #0			; m[R6] <- R3 (replace contents m[R6] with R3)
 ; increment to next address and update the counter
 ADD R6, R6, #1			; increment to the next address of the array
 ADD R5, R5, #-1		; decrement the counter
 BRp DEC_TO_HEX_LOOP		; if (R5 > 0) go to DEC_TO_HEX_LOOP
 BRz END_DEC_TO_HEX_LOOP	; if (R5 = 0) go to END_DEC_TO_HEX_LOOP

IS_C
 ; don't need R3 as hex counter anymore
 LD R3, LETTER_C		; load R3 with 'C'
 STR R3, R6, #0			; m[R6] <- R3 (replace contents m[R6] with R3)
 ; increment to next address and update the counter
 ADD R6, R6, #1			; increment to the next address of the array
 ADD R5, R5, #-1		; decrement the counter
 BRp DEC_TO_HEX_LOOP		; if (R5 > 0) go to DEC_TO_HEX_LOOP
 BRz END_DEC_TO_HEX_LOOP	; if (R5 = 0) go to END_DEC_TO_HEX_LOOP

IS_D
 ; don't need R3 as hex counter anymore
 LD R3, LETTER_D		; load R3 with 'D'
 STR R3, R6, #0			; m[R6] <- R3 (replace contents m[R6] with R3)
 ; increment to next address and update the counter
 ADD R6, R6, #1			; increment to the next address of the array
 ADD R5, R5, #-1		; decrement the counter
 BRp DEC_TO_HEX_LOOP		; if (R5 > 0) go to DEC_TO_HEX_LOOP
 BRz END_DEC_TO_HEX_LOOP	; if (R5 = 0) go to END_DEC_TO_HEX_LOOP

IS_E
 ; don't need R3 as hex counter anymore
 LD R3, LETTER_E		; load R3 with 'E'
 STR R3, R6, #0			; m[R6] <- R3 (replace contents m[R6] with R3)
 ; increment to next address and update the counter
 ADD R6, R6, #1			; increment to the next address of the array
 ADD R5, R5, #-1		; decrement the counter
 BRp DEC_TO_HEX_LOOP		; if (R5 > 0) go to DEC_TO_HEX_LOOP
 BRz END_DEC_TO_HEX_LOOP	; if (R5 = 0) go to END_DEC_TO_HEX_LOOP

IS_F
 ; don't need R3 as hex counter anymore
 LD R3, LETTER_F		; load R3 with 'F'
 STR R3, R6, #0			; m[R6] <- R3 (replace contents m[R6] with R3)
 ; increment to next address and update the counter
 ADD R6, R6, #1			; increment to the next address of the array
 ADD R5, R5, #-1		; decrement the counter
 BRp DEC_TO_HEX_LOOP		; if (R5 > 0) go to DEC_TO_HEX_LOOP
 BRz END_DEC_TO_HEX_LOOP	; if (R5 = 0) go to END_DEC_TO_HEX_LOOP


END_DEC_TO_HEX_LOOP

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3400		; restore R0
 LD R2, BACKUP_R2_3400		; restore R2
 LD R3, BACKUP_R3_3400		; restore R3
 LD R4, BACKUP_R4_3400		; restore R4
 LD R5, BACKUP_R5_3400		; restore R5
 ;LD R6, BACKUP_R6_3400		; restore R6
 LD R7, BACKUP_R7_3400		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3400 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R2_3400 .BLKW #1
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R5_3400 .BLKW #1
;BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

POS_SIXTEEN_P0 .FILL #1
POS_SIXTEEN_P1 .FILL #16
POS_SIXTEEN_P2 .FILL #256
POS_SIXTEEN_P3 .FILL #4096
NEG_SIXTEEN_P0 .FILL #-1
NEG_SIXTEEN_P1 .FILL #-16
NEG_SIXTEEN_P2 .FILL #-256
NEG_SIXTEEN_P3 .FILL #-4096
LETTER_A .FILL #65
LETTER_B .FILL #66
LETTER_C .FILL #67
LETTER_D .FILL #68
LETTER_E .FILL #69
LETTER_F .FILL #70
DEC_TO_CHAR_MASK .FILL #48
HEX_TO_DEC_LOOP_COUNTER .FILL #4
CHAR_X .FILL #120
HEX_COUNTER .FILL #0		; counts the hex value 0 - 15
OUTPUT_ARRAY_START .FILL x4000	; where the array will be stored
;----------------------------------------------------------------------------------------------------
