.model small
.stack 100h
.data
a db 'Enter 1st Number: $'
b db 'Enter 2nd Number: $'
msg db ' is the largest number. $'
.code
main proc
    mov ax, @data
    mov ds, ax

    ; show the first message
    mov ah, 9
    lea dx, a
    int 21h

    ; get the first number
    mov ah, 1
    int 21h
    mov bl, al

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; show the second message
    mov ah, 9
    lea dx, b
    int 21h

    ; get the second number
    mov ah, 1
    int 21h
    mov bh, al

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    biggest:
    cmp bl, bh
    jg n1
    jmp n2

    n1:
    ; display the second number
    mov ah, 2
    mov dl, bl
    int 21h
    jmp p

    n2:
    ; display the first number
    mov ah, 2
    mov dl, bh
    int 21h
    jmp p

    p:
    mov ah, 9
    lea dx, msg
    int 21h
    jmp exit

    exit:
    mov ah, 4ch
    int 21h
main endp
end main

