; GREEN UNIVERSITY OF BANGLADESH, DEPARTMENT OF CSE
; --------------------------------------------------
; AUTHOR  : MD. MARUF SARKER
; ID      : 221002063
; SUBJECT : Microprocessor & Microcontroller Lab (CSE 304)
; PROBLEM : TAKE A STRING AS INPUT AND DISPLAY THE LENGTH OF THE STRING


.MODEL SMALL
.STACK 100H
.DATA
    MSG1 DB 10,13,'ENTER A STRING : $'
    MSG2 DB 10,13,'LENGTH OF THE STRING : $'
    CNT DB 25 DUP('0') 
     
.CODE 
    MAIN: 
        MOV AX, @DATA 
        MOV DS, AX 

        LEA DX, MSG1 
        MOV AH, 9
        INT 21H 

        ; READING THE STRING
        LEA SI, CNT     ; SI = OFFSET CNT
        MOV DX, SI      ; DX = SI
        MOV AH, 0AH     ; AH = 0AH
        INT 21H         ; READ STRING
         
        ; CHECKING IF THE STRING IS EMPTY
        MOV SI, 2       ; SI = 2
        CMP CNT+SI, 0DH ; IF CNT+SI = 0DH
        JE EXIT         ; THEN EXIT
      
        LEA DX, MSG2
        MOV AH, 9
        INT 21H 

        ; CONVERTING THE LENGTH OF THE STRING TO ASCII
        MOV SI, 1       ; SI = 1
        MOV AL, CNT+SI  ; AL = CNT+SI
        MOV AH, 00H     ; AH = 00H
        MOV BL, 0AH     ; BL = 0AH
        AAD             ; AX = AL * 10 + AH
        DIV BL          ; AX = AX / BL

        ; DISPLAY FIRST DIGIT
        MOV DX, AX 
        ADD DL, 30H
        MOV AH, 2
        INT 21H 
        
        ; DISPLAY SECOND DIGIT
        MOV DL, DH 
        ADD DL, 30H 
        MOV AH, 2
        INT 21H 

    EXIT:   
        MOV AH, 4CH
        INT 21H
ENDP
