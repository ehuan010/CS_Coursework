.orig x3000

LD R7, SUB_PRINT_CHAR_4000
JSRR R7

HALT
;--------------------
; Data Block for main
;--------------------
SUB_PRINT_CHAR_4000 .FILL x4000


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_PRINT_CHAR_4000
; Input R1, R2, R5, R6: Two values stored in R1 and R2. Multiplied result in R5. Sign in R6
; Postcondition: Print out the result R5 with sign R6 of multiplying the two numbers R1 and R2
; Return Value: (none)

.ORIG x4000

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_4000		; backup R0
 ST R3, BACKUP_R3_4000		; backup R3
 ST R4, BACKUP_R4_4000		; backup R4
 ;ST R5, BACKUP_R5_4000		; backup R5
 ;ST R6, BACKUP_R6_4000		; backup R6
 ST R7, BACKUP_R7_4000		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

;first I check the underflow/overflow condition using R6 the sign and R5 the value of -1

ST R1, FIRST_VALUE_4		; store R1 into label
ST R2, SECOND_VALUE_4		; store R2 into label
ST R5, MULTIPLIED_RESULT	; store R5 into label
ST R6, SIGN_VALUE		; store R6 into label

; + is 43 and - is 45 ...soo if I subtract 45 and it is zero it must be -. If neg result then positive

LD R3, SIGN_MASK		; load R3 with the SIGN_MASK

LD R6, SIGN_VALUE		; reload R6 with SIGN_VALUE
ADD R6, R6, R3			; subtracts 45 from the value (the R6 value got changed)
BRn RESULT_IS_POS		; if (R6 < 0) then go to RESULT_IS_POS
BRz RESULT_IS_NEG		; else if (R6 = 0) then go to RESULT_IS_NEG
; don't need BRp because R6 holds the sign...so it HAS to be one of these

RESULT_IS_POS
 LD R5, MULTIPLIED_RESULT	; reload R5 with MULTIPLIED_RESULT
 BRn OVERFLOWED			; if R5 is -1 then it overflows for + result
 BRzp PRINT_EVERYTHING		; if (R5 >= 0) then go to PRINT_EVERYTHING

RESULT_IS_NEG
 LD R5, MULTIPLIED_RESULT	; reload R5 with MULTIPLIED_RESULT
 BRn UNDERFLOWED		; if R5 is -1 then it underflows for - result
 BRzp PRINT_EVERYTHING		; if (R5 >= 0) then go to PRINT_EVERYTHING


OVERFLOWED
 LD R0, NEWLINE_2		; load R0 with newline
 OUT				; print newline
 LEA R0, OVERFLOW_MSG		; load R0 with overflow message
 PUTS				; print it out
 BRnzp DONE_PRINTING		; after doing this then it is DONE_PRINTING

UNDERFLOWED
 LD R0, NEWLINE_2		; load R0 with newline
 OUT				; print newline
 LEA R0, UNDERFLOW_MSG		; load R0 with underflow message
 PUTS				; print it out
 BRnzp DONE_PRINTING		; after doing this then it is DONE_PRINTING


; BRn and BRp sooo if it is postive the output a +...if - then output a - then print the number

; this loop must print (ie. +100 * -10 = -1000)
PRINT_EVERYTHING


LD R0, NEWLINE_2
OUT

;****************************************************************************************************

LD R1, FIRST_VALUE_4
BRzp OUTPUT_PLUS
BRn OUTPUT_MINUS

; Output the sign first
OUTPUT_PLUS
 LD R0, PLUS_SIGN
 OUT
 BRp OUTPUT_R1			; will this work???

OUTPUT_MINUS
 LD R0, MINUS_SIGN
 OUT
 BRp OUTPUT_R1

OUTPUT_R1
 LD R0, COUNTER
 LD R3, NEG_TEN_THOUSAND
 LD R4, CHAR_MASK

 R1_PRINT_LOOP
  ADD R1, R1, R3		; add R1 with R3
  BRn PRINT_R1_1ST		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R1_PRINT_LOOP		; if (R0 > 0) go to R1_PRINT_LOOP

 PRINT_R1_1ST
  LD R3, POS_TEN_THOUSAND
  ADD R1, R1, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_THOUSAND

 R1_PRINT_LOOP_2
  ADD R1, R1, R3		; add R1 with the 
  BRn PRINT_R1_2ND		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R1_PRINT_LOOP_2 		; if (R0 > 0) go to R1_PRINT_LOOP

 PRINT_R1_2ND
  LD R3, POS_THOUSAND
  ADD R1, R1, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_HUNDRED

 R1_PRINT_LOOP_3
  ADD R1, R1, R3		; add R1 with the 
  BRn PRINT_R1_3RD		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R1_PRINT_LOOP_3 		; if (R0 > 0) go to R1_PRINT_LOOP

 PRINT_R1_3RD
  LD R3, POS_HUNDRED
  ADD R1, R1, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_TEN

 R1_PRINT_LOOP_4
  ADD R1, R1, R3		; add R1 with the 
  BRn PRINT_R1_4TH		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R1_PRINT_LOOP_4 		; if (R0 > 0) go to R1_PRINT_LOOP

 PRINT_R1_4TH
  LD R3, POS_TEN
  ADD R1, R1, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_ONE

 R1_PRINT_LOOP_5
  ADD R1, R1, R3		; add R1 with the 
  BRn PRINT_R1_5TH		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R1_PRINT_LOOP_5 		; if (R0 > 0) go to R1_PRINT_LOOP

 PRINT_R1_5TH
  LD R3, POS_ONE
  ADD R1, R1, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter
  
  ;^ is that last LD unnecessary??!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

;****************************************************************************************************

LD R0, SPACE
OUT
LD R0, STAR
OUT
LD R0, SPACE
OUT


;****************************************************************************************************

LD R2, SECOND_VALUE_4
BRzp OUTPUT_PLUS_2
BRn OUTPUT_MINUS_2

; Output the sign first
OUTPUT_PLUS_2
 LD R0, PLUS_SIGN
 OUT
 BRp OUTPUT_R2			; will this work???

OUTPUT_MINUS_2
 LD R0, MINUS_SIGN
 OUT
 BRp OUTPUT_R2

OUTPUT_R2
 LD R0, COUNTER
 LD R3, NEG_TEN_THOUSAND
 LD R4, CHAR_MASK

 R2_PRINT_LOOP
  ADD R2, R2, R3		; add R2 with R3
  BRn PRINT_R2_1ST		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R2_PRINT_LOOP		; if (R0 > 0) go to R2_PRINT_LOOP

 PRINT_R2_1ST
  LD R3, POS_TEN_THOUSAND
  ADD R2, R2, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_THOUSAND

 R2_PRINT_LOOP_2
  ADD R2, R2, R3		; add R2 with R3
  BRn PRINT_R2_2ND		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R2_PRINT_LOOP_2 		; if (R0 > 0) go to R2_PRINT_LOOP

 PRINT_R2_2ND
  LD R3, POS_THOUSAND
  ADD R2, R2, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_HUNDRED

 R2_PRINT_LOOP_3
  ADD R2, R2, R3		; add R2 with R3
  BRn PRINT_R2_3RD		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R2_PRINT_LOOP_3 		; if (R0 > 0) go to R2_PRINT_LOOP

 PRINT_R2_3RD
  LD R3, POS_HUNDRED
  ADD R2, R2, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_TEN

 R2_PRINT_LOOP_4
  ADD R2, R2, R3		; add R2 with R3 
  BRn PRINT_R2_4TH		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R2_PRINT_LOOP_4 		; if (R0 > 0) go to R2_PRINT_LOOP

 PRINT_R2_4TH
  LD R3, POS_TEN
  ADD R2, R2, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_ONE

 R2_PRINT_LOOP_5
  ADD R2, R2, R3		; add R2 with R3
  BRn PRINT_R2_5TH		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R2_PRINT_LOOP_5 		; if (R0 > 0) go to R2_PRINT_LOOP

 PRINT_R2_5TH
  LD R3, POS_ONE
  ADD R2, R2, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

  ;^ is that last LD unnecessary??!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

;****************************************************************************************************

LD R0, SPACE
OUT
LD R0, EQUALS
OUT
LD R0, SPACE
OUT

; output the sign of the multiplied number
;LD R0, SIGN_VALUE
LD R0, PLUS_SIGN
OUT

;****************************************************************************************************

LD R5, MULTIPLIED_RESULT

;LD R5, POS_TEN

; sign should already be outputted

OUTPUT_R5
 LD R0, COUNTER
 LD R3, NEG_TEN_THOUSAND
 LD R4, CHAR_MASK

 R5_PRINT_LOOP
  ADD R5, R5, R3		; add R5 with R3
  BRn PRINT_R5_1ST		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R5_PRINT_LOOP		; if (R0 > 0) go to R5_PRINT_LOOP

 PRINT_R5_1ST
  LD R3, POS_TEN_THOUSAND
  ADD R5, R5, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_THOUSAND

 R5_PRINT_LOOP_2
  ADD R5, R5, R3		; add R5 with R3
  BRn PRINT_R5_2ND		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R5_PRINT_LOOP_2 		; if (R0 > 0) go to R5_PRINT_LOOP

 PRINT_R5_2ND
  LD R3, POS_THOUSAND
  ADD R5, R5, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_HUNDRED

 R5_PRINT_LOOP_3
  ADD R5, R5, R3		; add R5 with R3
  BRn PRINT_R5_3RD		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R5_PRINT_LOOP_3 		; if (R0 > 0) go to R5_PRINT_LOOP

 PRINT_R5_3RD
  LD R3, POS_HUNDRED
  ADD R5, R5, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_TEN

 R5_PRINT_LOOP_4
  ADD R5, R5, R3		; add R5 with R3 
  BRn PRINT_R5_4TH		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R5_PRINT_LOOP_4 		; if (R0 > 0) go to R5_PRINT_LOOP

 PRINT_R5_4TH
  LD R3, POS_TEN
  ADD R5, R5, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_ONE

 R5_PRINT_LOOP_5
  ADD R5, R5, R3		; add R5 with R3
  BRn PRINT_R5_5TH		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R5_PRINT_LOOP_5 		; if (R0 > 0) go to R5_PRINT_LOOP

 PRINT_R5_5TH
  LD R3, POS_ONE
  ADD R5, R5, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

;****************************************************************************************************
DONE_PRINTING

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_4000		; restore R0
 LD R3, BACKUP_R3_4000		; restore R3
 LD R4, BACKUP_R4_4000		; restore R4
 ;LD R5, BACKUP_R5_4000		; restore R5
 ;LD R6, BACKUP_R6_4000		; restore R6
 LD R7, BACKUP_R7_4000		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_4000 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R3_4000 .BLKW #1
BACKUP_R4_4000 .BLKW #1
;BACKUP_R5_4000 .BLKW #1
;BACKUP_R6_4000 .BLKW #1
BACKUP_R7_4000 .BLKW #1

FIRST_VALUE_4 .FILL #0
SECOND_VALUE_4 .FILL #0
SIGN_VALUE .FILL #0
MULTIPLIED_RESULT .FILL #0
SIGN_MASK .FILL #-45
NEWLINE_2 .FILL #10
SPACE .FILL #32
STAR .FILL #42
EQUALS .FILL #61
PLUS_SIGN .FILL #43
MINUS_SIGN .FILL #45
OVERFLOW_MSG .STRINGZ "Overflow =["
UNDERFLOW_MSG .STRINGZ "Underflow =["

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

;----------------------------------------------------------------------------------------------------

.END
