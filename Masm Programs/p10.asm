;Program to insert charcter 'c' in miroproessor.
.model small
.data
str db "miroproessor$$$$"
org 20h
len dw ($-str)
chr db 'c'
.code
main proc
    mov ax,@data
    mov ds,ax
    mov bx,03h
    call insert
    mov bx,09h
    call insert
    lea dx,str
    mov ah,09h
    int 21h
    mov ah,4ch
    int 21h
main endp
insert proc
    lea si,str
    mov dl,chr
    mov cx,len
    add si,cx
    inc cx
    mov len,cx
    sub cx,bx
myloop:
    mov di,si
    dec di
    mov ax,[di]
    mov [si],ax
    dec si
    loop myloop
    mov [si],dl
    ret
insert endp
    end main
