;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 06
;-----------------------------------------------------------------------------------

;------------
; Main Code
;------------
.ORIG x3000

LD R1, UNSIGNED_VALUE			; R1 <- m[UNSIGNED_VALUE] = user chosen value

LD R6, SUB_RIGHT_SHIFT_3200		; R6 <- m[SUB_RIGHT_SHIFT_3200] = x3200
JSRR R6					; jump to (R6) and perform the subroutine

HALT					; end the program

;--------------------
; Data Block for main
;--------------------
SUB_RIGHT_SHIFT_3200 .FILL x3200
UNSIGNED_VALUE .FILL #-8050


;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_RIGHT_SHIFT_3200
; Input R1: Some value stored in register
; Postcondition: Performs a right-shift on the bits of the value stored in R1
; Return Value: R1 holds the value of the right-shifted value

.ORIG x3200

;----------------------------------------------------------------------------------------------------

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R2, BACKUP_R2_3200		; backup R2
 ST R3, BACKUP_R3_3200		; backup R3
 ST R4, BACKUP_R4_3200		; backup R4
 ST R7, BACKUP_R7_3200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

; put R1 into another register? say R2? cause I needs to check if the bit is 1 or 0
; store the new value into a label?

; first AND the value with 1000 0000 0000 0000. Store the 0 or 1 in a different register. Left shift the bits, doing this only n-bits - 1 times...then append the 0 or 1 to 

; to change MSB to zero just AND it with 0111 1111 1111 1111 (ie 0101 AND 0111 = 0101 YAY) 
; another example (1001 AND 0111 = 0001 YAY. 

;LD R2, MSB_TO_ZERO		; R2 <- m[MSB_TO_ZERO] = #32767 positive bound num
LD R3, FIRST_BIT_CHECKER	; R3 <- m[FIRST_BIT_CHECKER] = x8000 negative bound num
LD R4, FIFTEEN_COUNTER		; R4 <- m[FIFTEEN_COUNTER] = #15

;checks the first bit to see if it is a negative or positive number
FIRST_BIT_CHECK
 ST R1, VALUE_OF_R1		; store value of R1 into VALUE_OF_R1 before messing with it
 AND R1, R1, R3			; check the first bit
 BRz IS_ZERO			; if the first bit is zero go to IS_ZERO

 ;otherwise it is a one and program continues here
 IS_ONE
  LD R1, VALUE_OF_R1		; R1 <- m[VALUE_OF_R1] restore the original value
  LD R2, FIRST_BIT_CHECKER	; R2 <- m[FIRST_BIT_CHECKER] = x8000 used to append 1 to MSB later on
  BRn CHECK_MSB_LOOP		; R2 must be negative so I use this to jump to CHECK_MSB_LOOP

 ;first bit is zero
 IS_ZERO
  LD R1, VALUE_OF_R1		; R1 <- m[VALUE_OF_R1] restore the original value
  LD R2, MSB_TO_ZERO		; R2 <- m[MSB_TO_ZERO] = #32767 used to append 0 to MSB later on
  BRp CHECK_MSB_LOOP		; R2 must be positive so I use this to jump to CHECK_MSB_LOOP 

; ^ (don't need that BRp, but keeping it there so easier to follow) 

;This checks the most significant bit for a 1 or 0
CHECK_MSB_LOOP
 ST R1, VALUE_OF_R1		; stores the current value of R1 into m[VALUE_OF_R1]
 AND R1, R1, R3			; AND's R1 to check if the 1st bit is 1 or 0
 BRz LEFT_SHIFT_APPEND_0	; if (R1 = 0) go to LEFT_SHIFT_APPEND_0 otherwise continue	
 
 ;this will left shift and append a 1
 LEFT_SHIFT_APPEND_1
  LD R1, VALUE_OF_R1		; load current R1 value
  ADD R1, R1, R1		; left shift
  ADD R1, R1, #1		; append's a 1 
  ADD R4, R4, #-1		; decrements the counter R4
  BRp CHECK_MSB_LOOP		; if (R4 > 0) go to CHECK_MSB_LOOP) otherwise next condition is valid
  BRz SKIP			; if (R4 = 0) quit the loop and SKIP the LEFT_SHIFT_APPEND_0 step
 
 ;this will left shift and append a 0
 LEFT_SHIFT_APPEND_0		
  LD R1, VALUE_OF_R1		; load current R1 value
  ADD R1, R1, R1		; left shift
  ADD R1, R1, #0		; is this line unnecessary? auto put a zero at end of left-shift?
  ADD R4, R4, #-1		; decrements the counter R4
  BRp CHECK_MSB_LOOP		; if (R4 > 0) go to CHECK_MSB_LOOP) otherwise go to QUIT


SKIP

ADD R2, R2, #0			; R2 <- R2 + 0 (just assigns R2 to itself so I can use BR)
BRp MAKE_MSB_ZERO		; if (R2 > 0) go to MAKE_MSB_ZERO otherwise continue

;this makes the MSB one
MAKE_MSB_ONE
 ADD R1, R1, R2			; R1 <- R1 + R2(this will set the MSB to 1/make R1 its correct value)
 BRn END_PROG			; R1 will be negative number so go to END_PROG

;this makes the MSB zero
MAKE_MSB_ZERO
 AND R1, R1, R2			; changes MSB to zero by ANDing it with #32767
 BRp END_PROG			; this is here for consistency, but not needed to go to END_PROG

END_PROG

; (3) Restore all modified registers except Return Values
 LD R2, BACKUP_R2_3200		; restore R2
 LD R3, BACKUP_R3_3200		; restore R3
 LD R4, BACKUP_R4_3200		; restore R4
 LD R7, BACKUP_R7_3200		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;------------------------- 	
BACKUP_R2_3200 .BLKW #1		;one for each register modified (except return val)
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1

MSB_TO_ONE .FILL #-1
MSB_TO_ZERO .FILL #32767
VALUE_OF_R1 .FILL #0
FIRST_BIT_CHECKER .FILL x8000
FIFTEEN_COUNTER .FILL #15

;----------------------------------------------------------------------------------------------------

.END
