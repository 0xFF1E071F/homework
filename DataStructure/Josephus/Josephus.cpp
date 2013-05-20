//Josephus
#include<iostream>
using namespace std;

typedef struct LNode
{
    int num;   //���
    int code; //����
    struct LNode *next;
}LNode;

void create(LNode *&tail, int m, int n)
{
    LNode *p, *q; //�����ڵ�
    LNode *head; //ͷ���
    if(n < 1) //�����쳣, �˳�����
    {
        cout << "Number error!" << endl;
        system("pause");
        exit(1);  
    }
   
    if(n == 1)
    {
        cout << "1" << endl;
        system("pause");
        exit(0);
    }

    //�� n >= 2 ʱ

    head = new LNode;
    p = head;
    p -> num = 1;
    cin >> p ->code; //�����һ������

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

void run(LNode *&tail, int m, int n)
{
    LNode *p, *q; //�����ڵ�
    p = tail;
   
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j < m; j++) //p��λ�ڳ����ߵ�ǰһ��
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
    LNode *tt; //β�ڵ�

    int m; //��������
    int n; //����

    cout << "Input the number of people: ";
    cin >> n;
   
    cout << "Input the first code: ";
    cin >> m;

    create(tt, m, n);
    run(tt, m, n);

    return 0;
}
