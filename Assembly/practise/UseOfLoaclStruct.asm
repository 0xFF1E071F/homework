;ʹ�þֲ��ṹ�����
APIcall	proc parameter1:DWORD, parameter2:DWORD, ppoi:DWORD
	
	mov eax, ppoi	;ppoi��ָ��POINT�ṹ�������ָ��
	mov [eax], BYTE PTR 10
	mov [eax+1], BYTE PTR 12
	ret

APIcall endp

APIcall	proc parameter1:DWORD, parameter2:DWORD, ppoi:DWORD
	
	mov eax, ppoi
	mov (POINT PTR [eax]).x, 10
	mov (POINT PTR [eax]).y, 12
	ret

APIcall endp