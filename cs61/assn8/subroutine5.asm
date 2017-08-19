;------------
; Main Code
;------------
.ORIG x3000

LD R1, NUM
LD R7, SUB_MACHINE_STATUS_4200		;load R7 with (SUB_MENU_3200)
JSRR R7					; jump to SUB_MENU_3200

HALT				; halts the program

;--------------------
; Data Block for main
;--------------------
SUB_MACHINE_STATUS_4200 .FILL x4200
NUM .FILL #15

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_MACHINE_STATUS_4200
; Input (R1): Which machine to check
; Postcondition: The subroutine has returned a value indicating whether the machine indicated by
;		 (R1) is busy or not.
; Return Value (R2): 0 if machine (R1) is busy, 1 if it is free
;----------------------------------------------------------------------------------------------------

.ORIG x4200

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_4200		; backup R0
 ST R1, BACKUP_R1_4200		; backup R1
 ST R3, BACKUP_R3_4200		; backup R3
 ST R4, BACKUP_R4_4200		; backup R4
 ST R5, BACKUP_R5_4200		; backup R5
 ST R6, BACKUP_R6_4200		; backup R6
 ST R7, BACKUP_R7_4200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

LD R3, FIFTEEN			; load R3 with #15
LD R4, BUSYVECTOR5		; load R4 with x6000
LDR R4, R4, #0			; load R4 with the contents of x6000
LD R5, FIRST_BIT_5		; load R5 with x8000

; R1 holds the (n) or which machine to check
NOT R1, R1			; make R1
ADD R1, R1, #1			; negative

ADD R3, R3, R1			; R3 <- R3 + R1 (this will give me the left shift amount
BRz BUSY_OR_FREE		; if (R3 = 0) go directly to BUSY_OR_FREE

; left-shift and then check the bit
N_SHIFT_LOOP
 ADD R4, R4, R4			; left-shift the bits
 ADD R3, R3, #-1		; decrement the counter
 BRp N_SHIFT_LOOP		; if (R3 > 0) then continue N_SHIFT_LOOP

; now check the 1st bit of value in R4
BUSY_OR_FREE
 AND R4, R4, R5			; R4 <- R4 AND 45 (checks the MSB)
 BRn DETERMINED_FREE		; if (R4 < 0) then DETERMINED_FREE
 BRz DETERMINED_BUSY		; else (R4 = 0) then DETERMINED_BUSY

DETERMINED_FREE
 LD R2, FREE5			; load R2 with #1
 BRp END_BUSY_OR_FREE		; will be p so END_BUSY_OR_FREE

DETERMINED_BUSY
 LD R2, BUSY5			; load R2 with #0
 BRz END_BUSY_OR_FREE		; will be z so END_BUSY_OR_FREE

END_BUSY_OR_FREE


; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_4200		; restore R0
 LD R1, BACKUP_R1_4200		; restore R1
 LD R3, BACKUP_R3_4200		; restore R3
 LD R4, BACKUP_R4_4200		; restore R4
 LD R5, BACKUP_R5_4200		; restore R5
 LD R6, BACKUP_R6_4200		; restore R6
 LD R7, BACKUP_R7_4200		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_4200 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R1_4200 .BLKW #1
BACKUP_R3_4200 .BLKW #1
BACKUP_R4_4200 .BLKW #1
BACKUP_R5_4200 .BLKW #1
BACKUP_R6_4200 .BLKW #1
BACKUP_R7_4200 .BLKW #1

FIFTEEN .FILL #15
BUSYVECTOR5.FILL x6000
FIRST_BIT_5.FILL x8000
BUSY5 .FILL #0
FREE5.FILL #1
;----------------------------------------------------------------------------------------------------

.ORIG x6000
BUSYNESS .FILL x7351

.END
