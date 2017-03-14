.MODEL SMALL
.STACK 32
.DATA
DATA1 DW 234DH, 0DE6H, 3BC7H, 566AH
ORG 10H
SUM DW  ?
.CODE
START   PROC FAR
        MOV AX, @DATA
        MOV DS, AX
        MOV CX, 0004H
        MOV BX, 0
        MOV DI, OFFSET DATA1
LOOP1:  ADD BX, [DI]
        INC DI
        INC DI
        LOOP LOOP1
        MOV SI, OFFSET SUM
        MOV [SI], BX
        MOV AH, 4CH
        INT 21H
        START ENDP
        END START 
