#include <iostream>
#include "stack.h"
using namespace std;

class queue {

public:

    stack<int> s1, s2;

    void enqueue(int);
    void dequeue();
};

void queue::enqueue(int val) {

    if(s1.isempty())
    {
        s1.push(val);
    }

    else //s1 stack is not empty.
    {
        while(!s1.isempty()) //push everything in stack s1 to stack s2.
        {
            s2.push(s1.top->val);
            s1.pop();
        }

        //push new element in stack s1,
        //this method makes sure that oldest entered element is always at the top of stack s1
        s1.push(val);

        while(!s2.isempty()) //push everything back into stack s1 from s2.
        {
            s1.push(s2.top->val);
            s2.pop();
        }

    }

    cout<<"\nInserted.";

}

void queue::dequeue() {

    if(s1.isempty())
    {
        cout<<"\nError, stack 1 is empty.";
        return;
    }

    else //stack s1 is not empty.
    {
        cout<<"\n"<<s1.top->val;
        s1.pop();
    }

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
