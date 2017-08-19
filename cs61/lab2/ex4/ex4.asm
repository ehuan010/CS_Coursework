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

LD R0, HEX_61
LD R1, HEX_1A		;loop counter

FOR_LOOP
 OUT
 ADD R0, R0, #1
 ADD R1, R1, #-1
 BRp FOR_LOOP
HALT

HEX_61 .FILL x61
HEX_1A .FILL x1A
.END
