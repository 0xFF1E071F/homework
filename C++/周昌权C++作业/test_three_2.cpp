#include<iostream>
using namespace std;

class student
{
public:
	student();
	void data_Input();
	void data_Output();
	~student();
private:
	char name[20];
	int num;
	int age;
};

student::student()
{
    cout << "Ĭ�Ϲ��캯��ִ������" << endl;
    cout << "������ѧ����������ѧ�š����䣺"; 
	cin >> name >> num >> age;
}

void student::data_Input()
{
    cout << "��Ա����ִ������" << endl;
    cout << "������ѧ����������ѧ�š����䣺";
	cin >> name >> num >> age;
}

void student::data_Output()
{
    cout << "��Ա����ִ�����" << endl;
	cout << "Name: " << name << endl;
	cout << "Number: " << num << endl;
	cout << "Age: " << age << endl;
}

student::~student()
{
    cout << "��������ִ�����" << endl;
	cout << "Name: " << name << endl;
	cout << "Number: " << num << endl;
	cout << "Age: " << age << endl;
}

int main(void)
{
	student stud;
	
	stud.data_Input();
	
	stud.data_Output();
	
	return 0;
}
