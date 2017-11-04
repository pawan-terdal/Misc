dispc macro char
    push dx
    push ax
    mov dl,char
    add dl,30h
    mov ah,02h
    int 21h
    pop ax
    pop dx
endm
disps macro str
    push dx
    push ax
    lea dx,str
    mov ah,09h
    int 21h
    pop ax
    pop dx
endm
.model small
.data
msg1 db "Time : $"
msg2 db 10, 13, "Date : $"
hi db '-'-30h
.code
    mov ax,@data
    mov ds,ax
    mov ah,2ch ; TIME
    int 21h
    disps msg1 ; Display Time
    mov al,ch ; Hour
    aam
    dispc ah
    dispc al
    dispc hi
    mov al,cl ; Minute
    aam
    dispc ah
    dispc al
    dispc hi
    mov al,dh ; Seconds
    aam
    dispc ah
    dispc al
    mov ah,2ah ; DATE
    int 21h
    disps msg2 ; Display Date
    mov al,dl ; Day
    aam
    dispc ah
    dispc al
    dispc hi
    mov al,dh ; Month
    aam
    dispc ah
    dispc al
    dispc hi
    mov ax,cx ; Year
    sub ax,2000
    aam
    dispc ah
    dispc al
    mov ah,4ch
    int 21h
    end
