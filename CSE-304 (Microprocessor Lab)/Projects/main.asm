; ICPC Balloons
; https://codeforces.com/contest/1703/problem/B
include 'emu8086.inc'

.model small
.stack 100h

.data
    msg db "ABCDEFGHIJKLMNOPQRSTUVWXYZ $" ; 26 letters
    msg1 db "Enter the length of the string: $"
    msg2 db "Enter the string: $"
    sz db ?
    res db ?
    a db 0
    b db 0
    c db 0
    d db 0
    e db 0
    f db 0
    g db 0
    h db 0

.code
main proc
    ; data segment initialization
    mov ax, @data
    mov ds, ax

    ; print msg1
    mov ah, 9
    lea dx, msg1
    int 21h

    ; read sz and store it in sz
    mov ah, 1
    int 21h
    mov sz, al

    printn ''

    ; print msg2
    mov ah, 9
    lea dx, msg2
    int 21h

    cmp sz, '1'
    je one
    cmp sz, '2'
    je two
    cmp sz, '3'
    je three
    cmp sz, '4'
    je four
    cmp sz, '5'
    je five
    cmp sz, '6'
    je six
    cmp sz, '7'
    je seven
    cmp sz, '8'
    je eight

    one:
        ; read first letter and check if it is 'A' and if it is, set a to 1
        mov ah, 1
        int 21h
        cmp al, 'A'
        jne not_n1a
        mov a, 1
        jmp p_freq

        not_n1a:
            cmp al, 'B'
            jne not_n1b
            mov b, 1
            jmp p_freq

        not_n1b:
            cmp al, 'C'
            jne not_n1c
            mov c, 1
            jmp p_freq

        not_n1c:
            cmp al, 'D'
            jne not_n1d
            mov d, 1
            jmp p_freq

        not_n1d:
            cmp al, 'E'
            jne not_n1e
            mov e, 1
            jmp p_freq

        not_n1e:
            cmp al, 'F'
            jne not_n1f
            mov f, 1
            jmp p_freq

        not_n1f:
            cmp al, 'G'
            jne not_n1g
            mov g, 1
            jmp p_freq

        not_n1g:
            cmp al, 'H'
            mov h, 1
            jmp p_freq
    jmp p_freq
    
    two:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        jne not_n21a
        mov a, 1
        jmp s2Letter

        not_n21a:
            cmp al, 'B'
            jne not_n21b
            mov b, 1
            jmp s2Letter

        not_n21b:
            cmp al, 'C'
            jne not_n21c
            mov c, 1
            jmp s2Letter

        not_n21c:
            cmp al, 'D'
            jne not_n21d
            mov d, 1
            jmp s2Letter

        not_n21d:
            cmp al, 'E'
            jne not_n21e
            mov e, 1
            jmp s2Letter

        not_n21e:
            cmp al, 'F'
            jne not_n21f
            mov f, 1
            jmp s2Letter

        not_n21f:
            cmp al, 'G'
            jne not_n21g
            mov g, 1
            jmp s2Letter

        not_n21g:
            cmp al, 'H'
            mov h, 1
            jmp s2Letter

            s2Letter:
                mov ah, 1
                int 21h
                cmp al, 'A'
                jne not_n22a
                mov a, 2
                jmp p_freq

                not_n22a:
                    cmp al, 'B'
                    jne not_n22b
                    mov b, 2
                    jmp p_freq

                not_n22b:
                    cmp al, 'C'
                    jne not_n22c
                    mov c, 2
                    jmp p_freq

                not_n22c:
                    cmp al, 'D'
                    jne not_n22d
                    mov d, 2
                    jmp p_freq

                not_n22d:
                    cmp al, 'E'
                    jne not_n22e
                    mov e, 2
                    jmp p_freq

                not_n22e:
                    cmp al, 'F'
                    jne not_n22f
                    mov f, 2
                    jmp p_freq

                not_n22f:
                    cmp al, 'G'
                    jne not_n22g
                    mov g, 2
                    jmp p_freq

                not_n22g:
                    cmp al, 'H'
                    mov h, 2
                    jmp p_freq
    jmp p_freq

    three:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        jne not_n31a
        mov a, 1
        jmp s3Letter

        not_n31a:
            cmp al, 'B'
            jne not_n31b
            mov b, 1
            jmp s3Letter

        not_n31b:
            cmp al, 'C'
            jne not_n31c
            mov c, 1
            jmp s3Letter

        not_n31c:
            cmp al, 'D'
            jne not_n31d
            mov d, 1
            jmp s3Letter

        not_n31d:
            cmp al, 'E'
            jne not_n31e
            mov e, 1
            jmp s3Letter

        not_n31e:
            cmp al, 'F'
            jne not_n31f
            mov f, 1
            jmp s3Letter

        not_n31f:
            cmp al, 'G'
            jne not_n31g
            mov g, 1
            jmp s3Letter

        not_n31g:
            cmp al, 'H'
            mov h, 1
            jmp s3Letter

            s3Letter:
                mov ah, 1
                int 21h
                cmp al, 'A'
                jne not_n32a
                mov a, 2
                jmp t3Letter

                not_n32a:
                    cmp al, 'B'
                    jne not_n32b
                    mov b, 2
                    jmp t3Letter

                not_n32b:
                    cmp al, 'C'
                    jne not_n32c
                    mov c, 2
                    jmp t3Letter

                not_n32c:
                    cmp al, 'D'
                    jne not_n32d
                    mov d, 2
                    jmp t3Letter

                not_n32d:
                    cmp al, 'E'
                    jne not_n32e
                    mov e, 2
                    jmp t3Letter

                not_n32e:
                    cmp al, 'F'
                    jne not_n32f
                    mov f, 2
                    jmp t3Letter

                not_n32f:
                    cmp al, 'G'
                    jne not_n32g
                    mov g, 2
                    jmp t3Letter

                not_n32g:
                    cmp al, 'H'
                    mov h, 2
                    jmp t3Letter

                    t3Letter:
                        mov ah, 1
                        int 21h
                        cmp al, 'A'
                        jne not_n33a
                        mov a, 3
                        jmp p_freq

                        not_n33a:
                            cmp al, 'B'
                            jne not_n33b
                            mov b, 3
                            jmp p_freq

                        not_n33b:
                            cmp al, 'C'
                            jne not_n33c
                            mov c, 3
                            jmp p_freq

                        not_n33c:
                            cmp al, 'D'
                            jne not_n33d
                            mov d, 3
                            jmp p_freq

                        not_n33d:
                            cmp al, 'E'
                            jne not_n33e
                            mov e, 3
                            jmp p_freq

                        not_n33e:
                            cmp al, 'F'
                            jne not_n33f
                            mov f, 3
                            jmp p_freq

                        not_n33f:
                            cmp al, 'G'
                            jne not_n33g
                            mov g, 3
                            jmp p_freq

                        not_n33g:
                            cmp al, 'H'
                            mov h, 3
                            jmp p_freq
    jmp p_freq

    four:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        jne not_n41a
        mov a, 1
        jmp s4Letter

        not_n41a:
            cmp al, 'B'
            jne not_n41b
            mov b, 1
            jmp s4Letter

        not_n41b:
            cmp al, 'C'
            jne not_n41c
            mov c, 1
            jmp s4Letter

        not_n41c:
            cmp al, 'D'
            jne not_n41d
            mov d, 1
            jmp s4Letter

        not_n41d:
            cmp al, 'E'
            jne not_n41e
            mov e, 1
            jmp s4Letter

        not_n41e:
            cmp al, 'F'
            jne not_n41f
            mov f, 1
            jmp s4Letter

        not_n41f:
            cmp al, 'G'
            jne not_n41g
            mov g, 1
            jmp s4Letter

        not_n41g:
            cmp al, 'H'
            mov h, 1
            jmp s4Letter

        s4Letter:
            mov ah, 1
            int 21h
            cmp al, 'A'
            jne not_n42a
            mov a, 2
            jmp t4Letter

            not_n42a:
                cmp al, 'B'
                jne not_n42b
                mov b, 2
                jmp t4Letter

            not_n42b:
                cmp al, 'C'
                jne not_n42c
                mov c, 2
                jmp t4Letter

            not_n42c:
                cmp al, 'D'
                jne not_n42d
                mov d, 2
                jmp t4Letter

            not_n42d:
                cmp al, 'E'
                jne not_n42e
                mov e, 2
                jmp t4Letter

            not_n42e:
                cmp al, 'F'
                jne not_n42f
                mov f, 2
                jmp t4Letter

            not_n42f:
                cmp al, 'G'
                jne not_n42g
                mov g, 2
                jmp t4Letter

            not_n42g:
                cmp al, 'H'
                mov h, 2
                jmp t4Letter

                t4Letter:
                    mov ah, 1
                    int 21h
                    cmp al, 'A'
                    jne not_n43a
                    mov a, 3
                    jmp f4Letter

                    not_n43a:
                        cmp al, 'B'
                        jne not_n43b
                        mov b, 3
                        jmp f4Letter

                    not_n43b:
                        cmp al, 'C'
                        jne not_n43c
                        mov c, 3
                        jmp f4Letter

                    not_n43c:
                        cmp al, 'D'
                        jne not_n43d
                        mov d, 3
                        jmp f4Letter

                    not_n43d:
                        cmp al, 'E'
                        jne not_n43e
                        mov e, 3
                        jmp f4Letter

                    not_n43e:
                        cmp al, 'F'
                        jne not_n43f
                        mov f, 3
                        jmp f4Letter

                    not_n43f:
                        cmp al, 'G'
                        jne not_n43g
                        mov g, 3
                        jmp f4Letter

                    not_n43g:
                        cmp al, 'H'
                        mov h, 3
                        jmp f4Letter

                        f4Letter:
                            mov ah, 1
                            int 21h
                            cmp al, 'A'
                            jne not_n44a
                            mov a, 4
                            jmp p_freq

                            not_n44a:
                                cmp al, 'B'
                                jne not_n44b
                                mov b, 4
                                jmp p_freq

                            not_n44b:
                                cmp al, 'C'
                                jne not_n44c
                                mov c, 4
                                jmp p_freq

                            not_n44c:
                                cmp al, 'D'
                                jne not_n44d
                                mov d, 4
                                jmp p_freq

                            not_n44d:
                                cmp al, 'E'
                                jne not_n44e
                                mov e, 4
                                jmp p_freq

                            not_n44e:
                                cmp al, 'F'
                                jne not_n44f
                                mov f, 4
                                jmp p_freq

                            not_n44f:
                                cmp al, 'G'
                                jne not_n44g
                                mov g, 4
                                jmp p_freq

                            not_n44g:
                                cmp al, 'H'
                                mov h, 4
                                jmp p_freq
    jmp p_freq

    five:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        jne not_n51a
        mov a, 1
        jmp s5Letter

        not_n51a:
            cmp al, 'B'
            jne not_n51b
            mov b, 1
            jmp s5Letter

        not_n51b:
            cmp al, 'C'
            jne not_n51c
            mov c, 1
            jmp s5Letter

        not_n51c:
            cmp al, 'D'
            jne not_n51d
            mov d, 1
            jmp s5Letter

        not_n51d:
            cmp al, 'E'
            jne not_n51e
            mov e, 1
            jmp s5Letter

        not_n51e:
            cmp al, 'F'
            jne not_n51f
            mov f, 1
            jmp s5Letter

        not_n51f:
            cmp al, 'G'
            jne not_n51g
            mov g, 1
            jmp s5Letter

        not_n51g:
            cmp al, 'H'
            mov h, 1
            jmp s5Letter

        s5Letter:
            mov ah, 1
            int 21h
            cmp al, 'A'
            jne not_n52a
            mov a, 2
            jmp t5Letter

            not_n52a:
                cmp al, 'B'
                jne not_n52b
                mov b, 2
                jmp t5Letter

            not_n52b:
                cmp al, 'C'
                jne not_n52c
                mov c, 2
                jmp t5Letter

            not_n52c:
                cmp al, 'D'
                jne not_n52d
                mov d, 2
                jmp t5Letter

            not_n52d:
                cmp al, 'E'
                jne not_n52e
                mov e, 2
                jmp t5Letter

            not_n52e:
                cmp al, 'F'
                jne not_n52f
                mov f, 2
                jmp t5Letter

            not_n52f:
                cmp al, 'G'
                jne not_n52g
                mov g, 2
                jmp t5Letter

            not_n52g:
                cmp al, 'H'
                mov h, 2
                jmp t5Letter

                t5Letter:
                    mov ah, 1
                    int 21h
                    cmp al, 'A'
                    jne not_n53a
                    mov a, 3
                    jmp f5Letter

                    not_n53a:
                        cmp al, 'B'
                        jne not_n53b
                        mov b, 3
                        jmp f5Letter

                    not_n53b:
                        cmp al, 'C'
                        jne not_n53c
                        mov c, 3
                        jmp f5Letter

                    not_n53c:
                        cmp al, 'D'
                        jne not_n53d
                        mov d, 3
                        jmp f5Letter

                    not_n53d:
                        cmp al, 'E'
                        jne not_n53e
                        mov e, 3
                        jmp f5Letter

                    not_n53e:
                        cmp al, 'F'
                        jne not_n53f
                        mov f, 3
                        jmp f5Letter

                    not_n53f:
                        cmp al, 'G'
                        jne not_n53g
                        mov g, 3
                        jmp f5Letter

                    not_n53g:
                        cmp al, 'H'
                        mov h, 3
                        jmp f5Letter

                        f5Letter:
                            mov ah, 1
                            int 21h
                            cmp al, 'A'
                            jne not_n54a
                            mov a, 4
                            jmp x5Letter

                            not_n54a:
                                cmp al, 'B'
                                jne not_n54b
                                mov b, 4
                                jmp x5Letter

                            not_n54b:
                                cmp al, 'C'
                                jne not_n54c
                                mov c, 4
                                jmp x5Letter

                            not_n54c:
                                cmp al, 'D'
                                jne not_n54d
                                mov d, 4
                                jmp x5Letter

                            not_n54d:
                                cmp al, 'E'
                                jne not_n54e
                                mov e, 4
                                jmp x5Letter

                            not_n54e:
                                cmp al, 'F'
                                jne not_n54f
                                mov f, 4
                                jmp x5Letter

                            not_n54f:
                                cmp al, 'G'
                                jne not_n54g
                                mov g, 4
                                jmp x5Letter

                            not_n54g:
                                cmp al, 'H'
                                mov h, 4
                                jmp x5Letter

                                x5Letter:
                                    mov ah, 1
                                    int 21h
                                    cmp al, 'A'
                                    jne not_n55a
                                    mov a, 5
                                    jmp p_freq

                                    not_n55a:
                                        cmp al, 'B'
                                        jne not_n55b
                                        mov b, 5
                                        jmp p_freq

                                    not_n55b:
                                        cmp al, 'C'
                                        jne not_n55c
                                        mov c, 5
                                        jmp p_freq

                                    not_n55c:
                                        cmp al, 'D'
                                        jne not_n55d
                                        mov d, 5
                                        jmp p_freq

                                    not_n55d:
                                        cmp al, 'E'
                                        jne not_n55e
                                        mov e, 5
                                        jmp p_freq

                                    not_n55e:
                                        cmp al, 'F'
                                        jne not_n55f
                                        mov f, 5
                                        jmp p_freq

                                    not_n55f:
                                        cmp al, 'G'
                                        jne not_n55g
                                        mov g, 5
                                        jmp p_freq

                                    not_n55g:
                                        cmp al, 'H'
                                        mov h, 5
                                        jmp p_freq
    jmp p_freq

    six:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        jne not_n61a
        mov a, 1
        jmp s6Letter

        not_n61a:
            cmp al, 'B'
            jne not_n61b
            mov b, 1
            jmp s6Letter

        not_n61b:
            cmp al, 'C'
            jne not_n61c
            mov c, 1
            jmp s6Letter

        not_n61c:
            cmp al, 'D'
            jne not_n61d
            mov d, 1
            jmp s6Letter

        not_n61d:
            cmp al, 'E'
            jne not_n61e
            mov e, 1
            jmp s6Letter

        not_n61e:
            cmp al, 'F'
            jne not_n61f
            mov f, 1
            jmp s6Letter

        not_n61f:
            cmp al, 'G'
            jne not_n61g
            mov g, 1
            jmp s6Letter

        not_n61g:
            cmp al, 'H'
            mov h, 1
            jmp s6Letter

        s6Letter:
            mov ah, 1
            int 21h
            cmp al, 'A'
            jne not_n62a
            mov a, 2
            jmp t6Letter

            not_n62a:
                cmp al, 'B'
                jne not_n62b
                mov b, 2
                jmp t6Letter

            not_n62b:
                cmp al, 'C'
                jne not_n62c
                mov c, 2
                jmp t6Letter

            not_n62c:
                cmp al, 'D'
                jne not_n62d
                mov d, 2
                jmp t6Letter

            not_n62d:
                cmp al, 'E'
                jne not_n62e
                mov e, 2
                jmp t6Letter

            not_n62e:
                cmp al, 'F'
                jne not_n62f
                mov f, 2
                jmp t6Letter

            not_n62f:
                cmp al, 'G'
                jne not_n62g
                mov g, 2
                jmp t6Letter

            not_n62g:
                cmp al, 'H'
                mov h, 2
                jmp t6Letter

                t6Letter:
                    mov ah, 1
                    int 21h
                    cmp al, 'A'
                    jne not_n63a
                    mov a, 3
                    jmp f6Letter

                    not_n63a:
                        cmp al, 'B'
                        jne not_n63b
                        mov b, 3
                        jmp f6Letter

                    not_n63b:
                        cmp al, 'C'
                        jne not_n63c
                        mov c, 3
                        jmp f6Letter

                    not_n63c:
                        cmp al, 'D'
                        jne not_n63d
                        mov d, 3
                        jmp f6Letter

                    not_n63d:
                        cmp al, 'E'
                        jne not_n63e
                        mov e, 3
                        jmp f6Letter

                    not_n63e:
                        cmp al, 'F'
                        jne not_n63f
                        mov f, 3
                        jmp f6Letter

                    not_n63f:
                        cmp al, 'G'
                        jne not_n63g
                        mov g, 3
                        jmp f6Letter

                    not_n63g:
                        cmp al, 'H'
                        mov h, 3
                        jmp f6Letter

                        f6Letter:
                            mov ah, 1
                            int 21h
                            cmp al, 'A'
                            jne not_n64a
                            mov a, 4
                            jmp x6Letter

                            not_n64a:
                                cmp al, 'B'
                                jne not_n64b
                                mov b, 4
                                jmp x6Letter

                            not_n64b:
                                cmp al, 'C'
                                jne not_n64c
                                mov c, 4
                                jmp x6Letter

                            not_n64c:
                                cmp al, 'D'
                                jne not_n64d
                                mov d, 4
                                jmp x6Letter

                            not_n64d:
                                cmp al, 'E'
                                jne not_n64e
                                mov e, 4
                                jmp x6Letter

                            not_n64e:
                                cmp al, 'F'
                                jne not_n64f
                                mov f, 4
                                jmp x6Letter

                            not_n64f:
                                cmp al, 'G'
                                jne not_n64g
                                mov g, 4
                                jmp x6Letter

                            not_n64g:
                                cmp al, 'H'
                                mov h, 4
                                jmp x6Letter

                                x6Letter:
                                    mov ah, 1
                                    int 21h
                                    cmp al, 'A'
                                    jne not_n65a
                                    mov a, 5
                                    jmp v6Letter

                                    not_n65a:
                                        cmp al, 'B'
                                        jne not_n65b
                                        mov b, 5
                                        jmp v6Letter

                                    not_n65b:
                                        cmp al, 'C'
                                        jne not_n65c
                                        mov c, 5
                                        jmp v6Letter

                                    not_n65c:
                                        cmp al, 'D'
                                        jne not_n65d
                                        mov d, 5
                                        jmp v6Letter

                                    not_n65d:
                                        cmp al, 'E'
                                        jne not_n65e
                                        mov e, 5
                                        jmp v6Letter

                                    not_n65e:
                                        cmp al, 'F'
                                        jne not_n65f
                                        mov f, 5
                                        jmp v6Letter

                                    not_n65f:
                                        cmp al, 'G'
                                        jne not_n65g
                                        mov g, 5
                                        jmp v6Letter

                                    not_n65g:
                                        cmp al, 'H'
                                        mov h, 5
                                        jmp v6Letter

                                        v6Letter:
                                            mov ah, 1
                                            int 21h
                                            cmp al, 'A'
                                            jne not_n66a
                                            mov a, 6
                                            jmp p_freq

                                            not_n66a:
                                                cmp al, 'B'
                                                jne not_n66b
                                                mov b, 6
                                                jmp p_freq

                                            not_n66b:
                                                cmp al, 'C'
                                                jne not_n66c
                                                mov c, 6
                                                jmp p_freq

                                            not_n66c:
                                                cmp al, 'D'
                                                jne not_n66d
                                                mov d, 6
                                                jmp p_freq

                                            not_n66d:
                                                cmp al, 'E'
                                                jne not_n66e
                                                mov e, 6
                                                jmp p_freq

                                            not_n66e:
                                                cmp al, 'F'
                                                jne not_n66f
                                                mov f, 6
                                                jmp p_freq

                                            not_n66f:
                                                cmp al, 'G'
                                                jne not_n66g
                                                mov g, 6
                                                jmp p_freq

                                            not_n66g:
                                                cmp al, 'H'
                                                mov h, 6
                                                jmp p_freq
    jmp p_freq

    seven:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        jne not_n71a
        mov a, 1
        jmp s7Letter

        not_n71a:
            cmp al, 'B'
            jne not_n71b
            mov b, 1
            jmp s7Letter

        not_n71b:
            cmp al, 'C'
            jne not_n71c
            mov c, 1
            jmp s7Letter

        not_n71c:
            cmp al, 'D'
            jne not_n71d
            mov d, 1
            jmp s7Letter

        not_n71d:
            cmp al, 'E'
            jne not_n71e
            mov e, 1
            jmp s7Letter

        not_n71e:
            cmp al, 'F'
            jne not_n71f
            mov f, 1
            jmp s7Letter

        not_n71f:
            cmp al, 'G'
            jne not_n71g
            mov g, 1
            jmp s7Letter

        not_n71g:
            cmp al, 'H'
            mov h, 1
            jmp s7Letter

        s7Letter:
            mov ah, 1
            int 21h
            cmp al, 'A'
            jne not_n72a
            mov a, 2
            jmp t7Letter

            not_n72a:
                cmp al, 'B'
                jne not_n72b
                mov b, 2
                jmp t7Letter

            not_n72b:
                cmp al, 'C'
                jne not_n72c
                mov c, 2
                jmp t7Letter

            not_n72c:
                cmp al, 'D'
                jne not_n72d
                mov d, 2
                jmp t7Letter

            not_n72d:
                cmp al, 'E'
                jne not_n72e
                mov e, 2
                jmp t7Letter

            not_n72e:
                cmp al, 'F'
                jne not_n72f
                mov f, 2
                jmp t7Letter

            not_n72f:
                cmp al, 'G'
                jne not_n72g
                mov g, 2
                jmp t7Letter

            not_n72g:
                cmp al, 'H'
                mov h, 2
                jmp t7Letter

                t7Letter:
                    mov ah, 1
                    int 21h
                    cmp al, 'A'
                    jne not_n73a
                    mov a, 3
                    jmp f7Letter

                    not_n73a:
                        cmp al, 'B'
                        jne not_n73b
                        mov b, 3
                        jmp f7Letter

                    not_n73b:
                        cmp al, 'C'
                        jne not_n73c
                        mov c, 3
                        jmp f7Letter

                    not_n73c:
                        cmp al, 'D'
                        jne not_n73d
                        mov d, 3
                        jmp f7Letter

                    not_n73d:
                        cmp al, 'E'
                        jne not_n73e
                        mov e, 3
                        jmp f7Letter

                    not_n73e:
                        cmp al, 'F'
                        jne not_n73f
                        mov f, 3
                        jmp f7Letter

                    not_n73f:
                        cmp al, 'G'
                        jne not_n73g
                        mov g, 3
                        jmp f7Letter

                    not_n73g:
                        cmp al, 'H'
                        mov h, 3
                        jmp f7Letter

                        f7Letter:
                            mov ah, 1
                            int 21h
                            cmp al, 'A'
                            jne not_n74a
                            mov a, 4
                            jmp x7Letter

                            not_n74a:
                                cmp al, 'B'
                                jne not_n74b
                                mov b, 4
                                jmp x7Letter

                            not_n74b:
                                cmp al, 'C'
                                jne not_n74c
                                mov c, 4
                                jmp x7Letter

                            not_n74c:
                                cmp al, 'D'
                                jne not_n74d
                                mov d, 4
                                jmp x7Letter

                            not_n74d:
                                cmp al, 'E'
                                jne not_n74e
                                mov e, 4
                                jmp x7Letter

                            not_n74e:
                                cmp al, 'F'
                                jne not_n74f
                                mov f, 4
                                jmp x7Letter

                            not_n74f:
                                cmp al, 'G'
                                jne not_n74g
                                mov g, 4
                                jmp x7Letter

                            not_n74g:
                                cmp al, 'H'
                                mov h, 4
                                jmp x7Letter

                                x7Letter:
                                    mov ah, 1
                                    int 21h
                                    cmp al, 'A'
                                    jne not_n75a
                                    mov a, 5
                                    jmp v7Letter

                                    not_n75a:
                                        cmp al, 'B'
                                        jne not_n75b
                                        mov b, 5
                                        jmp v7Letter

                                    not_n75b:
                                        cmp al, 'C'
                                        jne not_n75c
                                        mov c, 5
                                        jmp v7Letter

                                    not_n75c:
                                        cmp al, 'D'
                                        jne not_n75d
                                        mov d, 5
                                        jmp v7Letter

                                    not_n75d:
                                        cmp al, 'E'
                                        jne not_n75e
                                        mov e, 5
                                        jmp v7Letter

                                    not_n75e:
                                        cmp al, 'F'
                                        jne not_n75f
                                        mov f, 5
                                        jmp v7Letter

                                    not_n75f:
                                        cmp al, 'G'
                                        jne not_n75g
                                        mov g, 5
                                        jmp v7Letter

                                    not_n75g:
                                        cmp al, 'H'
                                        mov h, 5
                                        jmp v7Letter

                                        v7Letter:
                                            mov ah, 1
                                            int 21h
                                            cmp al, 'A'
                                            jne not_n76a
                                            mov a, 6
                                            jmp sv7Letter

                                            not_n76a:
                                                cmp al, 'B'
                                                jne not_n76b
                                                mov b, 6
                                                jmp sv7Letter

                                            not_n76b:
                                                cmp al, 'C'
                                                jne not_n76c
                                                mov c, 6
                                                jmp sv7Letter

                                            not_n76c:
                                                cmp al, 'D'
                                                jne not_n76d
                                                mov d, 6
                                                jmp sv7Letter

                                            not_n76d:
                                                cmp al, 'E'
                                                jne not_n76e
                                                mov e, 6
                                                jmp sv7Letter

                                            not_n76e:
                                                cmp al, 'F'
                                                jne not_n76f
                                                mov f, 6
                                                jmp sv7Letter

                                            not_n76f:
                                                cmp al, 'G'
                                                jne not_n76g
                                                mov g, 6
                                                jmp sv7Letter

                                            not_n76g:
                                                cmp al, 'H'
                                                mov h, 6
                                                jmp sv7Letter

                                                sv7Letter:
                                                    mov ah, 1
                                                    int 21h
                                                    cmp al, 'A'
                                                    jne not_n77a
                                                    mov a, 7
                                                    jmp p_freq

                                                    not_n77a:
                                                        cmp al, 'B'
                                                        jne not_n77b
                                                        mov b, 7
                                                        jmp p_freq

                                                    not_n77b:
                                                        cmp al, 'C'
                                                        jne not_n77c
                                                        mov c, 7
                                                        jmp p_freq

                                                    not_n77c:
                                                        cmp al, 'D'
                                                        jne not_n77d
                                                        mov d, 7
                                                        jmp p_freq

                                                    not_n77d:
                                                        cmp al, 'E'
                                                        jne not_n77e
                                                        mov e, 7
                                                        jmp p_freq

                                                    not_n77e:
                                                        cmp al, 'F'
                                                        jne not_n77f
                                                        mov f, 7
                                                        jmp p_freq

                                                    not_n77f:
                                                        cmp al, 'G'
                                                        jne not_n77g
                                                        mov g, 7
                                                        jmp p_freq

                                                    not_n77g:
                                                        cmp al, 'H'
                                                        mov h, 7
                                                        jmp p_freq
    jmp p_freq

    eight:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        jne not_n81a
        mov a, 1
        jmp s8Letter

        not_n81a:
            cmp al, 'B'
            jne not_n81b
            mov b, 1
            jmp s8Letter

        not_n81b:
            cmp al, 'C'
            jne not_n81c
            mov c, 1
            jmp s8Letter

        not_n81c:
            cmp al, 'D'
            jne not_n81d
            mov d, 1
            jmp s8Letter

        not_n81d:
            cmp al, 'E'
            jne not_n81e
            mov e, 1
            jmp s8Letter

        not_n81e:
            cmp al, 'F'
            jne not_n81f
            mov f, 1
            jmp s8Letter

        not_n81f:
            cmp al, 'G'
            jne not_n81g
            mov g, 1
            jmp s8Letter

        not_n81g:
            cmp al, 'H'
            mov h, 1
            jmp s8Letter

        s8Letter:
            mov ah, 1
            int 21h
            cmp al, 'A'
            jne not_n82a
            mov a, 2
            jmp t8Letter

            not_n82a:
                cmp al, 'B'
                jne not_n82b
                mov b, 2
                jmp t8Letter

            not_n82b:
                cmp al, 'C'
                jne not_n82c
                mov c, 2
                jmp t8Letter

            not_n82c:
                cmp al, 'D'
                jne not_n82d
                mov d, 2
                jmp t8Letter

            not_n82d:
                cmp al, 'E'
                jne not_n82e
                mov e, 2
                jmp t8Letter

            not_n82e:
                cmp al, 'F'
                jne not_n82f
                mov f, 2
                jmp t8Letter

            not_n82f:
                cmp al, 'G'
                jne not_n82g
                mov g, 2
                jmp t8Letter

            not_n82g:
                cmp al, 'H'
                mov h, 2
                jmp t8Letter

                t8Letter:
                    mov ah, 1
                    int 21h
                    cmp al, 'A'
                    jne not_n83a
                    mov a, 3
                    jmp f8Letter

                    not_n83a:
                        cmp al, 'B'
                        jne not_n83b
                        mov b, 3
                        jmp f8Letter

                    not_n83b:
                        cmp al, 'C'
                        jne not_n83c
                        mov c, 3
                        jmp f8Letter

                    not_n83c:
                        cmp al, 'D'
                        jne not_n83d
                        mov d, 3
                        jmp f8Letter

                    not_n83d:
                        cmp al, 'E'
                        jne not_n83e
                        mov e, 3
                        jmp f8Letter

                    not_n83e:
                        cmp al, 'F'
                        jne not_n83f
                        mov f, 3
                        jmp f8Letter

                    not_n83f:
                        cmp al, 'G'
                        jne not_n83g
                        mov g, 3
                        jmp f8Letter

                    not_n83g:
                        cmp al, 'H'
                        mov h, 3
                        jmp f8Letter

                        f8Letter:
                            mov ah, 1
                            int 21h
                            cmp al, 'A'
                            jne not_n84a
                            mov a, 4
                            jmp x8Letter

                            not_n84a:
                                cmp al, 'B'
                                jne not_n84b
                                mov b, 4
                                jmp x8Letter

                            not_n84b:
                                cmp al, 'C'
                                jne not_n84c
                                mov c, 4
                                jmp x8Letter

                            not_n84c:
                                cmp al, 'D'
                                jne not_n84d
                                mov d, 4
                                jmp x8Letter

                            not_n84d:
                                cmp al, 'E'
                                jne not_n84e
                                mov e, 4
                                jmp x8Letter

                            not_n84e:
                                cmp al, 'F'
                                jne not_n84f
                                mov f, 4
                                jmp x8Letter

                            not_n84f:
                                cmp al, 'G'
                                jne not_n84g
                                mov g, 4
                                jmp x8Letter

                            not_n84g:
                                cmp al, 'H'
                                mov h, 4
                                jmp x8Letter

                                x8Letter:
                                    mov ah, 1
                                    int 21h
                                    cmp al, 'A'
                                    jne not_n85a
                                    mov a, 5
                                    jmp v8Letter

                                    not_n85a:
                                        cmp al, 'B'
                                        jne not_n85b
                                        mov b, 5
                                        jmp v8Letter

                                    not_n85b:
                                        cmp al, 'C'
                                        jne not_n85c
                                        mov c, 5
                                        jmp v8Letter

                                    not_n85c:
                                        cmp al, 'D'
                                        jne not_n85d
                                        mov d, 5
                                        jmp v8Letter

                                    not_n85d:
                                        cmp al, 'E'
                                        jne not_n85e
                                        mov e, 5
                                        jmp v8Letter

                                    not_n85e:
                                        cmp al, 'F'
                                        jne not_n85f
                                        mov f, 5
                                        jmp v8Letter

                                    not_n85f:
                                        cmp al, 'G'
                                        jne not_n85g
                                        mov g, 5
                                        jmp v8Letter

                                    not_n85g:
                                        cmp al, 'H'
                                        mov h, 5
                                        jmp v8Letter

                                        v8Letter:
                                            mov ah, 1
                                            int 21h
                                            cmp al, 'A'
                                            jne not_n86a
                                            mov a, 6
                                            jmp sv8Letter

                                            not_n86a:
                                                cmp al, 'B'
                                                jne not_n86b
                                                mov b, 6
                                                jmp sv8Letter

                                            not_n86b:
                                                cmp al, 'C'
                                                jne not_n86c
                                                mov c, 6
                                                jmp sv8Letter

                                            not_n86c:
                                                cmp al, 'D'
                                                jne not_n86d
                                                mov d, 6
                                                jmp sv8Letter

                                            not_n86d:
                                                cmp al, 'E'
                                                jne not_n86e
                                                mov e, 6
                                                jmp sv8Letter

                                            not_n86e:
                                                cmp al, 'F'
                                                jne not_n86f
                                                mov f, 6
                                                jmp sv8Letter

                                            not_n86f:
                                                cmp al, 'G'
                                                jne not_n86g
                                                mov g, 6
                                                jmp sv8Letter

                                            not_n86g:
                                                cmp al, 'H'
                                                mov h, 6
                                                jmp sv8Letter

                                                sv8Letter:
                                                    mov ah, 1
                                                    int 21h
                                                    cmp al, 'A'
                                                    jne not_n87a
                                                    mov a, 7
                                                    jmp eg8Letter

                                                    not_n87a:
                                                        cmp al, 'B'
                                                        jne not_n87b
                                                        mov b, 7
                                                        jmp eg8Letter

                                                    not_n87b:
                                                        cmp al, 'C'
                                                        jne not_n87c
                                                        mov c, 7
                                                        jmp eg8Letter

                                                    not_n87c:
                                                        cmp al, 'D'
                                                        jne not_n87d
                                                        mov d, 7
                                                        jmp eg8Letter

                                                    not_n87d:
                                                        cmp al, 'E'
                                                        jne not_n87e
                                                        mov e, 7
                                                        jmp eg8Letter

                                                    not_n87e:
                                                        cmp al, 'F'
                                                        jne not_n87f
                                                        mov f, 7
                                                        jmp eg8Letter

                                                    not_n87f:
                                                        cmp al, 'G'
                                                        jne not_n87g
                                                        mov g, 7
                                                        jmp eg8Letter

                                                    not_n87g:
                                                        cmp al, 'H'
                                                        mov h, 7
                                                        jmp eg8Letter

                                                        eg8Letter:
                                                            mov ah, 1
                                                            int 21h
                                                            cmp al, 'A'
                                                            jne not_n88a
                                                            mov a, 8
                                                            jmp p_freq

                                                            not_n88a:
                                                                cmp al, 'B'
                                                                jne not_n88b
                                                                mov b, 8
                                                                jmp p_freq

                                                            not_n88b:
                                                                cmp al, 'C'
                                                                jne not_n88c
                                                                mov c, 8
                                                                jmp p_freq

                                                            not_n88c:
                                                                cmp al, 'D'
                                                                jne not_n88d
                                                                mov d, 8
                                                                jmp p_freq

                                                            not_n88d:
                                                                cmp al, 'E'
                                                                jne not_n88e
                                                                mov e, 8
                                                                jmp p_freq

                                                            not_n88e:
                                                                cmp al, 'F'
                                                                jne not_n88f
                                                                mov f, 8
                                                                jmp p_freq

                                                            not_n88f:
                                                                cmp al, 'G'
                                                                jne not_n88g
                                                                mov g, 8
                                                                jmp p_freq

                                                            not_n88g:
                                                                cmp al, 'H'
                                                                mov h, 8
                                                                jmp p_freq
    jmp p_freq

    printn ''

    p_freq:
    ; print frequency of each letter
    printn ''
    printn 'Frequency of each letter:'

    printn ''

    print 'A: '
    mov dl, a
    add dl, 48
    mov ah, 2
    int 21h

    printn ''

    print 'B: '
    mov dl, b
    add dl, 48
    mov ah, 2
    int 21h

    printn ''

    print 'C: '
    mov dl, c
    add dl, 48
    mov ah, 2
    int 21h

    printn ''

    print 'D: '
    mov dl, d
    add dl, 48
    mov ah, 2
    int 21h

    printn ''

    print 'E: '
    mov dl, e
    add dl, 48
    mov ah, 2
    int 21h

    printn ''

    print 'F: '
    mov dl, f
    add dl, 48
    mov ah, 2
    int 21h

    printn ''

    print 'G: '
    mov dl, g
    add dl, 48
    mov ah, 2
    int 21h

    printn ''

    print 'H: '
    mov dl, h
    add dl, 48
    mov ah, 2
    int 21h

    printn ''

    exit:
    mov ah, 4ch
    int 21h
main endp
end main
