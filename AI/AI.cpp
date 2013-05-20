#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

const int N = 4;//��Ⱥ��ģ
const int T = 100;//��󻻴���
const double Pc = 0.4;//������
const double Pm = 0.01;//������

int t;//���������� 

struct solution{
	int num;	//ʮ������ 
	char b[5];	//5λ������������Ⱦɫ��
	int f;		//��Ӧ�� 
	double p;	//ѡ�����
	double q;	//���۸��� 
}s[N], next[N]; 

//�����ַ� 
void swap(char *a, char *b){
	char c = *a;
	*a = *b;
	*b = c;
}

//ʮ����ת��Ϊ������ 
void DtoB(int n, char str[]){
	int tmp, i = 0;
	memset(str, '0', 5);
	while(n){
		tmp = n % 2;
		str[i] = (char)tmp;
		n /= 2;
		i++;
	}
	
	//��ת 
	swap(&str[0], &str[4]);
	swap(&str[1], &str[3]);
	/*
	char c;
	c = s[0];
	s[0] = s[4];
	s[4] = c;
	c = s[1];
	s[1] = s[3];
	s[3] = c; 
	*/
}

//���ɳ�ʼ��Ⱥ 
void init(){
	t = 1;
	srand((unsigned)time(0));
	
	for(int i = 0; i < N; i++){
		s[i].num = rand() % 32;
		DtoB(s[i].num, s[i].b);
		s[i].f = s[i].num * s[i].num;
	}
	
	int sumf = 0;//��Ӧ���ܺ� 
	for(int i = 0; i < N; i++)
		sumf += s[i].f;
	
	double sumq = 0.0;//���۸����ܺ� 
	for(int i = 0; i < N; i++){
		s[i].p = (double)s[i].f / sumf;
		sumq += s[i].p;
		s[i].q = sumq;
	} 
}

//����0~1֮�������� 
double randf() 
{ 
	return (double)(rand() % 1001) * 0.001; 
} 

//ѡ��-���� 
void SelectNCopy(){
	double r;
	struct solution tmp[N];
	for(int i = 0; i < N; i++){
		r = randf();
		if(r < s[0].q)
			tmp[i] = s[0];
		else{
			int j;
			for(j = 1; j < N; j++){
				if(r > s[j-1].q && r < s[j].q)
					break;
			}
			tmp[i] = s[j];
		}
	}
	for(int i = 0; i < N; i++)
		next[i] = tmp[i];
}

//���� 
void mate(){
	int a = 0, b = 0; 
	while(a == b){
		srand((unsigned)time(0));
		a = rand() % 4;
		b = rand() % 4;
	}
	int cb = rand() % 5;//������λ��
	char ctmp;
	for(int i = 0; i < cb; i++)	 {
	//	swap(&s[a].b[4 - i], &next[b].num[4 - i]);
 		ctmp = s[a].b[4 - i];
		next[a].b[4 - i] = next[b].b[4 - i];
 		next[b].b[4 - i] = ctmp;
	}
}

//���� 
void variate(){
	int bits = int(5 * Pm);
	if(bits < 1)
		return ;
	else{
		int tmp;
		srand((unsigned)time(0));
		for(int i = 0; i < N; i++){
			tmp = rand() % 5;
			if(next[i].b[tmp] == '0')
				next[i].b[tmp] = '1';
			else
				next[i].b[tmp] = '0';
		}
	}
	return ;
}

//������Ӧ�����Ľ� 
struct solution maxf(struct solution ss[]){
	struct solution temp = ss[0];
	for(int i = 1; i < N; i++)
		if(ss[i].f > temp.f)
			 temp = ss[i];
 	return temp;
}

//�������������� 
void evolve(){
	struct solution cm, nm;// cm����ǰ����Ӧ�����ֵ��nm��һ����Ӧ�����ֵ
	cm = maxf(s) ;
	nm = maxf(next);
	if(nm.f > cm.f)
		for(int i = 0; i < N; i++)
			s[i] = next[i];
}

//���Ŵ��㷨���� 
void solve(){
	int mt;//������� 
	while(t <= T){
		SelectNCopy();
	 	mt = (int)(5 * Pc) / 2;
	 	for(int i = 0; i < mt; i++)
			mate();
		//variate();
		evolve();
		t++;
	}
	struct solution max = s[0];
	for(int i = 0; i < N; i++)
		if(s[i].f > max.f)
			max = s[i];
	printf("��õĽ��ǣ�%d\n", max.num);
	return ;
}

int main(){
	init();
	solve(); 
	system("pause");
	return 0; 
}
