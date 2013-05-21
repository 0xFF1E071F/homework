/******������ʵ��ջ.cpp******/
#include <iostream>
#include <string>
using namespace std;

class Information
{
private:
    string sInfoName;
    string sDate;   //����
public:
    Information(string sInfoName)   //�Ӽ��̶�������Ϣ
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
class Stack     //����һ��Stack��
{
private:
    Node *TOP;    //ջ��
public:
    Stack()     //���������
    {
        TOP=NULL;
    }
    ~Stack()    //���������
    {
        while(TOP!=NULL)
        {
            TOP=TOP->NEXT;
            delete TOP;
        }
    }
    void Push(string str); //���ӽڵ�
    void Pop();     //ɾ����ǰ�ڵ�
    void Traverse();
};
void Stack::Push(string str)//���ӽڵ㵽ջ��
{
    Node *n=new Node(str);
    if(TOP==NULL)    //����ջ�ĵ�һ���ڵ�
    {
        n->NEXT=NULL;
        TOP=n;
        return;     //��������,��������ִ��
    }
    else
    {
        n->NEXT=TOP;
        TOP=n;
    }
}
void Stack::Pop()    //ɾ��ջ���ڵ�
{
    if(TOP==NULL)
    {
        cout << "\n   ջ������!!! " << endl;
        return; 
    }
    Node *TEMP;
    TEMP=TOP;
    TOP=TOP->NEXT;
    delete TEMP;
}
void Stack::Traverse()   //����ջ(������нڵ���Ϣ)
{
    if(TOP==NULL)
    {
        cout << "\n   ջ������!!! " << endl;
    }
    else
    {
        Node *TEMP;
        for(TEMP=TOP;TEMP!=NULL;TEMP=TEMP->NEXT)
        {      //ѭ����ʾ���нڵ���Ϣ
            cout<<TEMP->Disp_Node()<<endl; //��ʾ�ڵ��ʾ
        }
    }
}
int main()      //������
{
    Stack stObj;
    string data;
    cout << "\n **************��ջ������************** "<< endl;
    char cCmd;
    do
    {
        cout << "\n   ����(A) Ĩȥ(D) ���(T) �˳�(E): ";
        cin >> cCmd;
        switch(cCmd)
        {
            case 'A':
            case 'a':
            {
                cout<<"\n   �������� : ";
                cin >> data;
                stObj.Push(data);
                break;
            }
            case 'D':
            case 'd':
            {
                stObj.Pop();
                break;
            }
            case 'T':
            case 't':
            {
                stObj.Traverse();
                break;
                }
            case 'E':
            case 'e':
            {
                cout<<"\n *************��������ϡ�************* \n"; 
                break; 
            }
            default:
                cout << "\n   �������,����ѡ��˵� : ";
        }
    }while(cCmd!='E' && cCmd!='e');
    return 0;
}
