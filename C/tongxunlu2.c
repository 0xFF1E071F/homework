#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>

struct person
{
    char name[10];
    char mobile[20];
    char fixtelephone[10];
    char Email[20];
    char street[20];
 }person[10];

int k=0;

void print()
{
    int i;
    char ch[20];
    do{
        printf(" ���:\n����        �绰                �̻�         �ʼ�                ��ַ\n");
        for(i=0;i<k;i++)
        {
            printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
            printf("\n");
        }
        printf("�������˵�����Y/N��");scanf("%s",ch);
    }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}


void creat()
{
    char ch[20];

    printf("\n������Ϣ:\n");
    do
    {
        printf("\n����: ");
        scanf("%s",person[k].name);
        printf("�绰: ");
        scanf("%s",person[k].mobile);
        printf("\n�̶��绰: ");
        scanf("%ls",person[k].fixtelephone);
        printf("\n�����ʼ�: ");
        scanf("%s",person[k].Email);
        printf("\nסַ: ");
        scanf("%s",person[k].street);
            k++;
        printf("\n����������Ϣ��(y/n): ");
        scanf("%s",ch);
   }while(strcmp(ch,"y")==0||strcmp(ch,"Y")==0);
  print();
}

void del()
{
    int i,j;
    char c[20];
    printf("\n������Ҫɾ�������� ��\n");
    printf("���֣�");
    scanf("%s",&c);
    for(i=0;i<k;i++)
        if(strcmp(c,person[i].name)==0)
            {
                for(j=i;j<=2;j++)
                    person[j]=person[j+1];
                printf("\t\t\t��ɹ�ɾ���ˣ� %s\n",c);
                k--;
        }
        else 
            printf("");

    print();
}



void look_1()
{
    int i;
    char a[20],ch[10];
    printf("\n��������鿴�˵�����:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
        if(strcmp(person[i].name,a)==0)
            do{
                printf(" ���:\n����        �绰                �̻�         �ʼ�                ��ַ\n");
                printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
                printf("\n");
                printf("������һ������Y/N��");scanf("%s",ch);
   }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}



void look_2()
{
    int i;
    char a[20],ch[10];
    printf("\n��������鿴�ĺ���:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
        if(strcmp(person[i].mobile,a)==0)
        do{
            printf(" ���:\n����        �绰                �̻�         �ʼ�                ��ַ\n");
            printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
            printf("\n");
            printf("������һ������Y/N��");scanf("%s",ch);
        }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}
          
void look_3()
{
    int i;
    char a[20],ch[10];
    printf("\n��������鿴�̻�:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
        if(strcmp(person[i].fixtelephone,a)==0)
        do{
            printf(" ���:\n����        �绰                �̻�         �ʼ�                ��ַ\n");
            printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
            printf("\n");
            printf("������һ������Y/N��");scanf("%s",ch);
        }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}



void look_4()
{
    int i;
    char a[20],ch[10];
    printf("\n��������鿴��Email:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
        if(strcmp(person[i].Email,a)==0)
            do{
                printf(" ���:\n����        �绰                �̻�         �ʼ�                ��ַ\n");
                printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
                printf("\n");
                printf("������һ������Y/N��");scanf("%s",ch);
            }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}

void look_5()
{
    int i;
    char a[20],ch[10];
    printf("\n��������鿴��סַ:");
    scanf("%s",a);
    for(i=0;i<k;i++)  
    if(strcmp(person[i].street,a)==0)
        do{
            printf(" ���:\n����        �绰                �̻�         �ʼ�                ��ַ\n");
            printf("%-10s %-20s %-10s %-20s %-20s ",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
            printf("\n");
            printf("������һ������Y/N��");scanf("%s",ch);
        }while(strcmp(ch,"n")==0||strcmp(ch,"N")==0);
}

void look()
 { 
    int a;

    do{
        printf("\n\n");
        printf("                      1.��������ѯ\n\n\n");
        printf("                          2.���绰��ѯ\n\n\n") ;
        printf("                              3.���չ̻���ѯ\n\n\n");
        printf("                                  4.����Email��ѯ\n\n\n") ;
        printf("                                      5.����ַ��ѯ\n\n\n");
        printf("                                          6.�������˵�\n\n\n") ;
        printf("     ---------------------------------------------------------------------\n\n\n");
        
        printf(" �������ѡ��1-6 : ");
        scanf("%d",&a);
        switch(a){
                case 1:printf("\n");look_1();break;
                case 2:printf("\n");look_2();break;
                case 3:printf("\n");look_3();break;
                case 4:printf("\n");look_4();break;
                case 5:printf("\n");look_5();break;
                case 6:printf("\n");a=0;break;
                default:printf("\nֻ��ѡ��1-6��\n");
                }
    }while (a!=0);
}

void load()
{
    int i;
    FILE *fp;
    fp=fopen("d:\\xinxi.txt","r");
        if(fp==NULL)
        { 
            printf("���ܶ�ȡ�ļ�.\n");
            exit(0);
        }
    for(i=0;fread(&person[i],sizeof(struct person),1,fp)!=0;i++)
    {
        fscanf(fp,"%s %s %s %s %s\n",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);

        fprintf(fp,"%s %s %s %s %s\n",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street); }  /*����ʽ�����¼*/
        fclose(fp);
    }     /*�ر��ļ�*/

void save()   
{  
    FILE *fp; int i;
    if((fp=fopen("xinxi.txt","w"))==NULL)
    { 
        printf("���ܶ�ȡ�ļ�.\n");
        exit(0);
    }
    for(i=0;strlen(person[i].name)!=0;i++)
    fprintf(fp,"%s %s %s %s %s\n",person[i].name,person[i].mobile,person[i].fixtelephone,person[i].Email,person[i].street);
    fclose(fp);
}
int main()
{
    int a,b;
    printf("\n\n\n\n\n");
    printf("      ******************************************************************\n");
    printf("      *");printf("                      ��ӭʹ��ͨѶ¼����ϵͳ                 *\n\n");
    printf("      *");printf("                      ѧԺ������ѧԺ                         *\n\n");
    printf("      *");printf("                      רҵ����������                         *\n\n");
    printf("      *");printf("                      �����ˣ��ն�ƽ                         *\n\n");
    printf("      *");printf("                      ѧ�ţ�3109004331                       *\n\n");
    printf("      ******************************************************************\n");
    printf("\n\n                                  �������˵���1��\n");
    printf("                                      �˳���0��\n");
    scanf("%d",&b);
      
    if(b==0)
        exit(0);
    else
        do{
            printf("\n\n\n     --------------------------------------------------------------------\n");
            printf("           ");      
            printf("\t                  ����ͨѶ¼");  
            printf("\t\t");
            printf("\n      --------------------------------------------------------------------- \n");  
            printf("             ");       printf("\t                 1.��������");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 2.������Ϣ");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 3.��ʾ��Ϣ");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 4.��ѯ��Ϣ");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 5.ɾ����Ϣ");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 6.��������");        printf("\t\t\t\t\n\n");
            printf("             ");       printf("\t                 7.  �˳�  ");        printf("\t\t\t\t\n\n");
            printf("     ---------------------------------------------------------------------\n");
    
            printf(" �������ѡ��1-7 : \n\n\n");
            scanf("%d",&a);
   
            switch(a){
                case 1:printf("\n");load();break;
                case 2:printf("\n");creat();break;
                case 3:printf("\n");print();break;
                case 4:printf("\n");look();break;
                case 5:printf("\n");del();break;
                case 6:printf("\n");save();break;
                case 7:printf("\n");exit(0);break;
                default:printf("\nֻ��ѡ��1-7��\n");
            }
   }while(a!=0);
   return 0;
}
