; write a assembly program in emu8086 where take Name, ID, Phone, Email form user and print those input values inside a string like Hello $Name, we know your ID $ID. Thank you for sharing your phone number $Phone and Email address $Email

.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 10,13, "Enter your Name : $"
MSG2 DB 10,13, "Enter your ID : $"
MSG3 DB 10,13, "Enter your Phone : $"
MSG4 DB 10,13, "Enter your Email : $"
MSG5 DB 10,13, "Hello $"
MSG6 DB 10,13, "We know your ID $"
MSG7 DB 10,13, "Thank you for sharing your phone number $"
MSG8 DB 10,13, "and Email address $"
NAME DB 20,?,20 DUP("$")
ID DB 20,?,20 DUP("$")
PHONE DB 20,?,20 DUP("$")
EMAIL DB 20,?,20 DUP("$")
.CODE
MAIN PROC
MOV AX,@DATA
MOV DS,AX
LEA DX,MSG1
MOV AH,09H
INT 21H
LEA DX,NAME
MOV AH,0AH
INT 21H
LEA DX,MSG2
MOV AH,09H
INT 21H
LEA DX,ID
MOV AH,0AH
INT 21H
LEA DX,MSG3
MOV AH,09H
INT 21H
LEA DX,PHONE
MOV AH,0AH
INT 21H
LEA DX,MSG4
MOV AH,09H
INT 21H
LEA DX,EMAIL
MOV AH,0AH
INT 21H
LEA DX,MSG5
MOV AH,09H
INT 21H
LEA DX,NAME+2
MOV AH,09H
INT 21H
LEA DX,MSG6
MOV AH,09H
INT 21H
LEA DX,ID+2
MOV AH,09H
INT 21H
LEA DX,MSG7
MOV AH,09H
INT 21H
LEA DX,PHONE+2
MOV AH,09H
INT 21H
LEA DX,MSG8
MOV AH,09H
INT 21H
LEA DX,EMAIL+2
MOV AH,09H
INT 21H
MOV AH,4CH
INT 21H
MAIN ENDP
END MAIN

Output:

Enter your Name : $Rakib
Enter your ID : $123456
Enter your Phone : $01700000000
Enter your Email : $
