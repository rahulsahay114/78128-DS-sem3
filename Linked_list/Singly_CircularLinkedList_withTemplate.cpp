#include <iostream>

using namespace std;

template<class t>
struct node
{
    t data;
    node<t> *next;
};

template<class t>
class circularLL
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

template<class t>
char circularLL<t>::repeat(char ans) {


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

template<class t>
bool circularLL<t>::is_empty()
{
    if(head == NULL)
    {
        cout<<"\nList is empty";
        return true;
    }

    else
    {
        return false;
    }
}

template<class t>
void circularLL<t>::insert_end() {

    char ans = 'y';

    do
    {
        t val;
        node<t> *temp;
        node<t> *ptr = new node<t>;

        cout<<"\nEnter Value: ";
        cin>>val;

        ptr->data = val;

        if(head == NULL) //if list is empty.
        {
            head = ptr;
            head->next = head;
        }

        else if(head->next == head) //if only head is present in the list
        {
            head->next = ptr;
            ptr->next = head;
        }

        else
        {
            temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = ptr;
            ptr->next = head;
        }

        ans = repeat(ans);

    }while(tolower(ans) == 'y');
}

template<class t>
void circularLL<t>::traverse() {

    if(is_empty())
    {
        return;
    }

    else
    {
        node<t> *temp = head;

        do
        {
            cout<<" "<<temp->data;
            temp = temp->next;

        }while(temp != head);
    }
}

template<class t>
void circularLL<t>::insert_begin() {

    char ans = 'y';

    if(is_empty())
    {}

    else
    {
        do
        {
            node<t> *ptr = new node<t>;
            cout<<"\nEnter value: ";
            cin>>ptr->data;

            node<t> *temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            ptr->next = head;
            head = ptr;
            temp->next = head;

            ans = repeat(ans);

        }while (tolower(ans) == 'y');
    }
}

template<class t>
void circularLL<t>::insert_at() {

    node<t> *temp = head;
    node<t> *ptr = new node<t>;
    int pos, flag=0;

    if(is_empty())
    {
        return;
    }

    else if(head->next == head) //checking to see if head is the only item.
    {
        cout<<"\nEnter value: ";
        cin>>ptr->data;

        head->next = ptr;
        ptr->next = head;
    }

    else
    {
        cout<<"\nEnter value: ";
        cin>>ptr->data;

        cout<<"Enter position of insertion: ";
        cin>>pos;
        pos--;

        while(flag != pos-1)
        {
            temp = temp->next;
            flag++;
        }

        if(temp->next == head) //if pos was the last node
        {
            temp->next = ptr;
            ptr->next = head;
        }

        else
        {
            ptr->next = temp->next;
            temp->next = ptr;
        }
    }

    cout<<"Appended.";
}

template<class t>
void circularLL<t>::del_begin() {

    char ans = 'y';

    do
    {
        if(is_empty())
        {
            return;
        }

        else if(head->next == head) //checking to see if head is the only item
        {
            head = NULL;
        }

        else //more than one item
        {
            node<t> *temp = head;
            node<t> *temp1 = head;

            while(temp1->next != head)
            {
                temp1 = temp1->next;
            }

            head = head->next;
            temp1->next = head;
            delete(temp);
        }

        ans = repeat(ans);

    }while(tolower(ans) == 'y');
}

template<class t>
void circularLL<t>::del_end() {

    char ans = 'y';

    do {
        if(is_empty())
        {
            return;
        }

        else
        {
            int pos = 0, flag = 0;
            node<t> *temp = head;
            node<t> *temp1 = head;

            if(head->next == head) //if head is the only item.
            {
                head = NULL;
            }

            else
            {
                while(temp->next != head)
                {
                    temp = temp->next;
                    pos++;
                }

                while(flag != pos-1)
                {
                    temp1 = temp1->next;
                    flag++;
                }

                temp1->next = head;
                delete(temp);
            }

            ans = repeat(ans);
        }
    }while(tolower(ans) == 'y');
}

template<class t>
void circularLL<t>::del_at() {

    char ans = 'y';
    do
    {
        if(is_empty()) //checking if list is empty
        {
            return;
        }

        else //if not empty
        {
            node<t> *temp = head;
            node<t> *temp1 = head;
            int pos=0, flag=0;

            if(head->next == head) //checking to see if head is the only item in the list
            {
                head = NULL;
            }

            else //if more than one item
            {
                cout<<"Enter Position to delete: ";
                cin>>pos;
                pos--;

                if(pos == 0) //checking to see if delete at beginning condition is true.
                {
                    del_begin();
                    return;
                }

                else
                {
                    while(flag != pos)
                    {
                        temp = temp->next;
                        flag++;
                    } //moving temp to the node asked to be deleted

                    if(temp->next == head) //checking to see if last node is being asked to be deleted
                    {
                        del_end();
                        return;
                    }

                    else
                    {
                        flag=0;
                        while(flag != pos-1)
                        {
                            temp1 = temp1->next;
                            flag++;
                        } //temp1 at the before the node to be deleted

                        temp1->next = temp->next;
                        delete(temp);
                    }
                }
            }
        }

        ans = repeat(ans);

    }while(tolower(ans) == 'y');
}

template<class t>
void circularLL<t>::reverse() {

    if(is_empty())
    {
        return;
    }

    else
    {
        if(head->next == head)
        {
            cout<<"Only one item in the list. Add more.";
        }

        else
        {
            node<t> *temp;
            node<t> *temp1 = head;
            node<t> *temp2;

            temp = head->next;

            do {
                temp2 = temp->next;
                temp->next = head;
                head = temp;
                temp = temp2;
            }while(temp2 != temp1);


            temp1->next = head;
            cout<<"Reversed.";
        }
    }

}

template<class t>
void circularLL<t>::search() {

    if(is_empty())
    {
        return;
    }

    else
    {
        node<t> *temp = head;
        t key, flag=0, pos=0;

        cout<<"\nEnter Key to search: ";
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
    int datatype = 0;
    cout<<"\t Choose datatype: \n1. int \n2. float. \nEnter your choice: ";
    cin>>datatype;

    circularLL<int> obj;
    circularLL<float> obj1;

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
