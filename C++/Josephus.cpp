//Josephus
//����: �ܲ�Ȩ  ѧ��: 09051109  �༶: 09051109   
#include<iostream>
#include<cstdio>
using namespace std;

typedef struct LNode
{
    int num;
    int code;
    struct LNode *next;
}LNode;

struct LNode *tail;		//β���
struct LNode *head;		//ͷ���
struct LNode *p, *q;	//�������

int n;	//����
int m;  //��������

//�������� 
void create()
{
	cout << "Input the number of people: ";
    cin >> n;

	cout << "Input the first code: ";
	cin >> m;
    
	if(n < 1)	//������ֵ�쳣
		exit(1);//�˳�����

	head = new LNode;
	p = head;

    for(int i = 1; i < n; i++)
    {
        q = new LNode;
        p -> next = q;
		p = q;
    }

	tail = q;
	tail -> next = head;	//����ѭ������
	
    p = head;
	for(int i = 1; i <= n; i++)
	{
        p -> num = i;
        cin >> p -> code;	//��������
        p = p -> next;
    }
}

void run()
{
    p = tail;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			p = p -> next;
		}
		q = p -> next;
		m = q -> code;
		cout << q -> num; //��������ߵı�� 
        i < n ? cout << ' ' : cout << endl;
		p -> next = q -> next;	//pָ������ߵ���һ����

		delete q;
	}
}

int main(void)
{
	create();
	run();
	system("pause");
	return 0;
}