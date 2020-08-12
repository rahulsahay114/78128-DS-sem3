#include <iostream>
using  namespace std;

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
        head = NULL; 
    }

    void insert_end();
    void insert_begin();
    void traverse();
};

void linkedlist::insert_end()
{
    char ans = 'y';

    do{

     int val;

     cout<<"\n Enter Value: ";
     cin>>val;

     node *ptr = new node;
     ptr->data = val;


     if(head == NULL)
     {
         head = ptr;

     }

     else
     {
         node *temp;
         temp = head;

         while(temp->next != NULL) //NOTE: pay attention to syntax
         {
             temp = temp->next;
         }

         temp->next = ptr;
     }

     cout<<"Add another? (y/n)";
     cin>>ans;

     while(isalpha(ans) != true)
     {
         cout<<"Enter a valid choice!"<<endl;
         cout<<"Add another? (y/n)";
         cin>>ans;
     }

    }while(tolower(ans) == 'y');

}

void linkedlist::traverse()
{
    node *temp = head;

    while(temp != NULL) //NOTE: pay attention to the syntax here
    {
        cout<<" "<<temp->data;
        temp = temp->next;

    }
}

void linkedlist::insert_begin() {

    char ans = 'y';
    do {
        int val;
        cout<<"\n Enter Value: ";
        cin>>val;

        node *ptr = new node;
        ptr->data = val;

        ptr->next = head;
        head = ptr;

        cout<<"Add another? (y/n)";
        cin>>ans;

        while(isalpha(ans) != true)
        {
            cout<<"Enter a valid choice!"<<endl;
            cout<<"Add another? (y/n)";
            cin>>ans;
        }

    }while (tolower(ans) == 'y');

}

int main() {
    linkedlist obj;
    char ans = 'y';
    int ch;

    do {
        cout << "\nMENU: \n1. Add Item at end \n2. Traverse. \n3. Insert at beginning. \n\nEnter your Choice: ";
        cin >> ch;

        switch (ch) {

            case 1:
                obj.insert_end();
                break;

            case 2:
                obj.traverse();
                break;

            case 3:
                obj.insert_begin();
                break;
        }

        cout << "\n Menu?(y/n)";
        cin >> ans;

    } while (tolower(ans) == 'y');

    return 0;
}
