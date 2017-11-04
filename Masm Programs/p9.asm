;Count number of occurances.
.model small
.data
str db "exercise$"
len dw ($-str)
chr db 'e'
answer dw 0000h
.code
    mov ax,@data
    mov ds,ax
    lea si,str
    mov cx,len
    mov ah,chr
    mov dx,0000h
myloop:
    mov al,[si]
    inc si
    cmp al,ah
    jz found
    loop myloop
    jmp exit
found:
    inc dx
    loop myloop
exit:
    mov answer,dx
    mov ah,4ch
    int 21h
    end
