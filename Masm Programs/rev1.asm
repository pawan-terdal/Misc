.model small
.data
num dw 1234h
rev dw ?
.code
        mov ax,@data
        mov ds,ax
        mov ax,num
        mov bx,0010h
        mov cx,0004h
loop1:
        div bx
        push dx
        loop loop1

        mov cx,0004h
        mov ax,0000h
loop2:
        pop dx
        add ax,dx
        mul bx
        loop loop2
        
        mov rev,ax
        mov ah,4ch
        int 21h
        end  
