.386
.model flat, stdcall
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; Include �ļ�����
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
include	kernel32.inc
includelib	kernel32.lib
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ���ݶ�
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.data
	x	dw	15
 	y	dw 	16
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; �����
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.code
start:
   ;.....����Ѱַ����������������������	
   mov	ax, 1234H
   ;.....�Ĵ���Ѱַ����������������������	
   MOV	EAX, EBX
   ;.....ֱ��Ѱַ����������������������	
 
   MOV AX,x                 ;MOV AX,WORD PTR DS:[403000]
   MOV BX,[x]                ;MOV BX,WORD PTR DS:[403000]
   ;.....����Ѱַ����������������������	
   MOV ESI, offset x         ;MOV ESI,1xunzhi.00403000
   mov EDI, offset y          ;MOV EDI,1xunzhi.00403002
   ;.....�Ĵ������Ѱַ����������������������	 
   MOV Ah,[ESI]                 ;MOV AX,WORD PTR DS:[ESI]
   MOV BX,[EDI]                 ;MOV BX,WORD PTR DS:[EDI]
   mov [esi],bx                  ;MOV WORD PTR DS:[ESI],BX
   mov [edi],ax                  ;MOV WORD PTR DS:[EDI],AX
   ;.....����Ѱַ����������������������	
   MOV ESI,2                     
   MOV Ebx,offset y              ;MOV EBX,1xunzhi.00403002
   ;�����������Ĵ������Ѱַ����������������������������
   MOV 	AX,x[ESI]                ;MOV AX,WORD PTR DS:[ESI+403000]
   mov ebx,offset x              ;MOV EBX,1xunzhi.00403000
   ;������������ַ��ַѰַ ������������������������ 
   MOV 	AX,[EBX][ESI]              ;MOV AX,WORD PTR DS:[ESI+EBX]
   ;.....����Ѱַ����������������������	
   MOV Ebx,1 
   MOV Edi,1 
   ;����������������Ի�ַ��ַѰַ��ʽ ������������
   MOV	AX,x[EBX][EDI]   ;MOV AX,WORD PTR DS:[EDI+EBX+403000]
   ;.....����Ѱַ����������������������	
   MOV Esi,1 
   ;...............������ַѰַ....................
   MOV  AX,x[ESI*2]     ;MOV AX,WORD PTR DS:[ESI*2+403000]
   ;.....����Ѱַ����������������������
   MOV 	EBP, offset x    ;MOV EBP,1xunzhi.00403000
   ;...............��ַ������ַѰַ................ 
   MOV 	CX, [EBP] [ESI*2]   ;MOV CX,WORD PTR SS:[EBP+ESI*2]
   ;............................................
   invoke  ExitProcess,0

end start
