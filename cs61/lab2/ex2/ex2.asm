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

LDI R3, DEC_65
LDI R4, HEX_41

ADD R3, R3, #1
ADD R4, R4, #1

STI R3, DEC_65
STI R4, HEX_41

HALT

DEC_65 .FILL x4000
HEX_41 .FILL x4001

.orig x4000
NEW_DEC_65 .FILL #65
NEW_HEX_41 .FILL x41

.END
