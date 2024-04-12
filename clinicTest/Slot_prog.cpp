
#include <iostream>
#include <string>
#include "SlotList.h"
using namespace std;


template <class t> void SlotList<t>::AddSlotToEnd(t val)
{
    if(Head == NULL)
    {
        Head = new Slot<t>;
        Head->data = val;
        Head->Next = NULL;
    }
    else
    {
        Slot<t> *current = Head;
        Slot<t> * NewNode = new Slot<t>;
        while (current->Next != NULL)
        {
            current = current->Next;
        }

        current ->Next =NewNode ;
        NewNode->data = val;
        NewNode->Next = NULL;
    }
    counter++ ;
}
template <class t> void SlotList<t>::DeleteSlotFirst()
{
     if(Head == NULL)
    {
        cout<<"Empty !!\n";
    }
    else if (counter == 1)
    {
        Slot<t> * copyPtr =  Head;
        Head = NULL;
        delete copyPtr;
        counter--;
    }
    else if (counter >1)
    {
        Slot<t> *copyPtr1 = Head;
        Head = Head->Next;
        delete copyPtr1;
        counter--;
    }
}
template <class t> void SlotList<t>::DeleteSlotEnd()
{
     if(Head == NULL)
    {
        cout<<"Empty !!\n";
    }
    else if (counter == 1)
    {
        Slot<t> * copyPtr =  Head;
        Head = NULL;
        delete copyPtr;
        counter--;
    }
    else if(counter >1)
    {
        Slot<t> * ptr =  Head;
        for(int i=0;i<counter-2;i++)
        {
            ptr= ptr->Next;
        }
        Slot<t> *CopyPtr=ptr->Next;
        ptr->Next = NULL;
        delete CopyPtr;
        counter--;
    }
    else
    {
        cout << "Error out!! \n" ;
    }

}
template <class t> void SlotList<t>::AddSlotToFirst(t val)
{
    Slot<t> *NewNode = new Slot<t>;
    NewNode->data=val;
    NewNode->Next=Head;
    Head=NewNode;
    counter++;
}
template <class t> void SlotList<t>::showSlots()
{
    Slot<t> *ptr= Head;
    if(ptr==NULL)
    {
        cout<< "is Empty !\n";
    }
    else
        while (ptr!=NULL)
        {
            cout<< ptr->data<<endl;
            ptr=ptr->Next;
        }
}

template <class t> void SlotList<t>::DeleteSlotPos(int pos)
{
    if(pos == 1 )
    {
        DeleteSlotFirst();
    }
    else if(pos == counter)
    {
        DeleteSlotEnd();
    }
    else if(pos<counter)
    {
        Slot<t> *ptr = Head;
        for(int i=0;i<pos-1;i++)
        {
            ptr=ptr->Next;
        }
        Slot<t> *CopyPtr=ptr->Next;
        ptr->Next = ptr->Next->Next;
        delete CopyPtr;
        counter--;
    }
    else if(pos > counter)
    {
        cout<<"Out of Range!!\n";
    }

}
template <class t> void SlotList<t>::InsertSlotInPos(int pos,t val)
{
    if(pos == NULL )
    {
        AddSlotToFirst(val);
    }
    else if(pos == counter)
    {
        AddSlotToEnd(val);
    }
    else if(pos<counter)
    {
        Slot<t> *ptr = Head;
        for(int i=0;i<pos-1;i++)
        {
            ptr=ptr->Next;
        }
        Slot<t> *NewNode = new Slot<t>;
        NewNode->data = val;
        NewNode->Next = ptr->Next;
        ptr->Next = NewNode;
        counter++;
    }
    else if(pos > counter)
    {
        cout<<"Out of Range!!\n";
    }
}
