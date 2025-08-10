include 'emu8086.inc'

.model small
.stack 100h
.data
    v1 dw 5 dup(10)
    nl db 0dh, 0ah, '$' ; print new line
    msg db 'Hello Class. We are enjoying CSE 304. $'

.code
main proc
    mov ax, @data
    mov ds, ax
    
    printn '======== New task for the class ========='

    mov ah, 09h 
    lea dx, msg
    int 21h

    printn ''

    ; shortcut
    mov si, 11          
    mov msg[si], '$'

    ; brute force approach
    mov si, 11
    mov msg[si], 00
    mov si, 12
    mov msg[si], 00
    mov si, 13
    mov msg[si], 00
    mov si, 14
    mov msg[si], 00
    mov si, 15
    mov msg[si], 00
    mov si, 16
    mov msg[si], 00
    mov si, 17
    mov msg[si], 00
    mov si, 18
    mov msg[si], 00
    mov si, 19
    mov msg[si], 00
    mov si, 20
    mov msg[si], 00
    mov si, 21
    mov msg[si], 00
    mov si, 22
    mov msg[si], 00
    mov si, 23
    mov msg[si], 00
    mov si, 24
    mov msg[si], 00
    mov si, 25
    mov msg[si], 00
    mov si, 26
    mov msg[si], 00
    mov si, 27
    mov msg[si], 00
    mov si, 28
    mov msg[si], 00
    mov si, 29
    mov msg[si], 00
    mov si, 30
    mov msg[si], 00
    mov si, 31
    mov si, 32
    mov msg[si], 00
    mov si, 33
    mov msg[si], 00
    mov si, 34
    mov msg[si], 00

    mov ah, 09h 
    lea dx, msg
    int 21h

    printn ''


    mov ah, 4CH
    int 21h
    main endp
end main
