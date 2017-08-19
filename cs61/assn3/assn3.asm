;=================================================
;
; Name: <Huang, Edward>
; Login id: ehuan010 (861026626)
;
; Assignment name: <assn 3>
; Lab section: <024>
; TA: Muzo Akbay
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

.ORIG x3000		;Program begins here
;------------------
; Instructions
;------------------

LD R1, NUM		; R1 <- m[NUM] 
LD R2, MASK		; R2 <- m[MASK]
LD R3, ITERATOR		; R3 <- m[ITERATOR]
LD R4, NUM		; R4 <- m[NUM]


FOR_LOOP
 AND R1, R1, R2		; R1 <- R1 & R2 (AND's the first bit to get 0 or x8000)
 BRz BIT_IS_0		; if(R1 == 0) output BIT_IS_0 otherwise go to BIT_IS_1

 BIT_IS_1
  LD R0, ONE		; R0 <- m[ONE] = char 1
  OUT			; output value stored at R0

 
 ADD R4, R4, R4		; R4 <- R4 + R4 (ADDS NUM to itself to shift bits to left)
 ST R4, NUM		; m[NUM] <- R4 (stores left shifted value back into NUM)
 LD R1, NUM		; R1 <- m[NUM] (stores new value of NUM into R1)
 ADD R3, R3, #-1	; R3 <- R3 - 1 (subtract 1 from counter
 BRzp FOR_LOOP		; if (R3 >= 0) go back to FOR_LOOP

 BIT_IS_0
  LD R0, ZERO		; R0 <- m[ZERO] = char 0
  OUT			; output value stored at R0

 ADD R4, R4, R4		; R4 <- R4 + R4 (ADDS NUM to itself to shift bits to left)
 ST R4, NUM		; m[NUM] <- R4 (stores left shifted value back into NUM)
 LD R1, NUM		; R1 <- m[NUM] (stores new value of NUM into R1)
 ADD R3, R3, #-1	; R3 <- R3 - 1 (subtract 1 from counter
 BRzp FOR_LOOP		; if (R3 >= 0) go back to FOR_LOOP
END_FOR_LOOP

HALT			; Terminates the program

;----------
; Data
;----------
NUM .FILL x00A8		
MASK .FILL x8000
ITERATOR .FILL #15
ZERO .FILL x30
ONE .FILL x31

.END
