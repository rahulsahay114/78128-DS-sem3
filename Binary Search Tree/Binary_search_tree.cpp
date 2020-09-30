#include <iostream>
using namespace std;

struct node {
    int val;
    node* left;
    node* right;
};

class bst {

public:
    node *root;

    bst()
    {
        root = NULL;
    }

    void insert();
    void search(int);
};

void bst ::insert() {

    char ans = 'y';
    while(ans == 'y')
    {
        int temp;
        cout<<"\nEnter Value: ";
        cin>>temp;

        if(root == NULL) //empty tree
        {
            root = new node;
            root->val = temp;  //root node given the value entered by user
            root->left = NULL;
            root->right = NULL;
        }

        else if (root->right == NULL || root->left == NULL) //tree has only a root value
        {
            node* ptr = new node; //node to be inserted

            ptr->val = temp;
            ptr->right = ptr->left = NULL;

            if(temp < root->val && root->left == NULL)
            {
                root->left = ptr;
            }

            else if(temp > root->val && root->right == NULL)
            {
                root->right = ptr;
            }

            else
            {
                goto trav_ins;
            }
        }

        else //tree has more just a root value
        {
            trav_ins:
            //node for traversal
            node* ptr = root;

            //node which will be inserted
            node* ins = new node;
            ins->val = temp;
            ins->left = NULL;
            ins->right = NULL;

            while(ptr->left != NULL || ptr->right != NULL)
            {
                if(temp < ptr->val && ptr->left != NULL)
                {
                    ptr = ptr->left;
                }

                else if (temp > ptr->val && ptr->right != NULL)
                {
                    ptr = ptr->right;
                }

                else
                {
                    break;
                }
            }

            if(temp < ptr->val)
                ptr->left = ins;

            else
                ptr->right = ins;
        }

        cout<<"Continue: ";
        cin>>ans;
    }

}

void bst::search(int key)
{
    if(key == root->val)
    {
        cout<<"Key Found!";
        return;
    }

    else
    {
        node* temp;
        temp = root;

        int flag = -1;

        while(flag != 1)
        {
            if(key < temp->val )
            {
                temp = temp->left;
            }

            else if(key > temp->val)
            {
                temp = temp->right;
            }

            else if(temp->val == key)
            {
                flag = 1; //found
                cout<<"Key Found!";
                break;
            }
        }

    }
}

int main() {

    bst obj;
    obj.insert();

    int k=0;
    cout<<"\nEnter value to search: ";
    cin>>k;
    obj.search(k);

    return 0;
}
