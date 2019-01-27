#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int data;
    struct node*left , *right;
};

    int height(node*root)
    {
        int h=0;
        if(root!=NULL)
        {
            int lh = height(root->left);
            int rh = height(root->right);
            h = max(lh,rh);

        }
    }
    int diff(node *temp)
    {
        int l = height (temp->left);
        int r = height (temp->right);
        return (l-r);
    }

    node*l_rotate(node*parent)
    {
        node*temp1,*temp2;
        temp1 = parent->right;
        temp2 = temp1->left;
        temp1->left = parent;
        parent->right = temp2;
        return temp1;
    }

    node*r_rotate(node*parent)
    {
        node*temp1,*temp2;
        temp1 = parent->left;
        temp2 = temp1->right;
        temp1->right = parent;
        parent->left = temp2;
        return temp1;
    }
    node*rl_rotate(node*parent)
    {
        parent->right = r_rotate(parent->right);
        return(l_rotate(parent));
    }
    node*lr_rotate(node*parent)
    {
        parent->left = l_rotate(parent->left);
        return(r_rotate(parent));
    }

    node *balance(node *temp)
    {
        int bf = diff (temp);
        if (bf < -1)
        {
            if (diff (temp->right) < 0)
                temp = l_rotate (temp);
            else
                temp = rl_rotate (temp);
        }
        else if (bf > 1)
        {
            if (diff (temp->left) < 0)
                temp = lr_rotate (temp);
            else
                temp = r_rotate (temp);
        }
        return temp;
    }

    node *insert(node *root, int value)
    {

        if (root == NULL)
        {
            root->data = value;
            root->left = NULL;
            root->right = NULL;
        }
       else if (value < root->data)
        {
            root->left = insert(root->left, value);
            root = balance (root);
        }
        else if (value >= root->data)
        {
            root->right = insert(root->right, value);
            root = balance (root);
        }
        return root;
    }

    void display(node*root)
    {
        if(root==NULL)
            return;
        cout<<"\t"<<root->data;
        display(root->left);
        display(root->right);
    }

int main()
{
    int ch,item;

    struct node*root = NULL;
    while(1)
    {
         cout<<"\n 1.Insert Element into the tree";
         cout<<"\n 2.Display Balanced AVL Tree";
         cout<<"\n Enter your Choice: ";
         cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"\n Enter value to be inserted:-  ";
                cin>>item;
                root = insert(root, item);
                break;
            case 2:
                if (root == NULL)
                {
                    cout<<"\n Tree is Empty";
                    continue;
                }
                cout<<"\n Balanced AVL Tree:- ";
                display(root);
                break;
        }
    }
    return 0;
}
