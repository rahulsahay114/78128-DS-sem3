#include <iostream>
using namespace std;

class doubleLL
{
    struct node
    {
        int data;
        node *next;
        node *prev;
    };

    node *head;

public:

    doubleLL()
    {
        head = NULL;
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

bool doubleLL::is_empty() {

    if(head == NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
}

void doubleLL::insert_end() {

    char ans='y';

    do
    {

        int val;

        do {
            cout<<"\nEnter Value: ";
            cin>>val;

        }while(isdigit(val));

        node *temp;

        node *ptr = new node;
        ptr->data = val;

        if(is_empty())
        {
            head = ptr;
            head->prev = NULL;
            head->next = NULL;
        }

        else
        {
            if(head->next == NULL) //means that only 1 item in the list.
                /* Special Case as we won't be able to traverse the list, as there's only one
                 item. */
            {
                head->next = ptr; //then we set the 'next' pointer to the new node.
                ptr->prev = head;
                ptr->next = NULL;
            }

            else
            {
                temp = head;

                while(temp->next!= NULL)
                {
                    temp = temp->next;
                }
                //temp will be the last node of the list.

                temp->next = ptr; //changing the 'next' pointer of the last node to point to the new node.

                ptr->prev = temp;
                //setting the 'prev' pointer of the newly inserted node 'ptr' to point to the node behind it, i.e 'temp'.

                ptr->next = NULL;
                /*ptr is now the last node in the list, so it's next will be set to 'NULL' as the last node of the list
                is always NULL.*/
            }
        }

        do
        {
            cout<<"Appended."<<endl;
            cout<<"Add another?(y/n): ";
            cin>>ans;
            if(!isalpha(ans))
            {
                cout<<"\nEnter a valid choice."<<endl;
            }

        }while(!isalpha(ans));



    }while(tolower(ans) == 'y');

}

void doubleLL::traverse() {

    if(is_empty())
    {
        cout<<"List is Empty";
        return;
    }

    node *temp;
    temp = head;

    while(temp != NULL)
    {
        cout<<" "<<temp->data;
        temp = temp->next;
    }

}

void doubleLL::insert_begin() {

    node *temp;
    char ans = 'y';

    if(is_empty()) //if list is empty then it'll be first node insert condition.
    {
        insert_end();
    }

    else
    {
        do
        {
            //temp = head; //setting temp to the 'head' pointer.
            node *ptr = new node;

            int val;
            cout<<"\nEnter Value: ";
            cin>>val;

            ptr->data = val; //storing the value entered by the user into the new node.

            //proceeding to append it to the list

            head->prev = ptr;
            /*setting the head's 'prev' to point to the new head, as this new node
             * will become the new head and the original head will become the second node, hence the second
             * node's 'prev' should point to the node before it, in this case it's 'ptr'.*/

            ptr->next = head;
            /* the new node 'ptr's 'next' will point to the original head, as the head's 'next'
             * always points to next node*/

            ptr->prev = NULL;
            /*Since 'ptr' is now effectively the 'head' of the list, thus it's 'prev' will be NULL.*/

            head = ptr;
            //finally making the new node inserted at the beginning the new head. Thus being appended at the front.

            do
            {
                cout<<"Appended."<<endl;
                cout<<"Add another?(y/n): ";
                cin>>ans;
                if(!isalpha(ans))
                {
                    cout<<"\nEnter a valid choice."<<endl;
                }

            }while(!isalpha(ans));
        }while(tolower(ans) == 'y');
    }
}

void doubleLL::insert_at() {

    char ans = 'y';

    if(is_empty()) //empty list condition check
    {
        insert_end();
    }

    else
    {
        do
        {
            node *ptr = new node; //new node which will be inserted

            int val;
            cout<<"\nEnter Value: ";
            cin>>val; //storing value from user.

            ptr->data = val; //storing the value entered by the user into the new node.

            int pos, flag = 0;
            cout<<"Enter Position of Insertion (starts from 0): ";
            cin>>pos; //taking position of insertion

            node *temp = head; //temp set to head
            while(flag != pos-1)
            {
                temp = temp->next; //starting from head to the pos-1.
                flag++;
            }
            //at the end of the loop temp will be at pos-1.

            ptr->prev = temp;
            /*ptr will be inserted at pos, so 'prev' of ptr should point to node at 'pos-1', which is
             * where 'temp' is set.*/

            ptr->next = temp->next;
            /*ptr will be set at pos, so the 'next' of 'ptr' should point to node ahead of 'ptr', this
             * required address is stored in the next of 'temp', as it originally was right behind the node
             * that'll now be ahead of 'ptr' after insertion of 'ptr'.*/

            temp->next->prev = ptr;
            /* the 'prev' of the node ahead of 'ptr', i.e 'temp->next', should point to the node behind it.
             * In this case the pointer behind 'temp->next' will be 'ptr.' So we change the 'prev' of
             * 'temp->next' accordingly to 'ptr'.*/

            temp->next = ptr;
            /*the 'next' pointer of the node behind the newly inserted node, 'ptr', should point to the node
             * ahead of it. In this case, the node ahead of 'temp' is 'ptr', thus we set the 'next' of 'temp'
             * to point to 'ptr'.*/

            do
            {
                cout<<"Appended."<<endl;
                cout<<"Add another?(y/n): ";
                cin>>ans;
                if(!isalpha(ans))
                {
                    cout<<"\nEnter a valid choice."<<endl;
                }
            }while(!isalpha(ans));
        }while(tolower(ans) == 'y');
    }
}

void doubleLL::del_begin() {

    char ans = 'y';
    if(is_empty())
    {
        cout<<"\nList is Empty.";
    }

    else
    {
        do
        {
            node *temp;
            temp = head;
            head = head->next;
            head->prev = NULL;
            delete(temp);

            do
            {
                cout<<"Deleted."<<endl;
                cout<<"Delete another?(y/n): ";
                cin>>ans;
                if(!isalpha(ans))
                {
                    cout<<"\nEnter a valid choice."<<endl;
                }
            }while(!isalpha(ans));
        }while(tolower(ans) == 'y');
    }
}


int main()
{
    doubleLL obj;
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

            case 10:
                cout<<"\nExiting..."; exit(0);

            default: cout<<"Choose a Valid Option.";
        }

        cout << "\n Menu?(y/n)";
        cin >> ans;

    } while (tolower(ans) == 'y');

    return 0;
}
