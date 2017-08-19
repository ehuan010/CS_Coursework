;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 04
;-----------------------------------------------------------------------------------
.orig x3000

LD R1, NUM		; R1 <- m[NUM] 
LD R2, MASK		; R2 <- m[MASK]
LD R3, ITERATOR		; R3 <- m[ITERATOR]
LD R4, NUM		; R4 <- m[NUM]
LD R5, MAKE_SPACE	; R5 <- m[MAKE_SPACE]

LD R0, CHAR_B
OUT

FOR_LOOP
 AND R1, R1, R2		; R1 <- R1 & R2 (AND's the first bit to get 0 or x8000)
 
 BRz BIT_IS_0		; if(R1 == 0) output BIT_IS_0 otherwise go to BIT_IS_1

 BIT_IS_1
  LD R0, ONE		; R0 <- m[ONE] = char 1
  OUT			; output value stored at R0

 
 ADD R4, R4, R4		; R4 <- R4 + R4 (ADDS NUM to itself to shift bits to left)
 ST R4, NUM		; m[NUM] <- R4 (stores left shifted value back into NUM)
 LD R1, NUM		; R1 <- m[NUM] (stores new value of NUM into R1)
 
 ADD R5, R5, #-1
 BRz OUTPUT_SPACE

 ADD R3, R3, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
 BRzp FOR_LOOP		; if (R3 >= 0) go back to FOR_LOOP

 BIT_IS_0
  LD R0, ZERO		; R0 <- m[ZERO] = char 0
  OUT			; output value stored at R0

 ADD R4, R4, R4		; R4 <- R4 + R4 (ADDS NUM to itself to shift bits to left)
 ST R4, NUM		; m[NUM] <- R4 (stores left shifted value back into NUM)
 LD R1, NUM		; R1 <- m[NUM] (stores new value of NUM into R1)

 ADD R5, R5, #-1
 BRz OUTPUT_SPACE

 ADD R3, R3, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
 BRzp FOR_LOOP		; if (R3 >= 0) go back to FOR_LOOP

 OUTPUT_SPACE
  LD R0, SPACE
  OUT
  LD R5, MAKE_SPACE
  ADD R3, R3, #-1	; R3 <- R3 - 1 (subtract 1 from counter)
  BRzp FOR_LOOP		; if (R3 >= 0) go back to FOR_LOOP

END_FOR_LOOP

HALT			; Terminates the program

;DATA
NUM .FILL x00A8		
MASK .FILL x8000
ITERATOR .FILL #15
ZERO .FILL x30
ONE .FILL x31
CHAR_B .FILL x62
SPACE .FILL x20
MAKE_SPACE .FILL #4

.END
