#include <iostream>
using namespace std;

struct node
{
    int val;
    node* parent;
    node* left;
    node* right;
    int height; //height of the node.

    //int bf = 0; //balance factor = (height of right sub-tree) - (height of left sub-tree).
};

class avl
{
public:

    node *root;

    avl()
    {
        root = NULL;
    }

    node* newnode(int key, node* p);
    node* insert(int, node*);
    node* del(int, node*);
    node* rotate_right(node* r);
    node* rotate_left(node* r);
};

node* avl::newnode(int key, node* p) {

    node *temp = new node;
    temp->val = key;
    temp->parent = p; //the parent of the newly inserted node will be 'p'.
    temp->height = 1; //new leaf is always having a height of 1.
    temp->left = temp->right = NULL;
}

//utility functions
int max(int a, int b)
{
    if(a > b)
        return a;

    else if(b > a)
        return b;

    else
        return a;
}

int height(node* ptr)
{
    if(ptr == NULL)
        return 0;
    else
        return ptr->height;
}

int getBalanceFactor(node* ptr)
{
    int bf = ptr->left->height - ptr->right->height;
    return bf;
}

//right rotating a subtree with rooted at node 'r'
node* avl::rotate_right(node *r) {

    node* temp = r->left; //'temp' stores the left-subtree of 'r'.
    node* temp2 = temp->right; //'temp2' store the right-subtree of the left-child of 'r'.

    temp->right = r; //bringing the root 'r' down to become the right-child of the 'to-be new root' after rotation.
    r->left = temp2;

    //updating the heights
    r->height = 1 + max(height(r->left), height(r->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    //new root
    return temp;
}

//left rotating a subtree with rooted at node 'r'
node* avl::rotate_left(node* r)
{
    node* temp = r->right;
    node* temp2 = temp->left;

    //performing left rotation
    temp->left = r;
    r->right = temp2;

    //updating heights
    r->height = 1 + max(height(r->right), height(r->left));
    temp->height = 1 + max(height(temp->right), height(temp->left));

    //new root
    return temp;
}

//key is the value to be inserted with node 'ptr' as it's parent.
node* avl::insert(int key, node* parent) {

    //bst insertion
    if(parent == NULL)
        return newnode(key, NULL);

    else if(key < parent->val)
        parent->left = insert(key, parent->left);

    else if(key > parent->val)
        parent->right = insert(key, parent->right);

    else //cannot be equal
        return parent;

    parent->height = max(height(parent->right), height(parent->left)) + 1; //incrementing height of the parent.

    int balance_factor = getBalanceFactor(parent); //balance factor of parent.

    /* if difference in the heights of subtrees is not 1, 0, or -1,
     * rotating as needed. */

    //insertion in left child's left sub-tree. (LEFT-LEFT CASE)
    if (balance_factor > 1 && key < parent->left->val)
    {
        //do right-rotation
        return rotate_right(parent);
    }

    //RIGHT-RIGHT CASE
    if (balance_factor < -1 && key > parent->right->val)
    {
        //do left-rotation
        return rotate_left(parent);
    }

    //LEFT-RIGHT CASE
    if (balance_factor > 1 && key > parent->left->val)
    {
        parent->left = rotate_left(parent->left);
        return rotate_right(parent);
    }

    //RIGHT-LEFT CASE
    if (balance_factor < -1 && key < parent->left->val)
    {
        parent->right = rotate_right(parent->left);
        return rotate_left(parent);
    }

    return parent;
}

node* avl::del(int key, node *parent) {

    if(parent != NULL)
    {
        if(parent->val == key)
        {
            node *temp = NULL;
            if(parent->left != NULL && parent->right == NULL)
            {
                temp = parent;
                parent = parent->left;
                delete temp;
            }
            else if(parent->left == NULL && parent->right != NULL)
            {
                node *temp = parent;
                parent = parent->right;
                delete temp;
            }
            else if(parent->left != NULL && parent->right != NULL)
            {
                //getting the Left and Right Sub-Tree
                node *leftTree = parent->left;
                //finding the rightmost Node of the Left Sub-Tree
                node *rightmostLeft = leftTree;
                while(rightmostLeft->right != 0)
                {
                    rightmostLeft = rightmostLeft->right;
                }
                //saving the value to be copied to traverseNode
                int d = rightmostLeft->val;
                parent = del(rightmostLeft->val, parent);
                parent->val = d;
            }
            else if(parent->left == NULL && parent->right == NULL)
            {
                delete parent;
                parent = NULL;
            }
            return parent;
        }
        else if(parent->val < key)
        {
            parent->right = del(key, parent->right);
        }
        else if(parent->val > key)
        {
            parent->left = del(key, parent->left);
        }


        if(parent != NULL)
        {
            int balanceFactor = getBalanceFactor(parent);
            int bfRight = getBalanceFactor(parent->right);
            int bfLeft = getBalanceFactor(parent->left);
            if(balanceFactor > 1 && bfLeft >= 0)
            {
                //Left Left Case
                //Right Rotation
                parent = rotate_right(parent);

            }
            else if(balanceFactor < -1 && bfRight <= 0)
            {
                //Right Right Case
                //Left Rotation
                parent = rotate_left(parent);
            }
            else if(balanceFactor < -1 && bfRight > 0)
            {
                //Right Left Case
                //Right Rotation
                parent->right = rotate_right(parent->right);
                //Left Rotation
                parent = rotate_left(parent);
            }
            else if(balanceFactor > 1 && bfLeft < 0)
            {
                //Left Right Case
                //left rotating
                parent->left = rotate_left(parent->left);
                //right rotating
                parent = rotate_right(parent);
            }
        }
    }

    return parent;

}
int main() {

    avl obj;

    obj.insert(10, obj.root);
    obj.insert(9, obj.root);

    return 0;
}
