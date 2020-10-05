#include <iostream>
#include "stack.h"
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
    void rec_inorder(node*);
    void itr_preorder();
    void itr_inorder();
    void itr_postorder();
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

void bst::rec_inorder(node * ptr) {

    if(ptr == NULL)
        return;

    rec_inorder(ptr->left);

    cout<<ptr->val<<" ";

    rec_inorder(ptr->right);
}

void bst::itr_preorder() {

    stack<node*> obj; //making the stack of type 'node*' (pointer node) as we'll be pushing pointers into the stack.

    obj.push(root); //pushing the root node


    while(obj.isempty() == false)
    {
        nodee<node*>* ptr = obj.top;
        //nodee is the node in stack.h, added an extra 'e' to remove ambiguity as 'node' is also defined here.

        cout<<ptr->val->val<<" "; //first 'val' stores the 'node*' object and the second 'val' is the actual value stored in that 'node*' object.
        obj.pop(); //popping after printing.


        if(ptr->val->right)
            obj.push(ptr->val->right);

        if(ptr->val->left)
            obj.push(ptr->val->left);
    }
}

void bst::itr_postorder() {

    stack<node*> s1; //stack 1
    stack<node*> s2; //stack 2

    s1.push(root); //push root into stack 1

    while(s1.isempty() == false)
    {
        nodee<node*>* x = s1.top;
        s1.pop(); //popping element from s1.

        s2.push(x->val); //pushing the popped element from stack 1 to stack 2
        //here 'val' is a whole 'node*' with left, right and a int 'val' value.
        //since stack is of type 'node*' therefore we can only push whole 'node*' pointers into it.

        if(x->val->left)
            s1.push(x->val->left); //first, pushing the left child of the popped node, if present.

        if(x->val->right)
            s1.push(x->val->right); //then pushing the right child of the popped node, if present.
    }

    //stack 2 will have the elements of the BST in postorder form.
    while(s2.top->next != NULL)
    {
        cout<<s2.top->val->val<<" ";
        s2.top = s2.top->next;
    }

}

void bst::itr_inorder() {

    stack<node*> s; //empty stack

    node* ptr = root;
    s.push(ptr);

    while(ptr != NULL || s.isempty() == false)
    {
        while(ptr != NULL)
        {
            s.push(ptr);
            ptr = ptr->left;
        }

        ptr = s.top->val;
        s.pop();

        cout<<ptr->val;
    }
}

int main() {

    bst obj;

    int ch, k=0;
    char ans = 'y';

    do {

        cout<<"\nMENU.";
        cout<<"\n1. Insert. \n2. Search a Node. \n3. Recursive Preorder. \n4. Recursive Postorder \n5. Recursive Inorder"
              "\n6. Iterative Preorder. \n7. Iterative Postorder. \n8. Iterative Inorder.";

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

            case 5:
                obj.rec_inorder(obj.root);
                break;

            case 6:
                obj.itr_preorder();
                break;

            case 7:
                obj.itr_postorder();
                break;

            case 8:
                obj.itr_inorder();
                break;

            default: cout<<"\nInvalid!"; break;
        }

        cout<<"\nMenu(y/n): ";
        cin>>ans;

    }while(ans == 'y');

    return 0;
}

//9 5 15 6 3 14 17
//9 5 3 6 15 14 17 pre
//3 6 5 14 17 15 9 post