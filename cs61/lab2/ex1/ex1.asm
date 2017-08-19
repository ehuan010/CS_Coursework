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

LD R3, DEC_65
LD R4, HEX_41

HALT

DEC_65 .FILL #65
HEX_41 .FILL x41
.END
