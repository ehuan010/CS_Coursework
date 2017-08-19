;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 07
;-----------------------------------------------------------------------------------

;------------
; Main Code
;------------
.ORIG x3000

LD R0, START_OF_ARRAY

LD R7, SUB_GET_STRING_3200
JSRR R7

LD R0, START_OF_ARRAY
PUTS

HALT

;--------------------
; Data Block for main
;--------------------
SUB_GET_STRING_3200 .FILL x3200
START_OF_ARRAY .FILL x4000


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_GET_STRING_3200
; Parameter (R0): The address of where to start storing the string
; Postcondition: The subroutine has allowed the user to input a string,terminated by the [ENTER] key, and has stored it in an array that starts at (R0) and is NULL-terminated.
; Return Value: R5 The number of non-sentinel characters read from the user
;----------------------------------------------------------------------------------------------------


.ORIG x3200

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R1, BACKUP_R1_3200		; backup R1
 ST R2, BACKUP_R2_3200		; backup R2
 ST R3, BACKUP_R3_3200		; backup R3
 ST R4, BACKUP_R4_3200		; backup R4
 ST R6, BACKUP_R6_3200		; backup R6
 ST R7, BACKUP_R7_3200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

ST R0, START_ADDRESS
LD R5, CHAR_COUNTER

LEA R0, STRING_PROMPT
PUTS


STRING_LOOP

 GETC
 OUT
 
 ADD R2, R0, #0			; puts R0 char into R2
 ADD R2, R2, #-10
 BRz END_STRING_LOOP		; if result is 0 end the string loop, otherwise continue
 ADD R2, R2, #10		; add back the ten

 ; this screws it up cause it keeps loading R0 with x4000
 LD R0, START_ADDRESS		; loads R0 with the start_address
 STR R2, R0, #0			; m[R0] <- R2

 ADD R0, R0, #1			; increment to the next address
 ST R0, START_ADDRESS		; so add this to make it store the incremented address
 ADD R5, R5, #1			; increment the counter
 BRp STRING_LOOP

END_STRING_LOOP
 STR R2, R0, #0			; R2 will hold zero, so store zero into address pointed to by R0
 



; (3) Restore all modified registers except Return Values
 LD R1, BACKUP_R1_3200		; restore R1
 LD R2, BACKUP_R2_3200		; restore R2
 LD R3, BACKUP_R3_3200		; restore R3
 LD R4, BACKUP_R4_3200		; restore R4
 LD R6, BACKUP_R6_3200		; restore R6
 LD R7, BACKUP_R7_3200		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R1_3200 .BLKW #1	
BACKUP_R2_3200 .BLKW #1		;one for each register modified (except return val)
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R6_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1

CHAR_COUNTER .FILL #0
ENTER .FILL #10
MINUS_TEN .FILL #-10
START_ADDRESS .FILL #0
STRING_PROMPT .STRINGZ "Enter a string followed by ENTER to finish: "
;----------------------------------------------------------------------------------------------------

.END
