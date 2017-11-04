;Program to compute LCM
.model small
.data
    num1 dw 0006h
    num2 dw 0009h
    lcm dw ?
    gcd dw ?
.code
main proc
    mov ax,@data
    mov ds,ax
    mov ax,num1
    mov bx,num2
myloop:             ;First we compute GCD using Euclid's algorithm.
    mov dx,0000h
    mov cx,bx
    div bx
    mov bx,dx
    mov ax,cx
    cmp bx,0000h
    jne myloop
    mov gcd,ax
    mov cx,ax
    mov ax,num1
    mov bx,num2
    mul bx
    div cx
    mov lcm,ax      ;We find LCM by "LCM = NUM1 * NUM2 / GCD"
    mov ah,4ch
    int 21h
main endp
    end main
