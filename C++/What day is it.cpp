//��ĳ�������ڼ� 

#include<cstdio>
using namespace std;

char *name[] = { "Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday", "Sunday" }; 

int main()
{
    int d, m, y, a;
    printf("Day: ");scanf("%d",&d);
    printf("Month: ");scanf("%d",&m);
    printf("Year: ");scanf("%d",&y);
    //1��2�µ���ǰһ���13,14��
    if(m == 1 || m ==2 ) 
    {
        m +=12;
        y--;    
    }
    //�ж��Ƿ���1752��9��3��֮ǰ
    if( ( y < 1752 ) || ( y == 1752 && m < 9 ) ||
        ( y == 1752 && m == 9 && d < 3 ) )
    {
        a = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 + 5) % 7;    
    }
    else
    {
        a = (d + 2 * m + 3 * (m + 1) / 5+ y + y / 4 - y / 100 + y / 400) % 7;
    }
    printf("It is a %s\n", name[a]);
    system("pause");
    return 0;
}
