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
    void rec_preorder(node*);
    void rec_postorder(node*);
};

void bst::insert() {

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

            if(temp == NULL)
            {
                cout<<"Key not Found."; break;
            }
        }

    }
}

void bst::rec_preorder(node* ptr) {

    if(ptr == NULL) //if node is a leaf then return control to upper recursion
        return;

    cout<<ptr->val<<" "; //print out the value

    rec_preorder(ptr->left); //left subtree traversed recursively

    rec_preorder(ptr->right); //right subtree traversed recursively
}

void bst::rec_postorder(node* ptr) {

    if(ptr == NULL)
        return;

    rec_postorder(ptr->left);

    rec_postorder(ptr->right);

    cout<<ptr->val<<" ";
}

int main() {

    bst obj;

    int ch, k=0;
    char ans = 'y';

    do {

        cout<<"\nMENU.";
        cout<<"\n1. Insert. \n2. Search a Node. \n3. Recursive Preorder. \n4. Recursive Postorder";
        cout<<"\n\nEnter your choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                obj.insert();
                break;

            case 2:
                cout<<"\nEnter value to search: ";
                cin>>k;
                obj.search(k);
                break;

            case 3:
                obj.rec_preorder(obj.root);
                break;

            case 4:
                obj.rec_postorder(obj.root);
                break;

            default: cout<<"\nInvalid!"; break;
        }

        cout<<"\nMenu(y/n): ";
        cin>>ans;

    }while(ans == 'y');

    return 0;
}