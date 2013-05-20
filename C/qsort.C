#include <stdlib.h> 
#include <stdio.h> 

// ���庯��ָ��
typedef int (*fcmp)(const void *, const void *);

// ����Ҫ�����в��ҵ����鼰Ԫ��

int array[] = {21, 5, 12, 68, 56, 43, 10}; 

/* �û��Լ�����ıȽϺ�����ת�����ͺ���Ϊlsearch�е�
   int (*fcmp)(const void *, const void *) ����*/

int numcmp (const int *p1, const int *p2) 
{ 
   int value;

   // �Ƚ�
   value = *p1-*p2;

   if (value==0)
	   return 0;
   else if (value<0)
	   return -1;
   else
	   return 1;

} 

int main(void) 
{ 
   int i;
  
   // �������ǰ������
   printf("Before sorted,the array is:\n");

   for (i=0;i<7;i++)
	   printf("%6d",array[i]);
   printf("\n");

   // ʹ��qsort��������
   qsort(array, 7, sizeof(int), (fcmp)(numcmp)); 

   
   // ��������Ľ��
   printf("After sorted,the array is:\n");

   for (i=0;i<7;i++)
	   printf("%6d",array[i]);

   printf("\n");

   system("pause");
   return 0; 

} 
