/*
ID:chaos-z1
LANG:C++
PROG:ride
*/
#include <fstream>
using namespace std;

unsigned long a=1,b=1; //�˷��ĳ�ʼ��ҪŪ��1  �мǲ���0

int main()
{
    ifstream fin("ride.in");
    char t=fin.get();
    do
    {
        a*=(t-64);
        t=fin.get();
    } while (t!='\n');  //�ж��н���
    t=fin.get();
    do
    {
        b*=(t-64);
        t=fin.get();
    } while (t!='\n');
    fin.close();
    //fin.get���Զ����з� ��'\n' do while���жϽṹ������ C++���ַ��������Բ�����ѧ����
    //����ASCII�����ʽ�� ���Լǵ�-64  ��A��ASCII����65��
   
    ofstream fout("ride.out");
    if ((a%47)==(b%47))  //�����Ⱥ� ��Ҫ�ٴ���
        fout<<"GO\n";
    else
        fout<<"STAY\n";
    fout.close();
    return 0;
}
