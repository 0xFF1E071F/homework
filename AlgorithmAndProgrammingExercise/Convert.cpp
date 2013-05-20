// ��3.����ת��
 
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int menu(){
	int n;
	printf("��ӭʹ�ý���ת������\n");
	printf("	1. ʮ����\n");
	printf("	2. ������\n");
	printf("	3. �˽���\n");
	printf("	4. ʮ������\n");
	printf("	0. �˳�\n");
	printf("��ѡ���������ݵĽ��ƣ�\n");
	while(true){
		scanf("%d", &n);
		switch(n){
			case 1:printf("��ѡ������ʮ�������ݣ�\n");
				return 10;
			case 2:printf("��ѡ��������������ݣ�\n");
				return 2;
			case 3:printf("��ѡ������˽������ݣ�\n");
				return 8;
			case 4:printf("��ѡ������ʮ���������ݣ�\n");
				return 16;
			case 0:printf("�˳���\n");
				return 0;	
			default:printf("ѡ������������ѡ��"); 
		}
	}
}

//��r���Ƶ���ת����ʮ����
int RtoD(int r, char *n){
	int res = 0, tmp, base = 1, len;
	len = strlen(n) - 1;
	while(len >= 0){
		if(isdigit(n[len]))
			tmp = n[len] - '0';
		else if(islower(n[len]))
			tmp = n[len] - 'a' + 10;
		else
			tmp = n[len] - 'A' + 10;
		res += tmp * base;
		base *= r;
		len--;
	}
	return res;
}

//ʮ����ת���ɶ�Ӧ��r����
void DtoR(int n,int r)
{
    if(n)
    {
        DtoR(n/r,r);
        printf("%X", n%r);
    }    
}

void print(int n){
	printf("ʮ���ƣ�%d\n", n);
	printf("�����ƣ�");
	DtoR(n, 2);
	printf("\n");
	printf("�˽��ƣ�");
	DtoR(n, 8);
	printf("\n");
	printf("ʮ�����ƣ�");
	DtoR(n, 16);
	printf("\n");
}

//�ж����Ƿ�Ϸ�
int judge(char *s, int n){
	int i, r = n - 1, tmp;
	for(i = 0; s[i] != '\0'; i++){
		if(isdigit(s[i]))
			tmp = s[i] - '0';
		else if(islower(s[i]))
			tmp = s[i] - 'a' + 10;
		else if(isupper(s[i])) 
			tmp = s[i] - 'A' + 10;
		else
			return 0;
		if(tmp > r)
			return 0;
	}
	return 1;
}

int main(){
	int N, num;
	char str[1000];
	while(N = menu(), N) {
		scanf("%s", str);
		if(!judge(str, N)){
			printf("���������������������룡\n");
			continue;
		}
		num = RtoD(N, str);
		print(num);
	}
	return 0;
} 
