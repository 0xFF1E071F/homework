//Program to delete a substring in a string
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    void strdel(char *, char *);
    char cont;
    char str[50],sstr[10];
    int pos;
    do
    {
        fflush(stdin);
        printf("Enter any string: ");
        gets(str);
        printf("Enter any substring: ");
        gets(sstr);
        
        strdel(str, sstr);
        fflush(stdin);
        printf("Do you want to continue (y/n)\n");
        scanf("%c",&cont);
    }while( (cont=='Y') || (cont=='y'));
}

void strdel(char *os, char *ss)
{
    char *p;
    char ns[50];
    int k,l,i,f;
    l = strlen(ss);
    
    p = strstr(os, ss);//��������һ��ָ�룬��ָ���ַ���str2    
                        //�״γ������ַ���str1�е�λ�ã����û���ҵ�������NULL��
    
    if(p == NULL)
    {
        printf("Substring is not found (No Deletion)\n");
        return ;
    }
    else
    {
        k = p - os;
        f = 0;
        for(i = 0; i < k; i++)
        {
            ns[f] = os[i];
            f++;    
        }    
        for(i = (k + l); os[i] != '\0'; i++)
        {
            ns[f] = os[i];
            f++;
        }
    }
    ns[f] = '\0';
    printf("String after deleting the substring is ");
    puts(ns);
}                       
