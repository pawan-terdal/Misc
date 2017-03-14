.model small
.data
array dw 1111h,2222h,3333h,4444h,5555h,6666h,7777h
len dw ($-array)
key dw 4444h
keys db '0333h $'
msg1 db "KEY FOUND AT POSITION : $"
msg2 db "KEY NOT FOUND$"
pos dw ?
.code
                mov ax,@data
                mov ds,ax
                mov bx,0000h
                mov dx,len
                sub dx,0002h
                mov cx,key
myloop:
                cmp bx,dx
                ja notfound
                mov ax,bx
                add ax,dx
                shr ax,01h
                mov si,ax
                cmp cx,array[si]
                jz  found 
                jb  decupper
                jmp inclower
found:
                lea dx,msg1
                shr ax,01h
                inc ax
                mov pos,ax
                mov ah,09h
                int 21H
                mov ax,pos
                mov dl,al
                add dl,'0'
                mov ah,02h
                int 21H
                jmp exit
inclower:
                mov bx,ax
                add bx,0002h
                jmp myloop
decupper:
                cmp ax,0000h
                jz notfound
                mov dx,ax
                sub dx,0002h
                jmp myloop
notfound:
                lea dx,keys
                mov ah,09h
                int 21h
                lea dx,msg2
                mov ah,09h
                int 21h
exit:
                mov ah,4ch
                int 21h
                end
          
