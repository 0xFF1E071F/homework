#include<stdio.h>
#include<conio.h>
#include<math.h>
#define QUEENS 8

//��¼�����ŵ�ȫ�ֱ���
int iCount = 0;
int Site[QUEENS];

//�ݹ����ĺ���
void Queen();

//���һ����
void Output();

//�жϵ�n���ʺ����ȥ֮���Ƿ��г�ͻ
int IsValid(int n);

int main(){
	//�ӵ�0����ʼ�ݹ���̽ 
	Queen(0);
	return 0; 
}

//�ݹ���õ�n���ʺ�
void Queen(int n){
	int i;
	//������0��ʼ������8ʱ���Գ�һ���⣬�������������
	if(n == QUEENS){
		Output();
		return ;
	}
	
	//n��û�е�8���ڵ�n�еĸ�������������̽
	for(i = 1; i <= QUEENS; i++){
		//�ڸ��еĵ�i���Ϸ��ûʺ�
		Site[n] = i;
		if(IsValid(n)) 
			Queen(n + 1);
	} 
} 

//�жϵ�n���ʺ����ȥ֮���Ƿ��г�ͻ
int IsValid(int n){
	int i;
	//����n���ʺ��λ��������ǰ��n-1���ʺ��λ�ñȽ�
 	for(i = 0; i < n; i++){
	 	//�����ʺ���ͬһ���ϣ�����0
		if(Site[i] == Site[n]) 
			return 0;
		//�����ʺ���ͬһ�Խ����ϣ�����0
		if(abs(Site[i] - Site[n]) == n - i)
			return 0; 
 	}
 	//û�г�ͻ������1
	 return 1; 
}

//���һ���⣬��û�г�ͻ�ķ��÷���
void Output(){
	int i;
	//������ 
	printf("No.%-5d", ++iCount);
	//��������������ϵĻʺ��λ�ã������ڵ�����
	for(i = 0; i < QUEENS; i++)
		printf("%d ", Site[i]);
	printf("\n"); 
} 
