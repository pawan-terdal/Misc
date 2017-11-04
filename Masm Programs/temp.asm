.model small
.code
mov ax,0061H
mov cl,02h
sal al,cl
int 3h
mov ah,4ch
int 21h
end
