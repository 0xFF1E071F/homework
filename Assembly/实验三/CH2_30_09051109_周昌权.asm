.386
.model flat, stdcall
option casemap:none
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; Include �ļ�����
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
include windows.inc
include kernel32.inc
includelib kernel32.lib
include user32.inc
includelib user32.lib
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ���ݶ�
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.data
	szStr	db	'I co&me from Chi&na.', 0
	buf		db	50 dup(0)
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; �����
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.code
start:
	mov esi, offset szStr
	mov edi, offset buf
	mov ecx, sizeof szStr

s:	.if	BYTE PTR [esi] == '&'
		inc esi
	.else
		mov al, BYTE PTR [esi]
		mov BYTE PTR [edi], al
		inc esi
		inc edi
	.endif
	loop s
	mov esi, offset szStr
	mov edi, offset buf
	.while BYTE PTR [edi] != 0
		mov al, BYTE PTR [edi]
		mov BYTE PTR [esi], al
		inc esi
		inc edi
	.endw
	mov BYTE PTR [esi], 0
	invoke MessageBox,NULL, addr buf, addr szStr, MB_OK
	invoke ExitProcess,0
end start