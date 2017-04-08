;Program to find number of ones and zeroes
.model small
.data
num db 0AAh
none db 00h
nzero db 00h
.code
    mov ax,@data
    mov ds,ax
    mov al,num
    mov cx,08h
    mov dl,00h ;Number of ones
myloop:
    mov ah,al
    shr al,01h
    and ah,01h
    cmp ah,01h
    jz isone
    loop myloop
isone:
    inc dl
    loop myloop
exit:
    mov none,dl
    mov dh,08h
    sub dh,dl
    mov nzero,dh
    int 3h
    mov ah,4ch
    int 21h
    end
