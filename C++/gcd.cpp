//Greater commo divisor program.
#include<iostream>
#include<assert.h>
#include<algorithm>

using namespace std;

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

int main(void)
{
    int x, y, g;
    
    cout << "\nPROGRAM Gcd C++";
    do{
        cout << "\nEnter two integers: ";
        cin >> x >> y;
        assert(x * y != 0);     //precondition on gcd
        if(x < y)
            swap(x,y);
        cout << "\nGCD(" << x <<", " << y << ") = "
             << (g = gcd(x, y)) << endl;
        assert(x % g == 0 && y % g == 0);    
    } while(x != y);
    
    system("pause");
    return 0;
}
