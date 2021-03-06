;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 06
;-----------------------------------------------------------------------------------

;count how many 10,000's there are using a for loop...R2 gets/= R1 and if R2 is negative then quit. Use a counter and put it into R0 to know what decimal value we have.
;convert R0 to character first before printing


;------------
; Main Code
;------------
.ORIG x3000

LD R6, SUB_CONVERT_CHAR_3200
JSRR R6

ADD R1, R1, #1

LD R6, SUB_PRINT_CHAR_3400
JSRR R6

HALT

;--------------------
; Data Block for main
;--------------------
SUB_CONVERT_CHAR_3200 .FILL x3200
SUB_PRINT_CHAR_3400 .FILL x3400

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

LD R3, NEGATIVE_1	;
LD R4, MASK
LD R5, P_N_CHECK	; (checks if number is + or -)
	

; Resets the program when there is an error

LEA R0, PROMPT		; STORES ADDRESS OF THE PROMPT
PUTS			; outputs the PROMPT


;Check first character
GETC			; Get a character from the user and store it into R0
OUT


ADD R0, R0, R5		; + is #43 and - is #45...R5 shouExample: The ASCII code for a semi-colon (‘;’) is #59 == x3B == b0000 0000 0011 1011ld now be negative or 0
BRz CHAR_IS_N		; if (R5 = 0) the character must be negative

CHAR_IS_P		; the character must be +CHAR_PRINT_LOOP
 LD R5, ZERO		; R5 <-- m[ZERO] = #0
 ST R5, VAL_R5
 BRz FOR_LOOP

CHAR_IS_N		; the character must be -
 LD R5, NEGATIVE_1	; R5 <-- m[NEGATIVE_1] = #-1
 ST R5, VAL_R5
 BRn FOR_LOOP



;This FOR_LOOP takes in input from the user
FOR_LOOP
 GETC			; Get a character from the user and store it into R0
 OUT
 ;STR R0, R2, #0	; m[R2] <-- R0

 ST R0, VAL_R0		; first store the value of R0 into a label
 
 LD R6, VALIDATION
 ADD R0, R0, R6
 BRnz CONTINUE

 INVALID
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
 LD R0, VAL_R0
 ADD R0, R0, #-10	; R0 <-- R0 - 10
 BRz END_FOR_LOOP

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
VALIDATION .FILL #-57
ZERO .FILL #0
NEGATIVE_1 .FILL #-1
P_N_CHECK .FILL #-45
NINE .FILL #9
VAL_R0 .FILL #0
VAL_R1 .FILL #0
VAL_R5 .FILL #0
PROMPT .STRINGZ "Input a decimal number (max 5 digits in the range [-32768, +32767]) , preceded with +/‐, followed by ENTER key on keyboard: "
ERROR_MSG .STRINGZ "Not a valid input!!!"
NEWLINE .FILL #10
;----------------------------------------------------------------------------------------------------



; Subroutine: SUB_PRINT_CHAR_3400
; Input R0: Some value stored in R1 to print as decimal
; Postcondition: Print out the number stored in R1 as it's character equivalent
; Return Value: (none)

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
 ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

LD R0, COUNTER
LD R2, NEG_TEN_THOUSAND
LD R3, CHAR_MASK

CHAR_PRINT_LOOP
 ADD R1, R1, R2
 BRn PRINT_1ST
 ADD R0, R0, #1
 BRp CHAR_PRINT_LOOP


PRINT_1ST
 LD R2, POS_TEN_THOUSAND
 ADD R1, R1, R2			; reload back to original
 ADD R0, R0, R3			; add the R0 counter with the mask for the character
 OUT				; print R0
 LD R0, COUNTER			; reload the counter

LD R2, NEG_THOUSAND

CHAR_PRINT_LOOP_2
 ADD R1, R1, R2
 BRn PRINT_2ND
 ADD R0, R0, #1
 BRp CHAR_PRINT_LOOP_2


PRINT_2ND
 LD R2, POS_THOUSAND
 ADD R1, R1, R2			; reload back to original
 ADD R0, R0, R3
 OUT				; print R0
 LD R0, COUNTER			; reload the counter

LD R2, NEG_HUNDRED

CHAR_PRINT_LOOP_3
 ADD R1, R1, R2
 BRn PRINT_3RD
 ADD R0, R0, #1
 BRp CHAR_PRINT_LOOP_3


PRINT_3RD
 LD R2, POS_HUNDRED
 ADD R1, R1, R2			; reload back to original
 ADD R0, R0, R3
 OUT				; print R0
 LD R0, COUNTER			; reload the counter

LD R2, NEG_TEN

CHAR_PRINT_LOOP_4
 ADD R1, R1, R2
 BRn PRINT_4TH
 ADD R0, R0, #1
 BRp CHAR_PRINT_LOOP_4


PRINT_4TH
 LD R2, POS_TEN
 ADD R1, R1, R2			; reload back to original
 ADD R0, R0, R3
 OUT				; print R0
 LD R0, COUNTER			; reload the counter

LD R2, NEG_ONE

CHAR_PRINT_LOOP_5
 ADD R1, R1, R2
 BRn PRINT_5TH
 ADD R0, R0, #1
 BRp CHAR_PRINT_LOOP_5

PRINT_5TH
 LD R2, POS_ONE
 ADD R1, R1, R2			; reload back to original
 ADD R0, R0, R3
 OUT				; print R0
 LD R0, COUNTER			; reload the counter

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3400		; restore R0
 LD R2, BACKUP_R2_3400		; restore R2
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
BACKUP_R0_3400 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R2_3400 .BLKW #1
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R5_3400 .BLKW #1
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

COUNTER .FILL #0
NEG_TEN_THOUSAND .FILL #-10000
NEG_THOUSAND .FILL #-1000
NEG_HUNDRED .FILL #-100
NEG_TEN .FILL #-10
NEG_ONE .FILL #-1
POS_TEN_THOUSAND .FILL #10000
POS_THOUSAND .FILL #1000
POS_HUNDRED .FILL #100
POS_TEN .FILL #10
POS_ONE .FILL #1
CHAR_MASK .FILL #48
;------------------------------------------------------------------------------------------------



.END
