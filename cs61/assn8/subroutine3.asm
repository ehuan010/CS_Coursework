;------------
; Main Code
;------------
.ORIG x3000

LD R7, SUB_NUM_BUSY_MACHINES_3800	;load R7 with (SUB_MENU_3200)
JSRR R7					; jump to SUB_MENU_3200

HALT				; halts the program

;--------------------
; Data Block for main
;--------------------
SUB_NUM_BUSY_MACHINES_3800 .FILL x3800


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_NUM_BUSY_MACHINES_3800
; Input: (None)
; Postcondition: The subroutine has returned the number of busy machines
; Return Value (R2): The number of machines that are busy
;----------------------------------------------------------------------------------------------------

.ORIG x3800

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3800		; backup R0
 ST R1, BACKUP_R1_3800		; backup R1
 ST R3, BACKUP_R3_3800		; backup R3
 ST R4, BACKUP_R4_3800		; backup R4
 ST R5, BACKUP_R5_3800		; backup R5
 ST R6, BACKUP_R6_3800		; backup R6
 ST R7, BACKUP_R7_3800		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

LD R1, BUSYVECTOR3		; load R1 with x5200

LDR R3, R1, #0			; R3 <- m[R1] (R3 will hold the BUSYNESS)
LD R4, FIRST_BIT_3		; load R4 with x8000
LD R6, COUNTER3			; load R6 with #16
LD R2, NUM_BUSY			; load R2 with #0 to count how many busy

CHECK_NUM_BUSY_LOOP
 AND R5, R3, R4			; R5 <- R3 AND R4 (AND's R1 with R4 to see if it is x8000 or 0
 ;BRn NOT_BUSY			; if (R5 < 0) then NOT_BUSY
 BRz IS_BUSY			; if (R5 = 0) then IS_BUSY
 ; if it's not busy, continue
 ADD R3, R3, R3			; left shift R3 by adding to itself and then storing it back in R3
 ADD R6, R6, #-1		; decrement the 16 counter
 BRp CHECK_NUM_BUSY_LOOP	; if (R6 > 0) go to CHECK_NUM_BUSY_LOOP
 BRz END_NUM_BUSY_LOOP		; if (R6 = 0) go to END_NUM_BUSY_LOOP

IS_BUSY
 ADD R3, R3, R3			; left shift R3 by adding to itself and then storing it back in R3
 ADD R2, R2, #1			; increment number of busy by 1
 ADD R6, R6, #-1		; decrement the 16 counter
 BRp CHECK_NUM_BUSY_LOOP	; if (R6 > 0) go to CHECK_NUM_BUSY_LOOP
 BRz END_NUM_BUSY_LOOP		; if (R6 = 0) go to END_NUM_BUSY_LOOP

END_NUM_BUSY_LOOP


; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3800		; restore R0
 LD R1, BACKUP_R1_3800		; restore R1
 LD R3, BACKUP_R3_3800		; restore R3
 LD R4, BACKUP_R4_3800		; restore R4
 LD R5, BACKUP_R5_3800		; restore R5
 LD R6, BACKUP_R6_3800		; restore R6
 LD R7, BACKUP_R7_3800		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3800 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R1_3800 .BLKW #1
BACKUP_R3_3800 .BLKW #1
BACKUP_R4_3800 .BLKW #1
BACKUP_R5_3800 .BLKW #1
BACKUP_R6_3800 .BLKW #1
BACKUP_R7_3800 .BLKW #1

COUNTER3 .FILL #16
BUSYVECTOR3 .FILL x5200
FIRST_BIT_3 .FILL x8000
NUM_BUSY .FILL #0
;----------------------------------------------------------------------------------------------------


.ORIG x5200
BUSYNESS .FILL xF26B

.END
