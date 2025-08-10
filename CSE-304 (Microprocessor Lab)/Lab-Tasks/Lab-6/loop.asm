include 'emu8086.inc'

.model small
.stack 100h

.data

.code
main proc
    mov ax, @data
    mov ds, ax

    ; loop works like do while loop
    mov cx, 10
    level1:
        mov ax, cx
        call print_num
        printn ' - Hello World!'

    loop level1

    mov ah, 4ch
    int 21h
main endp

define_scan_num
define_print_num
define_print_num_uns
define_get_string
define_print_string
end main

