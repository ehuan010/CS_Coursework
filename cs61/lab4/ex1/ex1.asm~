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

LD R1, DATA_PTR		; R1 <-- m[DATA_PTR] = x4000
LD R2, FIRST_VAL	; R2 <-- m[FIRST_VAL] = #0
LD R6, ITERATOR		; R6 <-- m[ITERATOR] = #10

FOR_LOOP
 STR R2, R1, #0
 ADD R1, R1, #1
 ADD R2, R2, #1
 ;STR R2, FIRST_VAL
 ADD R6, R6, #-1
 BRp FOR_LOOP
END_FOR_LOOP

ADD R1, R1, #-4
LDR R2, R1, #0

HALT

;DATA
DATA_PTR .FILL x4000
FIRST_VAL .FILL #0
ITERATOR .FILL #10

.orig x4000
ARRAY .BLKW #10

.END
