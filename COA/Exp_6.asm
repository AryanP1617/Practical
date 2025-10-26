data segment
    msg1 db 0ah,0dh,"- - - - OF DF IF TF SF ZF - AF - PF - CF $"
    flag dw ?
data ends

code segment
    assume cs:code,ds:data
    start:
    mov ax,data
    mov ds,ax

    mov dx,OFFSET msg1
    mov ah,09h
    int 21h

    pushf
    pop ax
    mov flag,ax

    mov cx,16
    mov bx,8000h

    loops:
    mov ax,flag
    and ax,bx
    jz zero

    mov  dx,'1'
    mov ah,02h
    int 21h
    jmp short space

    zero:
    mov dx,'0'
    mov ah,02h
    int 21h

    space:
    ror bx,1
    loop loops

    mov ah,4ch
    int 21h
    
    code ends
    end start