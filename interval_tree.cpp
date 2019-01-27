#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))

using namespace std;

struct interval
{
    int a , b;
};

struct avl_node
{

    int m=0;
    struct avl_node *left;
    struct avl_node *right;
    interval *i;
}*root;

struct avl_node* newnode(struct interval i )
{
    struct avl_node *ptr = new avl_node;
    ptr->i = new interval(i);
    ptr->left = ptr->right = NULL;
    ptr->m = i.b ;
};

int max(int a , int b ,int c)
{
    if(a>=b && a>=c)
        return a;
    if(a>=b &&c>=a)
        return c;
    if(b>=a && b>=c)
        return b;
    if(b>=a && c>=b)
        return c;
}

int height(avl_node *temp)
{
    int h = 0;
    if (temp != NULL)
    {
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

int diff(avl_node *temp)
{
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

avl_node *rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    //parent->m = max(parent->left->m , parent->right->m , parent->m);
    //temp->m = max(temp->m , temp->left->m , temp->right->m);
    return temp;
}
avl_node *ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    //parent->m = max(parent->right->m , parent->left->m , parent->m);
    //temp->m = max(temp->m , temp->right->m , temp->left->m);
    return temp;
}
avl_node *lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
avl_node *rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
avl_node *balance(avl_node *temp)
{
    int bal_factor = diff (temp);
    if (bal_factor > 1)
    {
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }
    else if (bal_factor < -1)
    {
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
avl_node *insert(avl_node *root, interval i)
{
	if (root == NULL)
		{
		    return newnode(i);
		}
	int l = root->i->a;
	if (i.a< l)
    {
        root->left = insert(root->left, i);
        root = balance(root);
    }
    else
    {
        root->right = insert(root->right, i);
        root = balance(root);
    }
	if (root->m < i.b)
		root->m = i.b;
	return root;
}

void inorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<"\n("<<tree->i->a<<","<<tree->i->b<<") max = "<<tree->m;
    inorder (tree->right);
}

void preorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    cout<<"\n("<<tree->i->a<<","<<tree->i->b<<") max = "<<tree->m;
    preorder (tree->left);
    preorder (tree->right);
}
void postorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<"\n("<<tree->i->a<<","<<tree->i->b<<") max = "<<tree->m;
}

bool doOVerlap(interval i1, interval i2)
{
	if (i1.a <= i2.b && i2.a <= i1.b)
		return true;
	return false;
}

avl_node *overlap(avl_node *root, interval i)
{
    if (root == NULL)
        return NULL;
	if (doOVerlap(*(root->i), i))
		return root;
    if (root->left != NULL && root->left->m >= i.a)
		return overlap(root->left, i);
    return overlap(root->right, i);
}

int main()
{
    int choice;
    interval item;
    while (1)
    {
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.InOrder traversal"<<endl;
        cout<<"3.PreOrder traversal"<<endl;
        cout<<"4.PostOrder traversal"<<endl;
        cout<<"5.Overlap"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                {cout<<"Enter range to be inserted: ";
                cin>>item.a>>item.b;
                root = insert(root, item);
                break;}
            case 2:
                {cout<<"Inorder Traversal:"<<endl;
                inorder(root);
                cout<<endl;
                break;}
            case 3:
                {cout<<"Preorder Traversal:"<<endl;
                preorder(root);
                cout<<endl;
                break;}

            case 4:
                {cout<<"Postorder Traversal:"<<endl;
                postorder(root);
                cout<<endl;
                break;}
            case 5:
                {cout<<"Enter range to be checked: ";
                cin>>item.a>>item.b;
                avl_node *ptr = overlap(root , item);
                cout<<"\nOverlapping with :- "<<ptr->i->a <<" " <<ptr->i->b;
                break;}
            case 6:
                {exit(1);
                break;}
            }
        }
    return 0;
}
