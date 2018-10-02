#include<iostream>
using namespace std;
struct btnode
{
    int info;
    struct btnode *l,*r;
}*root = NULL, *temp=NULL;

class Binary_tree
{
private:

    void create()
    {
        int info;
        cout<<"\n Enter info :- ";
        cin>>info;
        temp = (struct btnode *)malloc(sizeof(struct btnode));
        temp->info = info;
        temp->l = temp->r = NULL;
    }

    void search(struct btnode *t)
    {

        if(t->l == NULL && t->r==NULL)
        {
            t->l = temp;
            return ;
        }
        else
        {
            if(t->l == NULL &&t->r!=NULL )
            {
                t->l = temp;
                return ;
            }
            else
            {
                if(t->r == NULL &&t->l!=NULL )
                {
                    t->r = temp;
                    return ;
                }
                if(t->l!=NULL && t->r!=NULL)
                {
                    struct btnode *t1 = root->l;
                    struct btnode *t2 = root->r;
                    if(t1->l ==NULL || t1->r==NULL )
                        search(root->l);
                    else if(t2->l ==NULL || t2->r==NULL)
                        search(root->r);
                }
            }
        }
    }

    int height(struct btnode* node)
    {
        if (node==NULL)
            return 0;
        else
        {
            int lheight = height(node->l);
            int rheight = height(node->r);
            if (lheight > rheight)
                return(lheight+1);
            else
                return(rheight+1);
        }
    }
    void printGivenLevel(struct btnode* root, int level)
    {
        if (root == NULL)
            return;
        if (level == 1)
            cout<<(root->info)<<"\t";
        else if (level > 1)
        {
            printGivenLevel(root->l, level-1);
            printGivenLevel(root->r, level-1);
        }
    }
public:
    void insert()
    {
        create();
        if (root == NULL)
            root = temp;
        else
            search(root);
    }
    void printLevelOrder(struct btnode* root)
    {
        int h = height(root);
        int i;
        for (i=1; i<=h; i++)
            printGivenLevel(root, i);
    }
    void inorder(struct btnode *t)
    {
        if(t!=NULL)
        {
            inorder(t->l);
            cout<<(t->info)<<"\t";
            inorder(t->r);
        }
    }
};
int main()
{
    Binary_tree obj;
    int n;
    cout<<"\nEnter the no. of elements you want to enter in the Binary Tree:- ";
    cin>>n;
    for(int i=0 ; i<n;i++)
        obj.insert();

    cout<<"\nLevel OrderTraversal:-"<<endl;
    obj.printLevelOrder(root);

    cout<<"\nInorder Traversal:-"<<endl;
    obj.inorder(root);

    return 0;
}
