#include<iostream>
using namespace std;

template <class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};

template <class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        void DisplayRevrse();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Inside constructor of DoublyLLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;    
    }
    else
    {
        newn->next = first;
        first->prev = newn;

        first = newn;
    }

    first->prev = last;
    last->next = first;

    iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }

    first->prev = last;
    last->next = first;

    iCount++;
}
/////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        first = first -> next;

        delete first->prev;

        first->prev = last;
        last->next = first;
    }
    
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;

        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;

        delete last->next;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct DoublyCLLnode<T> * temp = first;

    cout<<" <=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp -> next;
    }while(temp != first);
    
    cout<<"\n";
}

template <class T>
void DoublyCLL<T>::DisplayRevrse()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct DoublyCLLnode<T> * temp = last;

    cout<<" <=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp -> prev;
    }while(temp != last);
    
    cout<<"\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(first == NULL && last == NULL)
    {
        cout<<"list is empty\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        temp->next->prev = temp;

        delete target;

        iCount--;
    }
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        iCount++;
    }
}

int main()
{
    DoublyCLL<int> dobj;
    int iRet = 0;

    dobj.InsertFirst(51);
    dobj.InsertFirst(21);
    dobj.InsertFirst(11);
    
    dobj.InsertLast(101);
    dobj.InsertLast(111);
    dobj.InsertLast(121);

    dobj.Display();
    
    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";
    
    dobj.InsertAtPos(105,5);

    dobj.Display();
    
    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.DeleteAtPos(5);

    dobj.Display();
    dobj.DisplayRevrse();
    
    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.DeleteFirst();

    dobj.Display();
    
    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    dobj.DeleteLast();

    dobj.Display();
    
    iRet = dobj.Count();

    cout<<"Number of elements are : "<<iRet<<"\n";

    return 0;
}