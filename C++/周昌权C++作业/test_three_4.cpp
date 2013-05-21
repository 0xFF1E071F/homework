#include<iostream>
#include<stdlib.h>

using namespace std;

class CFltArray
{
public:
    CFltArray(int sz);
    CFltArray(CFltArray &A);
    float& operator = (CFltArray A);
    float& operator [] (int i);
    void ReSize(int sz); 
    int GetSize();
    ~CFltArray();
    
private:
    int size;
    float *Arr;
};

//Ĭ�Ϲ��캯�� 
CFltArray::CFltArray(int sz)
{
    if(sz <= 0)
        exit(1);
    size = sz;
    Arr = new float[size];     
}

//�������� 
CFltArray::~CFltArray()
{
    delete [] Arr;
}

//��������Ĵ�С
void CFltArray::ReSize(int sz)
{
    size = sz;
    Arr = new float[size];        
}

//ͨ���±귵������Ԫ��
float& CFltArray::operator [](int i)
{
    if(i < 0 || i > size - 1)  
    {
        cout << "�����±�Խ��!" << endl; 
        exit(1);
    }
    return Arr[i];  
}

//���ص�ǰ����Ĵ�С
int CFltArray::GetSize()
{
    return size;    
}

CFltArray::CFltArray(CFltArray &A)
{
    size = A.GetSize();
    Arr = new float[size]; 
    
    float *ap = A.Arr;
    float *tp = Arr;
    
    for(int i = 0; i < size; i++)
        *tp++ = *ap++;   
        
    cout << "�������캯��������" << endl;
}

float& CFltArray::operator = (CFltArray A)
{
    size = A.size;
    Arr = new float[size];
      
    float *ap = A.Arr;
    float *tp = Arr;
      
    for(int i = 0; i<size; i++)
        tp[i] = ap[i];
    
    return Arr[size];
}

int main(void)
{
    CFltArray array(10); 
    for(int i = 0; i < 10; i++)
        array[i] = i;
    for(int i = 0; i < 10; i++)
        cout << array[i] << "  ";
    cout << endl;
    
    CFltArray Aarray = array;
    cout << "��ʼ���������С: " << Aarray.GetSize() << endl;
    cout << Aarray[8] << endl;
    
    array.ReSize(20);
    cout << "���ú������С: " << array.GetSize() << endl; 
    
    system("pause");
    return 0;    
}
