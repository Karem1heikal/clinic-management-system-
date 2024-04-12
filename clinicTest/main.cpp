#include <iostream>
#include <windows.h>
#include "patientClass.h"
#include "slotlist.h"
using namespace std;

bool Check_ID_before(int *arr,int NewPos,int item);
bool Check_ID_before(int *arr,int NewPos,int item)
{
    for (int i=NewPos-1;i>=0 ;i--)
    {
        if(arr[i]==item)
            return 1;
    }
    return 0;
}
bool CheckPassword()
{
    int cnt=0;
    string passIn;

    while((cnt<3))
    {
        cout<<"Password : ";
        cin>>passIn;
        if(passIn == "1234")
            return true;
        cnt++;
    }
    return false;
}
void countdown()
{
    cout << "3" << endl;
    Sleep(1000);
    cout << "2" << endl;
    Sleep(1000);
    cout << "1" << endl;
    Sleep(1000);
    cout << "0" << endl;
}
Node* Global_patient_node = NULL;

int main()
{
    SlotList <string> s;
    // set Slot avalable
    s.AddSlotToEnd("2pm to 2:30pm");
    s.AddSlotToEnd("2:30pm to 3pm");
    s.AddSlotToEnd("3pm to 3:30pm");
    s.AddSlotToEnd("4pm to 4:30pm");
    s.AddSlotToEnd("4:30pm to 5pm");
    //patient Linked List
    linkList pat;
    data_patient p;
    //default pasword
    string Def_pass = "1234";

    // Array to store recent IDs
    int id_arrBefore[100];

    // flag for checking the corrected id
    bool flag_ID=0;

    // pointer to Node that carry returned node of searched ID
    Node* ptr_check=NULL;

    // variable make as tools
    int Cho_user,Cho_admin , firstpatient=0,cntID=0;
    int Test_id, Cho_edit,Cho_slot,Cho_slotEx;

    while(1)
    {
        cout<<"(1) Admin \n(2) User\n";
        cout<<"Enter You Choice : ";
        cin>>Cho_user;

        if(Cho_user==1) // admin options
        {
            //password;

            if(CheckPassword())
            {
                system("cls");
               while(1)
                {
                    cout<<"(Admin Mode)\n\n(1) Add new patient.\n(2) Edit patient.\n(3) Reserve a slot.\n(4) Cancel Reserving a slot.\n(0) Back.\n";
                    cout<<"Enter Your Choice : ";
                    cin>>Cho_admin;
                    if(Cho_admin==0)
                        break;
                    switch(Cho_admin)
                    {
                    case 1: // Add new patient
                        cout<<"ID : ";
                        cin>> p.id;
                        cout<<"NAME : ";
                        cin>> p.name;
                        cout<<"Age : ";
                        cin>> p.age;
                        cout<<"Gender : ";
                        cin>> p.gender;
                        id_arrBefore[cntID++]=p.id;
                        if(firstpatient==0)
                        {
                            pat.AddtoEnd(p);
                            firstpatient=1;
                            system("cls");
                            cout<<"Added Successfully -_-!\n\n";
                        }
                        else{
                            flag_ID=Check_ID_before(id_arrBefore,cntID-1,p.id);
                            if(flag_ID==0){
                                pat.AddtoEnd(p);
                                system("cls");
                                cout<<"Added Successfully -_-!\n\n";
                            }
                            else
                            {
                                cout<<"\nAlready Exist!\n";
                            }
                        }
                        break;
                    case 2: //Edit patient
                        cout<<"ID : ";
                        cin>> Test_id;
                        ptr_check = pat.SearchPatient_ID(Test_id);
                        if(ptr_check==NULL)
                        {   system("cls");
                            cout<<"\nNot correct ID!\n\n";
                        }
                        else
                        {
                            system("cls");
                            pat.show_one_patient(ptr_check);
                            while(1)
                            {
                                cout<<"(1) Edit Name.\n(2) Edit age.\n(3) Edit gender.\n(0) Back.\n";
                                cout<<"Enter Your Choice : ";
                                cin>> Cho_edit;
                                if(Cho_edit==0) {system("cls");break;}
                                switch(Cho_edit)
                                {
                                    case 1:
                                    cout<<"NAME : ";
                                    cin>> ptr_check->data.name;
                                    break;
                                    case 2:
                                    cout<<"Age : ";
                                    cin>> ptr_check->data.age;
                                    break;
                                    case 3:
                                    cout<<"Gender : ";
                                    cin>> ptr_check->data.gender;
                                    break;
                                }
                                system("cls");
                                cout<<"Added Successfully -_-!\n\n";
                                pat.show_one_patient(ptr_check);
                            }
                        }
                        break;
                    case 3: //Reserve a slot
                        cout<<"ID : ";
                        cin>> Test_id;
                        ptr_check = pat.SearchPatient_ID(Test_id);
                        if(ptr_check==NULL)
                            cout<<"\nNot correct ID!\n\n";
                        else
                        {
                            s.showSlots();
                            cout<<"(0) back\n";
                            cout<<"Enter Your Choice : ";
                            cin>>Cho_slot;
                            if(Cho_slot==0) {system("cls"); break;}
                            Global_patient_node=ptr_check;
                            system("cls");
                            cout<< "Slot added successfully -_-!\n\n";
                            s.DeleteSlotPos(Cho_slot);
                            cout<<'('<<Global_patient_node->data.booking<<')'<<endl;
                            do{
                                cout<<"(1) Exchange\n(0) back\n";
                                cout<<"Enter Your Choice : ";
                                cin>>Cho_slotEx;
                                if(Cho_slotEx==0) {system("cls"); break;}
                                if(Cho_slotEx==1)
                                {
                                    s.InsertSlotInPos(Cho_slot,Global_patient_node->data.booking);
                                    s.showSlots();
                                    cout<<"Enter Your Choice : ";
                                    cin>>Cho_slot;
                                    s.DeleteSlotPos(Cho_slot);
                                    system("cls");
                                    cout<< "Slot added successfully -_-!\n\n";
                                    cout<<'('<<Global_patient_node->data.booking<<')'<<endl;
                                }
                            }while(1);

                        }
                        break;
                    case 4: //Cancel Reserving a slot
                        cout<<"ID : ";
                        cin>> Test_id;
                        ptr_check = pat.SearchPatient_ID(Test_id);
                        if(ptr_check==NULL)
                        {
                            system("cls");
                            cout<<"\nNot correct ID!\n\n";
                        }
                        else
                        {
                            s.InsertSlotInPos(Cho_slot,Global_patient_node->data.booking);
                            ptr_check->data.booking="";
                            s.showSlots();
                            if(Cho_slot==0){system("cls"); break;}
                            system("cls");
                            cout<< "Cancel slot Reserved successfully -_-!\n\n";
                        }
                        break;
                    }
                }
            }
            else
            {
                countdown();
                HWND window;
                AllocConsole();
                // You Can Find HANDLE of other windows too
                window = FindWindowA("ConsoleWindowClass", NULL);
                ShowWindow(window, 0);
                countdown();
                system("cls");
                ShowWindow(window, 1);

            }
        }
        else if(Cho_user==2)
        {
            system("cls");
            while(1){

                cout<<"(User Mode)\n\n(1) View_patient \n(2) View today’s reservations\n(0) back\n";
                cout<<"Enter You Choice : ";
                cin>>Cho_user;
                if(Cho_user==0) break;
                switch(Cho_user)
                {
                case 1:
                    cout<<"ID : ";
                    cin>> Test_id;
                    ptr_check = pat.SearchPatient_ID(Test_id);
                    if(ptr_check==NULL){
                        system("cls");
                        cout<<"\nNot correct ID!\n";
                    }
                    else
                    {
                        system("cls");
                        pat.show_one_patient(ptr_check);
                        cout<<'*'<<ptr_check->data.booking<<'*'<<'\n';
                        cout<<"************************************************\n";
                    }
                    break;
                case 2:
                    system("cls");
                    pat.showTodaySslots();
                    break;
                }

            }

        }
    }

    return 0;
}

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
        Global_patient_node->data.booking =  copyPtr->data;
        Head = NULL;
        delete copyPtr;
        counter--;
    }
    else if (counter >1)
    {
        Slot<t> *copyPtr1 = Head;
        Global_patient_node->data.booking =  copyPtr1->data;
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
        Global_patient_node->data.booking = copyPtr->data;
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
        Global_patient_node->data.booking = CopyPtr->data;
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
    int cnt = 0;
    if(ptr==NULL)
    {
        cout<< "is Empty !\n";
    }
    else
        while (ptr!=NULL)
        {
            cout<<'('<<++cnt<<") ";
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
        for(int i=0;i<pos-2;i++)
        {
            ptr=ptr->Next;
        }
        Slot<t> *CopyPtr=ptr->Next;
        Global_patient_node->data.booking = CopyPtr->data;
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
    if(pos == 1 )
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
        for(int i=0;i<pos-2;i++)
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
template <class t> Slot<t>* SlotList<t>::SearchSlot(t val)
{
    Slot<t> *ptr = Head;
    while(ptr!=NULL){
        if((ptr->data == val))
        {
            return ptr;
        }
        ptr=ptr->Next;
    }
    return NULL;
}

   /*
    switch(Cho_user)
    {
    case 1: // admin options

        while(1)
        {
            system("cls");
            cout<<"(Admin Mode)\n\n(1) Add new patient.\n(2) Edit patient.\n(3) Reserve a slot.\n(4) Cancel Reserving a slot.\n(5) show.\n(0) Back.\n";
            cout<<"Enter You Choice : ";
            cin>>Cho_admin;
            if(Cho_admin==0)
                break;
            switch(Cho_admin)
            {
            case 1: // Add new patient
                cout<<"ID : ";
                cin>> p.id;
                cout<<"NAME : ";
                cin>> p.name;
                cout<<"Age : ";
                cin>> p.age;
                cout<<"Gender : ";
                cin>> p.gender;
                ptr_check = pat.SearchPatient_ID(12);
                cout<<"ddd";
                if(ptr_check==NULL)
                    pat.AddtoEnd(p);
                else
                    cout<<"\nAlready Exist!\n";
                break;
            case 2:  // Edit Data patient
                cout<<"ID : ";
                cin>> Test_id;
                ptr_check = pat.SearchPatient_ID(Test_id);
                if(ptr_check==NULL)
                    cout<<"\nNot correct ID!\n";
                else
                {
                    int Cho_edit;
                    while(1)
                    {
                        cout<<"(1) Edit Name.\n(2) Edit age.\n(3) Edit gender.\n(0) Back.\n";
                        cin>> Cho_edit;
                        if(Cho_edit==0) break;
                        switch(Cho_edit)
                        {
                            case 1:
                            cout<<"NAME : ";
                            cin>> ptr_check->data.name;
                            break;
                            case 2:
                            cout<<"Age : ";
                            cin>> ptr_check->data.age;
                            break;
                            case 3:
                            cout<<"Gender : ";
                            cin>> ptr_check->data.gender;
                            break;
                        }
                        system("cls");;
                        cout<<"Added Successfully -_-!\n\n";
                    }
                }
                break;
            case 5:  // Show
                pat.show();
                break;
            }
        }
        break;
    case 2:
        break;

    }
*/


    /*
    p.id=12;
    p.age=50;
    p.gender="male";
    p.name="moh";
    pat.AddtoEnd(p);
    p1.id=10;
    p1.age=50;
    p1.gender="male";
    p1.name="ali";
    pat.AddtoEnd(p1);
    p2.id=16;
    p2.age=50;
    p2.gender="male";
    p2.name="ram";
    pat.InsertInPos(2,p2);
    pat.DeleteFirst();
    pat.show();
    Node* ptr_patient=pat.SearchPatient_ID(15);
    if(ptr_patient==NULL){
        cout<<"Incorrect ID !";
    }
    else
    pat.show_one_patient(ptr_patient);'
    */


























