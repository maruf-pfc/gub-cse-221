.model small
.stack 100h
.data
a db 'Enter First Number: $'
b db 'Enter Second Number: $'
c db 'Enter Third Number: $'
msg db ' is the smallest number $'

.code
main proc
    mov ax, @data
    mov ds, ax

    ; ask for first number
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

    ; ask for second number
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

    ; ask for third number
    mov ah, 9
    lea dx, c
    int 21h

    ; get the third number
    mov ah, 1
    int 21h
    mov cl, al

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; compare the numbers
    cmp bl, bh
    jle num1
    jmp num2

    num1:
        cmp bl, cl
        jle n1
        mov ah, 2
        mov dl, cl
        int 21h
        jmp print

    num2:
        cmp bh, cl
        jle n2
        mov ah, 2
        mov dl, cl
        int 21h
        jmp print

    n1:
        mov ah, 2
        mov dl, bl
        int 21h
        jmp print

    n2:
        mov ah, 2
        mov dl, bh
        int 21h
        jmp print

    print:
        mov ah, 9
        lea dx, msg
        int 21h
        jmp exit

    exit:
        mov ah, 4ch
        int 21h
main endp
end main
