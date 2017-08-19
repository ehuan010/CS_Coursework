;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 01
;-----------------------------------------------------------------------------------
.orig x3000
;------------------
; Instructions
;------------------
LD R1, DEC_0            ; R1 <-- #0  (clear the "answer" register)
LD R2, DEC_12           ; R2 <-- #12 (the number to multiply by six)
LD R6, DEC_6            ; R6 <-- #6  (loop counter)

FOR_LOOP_1
   ADD R1, R1, R2	; R1 <--- R1 + R2
   ADD R6, R6, #-1	; R6 <--- R6 - 1 (update loop counter, R6 is now the LMR)
   BRp FOR_LOOP_1	; if (R6 > 0) { jump to FOR_LOOP_1 }
END_FOR_LOOP_1
HALT			; Stop execution of program

;----------
; Data
;----------
DEC_0	.fill #0
DEC_6	.fill #6
DEC_12	.fill #12
.end
