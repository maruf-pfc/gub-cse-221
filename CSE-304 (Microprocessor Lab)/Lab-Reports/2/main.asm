.MODEL SMALL
.STACK 100H
.DATA
	MSG1 DB 10,13,"ENTER FIRST NUMBER : $"
	MSG2 DB 10,13,"ENTER SECOND NUMBER : $"
	MSG3 DB 10,13,"RESULT 1 : $"
    MSG4 DB 10,13,"RESULT 2 : $"

	NUM1 DB ?
	NUM2 DB ?
	RESULT DB ?

.CODE
MAIN PROC
    ; data segment
	MOV AX, @DATA
	MOV DS, AX

    ; print msg1
	MOV AH, 09H
	LEA DX, MSG1
	INT 21H

    ; read num1 --> convert it to number --> store it in NUM1
	MOV AH, 01H
	INT 21H
	SUB AL, 30H
	MOV NUM1, AL

    ; print msg2
	MOV AH, 09H
	LEA DX, MSG2
	INT 21H

    ; read num2 --> convert it to number --> store it in NUM2
	MOV AH, 01H
	INT 21H
	SUB AL, 30H
	MOV NUM2, AL

    ; multiply num1 and num2 --> store it in AL --> convert it to character --> store it in RESULT
	MOV AL, NUM1
	MUL NUM2
	ADD AL, 30H
	MOV RESULT, AL

    ; print msg3
	MOV AH, 09H
	LEA DX, MSG3
	INT 21H

    ; print result
	MOV AH, 02H
	MOV DL, RESULT
	INT 21H

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; new line
    mov ah, 2
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h

    ; print 2 * 4 = 8
    ; print msg3
    MOV AH, 09H
    LEA DX, MSG4
    INT 21H

    MOV AL, 2
    MOV BL, 4
    MUL BL
    ADD AL,30H
    MOV BL,AL

    ; display 
    MOV AH, 2
    MOV DL, BL
    INT 21H

    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H

    ; exit
	MOV AH, 4CH
	INT 21H
MAIN ENDP
END MAIN
