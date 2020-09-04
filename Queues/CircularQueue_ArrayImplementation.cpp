#include <iostream>
using namespace std;

class cqueue
{
public:
    int front, rear, size;
    int* q;

    //constructor
    cqueue(int s=5)
    {
        size = s;
        q = new int[size];
        front = -1;
        rear = -1;
    }

    //functions
    bool is_empty();
    bool is_full();
    void enqueue(int);
    void clear();
    void display();
    void dequeue();

    //destructor
    ~cqueue()
    {
        delete[] q;
    }
};

bool cqueue::is_empty() {

    if(front == -1 && rear == -1)
        return true;

    else
        return false;
}

bool cqueue::is_full() {

    if((rear == size-1 && front == 0) || (rear == front - 1))
        //if either rear at the end of the array. or rear behind front i.e |rear-front| = -1 then array full.
        return true;

    else
        return false;
}

void cqueue::enqueue(int val) {

    if(is_empty()) //if queue empty
    {
        q[++rear] = val;
        front++;
    }

    else if(is_full()) //if queue is full
    {
        cout<<"\nQueue is full. Overflow."; //overflow condition
        return;
    }

    else //normal insertion.
    {
        if(rear == size-1 && front != 0)
        /* 'rear' at the end of the array and front of queue is empty, i.e one position in the array,
        from the beginning, is empty because one item already dequeued.*/
        {
            rear = 0;
            q[rear] = val;
        }

        else
        {
            q[++rear] = val;
        }
    }

    cout<<"Inserted.";
}

void cqueue::dequeue() {

    if(is_empty()) //if queue is empty
    {
        cout<<"\nQueue is empty.";
        return;
    }

    else if(front == rear) //if one element only.
    {
        front = -1;
        rear = -1;
    }

    else if(front == size-1)
    //front is at the end of the array,
    // it'll need to jump back to the start after deletion as it's a circular queue.
    {
        front = 0;
    }

    else //if queue is not empty
    {
        front++;
    }
    cout<<"Deleted.";
}

void cqueue::display() {

    if(is_empty())
    {
        cout<<"\nQueue is Empty.";
        return;
    }

    else
    {
        cout<<endl;
        if(rear > front)
            //if rear and front in standard positions,
            // i.e rear is at either size-1 or behind and front at 0th index
        {
            for(int i=front; i<=rear; i++) //normally display the queue.
            {
                cout<<q[i]<<" ";
            }
        }

        else //if 'front' and 'rear' not in standard positions.
        {
            for(int i=front; i<size; i++) //display array normally till size-1.
            {
                cout<<q[i]<<" ";
            }

            //and then display the elements that were inserted into the queue after a few items were deleted.
            int temp = -1;
            while(temp != rear)
            {
                temp++;
                cout<<q[temp]<<" ";
            }
        }
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

int main() {

    cqueue obj; //queue object
    char ans = 'y';
    int val;

    /*obj.enqueue(1);
    obj.enqueue(2);
    obj.enqueue(3);
    obj.enqueue(4);
    obj.enqueue(5);*/

    //^for debugging purposes, to fill the standard queue of length 5 at the beginning itself.

    do {
        int ch;
        cout<<"\n1. Insert \n2. Delete \n3. Display \n4. Clear \n5. Exit \nEnter your Choice: ";
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
