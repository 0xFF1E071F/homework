#include <stdio.h>          //ʹ�ö�̬����,ʵ��Fibonacci����. 
#include <stdlib.h>         //������Ϊa[n]=a[n-1]+a[n-2],����a[0]=a[1]=1. 

int main(void)
{
    int i,num;
    long *f,*tmp;
    
    printf("������Fibonacci���еĸ���: ");
    scanf("%d",&num);
    printf("\n");
    
    f=(long*)calloc(num,sizeof(int));
    if(f==NULL)
    {
        printf("û���ڴ���Է���!\n");
        return 0;
    }    
    
    f[0]=f[1]=1;            //����д�� *f=*(f+1)=0. 
    
    for(i=2;i<num;i++)
        f[i]=f[i-1]+f[i-2];         //����д��*(f+i)=*(f+i-1)+*(f+i-2) 
    
    for(tmp=f;tmp<f+num;tmp++)           //tmp++ʹtmpָ����һ����Ԫ, 
        if((tmp-f+1)%5!=0)               //��������һ���ֽ�,��Ϊtmpָ��� 
            printf("%10ld",*tmp);        //��Ԫ������long��. 
        else
            printf("\n");
    
    free(f);
    system("pause"); 
    return 0;    
}
