;Program to compute factorial
.model small
.data
num dw 0005h
fact dw ?
.code
main proc
    mov ax,@data    ;Initialize data segment.
    mov ds,ax
    mov ax,0001h
    mov cx,num
    call factorial
    mov fact,ax
    mov ah,4ch
    int 21h
main endp
factorial proc      ;factorial procedure
    cmp cx,0001h    ;If num = 1 then return.
    je return
    mul cx          ;Multiply num to fact.
    dec cx          ;decrement number.
    call factorial  ;Recursively call procedure again.
return:
    ret
factorial endp
    end main
