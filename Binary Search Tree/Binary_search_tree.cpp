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
            root->val = temp;
            root->left = NULL;
            root->right = NULL;
        }

        else if (root->right == NULL || root->left == NULL) //tree has only a root value
        {
            node* ptr = new node;
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

int main() {

    bst obj;
    obj.insert();

    return 0;
}
