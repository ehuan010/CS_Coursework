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

; PUSH 3 times with values 10, 9, 8 OVERFLOW
LD R0, PUSH_VALUE
LD R7, SUB_STACK_PUSH_3200
JSRR R7

LD R0, PUSH_VALUE2
LD R7, SUB_STACK_PUSH_3200
JSRR R7

LD R0, PUSH_VALUE3
LD R7, SUB_STACK_PUSH_3200
JSRR R7


HALT


;--------------------
; Data Block for main
;--------------------
SUB_STACK_PUSH_3200 .FILL x3200
STACK_ADDR .FILL x4000
TOP .FILL x4000
CAPACITY .FILL #2
PUSH_VALUE .FILL #10
PUSH_VALUE2 .FILL #9
PUSH_VALUE3 .FILL #8

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_STACK_PUSH_3200
; Parameter (R0): The value to push onto the stack 
; Parameter (R1): stack_addr: A pointer to the beginning of the stack
; Parameter (R2): top: A pointer to the next place to PUSH an item 
; Parameter (R3): capacity: The # of additional items the stack can hold 
; Postcondition: The subroutine has pushed (R0) onto the stack. If an overflow occured, the
;		 subroutine has printed an overflow error message and terminated.
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

OVERFLOW_MSG .STRINGZ "OVERFLOW!!!"
;----------------------------------------------------------------------------------------------------

.END
