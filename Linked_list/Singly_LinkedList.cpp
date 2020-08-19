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
        head = NULL; //head is used to store and keep track of the first node.
    }

    void insert_end();
    void insert_begin();
    void insert_at();
    void traverse();
    void del_begin();
    void del_end();
    void del_at();
    void reverse();
    void search();
    bool is_empty();
};

bool linkedlist::is_empty() {
    if(head == NULL)
    {
        cout<<"List is empty.";
        return true;
    }

    else
        return false;
}

void linkedlist::insert_end()
{
    char ans = 'y';

    do{

     int val;

     cout<<"\n Enter Value: ";
     cin>>val; //input from user

     node *ptr = new node; //new node which will be appended.
     ptr->data = val;
     ptr->next = NULL; //Since being inserted at the end, the last node's 'next' pointer is always NULL.


     if(head == NULL) //checking if the list is empty.
     {
         head = ptr; //list empty, hence this will become the head pointer i.e the 'first' pointer.

     }

     else //list not empty
     {
         node *temp; //temp node to help us travel to the last node in the list.
         temp = head;

         while(temp->next != NULL) //NOTE: pay attention to syntax
         {
             temp = temp->next; //at the end of the loop, temp will be equal to the last node/item in the list.
         }

         temp->next = ptr; 
         /*changing the last node/item's 'next' pointer to have the address of the new node 'ptr', 
          effectively appending the new pointer 'ptr' to the list*/
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
    //setting the 'temp' node to head. So that we can iterate from the first item to the last one.

    if(is_empty())
        return;

    while(temp != NULL) //NOTE: pay attention to the syntax here: 'temp!=NULL' will help us travel to the
        //last node and access it's value.
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
        ptr->next = head; //storing address of previous head into the new node which will become the new head.
        head = ptr; //setting head to the new node (ptr).

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

void linkedlist::insert_at() {

    if(is_empty())
        return; //checking if empty

    int val, pos;
    cout<<"\n Enter Value: ";
    cin>>val;

    cout<<"Enter position to insert (begins from 0): ";
    cin>>pos;

    node *ptr = new node;
    ptr->data = val;

    if(head == NULL) //checking if list is empty
    {
        cout<<"\n List is Empty!";
    }

    else if (pos == 0) //insert-at-beginning condition.
    {
        insert_begin();
    }

    else
    {
        node *temp = head;
        int flag=0;

        while(flag != pos-1)
        {
            temp = temp->next;
            flag++; //flag will help us to go to the (pos-1)th node. i.e the node before the node which we will insert.
        } 
        
        //at the end of the loop, 'temp' will be the node before the node that we will insert.

        ptr->next = temp->next; 
        /*setting the new node's 'next pointer' to point to the next node, 
        i.e the node ahead of the node that we will insert.*/
        
        temp->next = ptr; 
        /* setting the 'next' pointer of node before the inserted node
         to have the address of ptr (new node), thus appending it*/
    }


}

void linkedlist::del_begin() {

    if(is_empty())
        return;

    node *ptr;
    ptr = head; //bringing the temporary ptr (node) to the head so that we can free it and delete it.

    head = head->next;
    /*moving current 'head' to the next node via the 'next' pointer which stores the address
    of the next node, as the current node which head was pointing to is going to be deleted.*/

    free(ptr); //deleting the node.
    cout<<"Item Deleted.";
}

void linkedlist::del_end() {

    if(is_empty())
        return;

    node *ptr;
    node *temp=head;
    int pos=0;

    while(temp->next!=NULL)
    {
        temp = temp->next;
        pos++; //pos will count the number of items in the list.
    }

    temp = head;

    int flag=0;
    while(flag != pos-1) //using the number of items in the list, we travel to the second last item/node.
    {
        temp = temp->next; //at the end of the loop temp will be set to the 2nd last node.
        flag++;
    }
    
    ptr = temp->next; 
    /*setting ptr to the node which is going to be deleted, 
    i.e 2nd last node's 'next' pointer, which holds the address of the last node.*/
    
    temp->next = NULL;
    /*setting the temp node's 'next' pointer, which is set to the node
    before the node to be deleted, to NULL as it'll effectively become the last node in the list. And, the
    last node's 'next' pointer is always set to NULL.*/
    
    free(ptr); //deleting the node.
    cout<<"\n Item Deleted.";

}

void linkedlist::del_at() {

    if(is_empty())
        return;

    int pos;
    
    cout<<"\n Position to be deleted (begin from 0): ";
    cin>>pos; //user input

    if(pos == 0) //delete-at-beginning condition.
    {
        del_begin();
    }

    else if (head == NULL) //checking if the list is empty
    {
        cout<<"\n List is Empty";
    }

    else
    {
        node *temp = head;
        int flag=0;

        while(flag != pos-1)
        {
            temp = temp->next;
            flag++;
        }

        /* at the end of the loop 'temp' will be the node before the node that we want to delete */

        node *ptr = temp->next;
        /*'ptr' will now be the node which we want to delete, i.e 'temp->next' as
        'temp->next' has the address of the node ahead of it.*/

        temp->next = ptr->next;
        /* setting the 'next' pointer to the address of the node ahead of the deleted node, so that the
        linked list will maintain it's links, i.e after deleting a node the node before it will point to
        the node ahead of the deleted node*/

        free(ptr); //deleting the node.
        cout<<"\nItem Deleted.";
    }
        
}

void linkedlist::reverse() {

    if(is_empty())
        return;

    else if(head->next == NULL) //checking if only a single item in the list
    {
        cout<<"List Reversed!"; //the reverse of a list with a single item will be the same sas it's original.
        return;
    }

    node *temp, *temp1;

    temp = head; //setting temp to the first node, i.e head. It'll always in the back.
    temp1 = temp->next; //temp1 set to the node next to 'temp' node. It'll always be in the front.

    head = temp1->next;
    /*setting the head to be in front of temp and temp1 (positions: temp, temp1, head)
    if there are two items in the list, then 'head' will not have a 'temp1->next' to go to
    so it could be set to NULL or some junk value.*/

    temp->next = NULL;
    /*the unreversed list's head will become the last node, and the last node's 'next' is always NULL, so
     here we effectively set the  'next' of unreversed list's 'head' to NULL */

    while(temp1->next != NULL) //making sure we exit the loop as soon as we reach the last node.
    {
        temp1->next = temp;
        //setting the front node's 'next' to point to the back node. (reversing the links!)

        temp = temp1;
        //temp and temp1 now point to the same node.
        //(positions: temp ->(a node)<- temp1 head -> (node ahead of the node temp&temp1 are at)

        temp1 = head;
        //moving temp1 to be in the front again.
        //(positions: temp, temp1-> (a node) <- head)
        //now the while loop will execute again, and head will be ahead of temp1.

        head = temp1->next;
        //setting the head to the node ahead of temp1. (i.e positions of nodes will be: temp, temp1, head)
    }

    head = temp1;

    head->next = temp;
    /* at the end of the loop, head's 'next' or is holding the address of the node next to it (in reverse order)
     or some random junk value or set to NULL. So we set it back to temp1, ie last node of the unreversed list,
     this is the last step to finally set the unreversed list's last node,
     whose 'next' was NULL, so we set it to point to the second node of the reversed list, ie 'temp',
     thus effectively becoming the 'head' node of the list*/

    cout<<"List Reversed!";
}

void linkedlist::search() {

    if(is_empty())
        return;

    int key, pos=-1, ctr=0;

    cout<<"\n Enter Key to search for: ";
    cin>>key;

    node *temp = head;

    while(temp!=NULL)
    {
        if(temp->data == key)
        {
            pos = ctr;
        }
        temp = temp->next;
        ctr++;

    }

    if(pos != -1)
    {
        cout<<key<<" found at: "<<pos+1;
    }
    else
        cout<<"Not Found.";
}

int main() {

    linkedlist obj;
    char ans = 'y';
    int ch;

    do {
        cout << "\nMENU: \n1. Add Item at end \n2. Insert at beginning. \n3. Insert at a Location. "
                "\n4. Traverse. \n5. Delete Node at Beginning \n6. Delete Node at the End "
                "\n7. Delete node at a location. \n8. Reverse. \n9. Search. \n10. Exit. \n\nEnter your Choice: ";
        cin >> ch;

        switch (ch) {

            case 1:
                obj.insert_end();
                break;

            case 2:
                obj.insert_begin();
                break;

            case 3:
                obj.insert_at();
                break;

            case 4:
                obj.traverse();
                break;

            case 5:
                obj.del_begin();
                break;

            case 6:
                obj.del_end();
                break;

            case 7:
                obj.del_at();
                break;

            case 8:
                obj.reverse();
                break;

            case 9:
                obj.search();
                break;

            case 10:
                cout<<"\nExiting..."; exit(0);

            default: cout<<"\n Choose a Valid Option.";
        }

        cout << "\n Menu?(y/n)";
        cin >> ans;

    } while (tolower(ans) == 'y');

    return 0;
}
