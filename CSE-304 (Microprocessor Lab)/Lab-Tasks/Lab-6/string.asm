include 'emu8086.inc'

.model small
.stack 100h

.data

.code
main proc
    mov ax, @data
    mov ds, ax

    mov dx, 30
    print 'Enter your name: '
    call get_string

    printn ''

    print 'Hello, '
    call print_string

    mov ah, 4ch
    int 21h
main endp

define_scan_num
define_print_num
define_print_num_uns
define_get_string
define_print_string
end main

