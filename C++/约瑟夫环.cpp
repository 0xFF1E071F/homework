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

void create(struct LNode *tail, int n, int m)
{
    struct LNode *head;     //ͷ��� 
    struct LNode *p, *q;    //�����ڵ� 
    
    if(n < 1)  //�����쳣, �˳����� 
	{
        cout << "Number error!" << endl;
        system("pause");
		exit(1);   
    }
    
    if(1 == n)
    {
        cout << "1" << endl;
        system("pause");
        exit(0);
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

void run(struct LNode *p, int n, int m)
{
    struct LNode *q;
    
	for(int i = 1 ; i <= n; i++)
	{
		for(int j = 1; j < m; j++)  //p��λ�ڳ����ߵ�ǰһ�� 
		{
			p = p -> next;
		}
		    
		q = p -> next;    //qָ�������
             
		cout << q -> num; //��������ߵı�� 
		i < n ? cout << ' ' : cout << endl;
		    
		m = q -> code;    //���±������� 
		p -> next = q -> next;    //pָ������ߵ���һ��
		    
		delete q; //ɾ�������߽ڵ� 
	}
}

int main()
{
    struct LNode *tail;     //β�ڵ� 
    
    int n;  //���� 
    int m;  //�������� 
    
    cout << "Input the number of people: ";
	cin >> n;
    
    cout << "Input the first code: ";
	cin >> m;
    
    create(tail, n, m);
	run(tail, n, m);
	
	system("pause");
	return 0;
}
