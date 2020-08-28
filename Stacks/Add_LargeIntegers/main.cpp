#include <iostream>
#include <algorithm>
#include "stack.h"
using namespace std;

stack<int> inp1, inp2;
stack<int> result;

char str1[] = "1000";
char str2[] = "123";

void addTwo(stack<int> &inp1, stack<int> &inp2, stack<int> &result)
{
    node<int>* ptr1;
    node<int>* ptr2;

    ptr1 = inp1.top;
    ptr2 = inp2.top;

    int carry = 0;
    int sum = 0;
    int push = 0;



    while(ptr2 != nullptr)
    {
        sum = ptr1->val + ptr2->val;
        push = sum%10;

        result.push((push + carry));

        carry = sum/10;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    while(ptr1 != nullptr)
    {
        push = ptr1->val;
        result.push(push);
        ptr1 = ptr1->next;
    }

    if(carry != 0)
    {
        result.push(carry);
    }
}

int main()
{

    int s1 = sizeof(str1)-1;
    for(int i=0; i<s1; i++)
    {
        char temp[] = " ";
        //empty char array to hold only one digit at a time; only a single item is in this array at any moment.
        //We need this so that we can use it in stoi, as stoi requires a char array to be passed.

        temp[0] = str1[i]; //temporary char array's 0th index always holds the digit.

        inp1.push(stoi(temp)); //pushing one digit into the stack at a time, after converting it to int via stoi()
    }

    int s2 = sizeof(str2)-1;
    for(int i=0; i<s2; i++)
    {
        char temp[] = " ";
        temp[0] = str2[i];
        inp2.push(stoi(temp));
    }

    cout<<endl<<endl<<"Input1 in the stack: ";
    inp1.display();
    cout<<endl<<"Input2 in the stack: ";
    inp2.display();

    addTwo(inp1, inp2, result);

    cout<<endl<<"Result: ";
    result.display();
}
