#ifndef PATIENTCLASS_H_INCLUDED
#define PATIENTCLASS_H_INCLUDED
using namespace std;
struct data_patient
{
    int id;
    int age;
    string name;
    string gender;
    string booking;
};
struct Node
{
    data_patient data;
    Node * Next;
};
class linkList{
private:
    Node *Head;
    int counter;
public:
    linkList()
    {
        Head = NULL;
        counter = 0;
    }
    bool AddtoEnd(data_patient val);
    bool AddtoFirst(data_patient val);
    void InsertInPos(int pos, data_patient val);
    void show();
    void show_one_patient(Node *);
    void DeleteEnd();
    void DeleteFirst();
    void DeletePos(int pos);
    Node * SearchPatient_ID(int item_id);
    void showTodaySslots();
    int GetCounter();

};

#endif // PATIENTCLASS_H_INCLUDED
