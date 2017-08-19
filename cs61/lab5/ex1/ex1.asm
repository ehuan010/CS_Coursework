;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 05
;-----------------------------------------------------------------------------------

;------------
; Main Code
;------------
.orig x3000
	LD R1, DATA_PTR		; R1 <-- m[DATA_PTR] = x4000
	LD R2, FIRST_VAL	; R2 <-- m[FIRST_VAL] = #2
	LD R6, ITERATOR		; R6 <-- m[ITERATOR] = #10

	FOR_LOOP
 	 STR R2, R1, #0		; m[R1] <- R2 (#2)
 	 ADD R1, R1, #1		; R1 <- R1 + 1 (increment to next address)
 	 ADD R2, R2, R2		; R2 <- R2 + R2 (double R2 aka multiplication)
 	 ADD R6, R6, #-1	; R6 <- R6 - 1 (ITERATOR to loop 10 times)
 	 BRp FOR_LOOP		; if(R6 > 0) go to FOR_LOOP
	END_FOR_LOOP

	LD R1, DATA_PTR
	;LDR R2, R1, #0
	;ST R2, SUB_DATA

	LD R5, SUB_OUTPUT_BINARY_3200
	JSRR R5
	
	LD R6, ITERATOR
	ADD R6, R6, #-1

	FOR_LOOP_3
	 LD R0, NEWLINE
	 OUT
	 ADD R1, R1, #1
	 ;LDR R2, R1, #0
	 ;ST R2, SUB_DATA
	 
	 JSRR R5

	 
	 ADD R6, R6, #-1
	 ;ST R6, ITERATOR
	 
	 BRp FOR_LOOP_3
	END_FOR_LOOP_3
	
	HALT

;--------------------
; Data Block for main
;--------------------
DATA_PTR .FILL x4000
FIRST_VAL .FILL #2
ITERATOR .FILL #10
NEWLINE .FILL xA
SUB_OUTPUT_BINARY_3200 .FILL x3200


; Subroutine: SUB_OUTPUT_BINARY_3200
; Input R2: Some value to print the binary bits of
; Postcondition: Prints (R2) as a 16-bit binary number
; Return Value: No registers with a return value

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
	;LD R2, SUB_DATA		; R1 <- m[NUM] 
	LDR R2, R1, #0
	LD R3, MASK		; R2 <- m[MASK]
	LD R4, ITERATOR_2	; R3 <- m[ITERATOR]
	;LD R5, SUB_DATA		; R4 <- m[NUM]
	LDR R5, R1, #0
	LD R6, MAKE_SPACE	; R5 <- m[MAKE_SPACE]

	LD R0, CHAR_B
	OUT

FOR_LOOP_2
 	AND R2, R2, R3	; R1 <- R1 & R2 (AND's the first bit to get 0 or x8000)
 
 	BRz BIT_IS_0	; if(R1 == 0) output BIT_IS_0 otherwise go to BIT_IS_1

 	BIT_IS_1
  	 LD R0, ONE	; R0 <- m[ONE] = char 1
  	 OUT		; output value stored at R0

 
 	 ADD R5, R5, R5 ; R4 <- R4 + R4 (ADDS NUM to itself to shift bits to left)
 	 ST R5, SUB_DATA; m[NUM] <- R4 (stores left shifted value back into NUM)
	 LD R2, SUB_DATA; R1 <- m[NUM] (stores new value of NUM into R1)
 
	 ADD R6, R6, #-1
 	 BRz OUTPUT_SPACE

 	 ADD R4, R4, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
 	 BRzp FOR_LOOP_2	; if (R3 >= 0) go back to FOR_LOOP

 	BIT_IS_0
  	 LD R0, ZERO	; R0 <- m[ZERO] = char 0
  	 OUT		; output value stored at R0

 	 ADD R5, R5, R5	; R4 <- R4 + R4 (ADDS NUM to itself to shift bits to left)
	 ST R5, SUB_DATA; m[NUM] <- R4 (stores left shifted value back into NUM)
 	 LD R2, SUB_DATA; R1 <- m[NUM] (stores new value of NUM into R1)

 	 ADD R6, R6, #-1
 	 BRz OUTPUT_SPACE

 	 ADD R4, R4, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
 	 BRzp FOR_LOOP_2	; if (R3 >= 0) go back to FOR_LOOP

 	OUTPUT_SPACE
 	 LD R0, SPACE
 	 OUT
  	 LD R6, MAKE_SPACE
 	 ADD R4, R4, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
 	 BRzp FOR_LOOP_2	; if (R3 >= 0) go back to FOR_LOOP

	END_FOR_LOOP_2

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
BACKUP_R0_3200 .BLKW #1 	;one for each register modified (except return val).
BACKUP_R2_3200 .BLKW #1
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R5_3200 .BLKW #1
BACKUP_R6_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1

;EX4 DATA
SUB_DATA .FILL #0	
MASK .FILL x8000
ITERATOR_2 .FILL #15
ZERO .FILL x30
ONE .FILL x31
CHAR_B .FILL x62
SPACE .FILL x20
MAKE_SPACE .FILL #4

.orig x4000
	ARRAY .BLKW #10

.END
