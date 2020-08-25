#include <iostream>
using namespace std;

const int size=5;

template <class t>
class stack
{
public:
    t arr[size];
    t top;

    stack()
    {
        top = -1;
    }

    void push(t);
    void pop();
    void clear();
    void return_top();
    bool isempty();
    void display();

};

template<class t>
bool stack<t>::isempty() {

    if(top == -1)
    {
        cout<<"Stack is empty"<<endl;
        return true;
    }

    else
        return false;
}

template<class t>
void stack<t>::push(t val) {

    if(isempty()) //stack empty
    {
        arr[0] = val;
        top = 0;
    }

    else //stack not empty
    {
        if(top == size-1)
        {
            cout<<"\nStack is full.";
            return;
        }

        else
        {
            arr[++top] = val;
        }
    }

    cout<<"Push complete.";
}

template<class t>
void stack<t>::pop() {

    if(isempty())
    {
        return;
    }

    else
    {
        top--;
    }

    cout<<"Pop Complete.";

}

template<class t>
void stack<t>::clear() {

    if(isempty())
    {
        return;
    }

    else
    {
        top = -1;
    }

    cout<<"Stack Cleared.";

}

template<class t>
void stack<t>::return_top() {

    if(isempty())
    {
        return;
    }

    else
    {
        cout<<"Top Element of the stack: "<<arr[top];
    }
}

template<class t>
void stack<t>::display() {

    if(isempty())
    {
        return;
    }

    else
    {
        for(int i=0; i<=top; i++)
        {
            cout<<arr[i]<<" ";
        }
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
                obj.return_top();
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
