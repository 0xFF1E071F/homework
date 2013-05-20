//Greater commo divisor program.
#include<stdio.h>

//�����Լ���ĺ��� 
int gcd(int m,int n)    //m�Ǳ�����,n�ǳ���. 
{
    int r;
    
    while(n!=0)
    {
        r=m%n;      //r�������� 
        m=n;        //�����䱻���� 
        n=r;        //��������� 
    }    
    return m;
}

//����С������ 
int lcd(int m, int n)
{
    return m*n/gcd(m,n);    
} 

//������������ֵ 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;    
} 

int main(void)
{
    int x, y, g;
    
        printf("\nEnter two integers: ");
        scanf("%d%d",&x,&y);
        
        if(x < y)
            swap(&x,&y);
            
        printf("%d��%d�����Լ����: %d\n",x,y,gcd(x,y));
        printf("%d��%d����С��������: %d\n",x,y,lcd(x,y));
    
    system("pause");
    return 0;
}
