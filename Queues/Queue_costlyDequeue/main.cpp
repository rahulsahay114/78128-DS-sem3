#include <iostream>
#include "stack.h"
using namespace std;

class queue
{
public:

    stack<int> s1, s2;

    void enqueue(int val);
    void dequeue();
};

void queue::enqueue(int val) {

    s1.push(val);
}

void queue::dequeue() {

    if(s1.isempty() && s2.isempty())
    {
        cout<<"\nError, both stacks are empty.";
        return;
    }

    else if(s2.isempty()) //if only stack s2 is empty
    {
        while(!s1.isempty()) //push everything from stack s1 to s2.
        {
            s2.push(s1.top->val);
            s1.top = s1.top->next;
        }
    }

    cout<<s2.top->val<<" "; //print the top element from s2.
    s2.pop(); //and pop it out.
}

int main() {

    queue obj;

    cout<<"\nobj.enqueue(1); ";
    obj.enqueue(1);

    cout<<"\nobj.enqueue(2); ";
    obj.enqueue(2);

    cout<<"\nobj.enqueue(3); ";
    obj.enqueue(3);

    cout<<"\n\nDequeue order: ";
    obj.dequeue();
    obj.dequeue();
    obj.dequeue();

    return 0;
}
