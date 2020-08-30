#include <iostream>
#include "stack.h"
#include<string>
using namespace std;

void delimiter_check(const char* inp)
{
    stack<char> obj; //stack to keep track of delimiter.

    for(int i=0; inp[i] != '\0'; i++) //traversing through the expression
    {
        switch (inp[i]) {

            case '(':
                obj.push(inp[i]);
                break;

            case ')':

                if(obj.top == NULL)
                {
                  cout<<"\nDelimiters not Matching.";
                  exit(0);
                }

                else if(obj.top->val == '(')
                {
                    obj.pop();
                }


        }
    }

    if(obj.isempty())
    {
        cout<<"\nDelimiters Matching.";
    }

    else
    {
        cout<<"\nDelimiters Not Matching.";
    }

}

int main() {

    const char* inp = "((a+b) + (c+d))"; //input expression ((a+b) + (c+d))

    delimiter_check(inp);

    return 0;
}
