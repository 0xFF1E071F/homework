#include<iostream>
using namespace std;

const double PI = 3.14159;

class Circle         
{
public:
	Circle(double r);
	double Circumference();
	double Area();
	friend double fCircle_L(Circle &rr);
	friend double fCircle_S(Circle &rr);
private:
	double radius;
};

Circle::Circle(double r)
{
	radius = r;
}

//��Ա���������ܳ� 
double Circle::Circumference()
{
    cout << "��Ա����������" << endl;
	return 2 * PI * radius;
}

//��Ա����������� 
double Circle::Area()
{
    cout << "��Ա����������" << endl;
	return PI * radius *radius;
}

//��Ԫ�������ܳ� 
double fCircle_L(Circle &r)
{
    cout << "��Ԫ����������" << endl;
	double L = 2 * PI * r.radius;
    return L;    
}

//��Ԫ��������� 
double fCircle_S(Circle &r)
{
    cout << "��Ԫ����������" << endl;
	double S = PI * r.radius * r.radius;
    return S;
}

int main(void)
{
	double R;
	cout << "������뾶: "; 
	while(cin >> R)
	{
		Circle C(R);
		
		cout << C.Circumference() << endl;
		cout << C.Area() << endl;
		
		cout << fCircle_L(C) << endl;
		cout << fCircle_S(C) << endl;
		
		cout << "\n\n������뾶: "; 
	}
	return 0;
}
