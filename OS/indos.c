/* indos.c -- Functions to manage DOS flags */
#include<stdlib.h>
#include<dos.h>

#define GET_INDOS 0x34
#define GET_CRIT_ERR 0x5d06

char far *indos_ptr = 0;	/* ��ָ��������INDOS��־�ĵ�ַ */
char far *crit_err_ptr = 0;	/* ��ָ�����������ش����־�ĵ�ַ */

void InitDos(void);
int DosBusy(void);

/* InitDos()�����������ǻ��INDOS��־��ַ�����ش����־�ĵ�ַ */
void InitDos(void)
{
	union REGS regs;
	struct SREGS segregs;
	
	/* ���INDOS��־�ĵ�ַ */
	regs.h.ah = GET_INDOS;
	/* intdosx(): Turbo C�Ŀ⺯�����书���ǵ���DOS��INT21H�ж� */
	intdosx(&regs, &regs, &segregs);
	/* MK_FP(): ����һ��������ֻ��һ���� */
	/* �书�������λ�ַ����ƫ�Ƶ�ַ�����㣬Ҳ����ȡʵ�ʵ�ַ�� */
	indos_ptr = MK_FP(segregs.es, regs.x.bx);
	
	/* ������ش����־�ĵ�ַ */
	/* �������õ���_osmajor��_osminor��Turbo C��ȫ�̱����� ����ǰ��ΪDOS�汾�ŵ���Ҫ���֣�����Ϊ�汾�ŵĴ�Ҫ���֡� */
	if(_osmajor < 3)
		crit_err_ptr = indos_ptr + 1;
	else if(_osmajor == 3 && _osminor == 0)
		crit_err_ptr = indos_ptr - 1;
	else
	{
		regs.x.ax = GET_CRIT_ERR;
		indosx(&regs, &regs, &segregs);
		crit_err_ptr = MK_FP(segregs.ds, regs.x.si);
	}
}

/* DosBusy(): ���������ǻ��Indos��־�����ش����־��ֵ���ж��Ƿ�dosæ�� */
/* �������ֵ��1����ʾdosæ�� */
/* �������ֵ��0����ʾdos��æ�� */
/* �������ֵ��-1����ʾ��û�е���InitDos() */
int DosBusy(void)
{
	if(indos_ptr && crit_err_ptr)
		return (*indos_ptr || *crit_err_ptr);
	else
		return -1;	/* InitDos() hasn't been called */
}