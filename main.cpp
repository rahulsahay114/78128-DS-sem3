#include <iostream>

class linkedlist
{
    struct node
    {
        int data;
        node *next;
    };

    node *head;

public:

    linkedlist()
    {
        head->next = NULL;
    }

    void insert();
    void traverse();
};

void linkedlist::insert()
{
    char ans = 'y';

    do{

     int val;

     std::cout<<"\n Enter Value: ";
     std::cin>>val;

     node *ptr = new node;
     ptr->data = val;


     if(head == NULL)
     {
         head = ptr;

     }

     else
     {
         node *temp = head;

         while(temp->next != NULL)
         {
             temp = temp->next;
         }

         temp->next = ptr;
     }

     std::cout<<"Add another? (y/n)";
     std::cin>>ans;

    }while(tolower(ans) == 'y');

}

void linkedlist::traverse()
{
    node *temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
        std::cout<<" "<<temp->data;
    }
}

int main()
{
    linkedlist obj;
    char ans = 'y';
    int ch;

    do
    {
        std::cout<<"\nMENU: \n1. Add Item \n2. Traverse. \n\nEnter your Choice: ";
        std::cin>>ch;

        switch (ch) {

            case 1: obj.insert(); break;

            case 2: obj.traverse(); break;

        }

        std::cout<<"\n Menu?(y/n)";
        std::cin>>ans;

    }while (tolower(ans) == 'y');

    return 0;
}


