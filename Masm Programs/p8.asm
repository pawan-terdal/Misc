;Search character in string.
.model small
.data
str db "PESIT SOUTH CAMPUS$"
len dw ($-str)
pos dw 0FFFFh
chr db 'S'
msg1 db "Character found.$"
msg2 db "Character not found.$"
.code
    mov ax,@data
    mov ds,ax
    mov cx,len
    mov ah,chr
    mov si,00h
myloop:
    mov al,str[si]
    cmp ah,al
    jz found
    inc si
    loop myloop
    lea dx,msg2
    mov ah,09h
    int 21h
    jmp exit
found:
    mov pos,si
    lea dx,msg1
    mov ah,09h
    int 21h
exit:
    mov ah,4ch
    int 21h
    end
