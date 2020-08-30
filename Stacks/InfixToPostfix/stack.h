#include <iostream>
using namespace std;

template <class t>
struct node {
    t val;
    node<t>* next;
};

template <class t>
class stack
{
public:

    node<t>* top;
    node<t>* tail;

    void push(t val);
    void pop();
    void clear();
    void display();
    void top_el();
    bool isempty();

    stack()
    {
        top = nullptr;
    }

};

template <class t>
bool stack<t>::isempty() {

    if(top == nullptr)
    {
        //cout<<"\nStack is empty"<<endl; // commenting it out to avoid unnecessary print statements in AddtwoIntegers
        return true;
    }

    else
    {
        return false;
    }

}

template <class t>
void stack<t>::push(t val) {

    node<t>* ptr = new node<t>;
    ptr->val = val;

    if(isempty()) //list is empty
    {
        top = ptr;
        top->next = nullptr;
        tail = top;
    }

    else //if list is not empty
    {
        ptr->next = top;
        top = ptr;
    }
    //cout<<"\nPush complete."; // commenting it out to avoid unnecessary print statements in AddtwoIntegers
}

template <class t>
void stack<t>::pop()
{
    if(isempty())
    {
        return;
    }

    else
    {
        node<t>* temp = top;
        top = top->next;
        delete(temp);
        cout<<"Pop complete.";
    }
}

template <class t>
void stack<t>::display() {

    if(isempty())
    {
        return;
    }

    else
    {
        node<t>* temp = top;
        while(temp != nullptr)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        //cout<<"\nTop: "<<top->val;
        //cout<<"\nTail: "<<tail->val;

        //^for debugging purposes.
    }
}

template <class t>
void stack<t>::clear() {

    node<t>* temp = top;
    node<t>* temp1 = temp;
    while(temp != nullptr)
    {
        delete(temp1);
        temp = temp->next;
        temp1 = temp;
    }
}

template<class t>
void stack<t>::top_el() {

    if(isempty())
    {
        return;
    }

    else
    {
        node<t>* temp = top;
        cout<<"\nTop Element: "<<top->val;
    }

}
