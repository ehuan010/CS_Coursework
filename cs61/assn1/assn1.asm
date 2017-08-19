;=================================================
;
; Name: <Huang, Edward>
; Login id: ehuan010 (861026626)
;
; Assignment name: <assn 1>
; Lab section: <024>
; TA: Muzo Akbay
;
; I attest that this code was totally given to me
; and that I didn't come up with any of it =P
;=================================================

;-----------------------------------------------------------------------------------
;REG VALUES		R0	R1	R2	R3	R4	R5	R6	R7
;-----------------------------------------------------------------------------------
;Pre-loop		0	32767	0	0	0	0	0	1168
;Iteration 01		0	6	12	0	0	0	0	1168
;Iteration 02		0	5	12	12	0	0	0	1168
;Iteration 03		0	4	12	24	0	0	0	1168
;Iteration 04		0	3	12	36	0	0	0	1168
;Iteration 05		0	2	12	48	0	0	0	1168
;Iteration 06		0	1	12	60	0	0	0	1168
;End of Program		0	0	12	72	0	0	0	DEC_0
;-----------------------------------------------------------------------------------

.ORIG x3000		;Program begins here
;------------------
; Instructions
;------------------
LD R1, DEC_6            ;R1 <-- 6
LD R2, DEC_12           ;R2 <-- 12 
LD R3, DEC_0            ;R3 <-- 0  

DO_WHILE
   ADD R3, R3, R2	; R3 <-- R3 + R2
   ADD R1, R1, #-1	; R1 <-- R1 - 1 (update loop counter, R1 is now the LMR)
   BRp DO_WHILE		; if (LMR > 0) goto DO_WHILE
END_DO_WHILE
HALT			; Stop execution of program

;----------
; Data
;----------
DEC_0	.fill #0
DEC_6	.fill #6
DEC_12	.fill #12

.END
