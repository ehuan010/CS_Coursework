;=================================================
;
; Name: <Huang, Edward>
; Login id: ehuan010 (861026626)
;
; Assignment name: <assn 7>
; Lab section: <024>
; TA: Muzo Akbay
;
; I hereby certify that the contents of this file
; are ENTIRELY my own original work.
;
;=================================================
;------------
; Main Code
;------------
.ORIG x3000

LD R1, BEG_OF_ARRAY		; loads R1 with the address x4000

LD R7, SUB_INPUT_SENTENCE_3200	; loads R7 with the address x3200
JSRR R7				; jumps to subroutine at x3200

LD R1, BEG_OF_ARRAY		; loads R1 with the address x4000

LD R7, SUB_FIND_LONGEST_WORD_3400	; loads R7 with the address x3400
JSRR R7				; jumps to subroutine at x3400

LD R1, BEG_OF_ARRAY		; loads R1 with the address x4000

LD R7, SUB_PRINT_ANALYSIS_3600	; loads R7 with the address x3600
JSRR R7				; jumps to subroutine at x3600

HALT				; halts the program

;--------------------
; Data Block for main
;--------------------
SUB_INPUT_SENTENCE_3200 .FILL x3200
SUB_FIND_LONGEST_WORD_3400 .FILL x3400
SUB_PRINT_ANALYSIS_3600 .FILL x3600
BEG_OF_ARRAY .FILL x4000

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_INPUT_SENTENCE_3200
; Input (R1): The address of where to store the array of words
; Postcondition: The subroutine has collected an ENTER-terminated string of words from the user and
;		 stored them in consecutive memory locations, starting at (R1).
; Return Value: None
;----------------------------------------------------------------------------------------------------

.ORIG x3200

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3200		; backup R0
 ST R2, BACKUP_R2_3200		; backup R2
 ST R3, BACKUP_R3_3200		; backup R3
 ST R4, BACKUP_R4_3200		; backup R4
 ST R5, BACKUP_R5_3200		; backup R5
 ST R6, BACKUP_R6_3200		; backup R6
 ST R7, BACKUP_R7_3200		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

ST R1, ARRAY_START		; store the starting address of the array
LD R2, NULL			; store R2 with #0

LEA R0, PROMPT			; load R0 with the first address of PROMPT
PUTS				; output the PROMPT

SENTENCE_LOOP
 GETC				; gets a character from the user
 OUT				; outputs the character
 STR R0, R1, #0			; store value of R0 into the location pointed to by R1
 ADD R0, R0, #-10		; subtract 10 to check for the ENTER key
 BRz IS_ENTER			; if (R0 = 0) then go to IS_ENTER
 ADD R1, R1, #1			; increment the address of R1
 BRp SENTENCE_LOOP		; else if (R0 > 0) go to SENTENCE_LOOP

IS_ENTER
 STR R2, R1, #0			; since ENTER was input, replace it with a 0
 ADD R1, R1, #1			; increment the address of R1
 GETC				; gets a character from the user
 OUT				; outputs the character
 STR R0, R1, #0			; store the value of R0 into the location pointed to by R1
 ADD R1, R1, #1			; increment the address of R1
 ADD R0, R0, #-10		; subtract 10 to check for the ENTER key
 BRz TERMINATE_ENTER		; if (R0 = 0) then go to TERMINATE_ENTER
 BRp SENTENCE_LOOP		; else if (R0 > 0) go to SENTENCE_LOOP

TERMINATE_ENTER
 ADD R1, R1, #-1		; decrement the address of R1
 STR R2, R1, #0			; since ENTER was input, replace it with a 0

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3200		; restore R0
 LD R2, BACKUP_R2_3200		; restore R2
 LD R3, BACKUP_R3_3200		; restore R3
 LD R4, BACKUP_R4_3200		; restore R4
 LD R5, BACKUP_R5_3200		; restore R5
 LD R6, BACKUP_R6_3200		; restore R6
 LD R7, BACKUP_R7_3200		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3200 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R2_3200 .BLKW #1
BACKUP_R3_3200 .BLKW #1
BACKUP_R4_3200 .BLKW #1
BACKUP_R5_3200 .BLKW #1
BACKUP_R6_3200 .BLKW #1
BACKUP_R7_3200 .BLKW #1

PROMPT .STRINGZ "Input words followed by the ENTER key to type a sentence. Hit ENTER twice in succession when finished: "
ARRAY_START .FILL #0
NULL .FILL #0
;----------------------------------------------------------------------------------------------------

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_FIND_LONGEST_WORD_3400
; Input (R1): The address of the array of words
; Postcondition: The subroutine has located the longest word in the array of words.
; Return Value (R2): The address of the beginning of the longest word
;----------------------------------------------------------------------------------------------------

.ORIG x3400

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3400		; backup R0
 ST R3, BACKUP_R3_3400		; backup R3
 ST R4, BACKUP_R4_3400		; backup R4
 ST R5, BACKUP_R5_3400		; backup R5
 ST R6, BACKUP_R6_3400		; backup R6
 ST R7, BACKUP_R7_3400		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

; R1 holds 1st address, R2 holds the address of longest word, R3 holds the start address of each word
; R4 will hold the largest word count so far... R5 will be letter counter

; compare R4 and R5 then either keep R2 with R2 or load R2 with R3 address.

ST R1, ARRAY_START_2		; store the starting address of the array
LD R5, LETTER_COUNT		; load R5 with #0

ADD R3, R1, #0			; load the address of R1 into R3
ADD R2, R1, #0			; load the address of R1 into R2

SET

COUNT_LENGTH
 LDR R6, R1, #0			; load character at location R1 into R6
 BRz NULL_CHAR			; if (R6 = 0) go to NULL_CHAR
 ADD R5, R5, #1			; increment the counter by 1
 ADD R1, R1, #1			; increment R1 to the next address
 BRp COUNT_LENGTH		; if (R1 > 0) go to COUNT_LENGTH

; reached a 0 in the array
NULL_CHAR
 ADD R1, R1, #1			; increment R1 to the next address

 ; otherwise continue the loop to compare the sizes
 ADD R4, R4, #0			; loads R4 into itself
 BRz SKIP_CHECK			; if (R4 = 0) go to SKIP_CHECK (will only do it the first time?)
 
 ; After intital word is checked, now have to compare with everything else!!!!!!!
 ; flip R5 to compare it to R4
 NOT R5, R5			; get the negative of R5
 ADD R5, R5, #1			; get the negative of R5

 ADD R4, R4, R5			; R4 <- R4 - R5...subtract R4 by R5
 BRzp KEEP_SAME_VALUES		; if (R4 >= 0) go to KEEP_SAME_VALUES...don't change pointer and LSF
 BRn CHANGE_VALUES		; if (R4 < 0) go to CHANGE_VALUES...change pointer and largest so far R4

 ; the pointer and the largest value so far of R4 remains the same
 KEEP_SAME_VALUES
  NOT R5, R5			; turn R5 back to it's positive
  ADD R5, R5, #1		; turn R5 back to it's positive
  ADD R4, R4, R5		; R5 <- R4 + R5...turn R4 back to original value
  ADD R3, R1, #0		; gives R3 the address R1

  LDR R6, R1, #0		; load character at location R1 into R6
  BRz END_OF_SENTENCE		; if (R6 = 0) go to END_OF_SENTENCE


  LD R5, LETTER_COUNT		; load R5 with #0

  


  BRz COUNT_LENGTH		; if (R5 = 0) go to COUNT_LENGTH 
  ;the pointer will hold the same value

 ; the pointer and the largest value so far of R4 is changed
 CHANGE_VALUES
  NOT R5, R5			; turn R5 back to it's positive
  ADD R5, R5, #1		; turn R5 back to it's positive
  ADD R4, R5, #0		; place value of R5 into R4
  ADD R2, R3, #0		; place the value of R3 into R2
  ADD R3, R1, #0		; gives R3 the address R1

  LDR R6, R1, #0		; load character at location R1 into R6
  BRz END_OF_SENTENCE		; if (R6 = 0) go to END_OF_SENTENCE


  LD R5, LETTER_COUNT		; load R5 with #0
  BRz COUNT_LENGTH		; if (R5 = 0) go to COUNT_LENGTH
 ; the pointer holds a new value AND R2 will take the value of R3

 ; need to load R4 with initial value, and reset R5
 SKIP_CHECK
  ADD R4, R5, #0		; load R4 with the value of R5 (1st word)
  ADD R3, R1, #0		; gives R3 the address R1
  LD R5, LETTER_COUNT		; load R5 with #0
  BRz COUNT_LENGTH		; if (R4 > 0) go to COUNT_LENGTH, otherwise just quit???


END_OF_SENTENCE
 

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3400		; restore R0
 LD R3, BACKUP_R3_3400		; restore R3
 LD R4, BACKUP_R4_3400		; restore R4
 LD R5, BACKUP_R5_3400		; restore R5
 LD R6, BACKUP_R6_3400		; restore R6
 LD R7, BACKUP_R7_3400		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3400 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R3_3400 .BLKW #1
BACKUP_R4_3400 .BLKW #1
BACKUP_R5_3400 .BLKW #1
BACKUP_R6_3400 .BLKW #1
BACKUP_R7_3400 .BLKW #1

LETTER_COUNT .FILL #0
ARRAY_START_2 .FILL #0
;----------------------------------------------------------------------------------------------------

;----------------------------------------------------------------------------------------------------
; Subroutine: SUB_PRINT_ANALYSIS_3600
; Input (R1): The address of the beginning of the array of words
; Input (R2): The address of the longest word
; Postcondition: The subroutine has printed out a list of all the words entered as well as the 
;		 longest word in the sentence.
; Return Value : None
;----------------------------------------------------------------------------------------------------

.ORIG x3600

;-------------------------
; Instruction Block
;-------------------------
; (1) Backup all modified registers except Return Values
 ST R0, BACKUP_R0_3600		; backup R0
 ST R3, BACKUP_R3_3600		; backup R3
 ST R4, BACKUP_R4_3600		; backup R4
 ST R5, BACKUP_R5_3600		; backup R5
 ST R6, BACKUP_R6_3600		; backup R6
 ST R7, BACKUP_R7_3600		; backup R7

; (2) Perform whatever algorithm(s) this subroutine is suppose to perform

LEA R0, WORDS_ENTERED_PROMPT	; loads R0 with the start address of WORDS_ENTERED_PROMPT
PUTS				; output WORDS_ENTERED_PROMPT

PRINT_SENTENCE
 LDR R0, R1, #0			; loads R0 with value at location R1
 BRz OUTPUT_SPACE		; if (R0 = 0) output a space
 OUT				; otherwise output the value
 ADD R1, R1, #1			; increment R1 to the next address
 BRp PRINT_SENTENCE		; if (R1 > 0) go to PRINT_SENTENCE

OUTPUT_SPACE
 LD R0, SPACE			; load R0 with a space
 OUT				; output the space
 ADD R1, R1, #1			; increment R1 to the next address
 LDR R0, R1, #0			; loads R0 with value at location R1
 BRz END_PRINT_SENTENCE		; if (R0 = 0) go to END_PRINT_SENTENCE
 BRp PRINT_SENTENCE		; else if (R0 > 0) go to PRINT_SENTENCE

END_PRINT_SENTENCE

LD R0, NEWLINE			; load R0 with the newline character
OUT				; output the newline character
OUT				; output the newline character again

LEA R0, LONGEST_WORD_PROMPT	; load R0 with the start address of LONGEST_WORD_PROMPT
PUTS				; output LONGEST_WORD_PROMPT

OUTPUT_LONGEST_WORD
 ADD R0, R2, #0			; give R0 the address of R2
 PUTS
 ;OUT				; output the character
 ;ADD R2, R2, #1			; increment R2 to the next address
 ;LDR R0, R2, #0			; load R0 with the value at R2
 ;BRp OUTPUT_LONGEST_WORD	; if (R2 > 0) OUTPUT_LONGEST_WORD

; (3) Restore all modified registers except Return Values
 LD R0, BACKUP_R0_3600		; restore R0
 LD R3, BACKUP_R3_3600		; restore R3
 LD R4, BACKUP_R4_3600		; restore R4
 LD R5, BACKUP_R5_3600		; restore R5
 LD R6, BACKUP_R6_3600		; restore R6
 LD R7, BACKUP_R7_3600		; restore R7

; (4) Return to where you came from
RET				; jump to (R7)

;-------------------------
; Data Block
;-------------------------
BACKUP_R0_3600 .BLKW #1 	;one for each register modified (except return val)
BACKUP_R3_3600 .BLKW #1
BACKUP_R4_3600 .BLKW #1
BACKUP_R5_3600 .BLKW #1
BACKUP_R6_3600 .BLKW #1
BACKUP_R7_3600 .BLKW #1

LONGEST_WORD_PROMPT .STRINGZ "The longest word in the sentence is: "
WORDS_ENTERED_PROMPT .STRINGZ "These are the words entered: "
SPACE .FILL #32
NEWLINE .FILL #10
;----------------------------------------------------------------------------------------------------

.END
