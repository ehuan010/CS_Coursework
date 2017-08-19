;-----------------------------------------------------------------------------------
; Huang, Edward
; 861-02-6626
; Login: ehuan010
; Section: 24
; TA: Muzo Akbay
; Email: ehuan010@student.ucr.edu
; Lab 02
;-----------------------------------------------------------------------------------
.orig x3000

LD R1, COUNTER

FOR_LOOP 
 IN 
 ADD R0, R0, R1 
 BRp FOR_LOOP 
END_FOR_LOOP
HALT

COUNTER .FILL #-10

.END
