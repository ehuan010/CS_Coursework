;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 09
;-----------------------------------------------------------------------------------

;------------
; Main Code
;------------
.ORIG x3000

LD R1, STACK_ADDR		; load R1 with x4000
LD R2, TOP			; load R2 with x4000
LD R3, CAPACITY			; load R3 with #2
LD R6, CHAR_TO_DEC		; load R6 with #-48

; STEP 1
LEA R0, INPUT_PROMPT		; loads R0 with the first address of INPUT_PROMPT
PUTS				; output INPUT_PROMPT
GETC				; get a single char input
OUT				; output the char to prevent ghost-typing

ADD R0, R0, R6			; convert R0 char to the dec equivalent

; call push
LD R7, SUB_STACK_PUSH_3400
JSRR R7

; newline
LD R0, NEWLINE
OUT

; STEP 2
LEA R0, INPUT_PROMPT2		; loads R0 with the first address of INPUT_PROMPT2
PUTS				; output INPUT_PROMPT2
GETC				; get a single char input
OUT				; output the char to prevent ghost-typing

ADD R0, R0, R6			; convert R0 char to the dec equivalent

; call push
LD R7, SUB_STACK_PUSH_3400
JSRR R7

; newline
LD R0, NEWLINE
OUT

; STEP 3
LEA R0, OPERATION_PROMPT	; loads R0 with the first address of OPERATION_PROMPT
PUTS				; output OPERATION_PROMPT
GETC				; get a single char input
OUT				; output the char to prevent ghost-typing

; newline
LD R0, NEWLINE
OUT

; just ignore the operation entered

; STEP 4

; call SUB_RPN_MULTIPLY_3200
LD R7, SUB_RPN_MULTIPLY_3200	; load R7 with x3200
JSRR R7				; jump to x3200

; STEP 5

; call pop 
LD R7, SUB_STACK_POP_3600
JSRR R7

; convert R0 to decimal format
LD R7, SUB_PRINT_DECIMAL_4000
JSRR R7

HALT

;--------------------
; Data Block for main
;--------------------
INPUT_PROMPT .STRINGZ "Please enter a single-digit number: "
INPUT_PROMPT2 .STRINGZ "Please enter another single-digit number: "
OPERATION_PROMPT .STRINGZ "Input operation (*): "

SUB_RPN_MULTIPLY_3200 .FILL x3200
SUB_STACK_PUSH_3400 .FILL x3400
SUB_STACK_POP_3600 .FILL x3600
SUB_PRINT_DECIMAL_4000 .FILL x4000

STACK_ADDR .FILL x4200
TOP .FILL x4200
CAPACITY .FILL #2
CHAR_TO_DEC .FILL #-48
NEWLINE .FILL #10

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_RPN_MULTIPLY_3200
; Parameter (R1): stack_addr: A pointer to the beginning of the stack
; Parameter (R2): top: A pointer to the next place to PUSH an item 
; Parameter (R3): capacity: The # of additional items the stack can hold 
; Postcondition: The subroutine has popped off the top two values of the stack, multiplied them 
;		 together and pushed the resulting value back onto the stack.
; Return Value: R2 <- updated top value
;		R3 <- updated capacity value
;----------------------------------------------------------------------------------------------------

.ORIG x3200

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R4, BACKUP_R4_3200		; backup R4
 ST R5, BACKUP_R5_3200		; backup R5
 ST R6, BACKUP_R6_3200		; backup R6
 ST R7, BACKUP_R7_3200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

; call POP
LD R7, SUB_STACK_POP_2_3600
JSRR R7

; store that value in R4
ADD R4, R0, #0

; call POP
LD R7, SUB_STACK_POP_2_3600
JSRR R7

; store that value in R5
ADD R5, R0, #0

; multiply the two values
LD R7, SUB_MULTIPLY_3800
JSRR R7

; push result back onto the stack
LD R7, SUB_STACK_PUSH_2_3400
JSRR R7

; (3) Restore all modified registers except Return Values
 LD R4, BACKUP_R4_3200		; restore R4
 LD R5, BACKUP_R5_3200		; restore R5
 LD R6, BACKUP_R6_3200		; restore R6
 LD R7, BACKUP_R7_3200		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------		
BACKUP_R4_3200 .BLKW #1		;one for each register modified (except return val)
BACKUP_R5_3200 .BLKW #1	
BACKUP_R6_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1

SUB_STACK_PUSH_2_3400 .FILL x3400
SUB_STACK_POP_2_3600 .FILL x3600
SUB_MULTIPLY_3800 .FILL x3800
;----------------------------------------------------------------------------------------------------



;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_PUSH_3400
; Parameter (R0): The value to push onto the stack 
; Parameter (R1): stack_addr: A pointer to the beginning of the stack
; Parameter (R2): top: A pointer to the next place to PUSH an item 
; Parameter (R3): capacity: The # of additional items the stack can hold 
; Postcondition: The subroutine has pushed (R0) onto the stack. If an overflow occured, the
;		 subroutine has printed an overflow error message and terminated.
; Return Value: R2 <- updated top value
;		R3 <- updated capacity value
;----------------------------------------------------------------------------------------------------

.ORIG x3400

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R4, BACKUP_R4_3400		; backup R4
 ST R5, BACKUP_R5_3400		; backup R5
 ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

; R0 value to push onto stack, R1 stack_addr, R2 top, R3 capacity

; Verify capacity > 0 (else print overflow error)
ADD R3, R3, #0			; invoke NZP conditions
;BRz OVERFLOW_ERROR		; if (R3 = 0) capacity = 0 so print OVERFLOW_ERROR
BRp PUSH_ON_STACK		; if (R3 > 0) capacity > 0 so PUSH_ON_STACK

OVERFLOW_ERROR
 LEA R0, OVERFLOW_MSG		; loads the first address of OVERFLOW_MSG
 PUTS				; print out OVERFLOW_MSG
 HALT

; otherwise PUSH_ON_STACK
PUSH_ON_STACK
 STR R0, R2, #0			; m[R2] <- R0 (top of stack gets the value in R0) 

 ; top = top + 1
 ADD R2, R2, #1			; R2 <- R2 + 1 increment the top 

 ; capacity = capacity - 1
 ADD R3, R3, #-1			; R3 <- R3 - 1 decrement the capacity 


; (3) Restore all modified registers except Return Values
 LD R4, BACKUP_R4_3400		; restore R4
 LD R5, BACKUP_R5_3400		; restore R5
 LD R6, BACKUP_R6_3400		; restore R6
 LD R7, BACKUP_R7_3400		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------		
BACKUP_R4_3400 .BLKW #1		;one for each register modified (except return val)
BACKUP_R5_3400 .BLKW #1	
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

OVERFLOW_MSG .STRINGZ "OVERFLOW!!!"
;----------------------------------------------------------------------------------------------------


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_POP_3600
; Parameter (R1): stack_addr: A pointer to the beginning of the stack
; Parameter (R2): top: A pointer to the item to POP
; Parameter (R3): capacity: The # of additional items the stack can hold 
; Postcondition: The subroutine has popped MEM[top] off of the stack. If an underflow occured, the
;		 subroutine has printed an underflow error message and terminated.
; Return Value: R0 <- value popped off of the stack
;		R2 <- updated top value
;		R3 <- updated capacity value
;----------------------------------------------------------------------------------------------------

.ORIG x3600

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R4, BACKUP_R4_3600		; backup R4
 ST R5, BACKUP_R5_3600		; backup R5
 ST R6, BACKUP_R6_3600		; backup R6
 ST R7, BACKUP_R7_3600		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

; R1 stack_addr, R2 top, R3 capacity

; Verify top != stack_addr (else print underflow error)
NOT R1, R1			; Turn R1 into its inverse
ADD R1, R1, #1			; value

ADD R4, R2, R1			; R4 <- R2 - R1 verifies top != stack_addr
;BRz UNDERFLOW_ERROR		; if (R4 = 0) then top == stack_addr so go to UNDERFLOW_ERROR
BRp POP_OFF_STACK		; if (R4 > 0) top != stack so POP_OFF_STACK

UNDERFLOW_ERROR
 LEA R0, UNDERFLOW_MSG		; loads the first address of UNDERFLOW_MSG
 PUTS				; print out UNDERFLOW_MSG


; otherwise POP_OFF_STACK
POP_OFF_STACK
 NOT R1, R1			; Turn R1 back to original
 ADD R1, R1, #1			; value

 ; I need to initially decrement one time first??????????????????

 ; top = top - 1
 ADD R2, R2, #-1		; R2 <- R2 - 1 decrement the top 

 LDR R0, R2, #0			; R0 <- m[R2] (R0 gets the value on the top of stack)

 ; capacity = capacity + 1
 ADD R3, R3, #1			; R3 <- R3 + 1 increment the capacity


; (3) Restore all modified registers except Return Values
 LD R4, BACKUP_R4_3600		; restore R4
 LD R5, BACKUP_R5_3600		; restore R5
 LD R6, BACKUP_R6_3600		; restore R6
 LD R7, BACKUP_R7_3600		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)
;-------------------------
; Data Block
;-------------------------		
BACKUP_R4_3600 .BLKW #1		;one for each register modified (except return val)
BACKUP_R5_3600 .BLKW #1	
BACKUP_R6_3600 .BLKW #1
BACKUP_R7_3600 .BLKW #1

UNDERFLOW_MSG .STRINGZ "UNDERFLOW!!!"
;----------------------------------------------------------------------------------------------------


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_MULTIPLY_3800
; Parameter (R4): A number to be multiplied
; Parameter (R5): A number to be multiplied 
; Postcondition: The subroutine has multiplied the two numbers together
; Return Value: R0 <- multiplied result
;----------------------------------------------------------------------------------------------------

.ORIG x3800

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ;ST R0, BACKUP_R0_3800		; backup R0
 ;ST R3, BACKUP_R3_3800		; backup R3
 ;ST R4, BACKUP_R4_3800		; backup R4
 ;ST R5, BACKUP_R5_3800		; backup R5
 ST R6, BACKUP_R6_3800		; backup R6
 ST R7, BACKUP_R7_3800		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

ST R4, FIRST_VALUE_3		; store original value of R1
ST R5, SECOND_VALUE_3		; store original value of R2

LD R6, ANSWER_IS_ZERO 		; load R6 with zero

; checks if first value is negative
LD R4, FIRST_VALUE_3		; loads R1 with initial value to check it
BRn ABSOLUTE_VALUE_3		; if it's negative take the absolute value
BRz ZERO_RESULT			; if the first value is zero the answer is zero
;already solved for zero without this, but put it for easier readability
;BRzp PERFORM_MULTIPLY

CHECK_SECOND_VALUE_2
LD R5, SECOND_VALUE_3		; loads R2 with initial value to check it
BRz ZERO_RESULT			; if the second value is zero the answer is zero
BRn ABSOLUTE_VALUE_4		; if the second value is negative take the absolute value
BRp PERFORM_MULTIPLY		; if the second value is positive multiply it with the first

ABSOLUTE_VALUE_3
 NOT R4, R4			; invert R1
 ADD R4, R4, #1			; add 1 
 BRp CHECK_SECOND_VALUE_2	; R1 will be positive so go to CHECK_SECOND_VALUE_2

ABSOLUTE_VALUE_4
 NOT R5, R5			; invert R2
 ADD R5, R5, #1			; add 1
 BRp PERFORM_MULTIPLY		; R2 will be positive so go to PERFORM_MULTIPLY



PERFORM_MULTIPLY
ADD R5, R5, #-1			; subtract 1 from R2 to account for loop
ADD R6, R4, #0			; store R1 into R3 assuming R3 is zero

MULTIPLY_LOOP
 ADD R4, R4, R6			; adds R1 with R3
 BRn FLOW_ERROR			; if it becomes negative then it means it underflowed or overflowed
 ADD R5, R5, #-1		; decrements R2 as our counter
 BRp MULTIPLY_LOOP		; if (R2 > 0) continue to multiply
 BRz STORE_R1			; otherwise if (R2 = 0) go to STORE_R1

; other results
ZERO_RESULT
 LD R4, FIRST_VALUE_3		; reload R1 with initial value
 LD R5, SECOND_VALUE_3		; reload R2 with initial value
 LD R0, ANSWER_IS_ZERO		; load R5 with decimal 0
 BRz END_MULTIPLICATION		; R5 will be zero so END_MULTIPLICATION

FLOW_ERROR
 LD R4, FIRST_VALUE_3		; reload R1 with initial value
 LD R5, SECOND_VALUE_3		; reload R2 with initial value
 LD R0, FLOW_ERROR_SIGNAL	; load R5 with decimal -1 as the underflow or overflow error
 BRn END_MULTIPLICATION		; R5 will be negative so END_MULTIPLICATION

STORE_R1
 ADD R0, R4, #0			; assuming nothing is in R5, put the contents of R1 into it
 LD R4, FIRST_VALUE_3		; reload R1 with initial value
 LD R5, SECOND_VALUE_3		; reload R2 with initial value
 ;it will just auto end

END_MULTIPLICATION
 


; (3) Restore all modified registers except Return Values
 ;LD R3, BACKUP_R3_3800		; restore R3
 ;LD R4, BACKUP_R4_3800		; restore R4
 ;LD R5, BACKUP_R5_3800		; restore R5
 LD R6, BACKUP_R6_3800		; restore R6
 LD R7, BACKUP_R7_3800		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------	
;BACKUP_R3_3800 .BLKW #1		;one for each register modified (except return val)
;BACKUP_R4_3800 .BLKW #1
;BACKUP_R5_3800 .BLKW #1
BACKUP_R6_3800 .BLKW #1
BACKUP_R7_3800 .BLKW #1

FIRST_VALUE_3 .FILL #0
SECOND_VALUE_3 .FILL #0
ANSWER_IS_ZERO .FILL #0
FLOW_ERROR_SIGNAL .FILL #-1
;MIN_BOUND .FILL #-32767
;MAX_BOUND .FILL #32767
;----------------------------------------------------------------------------------------------------




; Subroutine: SUB_PRINT_DECIMAL_4000
; Parameter (R0): Some value stored in R0 to print as decimal
; Postcondition: Print out the number stored in R0 as it's character equivalent
; Return Value: (none)

.ORIG x4000

;----------------------------------------------------------------------------------------------------
;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R1, BACKUP_R1_4000		; backup R1
 ST R2, BACKUP_R2_4000		; backup R2
 ST R3, BACKUP_R3_4000		; backup R3
 ST R4, BACKUP_R4_4000		; backup R4
 ST R5, BACKUP_R5_4000		; backup R5
 ST R6, BACKUP_R6_4000		; backup R6
 ST R7, BACKUP_R7_4000		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

ADD R1, R0, #0			; store the value of R0 into R1

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
 LD R1, BACKUP_R1_4000		; restore R1
 LD R2, BACKUP_R2_4000		; restore R2
 LD R3, BACKUP_R3_4000		; restore R3
 LD R4, BACKUP_R4_4000		; restore R4
 LD R5, BACKUP_R5_4000		; restore R5
 LD R6, BACKUP_R6_4000		; restore R6
 LD R7, BACKUP_R7_4000		; restore R7
; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R1_4000 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R2_4000 .BLKW #1
BACKUP_R3_4000 .BLKW #1
BACKUP_R4_4000 .BLKW #1
BACKUP_R5_4000 .BLKW #1
BACKUP_R6_4000 .BLKW #1
BACKUP_R7_4000 .BLKW #1

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
