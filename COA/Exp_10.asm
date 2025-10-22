data segment
    msg1 db 0dh,0ah,"Enter a two digit number: $"
    msg2 db 0dh,0ah,"The result is: $"
data ends

code segment
assume cs:code,ds:data
start:

mov ax,data
mov ds,ax

mov dx,OFFSET msg1
mov ah,09h
int 21h

mov ah,01h
int 21h

mov bh,al



mov ah,01h
int 21h

mov bl,al

mov dx,OFFSET msg2
mov ah,09h
int 21h

mov dl,bh
mov ah,02h
int 21h

mov dl,bl
mov ah,02h
int 21h



mov ah,4ch
int 21h

code ends
end start