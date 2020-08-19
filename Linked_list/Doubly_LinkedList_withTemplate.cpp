#include <iostream>
using namespace std;

template <class t>
struct node
{
    t data;
    node<t> *next;
    node<t> *prev;
};

template <class t>
class doubleLL
{
    node<t> *head;

public:

    doubleLL<t>()
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

    ~doubleLL<t>()
    {
        delete(head);
    }
};

template<class t>
bool doubleLL<t>::is_empty() {

    if(head == NULL)
    {
        return true;
    }

    else
    {
        return false;
    }
}

template<class t>
void doubleLL<t>::insert_end() {

    char ans='y';

    do
    {

        t val;

        do {
            cout<<"\nEnter Value: ";
            cin>>val;

        }while(isdigit(val));

        node<t> *temp;

        node<t> *ptr = new node<t>;
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

template<class t>
void doubleLL<t>::traverse() {

    if(is_empty())
    {
        cout<<"List is Empty";
        return;
    }

    node<t> *temp;
    temp = head;

    while(temp != NULL)
    {
        cout<<" "<<temp->data;
        temp = temp->next;
    }

}

template<class t>
void doubleLL<t>::insert_begin() {

    node<t> *temp;
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
            node<t> *ptr = new node<t>;

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

template<class t>
void doubleLL<t>::insert_at() {

    char ans = 'y';

    if(is_empty()) //empty list condition check
    {
        insert_end();
    }

    else
    {
        do
        {
            node<t> *ptr = new node<t>; //new node which will be inserted

            int val;
            cout<<"\nEnter Value: ";
            cin>>val; //storing value from user.

            ptr->data = val; //storing the value entered by the user into the new node.

            int pos, flag = 0;
            cout<<"Enter Position of Insertion (starts from 0): ";
            cin>>pos; //taking position of insertion

            node<t> *temp = head; //temp set to head
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

template<class t>
void doubleLL<t>::del_begin() {

    char ans = 'y';
    if(is_empty()) //checking if the list is empty or not
    {
        cout<<"\nList is Empty.";
        return;
    }

    else
    {
        do
        {
            node<t> *temp;
            temp = head;
            //setting temp to the head, so we can delete it via temp.

            head = head->next;
            //since the first node wil be deleted, the head will shift to the next node to which 'head->next' points

            head->prev = NULL;
            //setting the new head's 'prev' pointer to NULL, as the head's 'prev' is always NULL.

            delete(temp);
            //deleting the first node of the list, 'temp' was set to it.

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

template<class t>
void doubleLL<t>::del_end() {

    if(is_empty()) //checking list empty condition
    {
        cout<<"\nList is Empty.";
        return;
    }

    else
    {
        node<t> *temp;
        temp = head;

        if(head->next == head->prev) //if only one node
        {
            delete(temp);
            head = NULL;
        }

        else
        {
            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            node<t> *temp1 = temp->prev;
            temp1->next = NULL;

            delete(temp);
        }
        cout<<"Deleted"<<endl;
    }
}

template<class t>
void doubleLL<t>::del_at() {

    if(is_empty())
    {
        cout<<"\nList is empty";
        return;
    }

    else
    {
        int pos;
        cout<<"\nEnter position to delete: ";
        cin>>pos;

        node<t> *temp;
        temp = head;

        if(head->next == head->prev) //if only one node
        {
            delete(temp);
            head = NULL;
        }

        else //if more than one node in the list
        {
            int flag = 0;

            while(flag != pos-1)
            {
                temp = temp->next;
                flag++;
            } //at the end of the loop, temp will be at the node behind the node we want to delete.

            node<t> *temp1;
            temp1 = temp->next;
            //temp1 will point to the node we want to delete, i.e 'temp->next' which points to the node ahead of temp.

            temp->next = temp1->next;
            /*resetting pointers accordingly. temp1 will be deleted so temp's 'next' should point to the node which will
            be ahead of it after deletion of temp1, i.e 'temp1->next'.*/

            temp1->next->prev = temp;
            //the 'prev' of the node ahead of temp1 should point to the node
            // that'll be behind it after deletion of temp1, i.e 'temp'.

            delete(temp1);
            //deleting the node temp1.
        }
        cout<<"Deleted."<<endl;
    }
}

template<class t>
void doubleLL<t>::reverse() {

    if(is_empty())
    {
        cout<<"\nList is empty";
        return;
    }

    else
    {
        node<t> *temp = NULL, *curr;
        curr = head;

        while(curr != NULL)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if(temp != NULL)
        {
            head = temp->prev;
        }
    }

}

template<class t>
void doubleLL<t>::search() {

    if (is_empty())
    {
        cout<<"\nList is empty.";
        return;
    }

    else
    {
        int key, pos=0, flag=0;
        cout<<"\nEnter Key to search: ";
        cin>>key;

        node<t> *temp = head;
        while(temp != NULL)
        {
            if(key == temp->data)
            {
                pos = flag;
                break;
            }
            temp = temp->next;
            flag++;
        }
        cout<<key<<" found at: "<<pos+1;
    }

}


int main()
{
    int datatype;
    cout<<"\t Choose List datatype: \n1. int 2. float. \nEnter your choice: ";
    cin>>datatype;

    doubleLL<int> obj;
    doubleLL<float> obj1;

    char ans = 'y';
    int ch;

    if(datatype == 1)
    {
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

                default: cout<<"Choose a Valid Option.";
            }

            do {
                cout << "\n Menu?(y/n)";
                cin >> ans;

                if(!isalpha(ans))
                {
                    cout<<"Enter a valid option: ";
                }
            }while(!isalpha(ans));
        } while (tolower(ans) == 'y');
    }

    else if(datatype == 2)
    {
        do {
            cout << "\nMENU: \n1. Add Item at end \n2. Insert at beginning. \n3. Insert at a Location. "
                    "\n4. Traverse. \n5. Delete Node at Beginning \n6. Delete Node at the End "
                    "\n7. Delete node at a location. \n8. Reverse. \n9. Search. \n10. Exit. \n\nEnter your Choice: ";
            cin >> ch;

            switch (ch) {

                case 1:
                    obj1.insert_end();
                    break;

                case 2:
                    obj1.insert_begin();
                    break;

                case 3:
                    obj1.insert_at();
                    break;

                case 4:
                    obj1.traverse();
                    break;

                case 5:
                    obj1.del_begin();
                    break;

                case 6:
                    obj1.del_end();
                    break;

                case 7:
                    obj1.del_at();
                    break;

                case 8:
                    obj1.reverse();
                    break;

                case 9:
                    obj1.search();
                    break;

                case 10:
                    cout<<"\nExiting..."; exit(0);

                default: cout<<"Choose a Valid Option.";
            }

            do {
                cout << "\n Menu?(y/n)";
                cin >> ans;

                if(!isalpha(ans))
                {
                    cout<<"Enter a valid option: ";
                }
            }while(!isalpha(ans));
        } while (tolower(ans) == 'y');
    }

    return 0;
}
