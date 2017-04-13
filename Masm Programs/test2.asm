.model small
.code
        mov ax,0FFFFh
        call delay
        mov ah,4ch
        int 21h
delay proc
        mov cx,0000h
        ret
delay endp
        end
