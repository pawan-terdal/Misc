.model small
.data
n1 dw ?
n2 db ?
n3 db ?
.code
mov ax,@data
mov ds,ax
mov ax,25ffh
mov bx,0000h
mov bl,al
mov cx,0000h
mov cl,ah
int 3h
end
