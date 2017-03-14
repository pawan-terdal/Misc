.model small
.data
array db 11h,22h,33h,44h,55h,66h,77h
len dw ($-array)
key db 33h
keys db '03h $'
msg1 db "KEY FOUND AT POSITION : $"
msg2 db "KEY NOT FOUND$"
pos db ?
.code
                mov ax,@data
                mov ds,ax
                mov bx,0000h
                mov dx,len
                sub dx,0002h
                mov cl,key
myloop:
                cmp bx,dx
                ja notfound
                mov ax,bx
                add ax,dx
                shr ax,01h
                mov si,ax
                cmp cl,array[si]
                jz  found 
                jb  decupper
                jmp inclower
found:
                lea dx,msg1
                inc ax
                add ax,'0'
                mov pos,al
                lea si,pos
                inc si
                mov bl,'$'
                mov [si],bl
                mov ah,09h
                int 21H
                lea dx,pos
                jmp exit
inclower:
                mov bx,ax
                inc bx
                jmp myloop
decupper:
                cmp ax,0000h
                jz notfound
                mov dx,ax
                dec dx
                jmp myloop
notfound:
                lea dx,keys
                mov ah,09h
                int 21h
                lea dx,msg2
exit:
                mov ah,09h
                int 21h
                mov ah,4ch
                int 21h
                end
          
