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
	szCaption	db	'convert num to string', 0
	szResult	db	6 dup(0)
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; �����
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.code
_Translate	proc	para1:DWORD, para2:DWORD
	
	local	_iNum	;������ʱ���汻����
	local	_iTemp	;������ʱ�������
	local	_szTemp[256]:BYTE	;���ڱ�������ASCII��
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ��ʼ��
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>	
	mov eax, para1
	mov _iNum, eax
	mov _iTemp, 16
	lea ebx, _szTemp	;������ת�������򱣴浽��ʱ����_szTemp
	xor ecx, ecx		;���ڼ�¼��ת�����������м�λ
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ��whileѭ���аѱ�ת��������ѭ����16�� �ѵõ�������
; ת����ASCII�룬�����浽_szTemp��ʱ�����С�
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>	
	.while _iNum
		xor edx, edx
		mov eax, _iNum
		div _iTemp
		mov _iNum, eax
		.if dl < 10
			add dl, 48
		.else
			add dl, 55
		.endif
		mov BYTE PTR [ebx], dl
		inc ebx
		inc ecx
	.endw
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; ��һ��repeatѭ�������򱣴��ASCII��ת��Ϊ˳�򱣴��ASCII��
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	mov eax, para2
	mov BYTE PTR [eax+ecx], 0
	lea ebx, _szTemp
	.repeat
		mov dl, BYTE PTR [ebx]
		mov BYTE PTR [eax+ecx-1], dl
		inc ebx
	.untilcxz
	ret

_Translate endp
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
start:
	mov eax, 31A6F1h
	invoke _Translate, eax, offset szResult
	invoke MessageBox, NULL, offset szResult, offset szCaption, MB_OK
	invoke ExitProcess, 0
end start