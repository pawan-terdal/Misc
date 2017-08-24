disps macro str
    push ax
    push dx
    lea dx,str
    mov ah,09h
    int 21h
    pop dx
    pop ax
endm
.model small
.data
str db "nithin$"
len dw ($-str)
rev db 10 dup('$')
msg1 db "Palin.$"
msg2 db "Not Palin.$"
.code
    mov ax,@data
    mov ds,ax
    mov cx,len
    dec cx
    mov ah,0000h
    lea si,str
myloop1:
    mov al,[si]
    push ax
    inc si
    loop myloop1
    mov cx,len
    dec cx
    lea di,rev
myloop2:
    pop ax
    mov [di],al
    inc di
    loop myloop2
    mov cx,len
    dec cx
    lea si,str
    lea di,rev
    disps rev
myloop:
    mov ax,[si]
    cmp ax,[di]
    jnz notpalin
    inc si
    inc di
    loop myloop
    disps msg1
    jmp exit

notpalin:
    disps msg2
exit:
    mov ah,4ch
    int 21h
    end
