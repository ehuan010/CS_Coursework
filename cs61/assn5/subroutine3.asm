.orig x3000

LD R7, SUB_MULTIPLY_TWO_NUM_3800
JSRR R7

HALT
;--------------------
; Data Block for main
;--------------------
SUB_MULTIPLY_TWO_NUM_3800 .FILL x3800


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

.END
