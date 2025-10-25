data segment
    string1 db 01h,03h,05h,07h,09h
    string2 db 02h,04h,06h,08h,10h
    string3 db 5 dup(0)
data ends

code segment
    assume cs:code,ds:data
    start:
        mov ax,data
        mov ds,ax
        mov es,ax

        lea si,string1
        lea di,string3

        mov cx,05h
        CLD

        rep MOVSB

        lea si,string2
        lea di,string1

        mov cx,05h
        CLD

        rep MOVSB

        lea si,string3
        lea di,string2

        mov cx,05h
        CLD

        rep MOVSB

        mov ah,4ch
        int 21h
    
    code ends
    end start
