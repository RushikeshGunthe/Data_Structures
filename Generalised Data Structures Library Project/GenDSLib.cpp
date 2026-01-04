
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name:            Rushikesh Vinod Gunthe
// Project Name:    Generalised Data Structures Library
// Discription:     This project is a clone of internal DS collection of Java LL
// Date:            31/12/2025
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Singly Linear LinkedList Structure and Class With Required Functions Decleration
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
struct SinglyLLLnode
{
    T data;
    struct SinglyLLLnode<T> *next; 
};

template <class T>
class SignlyLLL
{
    private:
        struct SinglyLLLnode<T> * first;
        int iCount;
    
    public:
        SignlyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T no, int pos);
        void DeleteAtPos(int pos);

};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Singly Circular LinkedList Structure and Class With Required Functions Decleration
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};

template <class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Doubly Linear LinkedList Structure and Class With Required Functions Decleration
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Doubly Circular LinkedList Structure and Class With Required Functions Decleration
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Singly Linear Linked-List Function Definations
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SignlyLLL<T>::SignlyLLL()
{
    cout<<"Inside constructor of SinglyLLL\n";

    this->first = NULL;
    this->iCount = 0;
}

template <class T>
void SignlyLLL<T>::InsertFirst(T no)
{
    struct SinglyLLLnode<T> * newn = NULL;
    
    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
void SignlyLLL<T>::InsertLast(T no)
{
    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

    newn = new struct SinglyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

template <class T>
void SignlyLLL<T>::DeleteFirst()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;

        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;

        delete temp;
    }

    this->iCount--;
}

template <class T>
void SignlyLLL<T>::DeleteLast()
{
    struct SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;

        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}
template <class T>
void SignlyLLL<T>::Display()
{
    if(this->first == NULL)
    {
        return;
    }

    struct SinglyLLLnode<T> * temp = this->first;

    while(temp != NULL)
    {
        cout<<"| "<< temp->data << " | -> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

template <class T>
int SignlyLLL<T>::Count()
{
    return this->iCount;
}

template <class T>
void SignlyLLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

    int i = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<< "Invalid position.\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new struct SinglyLLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = this->first;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SignlyLLL<T>::DeleteAtPos(int pos)
{
    int i = 0;

    struct SinglyLLLnode<T> * temp = NULL;
    struct SinglyLLLnode<T> * target = NULL;

    if(this->first == NULL)
    {
        return;
    }
    
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position.\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        
        temp->next = temp->next->next;
        delete target;

        this->iCount--;
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Singly Circular Linked-List Function Definations
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)   // if(iCount == 0)
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        newn->next = this->first;
        this->first = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(this->first == NULL && this->last == NULL)   // if(iCount == 0)
    {
        this->first = newn;
        this->last = newn;

        this->last->next = this->first;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;

        this->last->next = this->first;
    }

    this->iCount++;
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;
        delete this->last->next;

        this->last->next = this->first;
    }
    this->iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct SinglyCLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp -> next != this->last)
        {
            temp = temp -> next;
        }

        delete this->last;
        this->last = temp;

        this->last->next = this->first;
    }
    this->iCount--;
}

template <class T>
void SinglyCLL<T>::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    struct SinglyCLLnode<T> * temp = this->first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    } while (temp != this->last ->next);
    
    cout<<"\n";
}

template <class T>
int SinglyCLL<T>::Count()
{
    return this->iCount;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = this->first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next = newn;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Doubly Linear Linked-List Function Definations
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;

        
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;

        this->first = newn;
    }

    this->iCount++;
}

template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    struct DoublyLLLnode<T> * newn = NULL;

    newn = new struct DoublyLLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        newn->prev = this->last;
        this->last = newn;
    }

    this->iCount++;
}

template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;
        delete this->first->prev;

        this->first->prev = NULL;
    }
    this->iCount--;
}

template <class T>
void DoublyLLL<T>::DeleteLast()
{
    struct DoublyLLLnode<T> * temp = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        temp = this->first;

        while(temp -> next != this->last)
        {
            temp = temp -> next;
        }

        delete this->last;
        this->last = temp;

        this->last->next = NULL;
    }
    this->iCount--;
}

template <class T>
void DoublyLLL<T>::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    struct DoublyLLLnode<T> * temp = this->first;

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
    return this->iCount;
}

template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    struct DoublyLLLnode<T> * temp = NULL;
    struct DoublyLLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        temp->next->prev = temp;

        delete target;

        this->iCount--;
    }
}

template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    struct DoublyLLLnode<T> * temp = NULL;
    struct DoublyLLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new struct DoublyLLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = this->first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Doubly Cicular Linked-List Function Definations
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


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

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;    
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;

        this->first = newn;
    }

    this->first->prev = this->last;
    this->last->next = this->first;

    this->iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        newn->prev = this->last;
        this->last->next = newn;
        this->last = newn;
    }

    this->first->prev = this->last;
    this->last->next = this->first;

    this->iCount++;
}
/////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;

        delete this->first->prev;

        this->first->prev = this->last;
        this->last->next = this->first;
    }
    
    this->iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }
    else if(this->first == this->last)
    {
        delete this->first;

        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev;

        delete this->last->next;

        last->next = this->first;
        this->first->prev = this->last;
    }
    this->iCount--;
}

template <class T>
void DoublyCLL<T>::Display()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    struct DoublyCLLnode<T> * temp = this->first;

    cout<<" <=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp -> next;
    }while(temp != this->first);
    
    cout<<"\n";
}

template <class T>
void DoublyCLL<T>::DisplayRevrse()
{
    if(this->first == NULL && this->last == NULL)
    {
        return;
    }

    struct DoublyCLLnode<T> * temp = this->last;

    cout<<" <=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp -> prev;
    }while(temp != this->last);
    
    cout<<"\n";
}

template <class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * target = NULL;
    
    int i = 0;
    
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"list is empty\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp -> next;
        }

        target = temp -> next;

        temp->next = target->next;
        temp->next->prev = temp;

        delete target;

        this->iCount--;
    }
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    struct DoublyCLLnode<T> * newn = NULL;

    int i = 0;

    if(pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new struct DoublyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        temp = this->first;

        for(i = 1; i < pos -1; i++)
        {
            temp = temp -> next;
        }

        newn->next = temp -> next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;

        this->iCount++;
    }
}
