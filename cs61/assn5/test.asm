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

LD R6, SUB_CONVERT_CHAR_3200	; calls this to get the 1st number
JSRR R6

ST R1, FIRST_NUMBER		; stores the first number

LD R6, SUB_CONVERT_CHAR_3200	; calls this to get a 2nd number
JSRR R6				

ST R1, SECOND_NUMBER		; stores the second number

LD R1, FIRST_NUMBER		; reloads first number
LD R2, SECOND_NUMBER		; reloads second number

LD R6, SUB_FIND_LARGER_3400	; calls this to find the larger number
JSRR R6

LD R7, SUB_FINAL_SIGN_3600	; calls this to find the sign of the result
JSRR R7

LD R7, SUB_MULTIPLY_TWO_NUM_3800	; calls this to multiply R1 and R2
JSRR R7

LD R7, SUB_PRINT_CHAR_4000	; calls this to print our the results
JSRR R7

HALT				; ends the program

;--------------------
; Data Block for main
;--------------------
SUB_CONVERT_CHAR_3200 .FILL x3200
SUB_FIND_LARGER_3400 .FILL x3400
SUB_FINAL_SIGN_3600 .FILL x3600
SUB_MULTIPLY_TWO_NUM_3800 .FILL x3800
SUB_PRINT_CHAR_4000 .FILL x4000
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
LD R5, VALIDATION1	; loads R5 with VALIDATION1
LD R6, VALIDATION2	; loads R6 with VALIDATION2
	

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


 LD R0, NEWLINE		; load R0 with NEWLINE
 OUT			; output newline
 LEA R0, ERROR_MSG	; loads R0 with error message
 PUTS			; output the error message
 LD R0, NEWLINE		; loads newline
 OUT			; outputs newline
 ADD R0, R0, #0		; puts R0 into R0
 BRnzp RESTART		; restart the program no matter what
 
 CONTINUE

 ;if you subtract 10 and the value is zero end the for loop
 ;LD R0, VAL_R0
 ;ADD R0, R0, #-10	; R0 <-- R0 - 10
 ;BRz END_FOR_LOOP

 ;otherwise normally continue the program and load VAL_R0 back into R0
 
 LD R0, VAL_R0		; load R0 with VAL_R0
 ADD R0, R0, R4		; add R0 with R4

 LD R2, NINE		; load R2 with nine
 ADD R3, R3, #1		; increments the counter from -1 to 0 (start), etc.
 BRp CONVERTER		; if (R3 > 0) then go to CONVERTER

 ;put it into R1 for initial
 ADD R1, R1, R0		; add R1 with R0
 BRzp SKIP		; if (R1 >= 0) then go to SKIP

 CONVERTER
  ST R1, VAL_R1		; store R1 into VAL_R1
  LD R6, VAL_R1		; load R6 with VAL_R1

  MULTIPLY_BY_10
   ADD R1, R1, R6	; add R1 with R6
   ADD R2, R2, #-1 	; R2 with 9 only want to add it to itself 9 times
   BRp MULTIPLY_BY_10	; if (R2 > 0) go to MULTIPLY_BY_10
   
  ADD R1, R1, R0	; put R1 into R1
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

LD R5, VAL_R5		; load R5 with VAL_R5
BRz IS_P		; if (R5 = 0) then go to IS_P

;otherwise continue here
IS_N
 NOT R1, R1		; invert R1
 ADD R1, R1, #1		; add 1 (2's complement)

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



;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_FIND_LARGER_3400
; Input R1,R2: Two numbers stored in two different registers
; Postcondition: Checks which number is larger, and swaps if the second is larger than the first
; Return Value: R1 will hold the larger value and R2 will hold the smaller value

.ORIG x3400

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3400		; backup R0
 ST R3, BACKUP_R3_3400		; backup R3
 ST R4, BACKUP_R4_3400		; backup R4
 ST R5, BACKUP_R5_3400		; backup R5
 ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform


; Check R1
ST R1, FIRST_VALUE		; m[FIRST_VALUE] <- R1 (hold the original R1 value)
LD R1, FIRST_VALUE		; R1 <- m[FIRST_VALUE] (restore it for use)
BRn ABSOLUTE_VALUE_1		; if (R1 < 0) take the absolute value of it

; Check R2
CHECK_SECOND_VALUE		
 ST R2, SECOND_VALUE		; m[SECOND_VALUE] <- R2 (hold the original R2 value)
 LD R2, SECOND_VALUE		; R2 <- m[SECOND_VALUE] (restore it for use)
 BRn ABSOLUTE_VALUE_2		; if (R2 < 0) take the absolute value of it
 BRzp FIND_LARGER		; otherwise if (R2 >= 0) go to FIND_LARGER

; Take absolute value of R1
ABSOLUTE_VALUE_1
 NOT R1, R1			; invert R1
 ADD R1, R1, #1			; add 1 
 BRzp CHECK_SECOND_VALUE	; if (R1 >= 0) which it will be...go to CHECK_SECOND_VALUE

; Take absolute value of R2
ABSOLUTE_VALUE_2
 NOT R2, R2			; invert R2
 ADD R2, R2, #1			; add 1
 BRzp FIND_LARGER		; if (R2 >=0) which it will be...go to FIND_LARGER

; Finds the larger of the absolute value of the two numbers
FIND_LARGER
 ;subtract first from second
 NOT R1, R1			; invert R1
 ADD R1, R1, #1			; add 1 (this will be used for subtraction to determine larger value)
 
 ADD R3, R2, R1			; subtracts first from second (R2 -R1) and store it in R3
 BRnz NORMAL_RELOAD		; if (R3 <= 0) go to NORMAL_RELOAD
 BRp SWAP_RELOAD		; otherwise if (R3 > 0) go to SWAP_RELOAD

; swaps second and first value
SWAP_RELOAD
 LD R1, SECOND_VALUE		; R1 <- m[SECOND_VALUE]
 LD R2, FIRST_VALUE		; R2 <- m[FIRST_VALUE]
 BRnzp END_RELOAD		; always go to END_RELOAD

; load the original values
NORMAL_RELOAD
 LD R1, FIRST_VALUE		; R1 <- m[FIRST_VALUE]
 LD R2, SECOND_VALUE		; R2 <- m[SECOND_VALUE]
 BRnzp END_RELOAD		; always go to END_RELOAD

END_RELOAD

 ;if it's zero just load them back into normal
 ;if it's positive swap R1 and R2
 ;if it's negative keep R1 and R2 the same

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3400		; restore R0
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
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R5_3400 .BLKW #1
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1


FIRST_VALUE .FILL #0
SECOND_VALUE .FILL #0
;----------------------------------------------------------------------------------------------------


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_FINAL_SIGN_3600
; Input R1,R2: Two numbers stored in two different registers
; Postcondition: Determines the sign of the final answer +/-
; Return Value: R1 and R2 will hold their original value. R6 will hold the sign.

.ORIG x3600

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3600		; backup R0
 ST R3, BACKUP_R3_3600		; backup R3
 ST R4, BACKUP_R4_3600		; backup R4
 ST R5, BACKUP_R5_3600		; backup R5
 ;ST R6, BACKUP_R6_3600		; backup R6
 ST R7, BACKUP_R7_3600		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform


ST R1, FIRST_VALUE_2		; store R1
ST R2, SECOND_VALUE_2		; store R2

LD R1, FIRST_VALUE_2
BRzp POSITIVE_VAL		; first is zero/positive
BRn NEGATIVE_VAL		; first is negative

; first is zero/pos
POSITIVE_VAL
 LD R2, SECOND_VALUE_2		
 BRzp POSITIVE_RESULT		; first is zero/positive second is zero/positive = +
 BRn NEGATIVE_RESULT		; first is zero/positive second is neative = -

NEGATIVE_VAL
 LD R2, SECOND_VALUE_2
 BRzp NEGATIVE_RESULT		; first is negative second is zero/positive = -
 BRn POSITIVE_RESULT		; first is negative second is negative = +

POSITIVE_RESULT
 LD R6, POSITIVE_SIGN		; load R6 with +
 BRp FINAL_SIGN			; R6 will be postive so go to FINAL_SIGN

NEGATIVE_RESULT
 LD R6, NEGATIVE_SIGN		; load R6 with -
 BRp FINAL_SIGN			; R6 will be positive so go to FINAL_SIGN

FINAL_SIGN
 ;ADD R0, R6, #0
 ;OUT
 ;LD R4, TEST3
 ;NOT R1, R1
 ;ADD R1, R1, #1
 ;ADD R1, R1, R4
 ;LD R0, TEST4
 ;ADD R0, R1, #0
 ;OUT

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3600		; restore R0
 LD R3, BACKUP_R3_3600		; restore R3
 LD R4, BACKUP_R4_3600		; restore R4
 LD R5, BACKUP_R5_3600		; restore R5
 ;LD R6, BACKUP_R6_3600		; restore R6
 LD R7, BACKUP_R7_3600		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3600 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R3_3600 .BLKW #1
BACKUP_R4_3600 .BLKW #1
BACKUP_R5_3600 .BLKW #1
;BACKUP_R6_3600 .BLKW #1
BACKUP_R7_3600 .BLKW #1

FIRST_VALUE_2 .FILL #0
SECOND_VALUE_2 .FILL #0
NEGATIVE_SIGN .FILL #45
POSITIVE_SIGN .FILL #43


;----------------------------------------------------------------------------------------------------


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_MULTIPLY_TWO_NUM_3800
; Input R1,R2: Two numbers stored in two different registers
; Postcondition: Multiplies the two numbers stored in R1 and R2
; Return Value: Place the final value into R5

.ORIG x3800

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3800		; backup R0
 ST R3, BACKUP_R3_3800		; backup R3
 ST R4, BACKUP_R4_3800		; backup R4
 ;ST R5, BACKUP_R5_3800		; backup R5
 ;ST R6, BACKUP_R6_3800		; backup R6
 ST R7, BACKUP_R7_3800		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform


ST R1, FIRST_VALUE_3		; store original value of R1
ST R2, SECOND_VALUE_3		; store original value of R2

; checks if first value is negative
LD R1, FIRST_VALUE_3		; loads R1 with initial value to check it
BRn ABSOLUTE_VALUE_3		; if it's negative take the absolute value
BRz ZERO_RESULT			; if the first value is zero the answer is zero
;already solved for zero without this, but put it for easier readability
;BRzp PERFORM_MULTIPLY

CHECK_SECOND_VALUE_2
LD R2, SECOND_VALUE_3		; loads R2 with initial value to check it
BRz ZERO_RESULT			; if the second value is zero the answer is zero
BRn ABSOLUTE_VALUE_4		; if the second value is negative take the absolute value
BRp PERFORM_MULTIPLY		; if the second value is positive multiply it with the first

ABSOLUTE_VALUE_3
 NOT R1, R1			; invert R1
 ADD R1, R1, #1			; add 1 
 BRp CHECK_SECOND_VALUE_2	; R1 will be positive so go to CHECK_SECOND_VALUE_2

ABSOLUTE_VALUE_4
 NOT R2, R2			; invert R2
 ADD R2, R2, #1			; add 1
 BRp PERFORM_MULTIPLY		; R2 will be positive so go to PERFORM_MULTIPLY



PERFORM_MULTIPLY
ADD R2, R2, #-1			; subtract 1 from R2 to account for loop
ADD R3, R1, #0			; store R1 into R3 assuming R3 is zero

MULTIPLY_LOOP
 ADD R1, R1, R3			; adds R1 with R3
 BRn FLOW_ERROR			; if it becomes negative then it means it underflowed or overflowed
 ADD R2, R2, #-1		; decrements R2 as our counter
 BRp MULTIPLY_LOOP		; if (R2 > 0) continue to multiply
 BRz STORE_R1			; otherwise if (R2 = 0) go to STORE_R1

; other results
ZERO_RESULT
 LD R1, FIRST_VALUE_3		; reload R1 with initial value
 LD R2, SECOND_VALUE_3		; reload R2 with initial value
 LD R5, ANSWER_IS_ZERO		; load R5 with decimal 0
 BRz END_MULTIPLICATION		; R5 will be zero so END_MULTIPLICATION

FLOW_ERROR
 LD R1, FIRST_VALUE_3		; reload R1 with initial value
 LD R2, SECOND_VALUE_3		; reload R2 with initial value
 LD R5, FLOW_ERROR_SIGNAL	; load R5 with decimal -1 as the underflow or overflow error
 BRn END_MULTIPLICATION		; R5 will be negative so END_MULTIPLICATION

STORE_R1
 ADD R5, R1, #0			; assuming nothing is in R5, put the contents of R1 into it
 LD R1, FIRST_VALUE_3		; reload R1 with initial value
 LD R2, SECOND_VALUE_3		; reload R2 with initial value
 ;it will just auto end

END_MULTIPLICATION
 


; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3800		; restore R0
 LD R3, BACKUP_R3_3800		; restore R3
 LD R4, BACKUP_R4_3800		; restore R4
 ;LD R5, BACKUP_R5_3800		; restore R5
 ;LD R6, BACKUP_R6_3800		; restore R6
 LD R7, BACKUP_R7_3800		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3800 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R3_3800 .BLKW #1
BACKUP_R4_3800 .BLKW #1
;BACKUP_R5_3800 .BLKW #1
;BACKUP_R6_3800 .BLKW #1
BACKUP_R7_3800 .BLKW #1

FIRST_VALUE_3 .FILL #0
SECOND_VALUE_3 .FILL #0
ANSWER_IS_ZERO .FILL #0
FLOW_ERROR_SIGNAL .FILL #-1
;MIN_BOUND .FILL #-32767
;MAX_BOUND .FILL #32767
;----------------------------------------------------------------------------------------------------



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


LD R0, NEWLINE_2		; load R0 with newline
OUT				; output newline

;****************************************************************************************************

LD R1, FIRST_VALUE_4		; load R1 with it's original value
BRzp OUTPUT_PLUS		; if (R1 >=0) go to OUTPUT_PLUS
BRn OUTPUT_MINUS		; if (R1 < 0) go to OUTPUT_MINUS

; Output the sign first
OUTPUT_PLUS
 LD R0, PLUS_SIGN		; load R0 with +
 OUT				; output it
 BRp OUTPUT_R1			; R0 will be positive so go to OUTPUT_R1

OUTPUT_MINUS
 ;since it is negative I need to take the absolute value of it when I print
 NOT R1, R1			; invert R1
 ADD R1, R1, #1			; add 1
 LD R0, MINUS_SIGN		; load R0 with -
 OUT				; output it
 BRp OUTPUT_R1			; R0 will be positive so go to OUTPUT_R1

OUTPUT_R1
 LD R0, COUNTER			; load R0 with counter
 LD R3, NEG_TEN_THOUSAND	; load R3 with neg_ten_thousand
 LD R4, CHAR_MASK		; load R4 with char_mask

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

 LD R3, NEG_THOUSAND		; load R3 with neg_thousand

 R1_PRINT_LOOP_2
  ADD R1, R1, R3		; add R1 with R3
  BRn PRINT_R1_2ND		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R1_PRINT_LOOP_2 		; if (R0 > 0) go to R1_PRINT_LOOP

 PRINT_R1_2ND
  LD R3, POS_THOUSAND
  ADD R1, R1, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_HUNDRED		; load R3 with neg_hundred

 R1_PRINT_LOOP_3
  ADD R1, R1, R3		; add R1 with R3
  BRn PRINT_R1_3RD		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R1_PRINT_LOOP_3 		; if (R0 > 0) go to R1_PRINT_LOOP

 PRINT_R1_3RD
  LD R3, POS_HUNDRED
  ADD R1, R1, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_TEN			; load R3 with neg_ten

 R1_PRINT_LOOP_4
  ADD R1, R1, R3		; add R1 with R3
  BRn PRINT_R1_4TH		; if it becomes negative then go to the print
  ADD R0, R0, #1		; otherwise increment the counter by 1
  BRp R1_PRINT_LOOP_4 		; if (R0 > 0) go to R1_PRINT_LOOP

 PRINT_R1_4TH
  LD R3, POS_TEN
  ADD R1, R1, R3		; add to get it back to original
  ADD R0, R0, R4		; adds the mask to print out the correct character		
  OUT				; print R0
  LD R0, COUNTER		; reset the counter

 LD R3, NEG_ONE			; load R3 with neg_one

 R1_PRINT_LOOP_5
  ADD R1, R1, R3		; add R1 with R3
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

;output miscellaneous things

LD R0, SPACE
OUT
LD R0, STAR
OUT
LD R0, SPACE
OUT


;****************************************************************************************************

LD R2, SECOND_VALUE_4		; load R2 with its original value
BRzp OUTPUT_PLUS_2		; if (R2 >=0) go to OUTPUT_PLUS_2
BRn OUTPUT_MINUS_2		; if (R2 < 0) go to OUTPUT_MINUS_2

; Output the sign first
OUTPUT_PLUS_2
 LD R0, PLUS_SIGN		; load R0 with +
 OUT				; output it
 BRp OUTPUT_R2			; R0 will be positive so go to OUTPUT_R2

OUTPUT_MINUS_2
 ; since it's negative I have to take absolute value
 NOT R2, R2			; invert R2
 ADD R2, R2, #1			; add 1
 LD R0, MINUS_SIGN		; load R0 with a -
 OUT				; output it
 BRp OUTPUT_R2			; R0 will be positive so go to OUTPUT_R2

OUTPUT_R2
 LD R0, COUNTER			; load R0 with counter
 LD R3, NEG_TEN_THOUSAND	; load R3 with neg_ten_thousand
 LD R4, CHAR_MASK		; load R4 with char_mask

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

 LD R3, NEG_THOUSAND		; load R3 with neg_thousand

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

 LD R3, NEG_HUNDRED		; load R3 with neg_hundred

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

 LD R3, NEG_TEN			; load R3 with neg_ten

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

 LD R3, NEG_ONE			; load R3 with neg_one

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

;output miscellaneous things

LD R0, SPACE
OUT
LD R0, EQUALS
OUT
LD R0, SPACE
OUT

; output the sign of the multiplied number
LD R0, SIGN_VALUE
;LD R0, PLUS_SIGN
OUT

;****************************************************************************************************

LD R5, MULTIPLIED_RESULT	; this is the absolute value of the result

;LD R5, POS_TEN

; sign should already be outputted

OUTPUT_R5
 LD R0, COUNTER			; load R0 with counter
 LD R3, NEG_TEN_THOUSAND	; load R3 with neg_ten_thousand
 LD R4, CHAR_MASK		; load R4 with char_mask

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

 LD R3, NEG_THOUSAND		; load R3 with neg_thousand

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

 LD R3, NEG_HUNDRED		; load R3 with neg_hundred

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

 LD R3, NEG_TEN			; load R3 with neg_ten

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

 LD R3, NEG_ONE			; load R3 with neg_one

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

.END		; end of all code
