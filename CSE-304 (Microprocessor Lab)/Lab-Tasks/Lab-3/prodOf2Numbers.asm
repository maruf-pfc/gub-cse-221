.model small
.stack 100h

.data
    a dw 10
    b dw 20
    res dw ?
.code
    main proc
        mov ax, @data
        mov ds, ax
        
        mov ax, a
        mul b  
        
        mov res, ax
        
        mov ah, 4ch
        int 21h
    main endp
end main