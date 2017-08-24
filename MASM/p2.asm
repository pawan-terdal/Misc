.model small
.data
arr dw 5555h,4444h,1111h,3333h,2222h
len dw ($-arr)
.code
    mov ax,@data
    mov ds,ax
    mov cx,len
    sub cx,02h
    shr cx,01h
outloop:
    mov bx,cx
    mov si,0000h
inloop:
    mov ax,arr[si]
    cmp ax,arr[si+2]
    jb nochange
    xchg ax,arr[si+2]
    mov arr[si],ax
nochange:
    add si,02h
    dec bx
    jnz inloop
    dec cx
    jnz outloop
    int 3h
    mov ah,4ch
    int 21h
    end
