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


LD R5, DEC_65
LD R6, HEX_41
LDR R3, R5, #0
LDR R4, R6, #0

ADD R3, R3, #1
ADD R4, R4, #1

STR R3, R5, #0
STR R4, R6, #0

HALT

DEC_65 .FILL x4000
HEX_41 .FILL x4001

.orig x4000
NEW_DEC_65 .FILL #65
NEW_HEX_41 .FILL x41

.END
