#include <iostream>
using namespace std;

template <class t>
struct node_q {
    t val;
    node_q* next;
};

template <class t>
class queue {

public:

    node_q<t>* top = NULL;
    node_q<t>* rear = NULL;

    //functions
    bool is_empty();
    bool is_full();
    void enqueue(t val);
    void clear();
    void display();
    void dequeue();
};

template <class t>
bool queue<t>::is_empty() {

    if(top == NULL && rear == NULL)
    {
        return true;
    }

    else
        return false;
}

template <class t>
bool queue<t>::is_full() {

    if(rear->next == nullptr)
    {
        //cout<<"\nQueue is full.";
        return true;
    }

    else
        return false;
}

bool check(char ans)
{
    if(isdigit(ans))
        return false;

    if(ans == 'y')
        return true;

    else if(ans == 'n')
        return true;

    else
        return false;
}

template <class t>
void queue<t>::enqueue(t val) {

    node_q<t>* ptr = new node_q<t>;
    ptr->val = val;

    if(is_empty()) //if queue is empty
    {
        top = ptr;
        rear = ptr;
    }

    else
    {
        if(top == rear) //just one item in the list
        {
            rear->next = ptr;
            ptr->next = nullptr;
            rear = ptr;

            top->next = rear;
        }

        else //more than one item
        {
            rear->next = ptr;
            ptr->next = nullptr;
            rear = ptr;
        }
    }
    //cout<<"Inserted.";
}

template <class t>
void queue<t>::dequeue() {

    if(is_empty())
    {
        cout<<"\nQueue is empty.";
        return;
    }

    else if (top == rear) //one item
    {
        top = top->next;
        rear = rear->next;
    }

    else
    {
        node_q<t>* temp = top;
        top = top->next;
        delete(temp);
    }

    //cout<<"Deleted.";
}

template <class t>
void queue<t>::display() {

    if(is_empty())
    {
        cout<<"\nQueue is empty.";
        return;
    }

    else
    {
        node_q<t>* temp = top;
        while(temp != nullptr)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
}

template <class t>
void queue<t>::clear() {

    node_q<t>* temp = top;
    while(temp->next != nullptr)
    {
        temp = top;
        top = top->next;
        delete(temp);
    }

    //to indicate queue empty condition, we set top and rear to null.
    top = nullptr;
    rear = nullptr;
}
