.model small
.data
num dw 1234h
rev dw ?
.code
        mov ax,@data
        mov ds,ax
        mov ax,num
        mov cx,0004h
        mov bx,10h
        mov si,0000h
myloop :
        div bx
        xchg ax,si
        mov di,dx
        mul bx
        mov dx,di
        add ax,dx
        xchg ax,si
        loop myloop
 
        mov rev,si
        mov ah,4ch
        int 21h
        end
         
