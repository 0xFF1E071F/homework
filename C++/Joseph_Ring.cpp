//Josephus
//����:�ܲ�Ȩ ѧ��:09051109  �༶:09052311 
#include<iostream>
#include<cstdio>
using namespace std;

typedef struct LNode
{
	int num;   //��� 
	int code;  //���� 
	struct LNode *next;
}LNode;

struct LNode *head;     //ͷ��� 
struct LNode *tail;     //β�ڵ� 
struct LNode *p, *q;    //�����ڵ� 

int n;  //���� 
int m;  //�������� 

void create()
{
	cout << "Input the number of people: ";
	cin >> n;

    if(n < 1)  //�����쳣, �˳����� 
	{
        cout << "Number error!" << endl;
        system("pause");
		exit(1);   
    }

	cout << "Input the first code: ";
	cin >> m;
    
    if(1 == n)
    {
        getchar();  //����һ���س� 
        getchar();  //���������ַ� 
        cout << "1" << endl;
        system("pause");
        exit(0);    //�����˳����� 
    }
    
    //�� n >= 2 ʱ 
    
	head = new LNode;
	p = head;
	p -> num = 1;
	cin >> p -> code;  //�����һ������ 

	for(int i = 2; i <= n; i++)
	{
		q = new LNode;
		p -> next = q;
		q -> num = i;     //д���� 
		cin >> q -> code; //������������� 
		p = q;    //pָ���ѽ���������һ���ڵ� 
	}
	
	tail = p;
	tail -> next = head;    //����ѭ������ 
}

void run()
{
	p = tail;
	   
	while(n > 0)
	{
        int tmp = m % n;    //ʹѭ����ÿ���ڵ�������һ�� 
            
		for(int j = 1; j < tmp; j++)  //p��λ�ڳ����ߵ�ǰһ�� 
		{
			p = p -> next;
		}
		    
		q = p -> next;    //qָ�������
             
		cout << q -> num; //��������ߵı�� 
		n > 1 ? cout << ' ' : cout << endl;
		    
		m = q -> code;    //���±������� 
		p -> next = q -> next;    //pָ������ߵ���һ��
		    
		delete q; //ɾ�������߽ڵ� 
		n--;
	}
}

int main()
{
	create();
	run();
	system("pause");
	return 0;
}
