#include<iostream>
using namespace std;
int main(void)
{
    int i(1),sum(0);    //��ʼ�� 
    while(i<=10)
    {
        sum+=i;
        i++  ;  
    }    
    cout<<"sum="<<sum<<endl;
    system("pause");
    return 0;
}
