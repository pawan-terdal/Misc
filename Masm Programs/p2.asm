;Program to compute GCD using Euclid's algorithm.
.model small
.data
    num1 dw 0006h
    num2 dw 0009h
    gcd dw ?
.code
main proc
    mov ax,@data
    mov ds,ax
    mov ax,num1
    mov bx,num2
myloop:             ;Computing GCD using GCD(a,b) = GCD(b,a%b) when a%b = 0 => a is GCD.
    mov dx,0000h
    mov cx,bx
    div bx
    mov bx,dx
    mov ax,cx
    cmp bx,0000h
    jne myloop
    mov gcd,ax
    mov ah,4ch
    int 21h
main endp
    end main
