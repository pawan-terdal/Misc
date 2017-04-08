;Program to check odd or even
.model small
.data
num db 27h
msg1 db "Even.$"
msg2 db "Odd.$"
.code
    mov ax,@data
    mov ds,ax
    mov al,num
    and al,01h
    cmp al,01h
    je isodd
    lea dx,msg1
    mov ah,09h
    int 21h
    jmp exit
isodd:
    lea dx,msg2
    mov ah,09h
    int 21h
exit:
    mov ah,4ch
    int 21h
    end
