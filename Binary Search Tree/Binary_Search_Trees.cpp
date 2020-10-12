#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int leaf = 0;
int non_leaf = 0;
int tot_nodes = 0;

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
    node* insert(node*, int);
    node* newNode(int);
    void search(int);
    void rec_preorder(node*);
    void rec_postorder(node*);
    void rec_inorder(node*);
    void itr_preorder();
    void itr_inorder();
    void itr_postorder();
    void bfs();
    void mirror(node*);
    void count(node*);
    int height(node* node);
    node* delete_node(node*, int);
    node* change_key(node*, int old_val, int new_val);
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

    stack<node*> s; //empty stack, with elements of type 'node*'

    node* ptr = root; //set ptr as root

    while(ptr != NULL || s.isempty() == false)
    {
        while(ptr != NULL)
        {
            s.push(ptr);
            ptr = ptr->left;
        }

        ptr = s.top->val;
        //'top' is of type 'nodee*'(node struct defined in 'stack.h')
        // which is a node structure with element of type 'node*' in it as 'val'.
        // Thus 'val' of type 'node*' in  'top' of type 'nodee*' contains the actual integer 'val'.

        s.pop();

        cout<<ptr->val<<" "; //actual integer 'val' being displayed

        ptr = ptr->right;
    }
}

void bst::bfs() {

    if (root == NULL)
        return;

    queue<node*> q;
    //a queue of 'node*' (struct node pointer) therefore each 'val' of the queue will store a whole 'node*' object.
    //thus each 'val' of the queue 'q' will have a 'val' ('node*' defined in this program) with it's own 'left', 'right',
    //and 'val' (an integer).

    q.enqueue(root); //push root into the queue.

    while(q.is_empty() == false)
    {
        node_q<node*>* ptr = q.top;

        cout<<ptr->val->val<<" ";

        q.dequeue(); //pop from queue

        if (ptr->val->left != NULL)
            q.enqueue(ptr->val->left);

        if (ptr->val->right != NULL)
            q.enqueue(ptr->val->right);

    }

}

void bst:: mirror(node *n)
{
    //for a better understanding do a dry run.

    node *ptr = n; //node for traversal

    if(ptr == NULL) //base case.
        return;

    else
    {
        //recursively swap the left subtree first and then the right subtree.
        mirror(ptr->left);
        mirror(ptr->right);

        //swapping the terms
        node* temp = ptr->left;
        ptr->left = ptr->right;
        ptr->right = temp;
    }
}

void bst::count(node* n)
{
    node* ptr = n;

    if(ptr->left == NULL && ptr->right == NULL)
    {
        leaf++;
        return;
    }

    else
    {
        non_leaf++;
        count(ptr->left);
        count(ptr->right);
    }
}

node* bst::delete_node(node *n, int key) { //done via deletion by copying

    node* ptr = n;

    if(ptr == NULL) //base case
        return ptr;

    //if key to be deleted is smaller than the 'val' at 'ptr' then it lies in the left subtree of 'ptr'
    if(key < ptr->val)
        delete_node(ptr->left, key); //moving to the left subtree of 'ptr'

    //if key to be deleted is greater than the 'val' at 'ptr' then it lies in the right subtree of 'ptr'
    else if(key > ptr->val)
        delete_node(ptr->right, key); //moving to the left subtree of 'ptr'

    else //key equal to the value at the node 'ptr'
    {
        //for nodes with only one child or no child
        if(ptr->left == NULL)
        {
            node* temp = ptr->right; //temp will store the value of the right subtree of 'ptr'
            delete ptr; //deleting the node which has the same key value as given by user
            return temp; //returning 'temp' so we can use this node to run insert from.
        }

        if(ptr->right == NULL)
        {
            node* temp = ptr->left; //temp will store the value of the left subtree of 'ptr'
            delete ptr; //deleting the node which has the same key value as given by user
            return temp; //returning 'temp' so we can use this node to run insert from.
        }

        // node with two children: getting the inorder successor (smallest in the right subtree)
        node *temp = ptr->right;

        while (temp->left != NULL) //loop down to find the leftmost leaf in the right subtree of ptr as temp = ptr->right.
        {
            temp = temp->left;
        }

        ptr->val = temp->val; //setting the 'val' of 'ptr' to that of the leftmost leaf's in the right subtree of 'ptr'.

        ptr->right = delete_node(ptr->right, temp->val);
        //deleting the leftmost leaf in the right subtree of ptr.
    }
    return ptr;
}

node *bst::change_key(node *root, int old_val, int new_val) {

    // First delete old key value
    root = delete_node(root, old_val);

    // Then insert new key value
    root = insert(root, new_val);

    // Return new root
    return root;
}

node *bst::insert(node *node, int key) {

    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->val)
        node->left = insert(node->left, key);

    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

node* bst:: newNode(int item)
{
    node *temp = new node;
    temp->val = item;
    temp->left = temp->right = NULL;
    return temp;
}

int bst::height(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int l_height = height(node->left);
        int r_height = height(node->right);

        /* using the larger one */
        if (l_height > r_height)
            return(l_height + 1);
        else
            return(r_height + 1);
    }
}

int main() {

    bst obj;

    int ch, k=0, old_value =0, new_value=0, h=0;
    char ans = 'y';

    do {

        cout<<"\nMENU.";
        cout<<"\n1. Insert. \n2. Search a Node. \n3. Recursive Preorder. \n4. Recursive Postorder \n5. Recursive Inorder"
              "\n6. Iterative Preorder. \n7. Iterative Postorder. \n8. Iterative Inorder. \n9. Level by level Traversal"
              "\n10. Mirror Image. \n11. Count non-leaf, leaf and total nodes. \n12. Search and Replace."
              "\n13. Deletion by copying. \n14. Deletion by merging. \n15. Height of the Tree.";

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

            case 9:
                obj.bfs();
                break;

            case 10:
                obj.mirror(obj.root);
                cout<<"\nConverted to Mirror Tree! \nInorder Traversal of New Tree: ";
                obj.rec_inorder(obj.root);
                break;

            case 11:
                obj.count(obj.root);
                tot_nodes = leaf + non_leaf;
                cout<<"Leaf Nodes: "<<leaf<<"\nNon-Leaf Nodes: "<<non_leaf<<"\nTotal Nodes: "<<tot_nodes;
                break;

            case 12:
                cout<<"\nEnter Old Value: ";
                cin>>old_value;
                cout<<"Enter New Value: ";
                cin>>new_value;

                obj.change_key(obj.root, old_value, new_value);
                break;

            case 13:
                cout<<"\nEnter Value to delete: ";
                cin>>new_value;
                obj.delete_node(obj.root, new_value);

            case 15:
                h = obj.height(obj.root);
                cout<<"\nHeight: "<<h;
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