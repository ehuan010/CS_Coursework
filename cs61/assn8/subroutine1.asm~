;------------
; Main Code
;------------
.ORIG x3000

LD R7, SUB_ALL_MACHINES_BUSY_3400	;load R7 with (SUB_MENU_3200)
JSRR R7					; jump to SUB_MENU_3200

HALT				; halts the program

;--------------------
; Data Block for main
;--------------------
SUB_ALL_MACHINES_BUSY_3400 .FILL x3400


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_ALL_MACHINES_BUSY_3400
; Input: (None)
; Postcondition: The subroutine has returned a value indicating whether all machines are busy
; Return Value (R2): 1 if all machines are busy, 0 otherwise 
;----------------------------------------------------------------------------------------------------

.ORIG x3400

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3400		; backup R0
 ST R1, BACKUP_R1_3400		; backup R1
 ST R3, BACKUP_R3_3400		; backup R3
 ST R4, BACKUP_R4_3400		; backup R4
 ST R5, BACKUP_R5_3400		; backup R5
 ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

LD R1, BUSYVECTOR1		; load R1 with x5200

LDR R3, R1, #0			; R3 <- m[R1] (R3 will hold the BUSYNESS)
LD R4, FIRST_BIT_1		; load R4 with x8000
LD R6, COUNTER1			; load R6 with #16

CHECK_IF_BUSY_LOOP
 AND R5, R3, R4			; R5 <- R3 AND R4 (AND's R1 with R4 to see if it is x8000 or 0)
 BRn SOME_MACHINE_FREE		; if (R5 < 0) then SOME_MACHINE_FREE
 BRz LEFT_SHIFT_STILL_BUSY	; if (R5 = 0) then LEFT_SHIFT_STILL_BUSY

LEFT_SHIFT_STILL_BUSY
 ADD R3, R3, R3			; left shift R3 by adding to itself and then storing it back in R3
 ADD R6, R6, #-1		; decrement the 16 counter
 BRp CHECK_IF_BUSY_LOOP		; if (R6 > 0) go to CHECK_IF_BUSY_LOOP
 BRz ALL_MACHINES_BUSY		; if (R6 = 0) go to ALL_MACHINES_BUSY

SOME_MACHINE_FREE
 LD R2, FREE1			; load R2 with #0 because NOT all machines are busy
 BRz END_ALL_BUSY_CHECK		; END_ALL_BUSY_CHECK

ALL_MACHINES_BUSY
 LD R2, BUSY1			; load R2 with #1 because all machines are busy
 BRp END_ALL_BUSY_CHECK		; END_ALL_BUSY_CHECK

END_ALL_BUSY_CHECK

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3400		; restore R0
 LD R1, BACKUP_R1_3400		; restore R1
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
BACKUP_R1_3400 .BLKW #1
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R5_3400 .BLKW #1
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

COUNTER1 .FILL #16
BUSYVECTOR1 .FILL x5200
FIRST_BIT_1 .FILL x8000
BUSY1 .FILL #1
FREE1 .FILL #0

;----------------------------------------------------------------------------------------------------

.ORIG x5200
BUSYNESS .FILL xF26B

.END
