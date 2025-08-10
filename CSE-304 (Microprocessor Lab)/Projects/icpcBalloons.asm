; ICPC Balloons
; https://codeforces.com/contest/1703/problem/B
include 'emu8086.inc'

.model small
.stack 100h

.data
    msg1 db "Enter the length of the string: $"
    msg2 db "Enter the string(A-E): $"
    sz db ?
    cnt db 0
    res db ?
    a db 0
    b db 0
    c db 0
    d db 0
    e db 0

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

    one:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n11a
        jne not_n11a

        eq_n11a:
            inc a
            jmp p_freq
        not_n11a:
            cmp al, 'B'
            je eq_n11b
            jne not_n11b

        eq_n11b:
            inc b
            jmp p_freq
        not_n11b:
            cmp al, 'C'
            je eq_n11c
            jne not_n11c

        eq_n11c:
            inc c
            jmp p_freq
        not_n11c:
            cmp al, 'D'
            je eq_n11d
            jne not_n11d

        eq_n11d:
            inc d
            jmp p_freq
        not_n11d:
            inc e
            jmp p_freq
    jmp p_freq
    
    two:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n21a
        jne not_n21a

        eq_n21a:
            inc a
            jmp s2Letter
        not_n21a:
            cmp al, 'B'
            je eq_n21b
            jne not_n21b

        eq_n21b:
            inc b
            jmp s2Letter
        not_n21b:
            cmp al, 'C'
            je eq_n21c
            jne not_n21c

        eq_n21c:
            inc c
            jmp s2Letter
        not_n21c:
            cmp al, 'D'
            je eq_n21d
            jne not_n21d

        eq_n21d:
            inc d
            jmp s2Letter
        not_n21d:
            inc e
            jmp s2Letter

        s2Letter:
        ; read second letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n22a
        jne not_n22a

        eq_n22a:
            inc a
            jmp p_freq
        not_n22a:
            cmp al, 'B'
            je eq_n22b
            jne not_n22b

        eq_n22b:
            inc b
            jmp p_freq
        not_n22b:
            cmp al, 'C'
            je eq_n22c
            jne not_n22c

        eq_n22c:
            inc c
            jmp p_freq
        not_n22c:
            cmp al, 'D'
            je eq_n22d
            jne not_n22d

        eq_n22d:
            inc d
            jmp p_freq
        not_n22d:
            inc e
            jmp p_freq
    jmp p_freq

    three:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n31a
        jne not_n31a

        eq_n31a:
            inc a
            jmp s3Letter
        not_n31a:
            cmp al, 'B'
            je eq_n31b
            jne not_n31b

        eq_n31b:
            inc b
            jmp s3Letter
        not_n31b:
            cmp al, 'C'
            je eq_n31c
            jne not_n31c

        eq_n31c:
            inc c
            jmp s3Letter
        not_n31c:
            cmp al, 'D'
            je eq_n31d
            jne not_n31d

        eq_n31d:
            inc d
            jmp s3Letter
        not_n31d:
            inc e
            jmp s3Letter

        s3Letter:
        ; read second letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n32a
        jne not_n32a

        eq_n32a:
            inc a
            jmp t3Letter
        not_n32a:
            cmp al, 'B'
            je eq_n32b
            jne not_n32b

        eq_n32b:
            inc b
            jmp t3Letter
        not_n32b:
            cmp al, 'C'
            je eq_n32c
            jne not_n32c

        eq_n32c:
            inc c
            jmp t3Letter
        not_n32c:
            cmp al, 'D'
            je eq_n32d
            jne not_n32d

        eq_n32d:
            inc d
            jmp t3Letter
        not_n32d:
            inc e
            jmp t3Letter

        t3Letter:
        ; read third letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n33a
        jne not_n33a

        eq_n33a:
            inc a
            jmp p_freq
        not_n33a:
            cmp al, 'B'
            je eq_n33b
            jne not_n33b

        eq_n33b:
            inc b
            jmp p_freq
        not_n33b:
            cmp al, 'C'
            je eq_n33c
            jne not_n33c

        eq_n33c:
            inc c
            jmp p_freq
        not_n33c:
            cmp al, 'D'
            je eq_n33d
            jne not_n33d

        eq_n33d:
            inc d
            jmp p_freq
        not_n33d:
            inc e
            jmp p_freq
    jmp p_freq

    four:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n41a
        jne not_n41a

        eq_n41a:
            inc a
            jmp s4Letter
        not_n41a:
            cmp al, 'B'
            je eq_n41b
            jne not_n41b

        eq_n41b:
            inc b
            jmp s4Letter
        not_n41b:
            cmp al, 'C'
            je eq_n41c
            jne not_n41c

        eq_n41c:
            inc c
            jmp s4Letter
        not_n41c:
            cmp al, 'D'
            je eq_n41d
            jne not_n41d

        eq_n41d:
            inc d
            jmp s4Letter
        not_n41d:
            inc e
            jmp s4Letter

        s4Letter:
        ; read second letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n42a
        jne not_n42a

        eq_n42a:
            inc a
            jmp t4Letter
        not_n42a:
            cmp al, 'B'
            je eq_n42b
            jne not_n42b

        eq_n42b:
            inc b
            jmp t4Letter
        not_n42b:
            cmp al, 'C'
            je eq_n42c
            jne not_n42c

        eq_n42c:
            inc c
            jmp t4Letter
        not_n42c:
            cmp al, 'D'
            je eq_n42d
            jne not_n42d

        eq_n42d:
            inc d
            jmp t4Letter
        not_n42d:
            inc e
            jmp t4Letter

        t4Letter:
        ; read third letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n43a
        jne not_n43a

        eq_n43a:
            inc a
            jmp f4Letter
        not_n43a:
            cmp al, 'B'
            je eq_n43b
            jne not_n43b

        eq_n43b:
            inc b
            jmp f4Letter
        not_n43b:
            cmp al, 'C'
            je eq_n43c
            jne not_n43c

        eq_n43c:
            inc c
            jmp f4Letter
        not_n43c:
            cmp al, 'D'
            je eq_n43d
            jne not_n43d

        eq_n43d:
            inc d
            jmp f4Letter
        not_n43d:
            inc e
            jmp f4Letter

        f4Letter:
        ; read fourth letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n44a
        jne not_n44a

        eq_n44a:
            inc a
            jmp p_freq
        not_n44a:
            cmp al, 'B'
            je eq_n44b
            jne not_n44b

        eq_n44b:
            inc b
            jmp p_freq
        not_n44b:
            cmp al, 'C'
            je eq_n44c
            jne not_n44c

        eq_n44c:
            inc c
            jmp p_freq
        not_n44c:
            cmp al, 'D'
            je eq_n44d
            jne not_n44d

        eq_n44d:
            inc d
            jmp p_freq
        not_n44d:
            inc e
            jmp p_freq
    jmp p_freq

    five:
        ; read first letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n51a
        jne not_n51a

        eq_n51a:
            inc a
            jmp s5Letter
        not_n51a:
            cmp al, 'B'
            je eq_n51b
            jne not_n51b

        eq_n51b:
            inc b
            jmp s5Letter
        not_n51b:
            cmp al, 'C'
            je eq_n51c
            jne not_n51c

        eq_n51c:
            inc c
            jmp s5Letter
        not_n51c:
            cmp al, 'D'
            je eq_n51d
            jne not_n51d

        eq_n51d:
            inc d
            jmp s5Letter
        not_n51d:
            inc e
            jmp s5Letter

        s5Letter:
        ; read second letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n52a
        jne not_n52a

        eq_n52a:
            inc a
            jmp t5Letter
        not_n52a:
            cmp al, 'B'
            je eq_n52b
            jne not_n52b

        eq_n52b:
            inc b
            jmp t5Letter
        not_n52b:
            cmp al, 'C'
            je eq_n52c
            jne not_n52c

        eq_n52c:
            inc c
            jmp t5Letter
        not_n52c:
            cmp al, 'D'
            je eq_n52d
            jne not_n52d

        eq_n52d:
            inc d
            jmp t5Letter
        not_n52d:
            inc e
            jmp t5Letter

        t5Letter:
        ; read third letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n53a
        jne not_n53a

        eq_n53a:
            inc a
            jmp f5Letter
        not_n53a:
            cmp al, 'B'
            je eq_n53b
            jne not_n53b

        eq_n53b:
            inc b
            jmp f5Letter
        not_n53b:
            cmp al, 'C'
            je eq_n53c
            jne not_n53c

        eq_n53c:
            inc c
            jmp f5Letter
        not_n53c:
            cmp al, 'D'
            je eq_n53d
            jne not_n53d

        eq_n53d:
            inc d
            jmp f5Letter
        not_n53d:
            inc e
            jmp f5Letter

        f5Letter:
        ; read fourth letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n54a
        jne not_n54a

        eq_n54a:
            inc a
            jmp v5Letter
        not_n54a:
            cmp al, 'B'
            je eq_n54b
            jne not_n54b

        eq_n54b:
            inc b
            jmp v5Letter
        not_n54b:
            cmp al, 'C'
            je eq_n54c
            jne not_n54c

        eq_n54c:
            inc c
            jmp v5Letter
        not_n54c:
            cmp al, 'D'
            je eq_n54d
            jne not_n54d

        eq_n54d:
            inc d
            jmp v5Letter
        not_n54d:
            inc e
            jmp v5Letter

        v5Letter:
        ; read fifth letter
        mov ah, 1
        int 21h
        cmp al, 'A'
        je eq_n55a
        jne not_n55a

        eq_n55a:
            inc a
            jmp p_freq
        not_n55a:
            cmp al, 'B'
            je eq_n55b
            jne not_n55b

        eq_n55b:
            inc b
            jmp p_freq
        not_n55b:
            cmp al, 'C'
            je eq_n55c
            jne not_n55c

        eq_n55c:
            inc c
            jmp p_freq
        not_n55c:
            cmp al, 'D'
            je eq_n55d
            jne not_n55d

        eq_n55d:
            inc d
            jmp p_freq
        not_n55d:
            inc e
            jmp p_freq
    jmp p_freq

    printn ''
    printn ''

    p_freq:
    ; print frequency of each letter
    printn ''
    printn 'Frequency of each letter:'

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
    printn ''

    ; calculation part
    cmp a, 0
    je cnt_b
    jne inc_a

    inc_a:
    inc a 
    
    cnt_b:
    cmp b, 0
    je cnt_c
    jne inc_b

    inc_b:
    inc b

    cnt_c:
    cmp c, 0
    je cnt_d
    jne inc_c

    inc_c:
    inc c

    cnt_d:
    cmp d, 0
    je cnt_e
    jne inc_d

    inc_d:
    inc d

    cnt_e:
    cmp e, 0
    je result
    jne inc_e

    inc_e:
    inc e

    result:
    ; sum of all frequencies
    mov al, a
    add al, b
    add al, c
    add al, d
    add al, e

    ; print result
    print 'Result: '
    mov dl, al
    add dl, 48
    mov ah, 2
    int 21h

    exit:
    mov ah, 4ch
    int 21h
main endp
end main

