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

LD R1, DATA_PTR		; R1 <-- m[DATA_PTR] = x4000
LD R6, ITERATOR		; R6 <-- m[ITERATOR] = #10

FOR_LOOP
 GETC			; Get a character from the user and store it into R0
 STR R0, R1, #0		; m[R1] <-- R0
 ADD R1, R1, #1		; R1 <-- R1 + 1 (increments to the next address x4001..etc)
 ADD R6, R6, #-1	; R6 <-- R6 - 1 (decrements R6)
 BRp FOR_LOOP		; if(R6 > 0)
END_FOR_LOOP

HALT

DATA_PTR .FILL x4000
ITERATOR .FILL #10

.orig x4000
ARRAY .BLKW #10

.END
