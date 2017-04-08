;Program to separate odd and even numbers
.model large
.data
arr db 12H, 98H, 45H, 83H, 28H, 67H
len db ($-arr)
nodd db 00h
nevn db 00h
odd db 10 dup(?)
evn db 10 dup(?)
.code
    mov ax,@data
    mov ds,ax
    lea bx,arr
    lea si,odd
    lea di,evn
    mov dl,00h
    mov dh,00h
    mov cl,len
    sub ch,ch
myloop:
    mov al,[bx]
    and al,01h
    cmp al,01h
    je isodd
    mov ah,[bx]
    mov [di],ah
    inc dh
    inc di
    inc bx
    loop myloop
    jmp exit
isodd:
    mov ah,[bx]
    mov [si],ah
    inc dl
    inc si
    inc bx
    loop myloop
exit:
    mov nodd,dl
    mov nevn,dh
    int 3h
    mov ah,4ch
    int 21h
    end
