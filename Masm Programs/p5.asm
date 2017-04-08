;Program to check if Positive or Negative.
.model small
.data
num db 12H
msg1 db "Positive.$"
msg2 db "Negative.$"
.code
    mov ax,@data
    mov ds,ax
    mov al,num
    shl al,01h
    jc isnegative
    lea dx,msg1
    mov ah,09h
    int 21h
    jmp exit
isnegative:
    lea dx,msg2
    mov ah,09h
    int 21h
exit:
    mov ah,4ch
    int 21h
    end
