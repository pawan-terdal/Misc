.model small
.data
arr dw 1234h,2345h,3456h,4567h,5678h,6789h,789Ah
len dw ($-arr)
elem dw 6789h
msg1 db "Elem found at : $"
msg2 db "Elem not found.$" , 10, 13
.code
    mov ax,@data
    mov ds,ax
    mov bx,0000h
    mov dx,len
    sub dx,02h
    mov cx,elem
myloop:
    cmp bx,dx
    ja notfound
    mov ax,bx
    add ax,dx
    shr ax,01h
    mov si,ax
    cmp cx,arr[si]
    jz found
    ja inclower
    jb decupper
    jmp exit
found:
    mov cx,ax
    lea dx,msg1
    mov ah,09h
    int 21h
    mov dl,cl
    shr dl,01h
    inc dl
    add dl,'0'
    mov ah,02h
    int 21h
    jmp exit
notfound:
    lea dx,msg2
    mov ah,09h
    int 21h
    jmp exit
inclower:
    mov bx,ax
    add bx,02h
    jmp myloop
decupper:
    cmp ax,0000h
    jz notfound
    mov dx,ax
    sub dx,02h
    jmp myloop
exit:
    mov ah,4ch
    int 21h
    end
