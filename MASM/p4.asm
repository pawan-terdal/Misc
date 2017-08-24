.model small
.data
n dw 0006h
r dw 0003h
ncr dw ?
msg1 db "Fail.$"
msg2 db "Calculated check using d ds.$"
.code
main proc
    mov ax,@data
    mov ds,ax
    mov ax,n
    mov dx,r
    cmp ax,0000h
    jz fail
    cmp dx,ax
    ja fail
    mov cx,0000h
    call compute
    mov ncr,cx
    jmp exit
fail:
    lea dx,msg1
    mov ah,09h
    int 21h
exit:
    int 3h
    mov ah,4ch
    int 21h
main endp
compute proc
    cmp dx,0000h
    jz incbyone
    cmp dx,ax
    jz incbyone
    cmp dx,0001h
    jz incbyn
    mov si,ax
    dec si
    cmp dx,si
    jz incbyn
    dec ax
    push ax
    push dx
    call compute
    pop dx
    pop ax
    dec dx
    call compute
    ret
incbyn:
    add cx,ax
    ret
incbyone:
    add cx,01h
    ret
compute endp
    end main
