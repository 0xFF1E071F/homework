//��Ŀ: �����Ŵ��㷨�������[0, 31]�ϵĶ��κ���y = x*x�����ֵ
 
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

int N = 4;//��Ⱥ��ģ
int T = 100;//��󻻴���
double Pc = 0.4;//������
double Pm = 0.01;//������
int option = 0;

int t;//���������� 

bool flag = true;//����Ƿ��ǵ�һ�μ����� 

struct solution{
	int num;	//ʮ������ 
	char b[5];	//5λ������������Ⱦɫ��
	int f;		//��Ӧ�� 
	double p;	//ѡ�����
	double q;	//���۸��� 
}*s, *next;

void showCondition(){
	cout << "��Ⱥ��ģ: " << N << endl;
	cout << "��󻻴���: " << T << endl;
	cout << "������: " << Pc << endl;
	cout << "������: " << Pm << endl << endl;
	if(!flag)
		system("pause");
}

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
}

//���ɳ�ʼ��Ⱥ 
void init(){
	t = 1;
	srand((unsigned)time(0));
	if(flag){
		s = new struct solution[N];
		next = new struct solution[N];
		flag = false;
	}
	else{
		delete [] s;
		delete [] next;
	 	s = new struct solution[N];
		next = new struct solution[N];
	}
	
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
		a = rand() % N;
		b = rand() % N;
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
		variate();
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

// ����� 
void calculate(){
	init();
	solve();
}

void menu(){
	cout << "�����Ŵ��㷨�������[0, 31]�ϵĶ��κ���y = x*x�����ֵ\n" << endl;
	cout << "��ʼ״̬��" << endl;
	showCondition();
	
	cout << endl;
	while(true){
		cout << "1>>>������" << endl;
		cout << "2>>>������Ⱥ��ģ" << endl;
		cout << "3>>>������󻻴���" << endl;
		cout << "4>>>���ý�����" << endl;
		cout << "5>>>���ñ�����" << endl;
		cout << "6>>>��ʾ���ֲ���" << endl;
		cout << "0>>>�˳�����\n" << endl;
		
		cin >> option;
		
		switch(option){
			case 1:calculate();break;
			case 2:
					cout << "�������µ���Ⱥ��ģֵ�� ";
					cin >> N;break;
			case 3:
					cout << "�������µ���󻻴����� ";
					cin >> T;break;
			case 4:
					cout << "�������µĽ����ʣ� ";
					cin >> Pc;break;
			case 5:
					cout << "�������µı����ʣ� ";
					cin >> Pm;break;
			case 6:showCondition();break;
			case 0:exit(0);break;
			default:cout << "ѡ�����������ѡ��\n" << endl;break;
		}
	}
}

int main(){
	menu();
	return 0;
}
