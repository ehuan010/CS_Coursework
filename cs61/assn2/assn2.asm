;=================================================
;
; Name: <Huang, Edward>
; Login id: ehuan010 (861026626)
;
; Assignment name: <assn 2>
; Lab section: <024>
; TA: Muzo Akbay
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================

.ORIG x3000		;Program begins here
;------------------
; Instructions
;------------------

LD R3, TEMP1		; store hexadecimal -x30 into R3
LD R4, TEMP2		; store hexadecimal x39 into R4

; WORKS FOR POSITIVE RESULTS
IN			; prompt user to enter a character and store it into R0
ADD R1, R0, R3		; R1 <-- R0 + R3 (store converted value into R1)
IN			; prompt user to enter a character and store it into R0
ADD R2, R0, R3		; R2 <-- R0 + R3 (store converted value into R2)
NOT R2, R2		; R2 <-- -R2 (flip the bits)
ADD R2, R2, #1		; R2 <-- R2 + 1 

ADD R0, R1, R2		; R0 <-- R1 + -R2 (perform addition and store result to R0)
;BRn NUM_IS_N
BRzp NUM_IS_ZP

NUM_IS_N
 LD R0, DASH
 OUT
 ADD R0, R1, R2
 NOT R0, R0
 ADD R0, R0, #1
 ADD R0, R0, R4
 OUT
 HALT

NUM_IS_ZP
 ADD R0, R0, R4		; R0 <-- R0 + R4 (convert back to char form)
 OUT
 HALT

 


; Need an if statement to determine if the result is positive or negative?
;ADD R6, R0, #0	
;BRzp IF
;END_IF
;ADD R0, R0, R5
;ADD R0, R4, #0

;OUT			; Displays value stored in R0

;HALT			; Terminates the program

;----------
; Data
;----------
TEMP1 .FILL -x30	; Fill label TEMP3 with -x30 conversion factor
TEMP2 .FILL x30		; Fill label TEMP4 with x30 conversion factor
DASH .FILL #45
.END
