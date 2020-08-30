#include <iostream>
#include "stack.h"
#include <string>



int main() {

    int x1, x2;
    int res=0;

    const char *exp = "234*+82/-"; //"234*+82/-"

    stack<int> obj;

    for(int i=0; exp[i] != '\0'; i++)
    {
        if(obj.isempty()) //if the stack is empty.
        {
            char t[] = " ";
            t[0] = exp[i];
            obj.push(stoi(t));
        }

        else if(isdigit(exp[i]))
        {
            char t[] = " ";
            t[0] = exp[i];
            obj.push(stoi(t));
        }

        else if(ispunct(exp[i]))
        {
            switch(exp[i])
            {
                case '+':
                    x1 = obj.top->val;
                    x2 = obj.top->next->val;
                    obj.pop();
                    obj.pop();
                    res = x1+x2;
                    obj.push(res);
                    break;

                case '-':
                    x1 = obj.top->val;
                    x2 = obj.top->next->val;
                    obj.pop();
                    obj.pop();
                    if(x2>x1)
                    {
                        swap(x1, x2);
                    }
                    res = x1-x2;
                    obj.push(res);
                    break;


                case '/':
                    x1 = obj.top->val;
                    x2 = obj.top->next->val;
                    obj.pop();
                    obj.pop();
                    if(x2>x1)
                    {
                        swap(x1, x2);
                    }
                    res = x1/x2;
                    obj.push(res);
                    break;

                case '*':
                    x1 = obj.top->val;
                    x2 = obj.top->next->val;
                    obj.pop();
                    obj.pop();

                    res = x1*x2;
                    obj.push(res);
                    break;

            }
        }
    }

    obj.display();

    return 0;
}
