;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 03
;-----------------------------------------------------------------------------------
.orig x3000

;LD start address into R5 and an incrementer into R6
LD R5, DATA_PTR		; R5 <-- m[DATA_PTR] = x4000
LD R6, INCREMENT	; R6 <-- m[INCREMENT] = x0001


;LDR the value at x4000 into R3, increment to the next adress
;then LDR the value at x4001 into R4
LDR R3, R5, #0		; R3 <-- m[R5] or m[m[DATA_PTR]] or m[x4000] = #65
ADD R5, R5, R6		; R5 <-- R5 + R6 or x4000 + x0001
LDR R4, R5, #0		; R4 <-- m[R5] or m[x4001] = x41

;Now add the values in R3 and R4 by 1
ADD R3, R3, #1		; R3 <-- R3 + 1
ADD R4, R4, #1		; R4 <-- R4 + 1

LD R5, DATA_PTR		; RESET TO THE START

;STR the value of R3 and R4 back into the address x4000 and x4001 respectively
STR R3, R5, #0		; m[R5] <-- R3
ADD R5, R5, R6		; R5 <-- R5 + R6
STR R4, R5, #0		; m[R6] <-- R4

HALT			;

DATA_PTR .FILL x4000
INCREMENT .FILL x0001

.orig x4000
NEW_DEC_65 .FILL #65
NEW_HEX_41 .FILL x41

.END
