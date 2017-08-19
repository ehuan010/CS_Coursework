.orig x3000

LD R6, SUB_FIND_LARGER_3400
JSRR R6

HALT
;--------------------
; Data Block for main
;--------------------
SUB_FIND_LARGER_3400 .FILL x3400


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
LD R1, TEST			; R1 <- m[FIRST_VALUE] (restore it for use)
BRn ABSOLUTE_VALUE_1		; if (R1 < 0) take the absolute value of it

; Check R2
CHECK_SECOND_VALUE		
 ST R2, SECOND_VALUE		; m[SECOND_VALUE] <- R2 (hold the original R2 value)
 LD R2, TEST2			; R2 <- m[SECOND_VALUE] (restore it for use)
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

.END
