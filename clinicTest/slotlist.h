#ifndef SLOTLIST_H_INCLUDED
#define SLOTLIST_H_INCLUDED


template <typename t>
#define NULL 0
struct Slot
{
    t data ;
    Slot<t> * Next;
};
template <class t>
class SlotList{
private:
    Slot<t> *Head;
    int counter;
public:
    SlotList()
    {
        Head = NULL;
        counter = 0;
    }
    void AddSlotToEnd(t val);
    void AddSlotToFirst(t val);
    void InsertSlotInPos(int pos, t val);
    void showSlots();
    void DeleteSlotEnd();
    void DeleteSlotFirst();
    void DeleteSlotPos(int pos);
    Slot<t> *SearchSlot(t val);
    void showSingleSlot();

};


#endif // SLOTLIST_H_INCLUDED
