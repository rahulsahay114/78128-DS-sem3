#include <iostream>
using namespace std;

template <class t>
struct node {
    t val;
    node* next;
};

template <class t>
class queue {

public:

    node<t>* top = NULL;
    node<t>* rear = NULL;

    //functions
    bool is_empty();
    bool is_full();
    void enqueue();
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
        cout<<"\nQueue is full.";
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
void queue<t>::enqueue() {

    node<t>* ptr = new node<t>;

    cout<<"Enter value: ";
    cin>>ptr->val;

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
    cout<<"Inserted.";
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
    }

    else
    {
        node<t>* temp = top;
        top = top->next;
        delete(temp);
    }
    cout<<"Deleted.";
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
        node<t>* temp = top;
        while(temp != nullptr)
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }
    }
}

template <class t>
void queue<t>::clear() {

    node<t>* temp = top;
    while(temp->next != nullptr)
    {
        temp = top;
        top = top->next;
        delete(temp);
    }

    top = nullptr;
    rear = nullptr;
}

int main() {

    queue<int> obj;
    char ans = 'y';

    do {
        int ch;
        cout<<"\n1. Insert \n2. Delete \n3. Display \n4. Clear \n5. Exit \nEnter your Choice: ";
        cin>>ch;

        switch (ch) {

            case 1:
                obj.enqueue();
                break;

            case 2:
                obj.dequeue();
                break;

            case 3:
                obj.display();
                break;

            case 4:
                obj.clear();
                break;

            case 5:
                cout<<"Exiting...";
                exit(0);

            default:
                cout<<"Invalid Choice!";

        }

        cout<<"\nDo you want to continue?(y/n): ";
        cin>>ans;

        while(!check(ans))
        {
            cout<<"Enter a valid choice: ";
            cin>>ans;
        }

    }while(tolower(ans) == 'y');


    return 0;
}
