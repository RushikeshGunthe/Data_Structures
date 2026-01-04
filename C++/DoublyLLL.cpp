#include<iostream>
using namespace std;

template <class T>
struct DoublyLLLnode
{
    T data;
    struct DoublyLLLnode<T> *next;
    struct DoublyLLLnode<T> *prev;
};

template <class T>
class DoublyLLL
{
    private:
        struct DoublyLLLnode<T> * first;
        struct DoublyLLLnode<T> * last;
        int iCount;

    public:
        DoublyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"Inside constructor of DoublyLLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new struct DoublyLLLnode<T>;

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

    iCount++;
}

template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new struct DoublyLLLnode<T>;

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
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    iCount++;
}

template <class T>
void DoublyLLL<T>::DeleteFirst()
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

        first->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLLL<T>::DeleteLast()
{
    struct DoublyLLLnode<T> * temp = NULL;

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
        temp = first;

        while(temp -> next != last)
        {
            temp = temp -> next;
        }

        delete last;
        last = temp;

        last->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    struct DoublyLLLnode<T> * temp = first;

    cout<<"NULL <=> ";

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp -> next;
    }
    
    cout<<"NULL\n";
}

template <class T>
int DoublyLLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    struct DoublyLLLnode<T> * temp = NULL;
    struct DoublyLLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
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
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    struct DoublyLLLnode<T> * temp = NULL;
    struct DoublyLLLnode<T> * newn = NULL;

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
        newn = new struct DoublyLLLnode<T>;

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
    DoublyLLL<int> dobj;
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