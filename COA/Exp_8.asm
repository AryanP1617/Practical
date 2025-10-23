data segment
    num1 db 13h
    num2 db 12h
data ends

code segment
assume cs:code,ds:data
start:
    mov ax,data
    mov ds,ax

    mov al,num1
    mov bl,num2
    add al,bl

    mov al,num1 
    sub al,bl

    mov al,num1
    mul bl

    mov al,num1
    div bl

    mov al,num1
    or al,bl

    mov al,num1
    and al,bl

    mov al,num1
    xor al,bl

    mov al,num1
    not al

    mov ah,4ch
    int 21h

code ends
end start