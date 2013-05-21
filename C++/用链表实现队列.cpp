/******������ʵ�ֶ���.cpp******/
#include <iostream>
#include <string>
using namespace std;

class Information
{
private:
    string sInfoName;
    string sDate;   //����
public:
    Information(string sInfoName) //�Ӽ��̶�������Ϣ
    {
        this->sInfoName=sInfoName;
        cout<<"   �������� : ";
        cin>>sDate;
    }
    string Disp_Info() //��ʾ�ڵ�������Ϣ
    {
        return sDate;
    }
};

class Node
{
private:
    string sNodeName; //�ڵ��ʾ����
    Information INFO; //�ڵ�������Ϣ(Information) 
public:
    Node *NEXT;    //ָ����һ�ڵ�Ľڵ�ָ��(NEXT) 
    Node(string sNodeName,Node *NEXT=NULL):INFO(sNodeName)
    {
        this->sNodeName=sNodeName;
        this->NEXT=NEXT;
    }
    string Disp_Node() //��ʾ�ڵ�������Ϣ
    {
        return sNodeName;
    }
};
class QueClass    //����һ��QueClass��
{
private:
    Node *FRONT;   //����ͷ
    Node *REAR;    //����β
public:
    QueClass()    //���������
    {
        FRONT=NULL;
        REAR=NULL;
    }
    ~QueClass()    //���������
    {
        while(FRONT!=NULL)
        {
            FRONT=FRONT->NEXT;
            delete FRONT;
        }
    }
    void AddNode(string str); //���ӽڵ�
    void DeleNode();    //ɾ����ǰ�ڵ�
    void Traverse();
};
void QueClass::AddNode(string str)//���ӽڵ㵽����ͷ
{
    Node *n=new Node(str);
    if(FRONT==NULL)    //�������еĵ�һ���ڵ�
    {
        n->NEXT=NULL;
        FRONT=n;
        REAR=n;     //FRONT��REARָ��Ψһ��n
        return;     //��������,��������ִ��
    }
    else
    {
        REAR->NEXT=n;   //ԭREAR��NEXTָ��n
        REAR=n;     //n��Ϊ�µ�REAR
    }
}
void QueClass::DeleNode() //ɾ������ͷ�ڵ�
{
    if(FRONT==NULL)
    {
        cout << "\n   ���в�����!!! " << endl;
        return; 
    }
    Node *TEMP;
    TEMP=FRONT;
    FRONT=FRONT->NEXT;
    delete TEMP;
}
void QueClass::Traverse() //��������(������нڵ���Ϣ)
{
    if(FRONT==NULL)
    {
        cout << "\n   ���в�����!!! " << endl;
    }
    else
    {
        Node *TEMP;
        for(TEMP=FRONT;TEMP!=NULL;TEMP=TEMP->NEXT)
        {      //ѭ����ʾ���нڵ���Ϣ
            cout<<TEMP->Disp_Node()<<endl; //��ʾ�ڵ��ʾ
        }
    }
}
int main()      //������
{
    QueClass QueObj;
    string data;
    cout << "\n **************�����в�����************** "<< endl;
    char cCmd;
    do
    {
        cout << "\n   ����(A) ɾ��(D) ���(T) �˳�(E): ";
        cin >> cCmd;
        switch(cCmd)
        {
            case 'A':
            case 'a':
            {
                cout<<"\n   �������� : ";
                cin >> data;
                QueObj.AddNode(data);
                break;
            }
            case 'D':
            case 'd':
            {
                QueObj.DeleNode();
                break;
            }
            case 'T':
            case 't':
            {
                QueObj.Traverse();
                break;
            }
            case 'E':
            case 'e':
            {
                cout<<"\n *************��������ϡ�************* \n"; 
                break; 
            }
            default:
                cout << "\n   �������,����ѡ��˵� : \n";
        }
    }while(cCmd!='E' && cCmd!='e');
    return 0;
}
