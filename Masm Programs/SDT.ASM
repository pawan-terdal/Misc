CLRSCR MACRO	; macro definition to clear screen
MOV AL, 02H
MOV AH, 00H
INT 10H
ENDM
.MODEL SMALL
.DATA
        msg1 DB 10, 13,'The system time is: $'
        msg2 DB 10, 13,'The system date is: $'

.CODE
MOV AX,@DATA
MOV DS,AX
CLRSCR
LEA DX,msg1
MOV AH,09H
INT 21H
MOV AH,2CH  		; DOS function to read system time
INT 21H

MOV AL, CH         	; Hours in CH register
AAM			 ; unpack the digits
MOV BX, AX
CALL DISP 		; use a procedure to convert to ASCII and display on screen
MOV DL,':' 		; the format is  hh: mm: ss
MOV AH, 02H
INT 21H


MOV AL, CL  		; minutes in CL register
AAM
MOV BX,AX
CALL DISP
MOV DL,':'
MOV AH, 02H
INT 21H

MOV AL, DH 		; seconds in DH register
AAM
MOV BX,AX
CALL DISP
LEA DX,msg2
MOV AH,09H
INT 21H
DAY: MOV AH, 2AH    	; To get System Date
INT 21H
MOV AL, DL     		; Day is in DL
AAM
MOV BX, AX
CALL DISP
MOV DL,'/'
MOV AH, 02H    ; To Print / in DOS
INT 21H
MONTH:
MOV AH,2AH    ; To get System Date
INT 21H
MOV AL, DH     ; Month is in DH
AAM
MOV BX, AX
CALL DISP
MOV DL,'/'    ; To Print / in DOS
MOV AH, 02H
INT 21H
YEAR: MOV AH, 2AH    ; To get System Date
INT 21H
ADD CX, 0F830H; To negate the effects of 16bit value,
MOV AX, CX     ; since AAM is applicable only for AL (YYYY -> YY)
AAM
MOV BX, AX
CALL DISP
MOV AH, 4CH
 INT 21H

DISP  PROC  NEAR		; convert to ASCII and display
 MOV DL, BH
ADD DL, 30h
MOV AH, 02h
INT 21h
MOV DL, BL
ADD DL, 30h
MOV AH, 02h
INT 21h
RET
DISP ENDP

END
