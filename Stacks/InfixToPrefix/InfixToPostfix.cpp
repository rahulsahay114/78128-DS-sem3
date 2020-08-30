#include <iostream>
#include "stack.h"
#include <string>

using namespace std;

int precedence(char val) {
    char el[6] = {'(', ')', '*', '/', '+', '-'};
    int p; //precedence value

    switch (val) {
        case '(':
            p = 3;
            break;

        case ')':
            p = 3;
            break;

        case '*':
            p = 2;
            break;

        case '/':
            p = 2;
            break;

        case '+':
            p = 1;
            break;

        case '-':
            p = 1;
            break;

        default:
            p=0;

    }

    return p; //returns precedence of the operator
}

stack<char> postfix(stack<char> &obj, string &exp)
{
    stack<char> postfix; node<char>* temp = obj.top;

    char symbols[exp.length()-1]; int top=-1;

    while(temp->val != '\0')
    {
        if(ispunct(temp->val)) //if an operator
        {
            if(top == -1) //checking to see if symbol stack is empty
            {
                symbols[++top] = temp->val;
            }

            else //symbol stack not empty
            {
                if(symbols[top] == temp->val) //if same operator encountered
                {
                    postfix.push(temp->val); //push that operator into the postfix expression.
                    top--; //and pop that element off the stack.
                }

                else if(precedence(symbols[top]) >= precedence(temp->val)) //if operator with less precedence encountered
                {
                    do
                    {
                        postfix.push(symbols[top]);
                        top--;

                    }while(precedence(symbols[top]) < precedence((temp->val)));

                    symbols[top] = temp->val;
                }

                else
                {
                    symbols[++top] = temp->val;
                }
            }
        }

        else if (isalpha(temp->val)) //if operand encountered
        {
            postfix.push(temp->val); //push it into the postfix expression stack
        }

        temp = temp->next;
    }

    for(int i=top; i>=0; i--) //pushing the remaining operators in the stack to the postfix expression.
    {
        postfix.push(symbols[i]);
    }

    return postfix;
}

int main() {

    stack<char> obj;

    string exp;

    cout<<"\nEnter Expression: ";
    cin>>exp;

    //cout<<exp<<endl;

    for(int i= sizeof(exp)-1; i>=0; i--)
    {
        //cout<<exp[i]<<endl;
        obj.push(exp[i]);
    }

    stack<char> ans = postfix(obj, exp); //ans is an object of 'stack' thus contains the linked list.

    char display[exp.length()-1]; //array to hold the postfix answer in un-reversed order.
    int i=0;

    node<char>* ptr = ans.top; //a node to help traverse through the postfix (ans) linked list.
    while(ptr != nullptr)
    {
        display[i] = ptr->val;
        i++;
        ptr = ptr->next;

    }

    for(int j=sizeof(display)-1; j>=0; j--)
    {
        cout<<display[j];
    }

    return 0;
}
