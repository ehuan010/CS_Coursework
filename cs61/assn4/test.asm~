;=================================================
;
; Name: <Huang, Edward>
; Login id: ehuan010 (861026626)
;
; Assignment name: <assn 4>
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

RESTART
LD R1, ZERO		; don't use R1

LD R3, NEGATIVE_1	;
LD R4, MASK
LD R5, P_N_CHECK	; (checks if number is + or -)
	

; Resets the program when there is an error

LEA R0, PROMPT		; STORES ADDRESS OF THE PROMPT
PUTS			; outputs the PROMPT


;Check first character
GETC			; Get a character from the user and store it into R0
OUT


ADD R0, R0, R5		; + is #43 and - is #45...R5 should now be negative or 0
BRz CHAR_IS_N		; if (R5 = 0) the character must be negative

CHAR_IS_P		; the character must be +
 LD R5, ZERO		; R5 <-- m[ZERO] = #0
 ST R5, VAL_R5
 BRz FOR_LOOP

CHAR_IS_N		; the character must be -
 LD R5, NEGATIVE_1	; R5 <-- m[NEGATIVE_1] = #-1
 ST R5, VAL_R5
 BRn FOR_LOOP



;This FOR_LOOP takes in input from the user
FOR_LOOP
 GETC			; Get a character from the user and store it into R0
 OUT
 ;STR R0, R2, #0	; m[R2] <-- R0

 ST R0, VAL_R0		; first store the value of R0 into a label
 
 LD R6, VALIDATION
 ADD R0, R0, R6
 BRnz CONTINUE

 INVALID
 LD R0, NEWLINE
 OUT
 LEA R0, ERROR_MSG
 PUTS
 LD R0, NEWLINE
 OUT
 ADD R0, R0, #0
 BRnzp RESTART
 
 CONTINUE

 ;if you subtract 10 and the value is zero end the for loop
 LD R0, VAL_R0
 ADD R0, R0, #-10	; R0 <-- R0 - 10
 BRz END_FOR_LOOP

 ;otherwise normally continue the program and load VAL_R0 back into R0
 
 LD R0, VAL_R0
 ADD R0, R0, R4

 LD R2, NINE

 ADD R3, R3, #1		; increments the counter from -1 to 0 (start), etc.
 BRp CONVERTER

 ;put it into R1 for initial
 ADD R1, R1, R0
 BRzp SKIP

 CONVERTER
  ST R1, VAL_R1
  LD R6, VAL_R1

  MULTIPLY_BY_10
   ADD R1, R1, R6
   ADD R2, R2, #-1 ; R5 with 9 only want to add it to itself 9 times
   BRp MULTIPLY_BY_10
   
  ADD R1, R1, R0
 END_CONVERTER

 SKIP
 
 
 REST_OF_PROG
  ;ADD R2, R2, #1		; R1 <-- R1 + 1 (increments to the next address x4001..etc)
  ;ADD R3, R3, #1		; R3 <-- R3 + 1 (adds 1 to the counter to determine size)
  ;ST R3, COUNTER		; m[COUNTER] <-- R3
  LD R0, VAL_R0
  ADD R0, R0, #-10	; R0 <-- R0 - 10
  BRp FOR_LOOP		; if(R0 > 0)
  ;Need another branch for if it exceeds the 6 available slots?
END_FOR_LOOP

LD R5, VAL_R5
BRz IS_P
 
IS_N
 NOT R1, R1
 ADD R1, R1, #1

IS_P
;DO NOTHING

HALT




;----------
; Data
;----------
MASK .FILL #-48
VALIDATION .FILL #-57
ZERO .FILL #0
NEGATIVE_1 .FILL #-1
P_N_CHECK .FILL #-45
NINE .FILL #9
VAL_R0 .FILL #0
VAL_R1 .FILL #0
VAL_R5 .FILL #0
PROMPT .STRINGZ "Input a decimal number (max 5 digits in the range [-32768, +32767]) , preceded with +/‐, followed by ENTER key on keyboard: "
ERROR_MSG .STRINGZ "Not a valid input!!!"
NEWLINE .FILL #10

.END
