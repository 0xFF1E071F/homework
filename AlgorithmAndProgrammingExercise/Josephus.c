//��7. Լɪ������

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int num;   //��� 
	int code;  //���� 
	struct LNode *next;
}LNode;

void Josephus(struct LNode *tail, int n, int m)
{
    struct LNode *head;     //ͷ��� 
    struct LNode *p, *q;    //�����ڵ� 
    int i, j;
    if(n < 1)  //�����쳣, �˳����� 
	{
        printf("Number error!\n");
		exit(1);   
    }
    
    if(1 == n)
    {
        printf("1\n");
        exit(0);
    }
    
    //�� n >= 2 ʱ 
    
	head = (LNode *)malloc(sizeof(LNode));
	p = head;
	p -> num = 1;
	scanf("%d", &(p -> code));  //�����һ������ 

	for(i = 2; i <= n; i++)
	{
		q = (LNode *)malloc(sizeof(LNode));
		p -> next = q;
		q -> num = i;     //д���� 
		scanf("%d", &(q -> code)); //������������� 
		p = q;    //pָ���ѽ���������һ���ڵ� 
	}
	
	tail = p;
	tail -> next = head;    //����ѭ������ 
	
	p = tail;
	   
	for(i = 1 ; i <= n; i++)
	{
		for(j = 1; j < m; j++)  //p��λ�ڳ����ߵ�ǰһ�� 
		{
			p = p -> next;
		}
		    
		q = p -> next;    //qָ�������
             
		printf("%d", q -> num); //��������ߵı�� 
		printf("%c", i < n ? ' ' : '\n');
		    
		m = q -> code;    //���±������� 
		p -> next = q -> next;    //pָ������ߵ���һ��
		    
		free(q); //ɾ�������߽ڵ� 
	}
}

int main()
{
    struct LNode *tail;     //β�ڵ� 
    
    int n;  //���� 
    int m;  //�������� 
    
    printf("Input the number of people: ");
	scanf("%d", &n);
    
    printf("Input the first code: ");
	scanf("%d", &m);
    
    Josephus(tail, n, m);
	
	return 0;
}
