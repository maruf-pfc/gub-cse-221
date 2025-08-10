; Use 4 different variables
; a = Green
; b = University
; c = Of
; d = Bangladesh

; Now the modified string will be s = "Green_University_Of_Bangladesh"

INCLUDE 'EMU8086.INC'
.MODEL SMALL
.STACK 100H
.DATA
    A DB 40 DUP (?)
    B DB 40 DUP (?) 
    C DB 40 DUP (?)
    D DB 40 DUP (?)
    STR DB 100 DUP (?)

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    PRINT 'A: '
    MOV DX,40 
    LEA DI,A
    CALL GET_STRING
    PRINTN ''
    
    PRINT 'B: '
    MOV DX,40   
    LEA DI,B
    CALL GET_STRING
    PRINTN ''    

    PRINT 'C: '
    MOV DX,40   
    LEA DI,C
    CALL GET_STRING
    PRINTN ''
    
    PRINT 'D: '
    MOV DX,40    
    LEA DI,D
    CALL GET_STRING
    PRINTN '' 
    PRINTN ''
    
    PRINT 'MODIFIED STRING: '
    LEA SI, A
    CALL PRINT_STRING
    PRINT '_'
    
    LEA SI, B
    CALL PRINT_STRING
    PRINT '_'
    
    LEA SI, C
    CALL PRINT_STRING
    PRINT '_'
    
    LEA SI, D
    CALL PRINT_STRING
    PRINTN ''  

    EXIT:
    MOV AH, 4CH
    INT 21H

MAIN ENDP
DEFINE_GET_STRING
DEFINE_PRINT_STRING
END MAIN