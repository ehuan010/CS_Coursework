;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 08
;-----------------------------------------------------------------------------------

;------------
; Main Code
;------------
.ORIG x3000

LD R7, SUB_PRINT_OPCODES_3200
JSRR R7

HALT

;--------------------
; Data Block for main
;--------------------
SUB_PRINT_OPCODES_3200 .FILL x3200
;START_OF_ARRAY .FILL x4000


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_PRINT_OPCODES_3200
; Parameter : None
; Postcondition: The subroutine has printed out a list of every LC3 instruction and corresponding
;		 opcode in the following format:
;		 ADD = 0001
; Return Value: None
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

LD R1, OPCODE_ARRAY		; load R1 with 1st address of OPCODE_ARRAY
LD R2, STRING_ARRAY		; load R2 with 1st address of STRING_ARRAY

; loop to dereference R2 then OUT the char 1 by 1 until BRz...if BRn then quit the program
PRINT_STRING_LOOP
 LDR R0, R2, #0			; load R0 with value stored at R2
; first check if it is zero or negative 
 BRz FORMAT			; if (R0 = 0) then go to FORMAT
 BRn END_PRINT			; if (R0 = -1) go to END_PRINT
; if it isn't then output and increment counter
 OUT				; output R0 character
 ADD R2, R2, #1			; increment the pointer R2 to the next address
; need anything for the BR statement?
 ADD R0, R0, #0			; (do this to check it's value)
 BRp PRINT_STRING_LOOP		; if (R0 > 0) then continue PRINT_STRING_LOOP


; formats the space = space, and also increments R2 to the next address
FORMAT
 ; do this increment here because PRINT_STRING_LOOP checks value of R0
 ADD R2, R2, #1			; increment the pointer R2 to the next address
 LD R0, SPACE			; load R0 with space character
 OUT				; output the space
 LD R0, EQUALS			; load R0 with equals character
 OUT				; output the =
 LD R0, SPACE			; load R0 with space character
 OUT				; output the space

PRINT_OPCODE_LOOP
 LDR R0, R1, #0			; load R0 with the value stored at R1
 ;LD R5, TEST
 ;ADD R0, R0, R5
 ;OUT				; print out that character stored in R0

;testing this
 LD R6, SUB_PRINT_BINARY_3400 
 JSRR R6

 LD R0, NEWLINE			; load R0 with newline character
 OUT				; output the newline
 ADD R1, R1, #1			; increment the pointer R1 to the next address
 BRp PRINT_STRING_LOOP		; R1 should be positive so go back to PRINT_STRING_LOOP no matter what

; basically exit the program
END_PRINT

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

TEST .FILL #48
EQUALS .FILL #61
SPACE .FILL #32
NEWLINE .FILL #10
SUB_PRINT_BINARY_3400 .FILL x3400
OPCODE_ARRAY .FILL x4000
STRING_ARRAY .FILL x4200

;----------------------------------------------------------------------------------------------------

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_PRINT_BINARY_3400
; Parameter (R0): Decimal value to be printed as binary
; Postcondition: The decimal value stored in R0 will be printed as a 4 digit binary number
; Return Value: None
;----------------------------------------------------------------------------------------------------

.ORIG x3400

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R1, BACKUP_R1_3400		; backup R1
 ST R2, BACKUP_R2_3400		; backup R2
 ST R3, BACKUP_R3_3400		; backup R3
 ST R4, BACKUP_R4_3400		; backup R4
 ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

; left shift all the bits and then AND it with x8000, then print the 1's and 0's for the last 4 digits

LD R1, SHIFT_TWELVE		; load R1 with 12
LD R2, MSB_MASK			; load R2 with x8000

LEFT_SHIFT_LOOP
 ADD R0, R0, R0			; add R0 to itself to do a left shift
 ADD R1, R1, #-1		; decrement the iterator R1
 BRp LEFT_SHIFT_LOOP		; if (R1 > 0) keep doing LEFT_SHIFT_LOOP

LD R1, FOUR_COUNT		; load R1 with 4
ST R0, VAL_R0			; store the new value of R0 into VAL_R0

PRINT_LAST_4_BITS
 LD R0, VAL_R0			; load R0 with the VAL_R0
 AND R0, R0, R2			; AND R0 and R2 to check MSB
 BRz OUTPUT_ZERO		; if (R0 = 0) go to OUTPUT_ZERO
 BRn OUTPUT_ONE			; if (R0 < 0) go to OUTPUT_ONE (if you AND it you will get x8000)

OUTPUT_ZERO
 LD R0, ZERO_CHAR		; load R0 with char 0
 OUT				; output the 0
 LD R0, VAL_R0
 ADD R0, R0, R0
 ST R0, VAL_R0
 ADD R1, R1, #-1		; decrement the counter
 BRp PRINT_LAST_4_BITS		; if (R1 > 0) continue PRINT_LAST_4_BITS
 BRz END_OUTPUTS		; if (R1 = 0) END_OUTPUTS

OUTPUT_ONE
 LD R0, ONE_CHAR		; load R0 with char 1
 OUT				; output the 1
 LD R0, VAL_R0
 ADD R0, R0, R0
 ST R0, VAL_R0
 ADD R1, R1, #-1		; decrement the counter
 BRp PRINT_LAST_4_BITS		; if (R1 > 0) continue PRINT_LAST_4_BITS
 BRz END_OUTPUTS		; if (R1 = 0) END_OUTPUTS

END_OUTPUTS


; (3) Restore all modified registers except Return Values
 LD R1, BACKUP_R1_3400		; restore R1
 LD R2, BACKUP_R2_3400		; restore R2
 LD R3, BACKUP_R3_3400		; restore R3
 LD R4, BACKUP_R4_3400		; restore R4
 LD R6, BACKUP_R6_3400		; restore R6
 LD R7, BACKUP_R7_3400		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R1_3400 .BLKW #1	
BACKUP_R2_3400 .BLKW #1		;one for each register modified (except return val)
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

ZERO_CHAR .FILL #48
ONE_CHAR .FILL #49
FOUR_COUNT .FILL #4
SHIFT_TWELVE .FILL #12
MSB_MASK .FILL x8000
VAL_R0 .FILL #0
;----------------------------------------------------------------------------------------------------


; holds the opcode numbers
.ORIG x4000
OPCODE1 .FILL #1		; add
OPCODE2 .FILL #5		; and
OPCODE3 .FILL #0		; br
OPCODE4 .FILL #12		; jmp/ret
OPCODE5 .FILL #4		; jsr/jsrr
OPCODE6 .FILL #2		; ld
OPCODE7 .FILL #10		; ldi
OPCODE8 .FILL #6		; ldr
OPCODE9 .FILL #14		; lea
OPCODE10 .FILL #9		; not
OPCODE11 .FILL #8		; rti
OPCODE12 .FILL #3		; st
OPCODE13 .FILL #11		; sti
OPCODE14 .FILL #7		; str
OPCODE15 .FILL #15		; trap
OPCODE16 .FILL #13		; reserved

; holds the strings
.ORIG x4200
STRING1 .STRINGZ "ADD"
STRING2 .STRINGZ "AND"
STRING3 .STRINGZ "BR"
STRING4 .STRINGZ "JMP/RET"
STRING5 .STRINGZ "JSR/JSRR"
STRING6 .STRINGZ "LD"
STRING7 .STRINGZ "LDI"
STRING8 .STRINGZ "LDR"
STRING9 .STRINGZ "LEA"
STRING10 .STRINGZ "NOT"
STRING11 .STRINGZ "RTI"
STRING12 .STRINGZ "ST"
STRING13 .STRINGZ "STI"
STRING14 .STRINGZ "STR"
STRING15 .STRINGZ "TRAP"
STRING16 .STRINGZ "RESERVED"
TERMINATE .FILL #-1

.END
