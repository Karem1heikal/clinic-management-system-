#include <iostream>
#include "patientClass.h"
using namespace std;

int linkList::GetCounter()
{
    return counter;
}
Node * linkList::SearchPatient_ID(int item_id)
{
    Node *ptr = Head;
    while(ptr!=NULL){
        if((ptr->data.id == item_id))
        {
            return ptr;
        }
        ptr=ptr->Next;
    }
    return NULL;
}
void linkList::show_one_patient(Node *Patient_Info)
{
    Node *ptr=Patient_Info;
    cout<<"************************************************\n";
    cout<<"ID : ";
    cout<< ptr->data.id<<endl;
    cout<<"NAME : ";
    cout<< ptr->data.name<<endl;
    cout<<"Age : ";
    cout<< ptr->data.age<<endl;
    cout<<"gender : ";
    cout<< ptr->data.gender<<endl;
    cout<<"************************************************\n";
}
void linkList::DeleteEnd()
{
     if(Head == NULL)
    {
        cout<<"Empty !!\n";
    }
    else if (counter == 1)
    {
        Node * copyPtr =  Head;
        Head = NULL;
        delete copyPtr;
        counter--;
    }
    else if(counter >1)
    {
        Node * ptr =  Head;
        for(int i=0;i<counter-2;i++)
        {
            ptr= ptr->Next;
        }
        Node *CopyPtr=ptr->Next;
        ptr->Next = NULL;
        delete CopyPtr;
        counter--;
    }
    else
    {
        cout << "Error out!! \n" ;
    }
}
bool linkList::AddtoEnd(data_patient val)
{
    if(Head == NULL)
    {
        Head = new Node;
        Head->data.id = val.id;
        Head->data.age = val.age;
        Head->data.name = val.name;
        Head->data.gender = val.gender;
        Head->Next = NULL;
    }
    else
    {
        Node *current = Head;
        Node * NewNode = new Node;
        while (current->Next != NULL)
        {
            current = current->Next;
        }
        current ->Next =NewNode ;
        NewNode->data.id = val.id;
        NewNode->data.age = val.age;
        NewNode->data.name = val.name;
        NewNode->data.gender = val.gender;
        NewNode->Next = NULL;
    }
    counter++ ;
    return 0;
}
bool linkList::AddtoFirst(data_patient val)
{
    Node *NewNode = new Node;
    NewNode->data.id = val.id;
    NewNode->data.age = val.age;
    NewNode->data.name = val.name;
    NewNode->data.gender = val.gender;
    NewNode->Next=Head;
    Head=NewNode;
    counter++;
    return 0;
}
void linkList::DeleteFirst()
{
     if(Head == NULL)
    {
        cout<<"Empty !!\n";
    }
    else if (counter == 1)
    {
        Node * copyPtr =  Head;
        Head = NULL;
        delete copyPtr;
        counter--;
    }
    else if (counter >1)
    {
        Node *copyPtr1 = Head;
        Head = Head->Next;
        delete copyPtr1;
        counter--;
    }
}
void linkList::DeletePos(int pos)
{
    if(pos == 1 )
    {
        DeleteFirst();
    }
    else if(pos == counter)
    {
        DeleteEnd();
    }
    else if(pos<counter)
    {
        Node *ptr = Head;
        for(int i=0;i<pos-1;i++)
        {
            ptr=ptr->Next;
        }
        Node *CopyPtr=ptr->Next;
        ptr->Next = ptr->Next->Next;
        delete CopyPtr;
        counter--;
    }
    else if(pos > counter)
    {
        cout<<"Out of Range!!\n";
    }
}
void linkList::InsertInPos(int pos,data_patient val)
{
    if(pos == NULL )
    {
        AddtoFirst(val);
    }
    else if(pos == counter)
    {
        AddtoEnd(val);
    }
    else if(pos<counter)
    {
        Node *ptr = Head;
        for(int i=0;i<pos-1;i++)
        {
            ptr=ptr->Next;
        }
        Node *NewNode = new Node;
        NewNode->data.id = val.id;
        NewNode->data.age = val.age;
        NewNode->data.name = val.name;
        NewNode->data.gender = val.gender;
        NewNode->Next = ptr->Next;
        ptr->Next = NewNode;
        counter++;
    }
    else if(pos > counter)
    {
        cout<<"Out of Range!!\n";
    }

}
void linkList::show()
{
    Node *ptr= Head;
    if(ptr==NULL)
    {
        cout<< "is Empty !\n";
    }
    else
        while (ptr!=NULL)
        {
            cout<<"************************************************\n";
            cout<<"ID : ";
            cout<< ptr->data.id<<endl;
            cout<<"NAME : ";
            cout<< ptr->data.name<<endl;
            cout<<"Age : ";
            cout<< ptr->data.age<<endl;
            cout<<"gender : ";
            cout<< ptr->data.gender<<endl;
            cout<<"************************************************\n";
            ptr=ptr->Next;
        }
}
void linkList::showTodaySslots()
{
    Node *ptr= Head;
    if(ptr==NULL)
    {
        cout<< "is Empty !\n";
    }
    else
        while (ptr!=NULL)
        {
            cout<<"************************************************\n";
            cout<<"ID : ";
            cout<< ptr->data.id<<"\t\t|\t"<<"Slot : "<<ptr->data.booking<<endl;
            cout<<"************************************************\n";
            ptr=ptr->Next;
        }
}

