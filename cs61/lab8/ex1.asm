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

LD R0, START_OF_ARRAY

LD R7, SUB_TO_UPPER_3200
JSRR R7

PUTS

HALT

;--------------------
; Data Block for main
;--------------------
SUB_TO_UPPER_3200 .FILL x3200
START_OF_ARRAY .FILL x4000


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_TO_UPPER_3200
; Parameter (R0): Address to store the string at
; Postcondition: The subroutine has allowed the user to input a string,terminated by the [ENTER] key, has
;		 converted the string to upper case, and has stored it in a null-terminated array that
;		 starts at (R0).
; Return Value: R0 <- The address of the now uppercase string 
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

ST R0, ARRAY_START		; store the address to the start of the array
LD R1, ARRAY_START		; R1 will hold the starting address for the array
LD R4, SIZE_COUNTER		; load R4 with 1

LEA R0, STRING_PROMPT		; address of STRING_PROMPT is loaded to R0
PUTS				; output the STRING_PROMPT

; gets user input and stores it into the array
INPUT_LOOP
 GETC				; get user input
 OUT				; output typed in character
 STR R0, R1, #0			; places the value of R0 into the location R1 points to
 ADD R1, R1, #1			; increment the address by 1
 ADD R4, R4, #1			; increments the size counter by 1
 ADD R0, R0, #-10		; subtract 10 for enter key
 BRp INPUT_LOOP			; should be positive always to continue the INPUT_LOOP
 BRz EXIT_INPUT_LOOP		; if enter is entered, go to EXIT_LOOP

EXIT_INPUT_LOOP
 ADD R1, R1, #-1		; go back one address
 ADD R4, R4, #-1		; subtract one from the size counter
 LD R0, NULL			; loads R0 with the null character
 STR R0, R1, #0			; places the value of R0 into the location R1 points to

; now check the letters
LD R1, ARRAY_START		; load R1 with the address of the start of the array
LD R3, UPPERCASE_MASK		; load R3 with -x20


; to check whether or not it is lowercase!!!
LD R5, MIN_BOUND		; load R5 with -x61
LD R6, MAX_BOUND		; load R6 with -x7A

; R3 holds the -x20 mask

TRAVERSE_ARRAY
 LDR R2, R1, #0			; load the value at location R1 into R2
 ADD R2, R2, R6			; R2 - R6 to check MAX_BOUND
 BRp MAKE_UPPERCASE_LOOP	; if (R2 > 0) go to MAKE_UPPERCASE_LOOP
 BRnz DO_NOTHING		; if (R2 <= 0) go to CHECK_MIN

 DO_NOTHING
  ADD R1, R1, #1		; increment R1 to the next address of the array
  ADD R4, R4, #-1		; subtract 1 from the size counter R4
  BRp TRAVERSE_ARRAY		; if (R4 > 0) go to MAKE_UPPERCASE_LOOP
  BRz END_TRAVERSE		; if (R4 = 0) go to END_TRAVERSE

 MAKE_UPPERCASE_LOOP
  LDR R2, R1, #0		; load the value at location R1 into R2
  ADD R2, R2, R3		; subtracts R2 with R3
  STR R2, R1, #0		; stores value R2 at location R1
  ADD R1, R1, #1		; increment R1 to the next address of the array
  ADD R4, R4, #-1		; subtract 1 from the size counter R4
  BRp TRAVERSE_ARRAY		; if (R4 > 0) go to MAKE_UPPERCASE_LOOP
  BRz END_TRAVERSE		; if (R4 = 0) go to END_TRAVERSE

 CHECK_NEXT
 

END_TRAVERSE

LD R0, ARRAY_START

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

MAX_BOUND .FILL -x60
MIN_BOUND .FILL -x41
SIZE_COUNTER .FILL #1
NULL .FILL #0
UPPERCASE_MASK .FILL -x20
SPACE .FILL #-32
ARRAY_START .FILL #0
STRING_PROMPT .STRINGZ "Enter a lowercase string followed by ENTER to finish: "
;----------------------------------------------------------------------------------------------------

.END
