#include <iostream>
using namespace std;

struct node
{
    int coeff;
    int pow;
    node *next;
};

void insert(int x, int y, node **obj) {

    node *ptr, *temp;
    temp = *obj;

    if(temp == NULL) //if list empty, ptr will be first node in the list.
    {
        ptr = new node();
        ptr->coeff = x;
        ptr->pow = y;

        *obj = ptr;

        ptr->next = new node();
        ptr = ptr->next;
        ptr->next = NULL;
    }

    else
    {
        node *temp1 = (*obj)->next;
        while(temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        ptr = temp1;
        ptr->coeff = x;
        ptr->pow = y;
        ptr->next = new node;
        ptr = ptr->next;
        ptr->next = NULL;
    }
}

void add(node *obj1, node *obj2, node *result)
{
    while(obj1->next && obj2->next)
    {
        if(obj1->pow > obj2->pow)
        {
            result->pow = obj1->pow;
            result->coeff = obj1->coeff;
            obj1 = obj1->next;
        }

        else if(obj2->pow> obj1->pow)
        {
            result->pow = obj2->pow;
            result->coeff = obj2->coeff;
            obj2 = obj2->next;
        }

        else
        {
            result->pow = obj1->pow;
            result->coeff = obj1->coeff + obj2->coeff;
            obj1 = obj1->next;
            obj2 = obj2->next;
        }

        result->next = new node();
        result = result->next;
        result->next = NULL;
    }

    while(obj1->next || obj2->next)
    {
        if(obj1->next)
        {
            result->pow = obj1->pow;
            result->coeff = obj1->coeff;
            obj1 = obj1->next;
        }

        if(obj2->next)
        {
            result->pow = obj2->pow;
            result->coeff = obj2->coeff;
            obj2 = obj2->next;
        }

        result->next = new node();
        result = result->next;
        result->next = NULL;
    }
}

void printpoly(node *node){

    while(node->next != NULL)
    {
        cout<<node->coeff<<"^"<<node->pow;
        node = node->next;
        if(node->next != NULL)
            cout<<" + ";
    }
}

int main() {

    node *p1 = NULL, *p2 = NULL;
    int ch, x, y;
    char ans ='y';

    do {
        cout<<"Enter Coefficient: ";
        cin>>x;

        cout<<"Enter Power: ";
        cin>>y;

        insert(x, y, &p1);

        cout<<"\nInsert Another for Polynomial 1? (y/n): ";
        cin>>ans;

    }while(tolower(ans) == 'y');

    cout<<"\nFor Polynomial 2: ";
    do {
        cout<<"Enter Coefficient: ";
        cin>>x;

        cout<<"Enter Power: ";
        cin>>y;

        insert(x, y, &p2);

        cout<<"\nInsert Another for Polynomial 2? (y/n): ";
        cin>>ans;

    }while(tolower(ans) == 'y');

    node *result = new node;
    add(p1, p2, result);

    printpoly(result);

    return 0;
}
