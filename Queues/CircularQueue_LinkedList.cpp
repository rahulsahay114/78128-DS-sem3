#include <iostream>
using namespace std;

template <class t>
struct node {
    t val;
    node* next;
};

template <class t>
class cqueue
{
public:

    node<t>* front;
    node<t>* rear;

    //constructor
    cqueue()
    {
        front = NULL;
        rear = NULL;
    }

    //functions
    bool is_empty();
    void enqueue(int);
    void dequeue();
    void clear();
    void display();

    //destructor
    ~cqueue()
    {
        delete front;
        delete rear;
    }
};

template<class t>
bool cqueue<t>::is_empty() {

    if((front == NULL && rear == NULL))
        return true;

    else
        return false;

}

template <class t>
void cqueue<t>::enqueue(int val) {

    node<t>* ptr = new node<t>;
    ptr->val = val;
    ptr->next = NULL;

    if(is_empty()) { //if list empty, front and rear will point to the new node.

        front = ptr;
        rear = ptr;
    }

    else if(front == rear) //if only one item.
    //front's 'next' will point new node, new node will point to front
    //and rear will be set to the newest node.
    {
        front->next = ptr; //front's 'next' will point to the next node.
        ptr->next = front; //new node will point to front
        rear = ptr; //rear will be set to new node.
    }

    else //insert at end, and move rear to the newest node.
    {
        rear->next = ptr; //rear's 'next' will point to the new node.
        //'ptr' will be the last node in the circular node, thus the last node should point to the front.
        ptr->next = front; //ptr will point to the front, as it's a circular queue.
        rear = ptr; //rear set to the last node, i.e ptr.
    }
}

template <class t>
void cqueue<t>::dequeue() {

    if(is_empty()) //if queue is empty
    {
        cout<<"\nQueue is empty.";
        return;
    }

    else if(front == rear) //just one node in the queue
    {
        node<t>* temp = front; //temp to the front node; this will be deleted as queue follows First-In-First-out.

        front = NULL; //there'll be no items in the queue, i.e empty. Thus 'front' and 'rear'
        rear = NULL;

        delete(temp);

    }

    else
    {
        node<t>* temp = front;
        front = front->next;
        rear->next = front;
        delete(temp);
    }

    cout<<"Deleted.";
}

template <class t>
void cqueue<t>::display() {

    if(is_empty()) //if the queue is empty.
    {
        cout<<"\nQueue is empty.";
        return;
    }

    else if (front == rear) //if only one item.
    {
        cout<<front->val;
    }

    else //more than one item.
    {
        node<t>* temp = front;
        do
        {
            cout<<temp->val<<" ";
            temp = temp->next;
        }while(temp != front);
    }
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

template<class t>
void cqueue<t>::clear() {
    if(is_empty())
    {
        cout<<"\nOueue is empty.";
        return;
    }

    else if (front == rear) //if only one item in the list.
    {
        node<t>* temp = front; //temp will be pointing to the one and only item.

        front = NULL; //setting the front and rear pointers back to NULL.
        rear = NULL;

        delete(temp); //deleting that item,
    }

    else
    {
        node<t>* temp = front;

        do
        {
            temp = front;
            front = front->next;
            delete(temp);
        }while(temp->next != front);

        front = NULL;
        rear = NULL;

        cout<<"\nCleared.";
    }
}

int main() {

    cqueue<int> obj;
    char ans = 'y';
    int val;

    do {
        int ch;
        cout<<"\t\nQUEUES:\n1. Insert \n2. Delete \n3. Display \n4. Clear \n5. Exit \nEnter your Choice: ";
        cin>>ch;

        switch (ch) {

            case 1:
                cout<<"Enter Value: "; cin>>val;
                obj.enqueue(val);
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
