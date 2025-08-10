include 'emu8086.inc'

.model small
.stack 100h

.data

.code
main proc
    mov ax, @data
    mov ds, ax

    print 'Enter a number: ' ; cx = H:65535 - 1111 1111 1111 1111
    call scan_num

    mov ax, cx

    printn ''
    
    print 'Using print_num: ' ; cx = H:32767 - 0111 1111 1111 1111
    call print_num

    printn ''

    print 'Using print_num_uns: ' ; cx = H:65535 - 1111 1111 1111 1111
    call print_num_uns

    mov ah, 4ch
    int 21h
main endp

define_scan_num
define_print_num
define_print_num_uns
define_get_string
define_print_string
end main

