#include<iostream>
using namespace std;

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
    return iCount;
}

template <class T>
void SignlyLLL<T>::InsertAtPos(T no, int pos)
{
    struct SinglyLLLnode<T> * newn = NULL;
    struct SinglyLLLnode<T> * temp = NULL;

    int i = 0;

    if(pos < 1 || pos > this->iCount + 1)
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
        DeleteLast();
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

int main()
{
    SignlyLLL<int> sobj;
    int iRet = 0;

    sobj.InsertFirst(51);
    sobj.InsertFirst(21);
    sobj.InsertFirst(11);
    
    sobj.InsertLast(101);
    sobj.InsertLast(111);
    sobj.InsertLast(121);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are: "<<iRet <<"\n";

    sobj.DeleteFirst();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are: "<<iRet <<"\n";
    
    sobj.DeleteLast();

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are: "<<iRet <<"\n";

    sobj.InsertAtPos(60,1);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are: "<<iRet <<"\n";

    sobj.DeleteAtPos(1);

    sobj.Display();
    iRet = sobj.Count();
    cout<<"Number of nodes are: "<<iRet <<"\n";

    return 0;
}