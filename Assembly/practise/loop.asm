.386
.model flat,stdcall

include		windows.inc
include		user32.inc		;����API����������MessageBox��
includelib	user32.lib
include		kernel32.inc
includelib	kernel32.lib

.code
start:
	mov ax, 0
	mov cx, 236
      s:add ax, 123
      	loop s	
end start