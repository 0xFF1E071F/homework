//ת������
#include<iostream> 
using namespace std;

const double k = 0.000811;
const double I0 = 0.00408;
const double IBall = 40.85e-6;

int main()
{
    int x;//��ת����� ��λcm 
    double t;//���� ��λs 
    double IEx, ITh, per;
    while(cin >> x >> t)
    {
        IEx = 0.5 * (k * t * t - I0); //ʵ��ֵ 
        ITh = IBall + 0.2397 * x * x / 10000;   //����ֵ 
        per = (ITh - IEx) / ITh * 100;  //�ٷ���� 
        cout << IEx << endl;
        cout << ITh << endl;
        cout << per << "%" << endl;
    }
    return 0;
}
