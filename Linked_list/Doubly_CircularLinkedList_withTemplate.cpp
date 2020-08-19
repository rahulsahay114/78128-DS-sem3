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
class doubleCLL
{
    node<t> *head = NULL;

public:

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

    static char repeat(char ans) ;

    ~doubleCLL()
    {
        delete(head);
    }
};

bool check(char ans)
{
    if(isdigit(ans))
    {
        return false;
    }

    else if(ans == 'y')
    {
        return true;
    }

    else if(ans == 'n')
    {
        return true;
    }

    else
    {
        return false;
    }
}

template <class t>
char doubleCLL<t>::repeat(char ans) {

    cout<<"Done."<<endl;
    cout<<"Repeat?(y/n): ";
    cin>>ans;

    while(!check(ans)) //to see if the input by the user is valid or not
    {
        //input is invalid then this block is executed.
        cout<<endl<<"Enter a valid option (y/n): ";
        cin>>ans;
    }

    return ans;
}

template <class t>
bool doubleCLL<t>::is_empty() {

    if(head == NULL)
    {
        cout<<"\nList is empty.";
        return true;
    }

    else
    {
        return false;
    }
}

template <class t>
void doubleCLL<t>::insert_end() {

    char ans = 'y';

    do
    {
        t val;
        node<t> *temp = head;
        node<t> *ptr = new node<t>;

        cout<<"\nEnter Value: ";
        cin>>val;

        ptr->data = val;

        if(head == NULL) //empty list
        {
            head = ptr;
            head->next = ptr;
            head->prev = ptr;
        }

        else if(head->next  == head) //just one item.
        {
            head->next = ptr;
            ptr->prev = head;
            ptr->next = head;
            head->prev = ptr;
        }

        else
        {
            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = head;
            head->prev = ptr;
        }
        ans = repeat(ans);
    }while(tolower(ans) == 'y');
}

template <class t>
void doubleCLL<t>::traverse() {

    node<t> *temp = head;

    do
    {
        cout<<" "<<temp->data;
        temp = temp->next;

    }while(temp != head);

}

template <class t>
void doubleCLL<t>::insert_begin() {

    char ans = 'y';

    do
    {
        if(is_empty()) //if empty
        {
            node<t> *ptr = new node<t>;
            cout<<"\nEnter Value: ";
            cin>>ptr->data;

            head = ptr;
            head->next = ptr;
            head->prev = ptr;
        }

        else //not empty.
        {
            node<t> *ptr = new node<t>;
            cout<<"\nEnter Value: ";
            cin>>ptr->data;

            node<t> *temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }

            head->prev = ptr;
            ptr->next = head;

            head = ptr;

            temp->next = head;
            ptr->prev = temp;
        }

        ans = repeat(ans);

    }while(tolower(ans) == 'y');
}

template <class t>
void doubleCLL<t>::insert_at() {

    if(is_empty())
    {
        return;
    }

    else
    {
        if(head == NULL) //empty list
        {
            node<t> *ptr = new node<t>;
            cout<<"Enter Value: ";
            cin>>ptr->data;

            head = ptr;
            head->next = ptr;
            head->prev = ptr;
        }

        else if(head->next == head) //exactly one item
        {
            node<t> *ptr = new node<t>;
            cout<<"Enter Value: ";
            cin>>ptr->data;

            head->next = ptr;
            ptr->prev = head;
            ptr->next = head;
            head->prev = ptr;
        }

        else //more than one item.
        {
            int pos, flag=0;
            cout<<"\nEnter position of insertion: ";
            cin>>pos;
            pos--;

            if(pos == 0) //if user asked to insert node at the beginning
            {
                insert_begin();
            }

            else
            {
                node<t> *temp = head;

                while(flag != pos-1)
                {
                    temp = temp->next;
                    flag++;
                }

                if(temp->next == head) //if the user asked to insert node at the end
                {
                    insert_end();
                }

                else
                {
                    node<t> *ptr = new node<t>;
                    cout<<"Enter Value: ";
                    cin>>ptr->data;

                    ptr->prev = temp;
                    ptr->next = temp->next;
                    temp->next = ptr;
                    temp->next->prev = ptr;
                }
            }
        }
    }
}

template <class t>
void doubleCLL<t>::del_begin() {

    char ans = 'y';

    do
    {
        if(is_empty()) //if list is empty, cannot delete.
        {
            return;
        }

        else //not empty
        {
            if(head->next == head) //if exactly one item
            {
                head = NULL;
            }

            else //more than one item
            {
                node<t> *temp = head;
                node<t> *temp1;

                head = head->next;
                head->prev = temp->prev;
                temp1 = temp->prev;
                temp1->next = head;
                delete(temp);
            }
        }

        ans = repeat(ans);

    }while(tolower(ans) == 'y');
}

template <class t>
void doubleCLL<t>::del_end() {

    char ans = 'y';
    do
    {
        if(is_empty()) //if list is empty, cannot delete.
        {
            return;
        }

        else //not empty
        {
            if(head->next == head) //exactly one item.
            {
                head = NULL;
            }

            else //more than one item.
            {
                node<t> *temp = head->prev;
                node<t> *temp1 = temp->prev;

                temp1->next = temp->next;
                head->prev = temp1;
            }
        }

        ans = repeat(ans);

    }while(tolower(ans) == 'y');
}

template <class t>
void doubleCLL<t>::del_at() {

    if(is_empty()) //if list is empty, we cannot delete
    {
        return;
    }

    else //list not empty
    {
        int pos, flag=0;
        node<t> *temp = head;

        if(head->next == head) //if head is the only item in the list
        {
            head = NULL;
        }

        else //more than one item in the list
        {
            cout<<"\nEnter Position to delete: ";
            cin>>pos;

            if(pos == 1) //checking if delete at beginning condition true
            {
                del_begin();
                return;
            }

            else
            {
                while(flag != pos-1)
                {
                    temp = temp->next;
                    flag++;
                }

                if(temp->next == head) //delete at end condition true if temp is the last node,
                    // and the last node's 'next' always points to the head in a circular list.
                {
                    del_end();
                    return;
                }

                else
                {
                    node<t> *temp1 = temp->prev;
                    temp1->next = temp->next;
                    temp->next->prev = temp1;
                    delete(temp);
                }
            }
        }
    }

}

template <class t>
void doubleCLL<t>::reverse() {

    if(is_empty()) //empty list
    {
        return;
    }

    else //list not empty
    {
        node<t> *temp = head->prev;
        node<t> *temp1 = head->prev;

        do
        {
            cout<<" "<<temp->data;
            temp = temp->prev;
        }while(temp != temp1);
    }
}

template <class t>
void doubleCLL<t>::search() {

    if(is_empty())
    {
        return;
    }

    else
    {
        node<t> *temp = head;
        int key, pos=0, flag=0;

        cout<<"\nEnter Key to search for: ";
        cin>>key;

        do
        {
            if(temp->data == key)
            {
                pos = flag;
                break;
            }
            flag++;
            temp = temp->next;

        }while(temp != head);

        cout<<key<<" Found at: "<<pos+1;
    }

}

int main()
{
    cout<<"\t Choose datatype: \n1. int \n2. float. \nEnter your choice: ";
    int datatype;
    cin>>datatype;

    doubleCLL<int> obj;
    doubleCLL<float> obj1;

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
                    cout<<"Exiting...";
                    exit(0);
                    break;

                default:
                    cout<<"\nEnter a valid choice.";

            }

            do {
                cout << "\nMenu?(y/n)";
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
                    cout<<"Exiting...";
                    exit(0);
                    break;

                default:
                    cout<<"\nEnter a valid choice.";

            }

            do {
                cout << "\nMenu?(y/n)";
                cin >> ans;

                if(!isalpha(ans))
                {
                    cout<<"Enter a valid option: ";
                }
            }while(!isalpha(ans));


        } while (tolower(ans) == 'y');
    }
}
