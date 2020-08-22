#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

class LList
{
public:

    node *head = NULL;
    void insert();
    void del();
    bool is_empty();
    LList merge(LList);
    void display();

    LList()
    {
        head = NULL;
    }

    ~LList()
    {
        node *temp = head;
        while(temp != NULL)
        {
            delete(temp);
            temp = temp->next;
        }
    }

};

bool LList::is_empty()
{
    if(head == NULL)
    {
        cout<<"\nList is Empty.";
        return true;
    }

    else
    {
        return false;
    }
}

void LList::insert()
{
    node *ptr = new node();

    cout<<"\nEnter Value: ";
    cin>>ptr->data;

    if(head == NULL) //if list empty
    {
        head = ptr;
        ptr->next = NULL;
    }

    else //not empty
    {
        if(head->next == NULL) //just one item
        {
            if(ptr->data > head->data) //if new item bigger than existing item
            {
                head->next = ptr;
                ptr->next = NULL;
            }

            else //if new item smaller than existing item
            {
                ptr->next = head;
                head = ptr;
            }
        }

        else //more than one item
        {
            node *temp = head;
            node *temp1;

            while(temp->next != NULL)
            {
                if(temp->data > ptr->data)
                {
                    break;
                }

                else
                {
                    temp1 = temp; //temp1 will always store the node previous to temp.
                    temp = temp->next;
                }
            }

            if(temp == head) //if first item.
            {
                head = ptr;
                ptr->next = temp;
            }

            else if(temp->data < ptr->data)
            {
                /*if ptr is the greater than all the pre-existing values,
                special case for when there are only 3 nodes in the list.*/

                temp->next = ptr;
                ptr->next = NULL;
            }

            else //insertion in between.
            {
                temp1->next = ptr;
                ptr->next = temp;
            }
        }

    }

    cout<<"Done.";
}

void LList::del() {

    if(is_empty())
    {
        return;
    }

    else
    {

        node *temp = head;
        int pos;

        cout<<"Enter Position to delete: ";
        cin>>pos;
        pos--;

        if(pos == 0)
        {
            head = head->next;
            delete(temp);
        }

        else
        {
            int flag = 0;

            while(flag != pos-1)
            {
                temp = temp->next;
                flag++;
            }

            node *ptr = temp->next;
            temp->next = ptr->next;
            delete(ptr);
        }

    }
}

void LList::display() {

   if(is_empty())
   {
       return;
   }

   else
   {
       node *temp = head;
       while(temp != NULL)
       {
           cout<<temp->data<<" ";
           temp = temp->next;
       }
   }

}

void merge(LList &A, LList &B, LList &result) {

    node *tempA = A.head;
    node *tempB = B.head;
    node *tempR;

    while(tempA != NULL && tempB != NULL)
    {
        if(result.head == NULL) //If result list is empty
        {
            result.head = new node;
            tempR = result.head;

            if(tempA->data < tempB->data)
            {
                tempR->data = tempA->data;
                tempR->next = NULL;
                tempA = tempA->next;
            }

            else if(tempB->data < tempA->data)
            {
                tempR->data = tempB->data;
                tempR->next = NULL;
                tempB = tempB->next;
            }

            else
            {
                tempR->data = tempA->data;
                tempR->next = NULL;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }

        else if(result.head->next == NULL) //just one item in result list
        {
            tempR->next = new node;
            tempR = tempR->next;

            if(tempA->data < tempB->data)
            {
                tempR->data = tempA->data;
                tempR->next = NULL;
                tempA = tempA->next;
            }

            else
            {
                tempR->data = tempB->data;
                tempR->next = NULL;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }

        else if(tempR->next == NULL)//more than one item in result list.
        {
            tempR->next = new node;
            tempR = tempR->next;

            if(tempA->data < tempB->data)
            {
                tempR->data = tempA->data;
                tempR->next = NULL;
                tempA = tempA->next;
            }

            else if(tempB->data < tempA->data)
            {
                tempR->data = tempB->data;
                tempR->next = NULL;
                tempB = tempB->next;
            }

            else
            {
                tempR->data = tempA->data;
                tempR->next = NULL;
                tempA = tempA->next;
                tempB = tempB->next;
            }
        }
    }

    while(tempA != NULL || tempB != NULL)
    {
        tempR->next = new node;
        tempR = tempR->next;

        if(tempA != NULL)
        {
            tempR->data = tempA->data;
            tempA = tempA->next;
            tempR->next = NULL;
        }

        else if(tempB != NULL)
        {
            tempR->data = tempB->data;
            tempB = tempB->next;
            tempR->next = NULL;
        }

        else
        {
            tempA = tempA->next;
            tempB = tempB->next;
        }
    }

    cout<<"\nMerged list: ";
    result.display();
}

bool check(char ans)
{
    if(isalpha(ans))
    {
        if(tolower(ans) == 'y')
        {
            return true;
        }

        else if(tolower(ans) == 'n')
        {
            return true;
        }

        else
        {
            return false;
        }
    }

    else
    {
        return false;
    }

}

int main() {

    int ch;
    char ans = 'y', ans2 = 'y';

    LList obj1, obj2, result;

    do {

        cout<<"\n1. Insert. \n2. Delete \n3. Merge. \n4. Display \n5. Display merged list. \nEnter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                obj1.insert();
                break;

            case 2:
                obj1.del();
                break;

            case 3:
                obj2.~LList();
                cout<<"\nCreating List 2: ";
                do{
                    obj2.insert();
                    cout<<"\nAdd another?(y/n): ";
                    cin>>ans2;

                    while(!check(ans2))
                    {
                        cout<<"Invalid Option.";
                        cout<<"Add another?(y/n): ";
                        cin>>ans;
                    }

                }while(tolower(ans2) == 'y');

                obj2.display();
                merge(obj1, obj2, result);
                break;

            case 4:
                obj1.display();
                break;

            case 5:
                result.display();
                break;

            default:
                cout<<"\nEnter a Valid Choice!";
                break;
        }

        cout<<"\nMenu? (y/n): ";
        cin>>ans;


        while(!check(ans))
        {
            cout<<"Invalid Option.";
            cout<<"\nMenu? (y/n): ";
            cin>>ans;
        }

    }while(tolower(ans) == 'y');

    return 0;
}
