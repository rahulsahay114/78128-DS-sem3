#include <iostream>
using namespace std;

class queue
{
public:

    int *q;
    int front, rear, size;

    //initialising with constructor
    queue(int s=5)
    {
        front = -1;
        rear = -1;

        size = s;

        q = new int[size];
    }

    //destructor to delete the queue
    ~queue()
    {
        delete[] q;
    }

    //functions
    bool is_empty();
    bool is_full();
    void enqueue();
    void clear();
    void display();
    void dequeue();

};

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

bool queue::is_empty()
{
    if(front == -1 && rear == -1)
    {
        return true;
    }

    else
        return false;
}

bool queue::is_full()
{
    if(rear == size-1)
    {
        cout<<"\nQueue is full.";
        return true;
    }

    else
        return false;
}

void queue::enqueue() {

    char ans = 'y';

    do {

        cout<<"\nEnter value: ";
        int val;
        cin>>val;

        if(is_empty()) //if the queue is empty
        {
            q[++rear] = val; //bring 'rear' to 0th index and insert 'val' at the 0th index
            front++; //set 'front' to the 0th index.
        }

        else
        {
            if(is_full()) //checking to see if the queue is full
            {
                return; //full, cannot insert.
            }

            else //not full, can insert.
            {
                q[++rear] = val;
            }
        }

        cout<<"Add another? (y/n): ";
        cin>>ans;

        while(!check(ans))
        {
            cout<<"Enter a valid input: ";
            cin>>ans;
        }

    }while(tolower(ans) == 'y');
}

void queue::dequeue() {

    if(is_empty())
    {
        cout<<"\nQueue is empty.";
        return;
    }

    else
    {
        front++; //effectively removing the first element.
    }
}

void queue::display() {

   if(is_empty()) //if empty
   {
       cout<<"\nQueue is empty.";
       return;
   }

   else //queue exists
   {
       cout<<"Queue: ";
       int i=0;
       for(i=front; i<=rear; i++)
       {
           cout<<q[i]<<" ";
       }
   }
}

void queue::clear() {

    if(is_empty())
    {
        cout<<"\nQueue is empty.";
        return;
    }

    else
    {
       front = rear = -1;
       delete[] q;
       q = new int[size];
       cout<<"\nQueue is empty.";
    }
}

int main() {

    queue obj; //queue object
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
