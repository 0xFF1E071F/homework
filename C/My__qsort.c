//�Լ�д�Ŀ���,,���� 
#include<stdio.h>
#include<stdlib.h>

int cmp(const int *p1, const int *p2)   //�ȽϺ��� 
{
    int value;    
    value = *p1 - *p2;
    if(!value)
        return 0;
    else
        return value;
}

int main(void)
{
    int *p, i, n;
    printf("Input n numbers: ");
    scanf("%d",&n); 
    
    //���붯̬�ڴ� 
    p = (int*)calloc(n, sizeof(int));  
    
    if(p==NULL)
    {
        printf("ERROR\n");
        exit(1);
    }
    
    for(i=0;i<n;i++)
        scanf("%d",p+i);
        
    // ʹ��qsort��������
    qsort(p, n, sizeof(int), cmp);

    // ��������Ľ��
    printf("After sorted,the array is:\n");    

    for(i=0;i<n;i++)
        printf("%d%c",*(p+i),i<n-1?' ':'\n');
    
    printf("\n"); 
    
    free(p); 
    
    system("pause");           
    
    return 0;
}
