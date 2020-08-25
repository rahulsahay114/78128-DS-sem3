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
    node<t>* top;

public:
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
        cout<<"\nStack is empty"<<endl;
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
    }

    else //if list is not empty
    {
        ptr->next = top;
        top = ptr;
    }
    cout<<"Push complete.";
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

bool check(char ans)
{
    if(isdigit(ans))
    {
        return false;
    }

    else if(tolower(ans) == 'y')
    {
        return  true;
    }

    else if(tolower(ans) == 'n')
    {
        return true;
    }

    else
    {
        return false;
    }
}

int main() {

    int ch, val;
    char ans = 'y';

    stack<int> obj;

    do {

        cout<<"\nSTACK OPERATIONS: \n1. Push. \n2. Pop \n3. Clear \n4. Return Top Element. \n5. Display"
              "\nEnter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"\nEnter value to push: ";
                cin>>val;
                obj.push(val);
                break;

            case 2:
                obj.pop();
                break;

            case 3:
                obj.clear();
                break;

            case 4:
                obj.top_el();
                break;

            case 5:
                obj.display();
                break;

            default:
                cout<<"\nEnter a valid option!";
        }

        cout<<"\n\nMenu? (y/n): ";
        cin>>ans;

        bool itr = check(ans);

        if (!itr)
        {
            while(!itr)
            {
                cout<<"Enter a valid value: ";
                cin>>ans;
                itr = check(ans);
            }
        }

    }while(tolower(ans) == 'y');

    return 0;
}
