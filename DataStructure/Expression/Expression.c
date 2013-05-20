#include"Expression.h"

//�ж��Ƿ������
int isoperator(char optr)
{
    switch(optr)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return TRUE;
        default: return FALSE;
    }
}

//�ж��ַ�a������
void Judge(BiTree *E, char a)
{
    if(isdigit(a))	//a�ǳ���
    {
        (*E) -> data.tag = INT;
        (*E) -> data.num = a - '0';
    }
    else	//aΪ�ַ�
    {
        (*E) -> data.tag = CHAR;
        (*E) -> data.c = a;
    }
}

int ReadExpr(BiTree *E, char *expr)
{
    int i, len;		//lenΪexpr�ĳ���
    SqStack S;		//������ջ
    BiTree p, q;	//��������
     
    gets(expr);
    len = strlen(expr);
    //printf("len = %d\n", len);
    
    (*E) = (BiTree)malloc(sizeof(BiTNode));	//������ڵ�
    (*E) -> lchild = NULL;
    (*E) -> rchild = NULL;
    
    if(len == 1)	//���ʽ����Ϊ1ʱ
    {
        if(isdigit(expr[0]))
        {
            (*E) -> data.tag = INT;
            (*E) -> data.num = expr[0] - '0';
            return OK;
        }
        else if(isalpha(expr[0]))
        {
            (*E) -> data.tag = CHAR;
            (*E) -> data.c = expr[0];
            return OK;
        }
        else
        {
            printf("������ַ����������Ҳ���Ǳ�������������\n");
            return ERROR;
        }
    }
    else
    {
        Judge(E, expr[0]);
        InitStack(&S);//��ʼ��ջ
        q = (*E);
        
        Push(&S, q);//
        Push(&S, q);//�������ջ������Ϊ�ж���������ı��ʽ�ǲ�����ȷ�ı��ʽ
        
        for(i = 1; i < len && !StackEmpty(S); i++)
        {
            p = (BiTree)malloc(sizeof(BiTNode));
            Judge(&p, expr[i]);
            p -> lchild = NULL;
            p -> rchild = NULL;
            
            if(isoperator(expr[i])) //�������,�������ջ
            {
                if( !q -> lchild )	//���Ӳ���,������
                {
                    q -> lchild = p;
                    Push(&S, p);
                    q = p;
                }
                else				//�����Һ��Ӳ���,������
                {
                    q -> rchild = p;
                    Push(&S, p);
                    q = p;
                }
            }
            else	//���������,��ջ
            {
                if( !q -> lchild )
                {
                    q -> lchild = p;
                    Pop(&S, &q);
                }
                else
                {
                    q -> rchild = p;
                    Pop(&S, &q);
                } 
            }
        }//end for
        
        if(StackEmpty(S) && i >= len)
        {
            //printf("SM:%d  i:%d", StackEmpty(S), i);
            return OK;//���ʽΪǰ׺���ʽ
        }
        else
        {
            //printf("SM:%d  i:%d", StackEmpty(S), i);
            return ERROR; //����ǰ׺���ʽ
        }
    }
}

//��������ַ�����������Ƚ���������������ȼ���a��b���ȣ�����OK�����򷵻�ERROR
int PriCompare(char a, char b)
{
    if(isoperator(a) && isoperator(b))
    {
        if(a == '^')
        {
            if(b != '^')
                return OK;	//a�����ȼ���b��
            else
                return ERROR;
        }
        else if( a == '*' || a == '/')
        {
            if(b == '*' || b == '/' || b == '^')
                return ERROR;	
            else
                return OK;
        }
        else	//����a�����ȼ�����b��
            return ERROR;
    }
    else	//���������
        return ERROR;
}

//��������������׺���ʽ
void WriteExpr(BiTree E)
{
    if(E)//����Ϊ��
    {
		//�ȵݹ�������
        if(E -> lchild && E -> lchild -> data.tag == CHAR)//���Ӳ�����Ϊ�ַ�
		{
			if(PriCompare(E -> data.c, E -> lchild -> data.c))//E�����ȼ��������ӵĸ�
			{												  //������������ʽ
				printf("(");
				WriteExpr(E -> lchild);
				printf(")");
			}
			else//�����������������
				WriteExpr(E -> lchild);
		}
		else//������
			WriteExpr(E -> lchild);
		
		//���ʲ�������ڵ�
		if(E -> data.tag == INT)
		{
			printf("%d", E -> data.num);
		}
		else
		{
			printf("%c", E -> data.c);
		}

		//��ݹ�������
		if(E -> rchild && E -> rchild -> data.tag == CHAR)//�Һ��Ӳ�����Ϊ�ַ�
		{
			if(PriCompare(E -> data.c, E -> rchild -> data.c))//E�����ȼ������Һ��ӵĸ�
			{												 //������������ʽ
				printf("(");
				WriteExpr(E -> rchild);
				printf(")");
            }
			else//�����������������
				WriteExpr(E -> rchild);
		}
		else//���������
			WriteExpr(E -> rchild);
    }
}

//�Ա��ʽ�е����б���V�ĸ�ֵ������flagΪ��ʾ�Ƿ�ֵ���ı�־
void Assign(BiTree *E,char V,int c,int *flag)
{
	if(*E)
	{
		if((*E)->data.tag==CHAR&&(*E)->data.c==V)//����ҵ�Ҫ��ֵ�ı�������ֵ
		{
            (*E)->data.tag=INT;
            (*E)->data.num=c;
            *flag=1;
        }
		Assign(&((*E)->lchild),V,c,flag);//�ݹ�������
		Assign(&((*E)->rchild),V,c,flag);//�ݹ�������
	}
}
	
int powINT(int x, int exp)
{
    int i, result = 1;
    for(i = 1; i <= exp; i++)
        result *= i;
    return result;
}

int Operate(int a, char oprt, int b)
{
    switch(oprt)
    {
        case '+':return a + b;
        case '-':return a - b;
        case '*':return a * b;
        case '/':
            if(b != 0)
                return a / b;
            else
            {
                printf("��������Ϊ0\n");
                break;
            }
        case '^':return powINT(a, b);
        default:break;
    }
}

//����Ƿ���û��ֵ�ı��� 
int Check(BiTree E)
{
    if(E && E -> data.tag == CHAR)//��������Ϊ���Ϊ�ַ� 
    {
        if(isalpha(E -> data.c)) 
            return ERROR; 
            
        Check(E -> lchild);
        Check(E -> rchild);
        return OK;
    }
}

int Value(BiTree E)
{
    if(E)
    {
        //�������Һ��ӿ�, ��Ҷ�ӽ��, ������ֵ 
        if(!E -> lchild && !E -> rchild && E -> data.tag == INT)
            return E -> data.num;
        
        //�Ժ���������������ʽ��ֵ
        return Operate(Value(E -> lchild), E -> data.c, Value(E -> rchild));
    }
}

void CompoundExpr(char P, BiTree *E1, BiTree E2)
{
    BiTree E;
    E = (BiTree)malloc(sizeof(BiTNode));
    E -> data.tag = CHAR;
    E -> data.c = P;
    E -> lchild = *E1;
    E -> rchild = E2;
    (*E1) = E;
    printf("\n���ʽE���ϳɹ�������ʽ��Ϊ��\n");
    WriteExpr(E);
}

//���ѡ��˵�
int menu()
{
    printf("1.����ǰ׺���ʽ\n");
    printf("2.������ʽ����׺��ʾʽ\n"); 
    printf("3.�Ա�����ֵ\n");
    printf("4.������ʽ��ֵ\n");
    printf("5.����һ���µĸ��ϱ��ʽ\n");
    printf("0.�˳�\n\n");
    printf("���������ѡ��: "); 
    int choice = -1;
    scanf("%d%*c", &choice);
    return choice;
}

int main()
{
    BiTree E,newE;  //������ 
    char EXPR[81];  //ǰ׺���ʽ 
    int flag = ERROR, flag2 = ERROR;   //��Ǳ��ʽ�Ƿ�ֵ�ɹ�, OKΪ�ɹ�, ERRORΪʧ��
    char V; //Ҫ��ֵ�ı��� 
    char P; //�ϲ��Ĳ����� 
    while(1)
    {
        switch(menu())
        {
            case 1:
         	  	do{
                    printf("��������ȷ��ǰ׺���ʽ: ");
                    flag = ReadExpr(&E, EXPR);
                    if(flag == OK)
                        printf("���ʽ����ɹ�.\n\n");
                    else
                    {
                        printf("���ʽ����ʧ��.\n");
                        printf("��������ȷ��ǰ׺���ʽ: ");
                    }
                }while(flag == ERROR);
                if(flag == OK)
                {
                    printf("ǰ׺���ʽ����׺��ʾʽΪ�� ");
                    WriteExpr(E);
                    printf("\n\n");
                }
                break;
            case 2:
                if(flag == OK) 
                {
                    printf("ǰ׺���ʽ����׺��ʾʽΪ�� ");
                    WriteExpr(E);
                    printf("\n");
                }
                else
                    printf("���ʽ��û�й���, ���ȹ�����ʽ.\n");
                break;
            case 3:
                if(flag == OK)
                {
                    int Assign_tag = ERROR;//�Ƿ�ֵ�ɹ��ı�� 
                    char ch;//����Ҫ��ֵ�ı��� 
                    int n;//����Ҫ����ֵ 
                    printf("������Ҫ��ֵ�ı�����: "); 
                    ch = getchar();
                    printf("\nҪ��ֵΪ: "); 
                    scanf("%d", &n);
                    Assign(&E, ch, n, &Assign_tag);
                    if(Assign_tag == OK)
                    {
                        printf("��ֵ�ɹ�!\n");
                        printf("��ֵ����ʽΪ��");
                        WriteExpr(E);
                        printf("\n");
                    }
                    else
                        printf("���ʽ��û�� %c �������!\n", ch);
                }
                else
                    printf("���ʽ��û�й���, ���ȹ�����ʽ.\n");
                break;
            case 4:
                if(flag == OK)
                {
                    int chk = ERROR;
                    chk = Check(E);
                    if(chk == OK)//�����ʽ���Ƿ���δ��ֵ�ı��� 
                    {
                        WriteExpr(E);
                        printf("=%d\n", Value(E));
                    }
                    else
                    {
                        printf("���ʽ�ﻹ��δ��ֵ������\n\n");
                    } 
                }
                break;
            case 5:
                if(flag == OK)
                {
                    do{
                        printf("�������µı��ʽ: ");
                        
                        flag2 = ReadExpr(&newE, EXPR);
                        
                        if(flag2)
                            printf("���ʽ2����ɹ�.\n");
                        else
                        {
                            printf("���ʽ2����ʧ��.\n");
                            printf("��������ȷ��ǰ׺���ʽ.\n");
                        }
                    }while(flag2 == ERROR);
                    
                    printf("ǰ׺���ʽ2����׺��ʾʽΪ�� ");
                    WriteExpr(newE);
                    printf("\n\n");
                    
                    do{
                        printf("�����������: ");
                        P = getchar();
                    }while(!isoperator(P));
                     
                    CompoundExpr(P, &E, newE);
                    
                    printf("���ϵ�ǰ׺���ʽ����׺��ʾʽΪ�� ");
                    WriteExpr(E);
                    printf("\n\n");
                }
                break;
            case 0:
                printf("\n�밴������˳���\n");
                getch();
                exit(0);
            default:
                printf("\n���������밴������ص����˵�����ѡ��\n");
				getch();
                break;
        }
    }
}
