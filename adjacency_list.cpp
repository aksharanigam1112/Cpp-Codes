#include <iostream>
using namespace std;
struct Node
{
    int val;
    struct Node* next;

};
struct AdjList
{
    struct Node *head;
};

class Graph
{
private:
    int Vertices;
    struct AdjList* arr;
public:
    Graph(int v)
    {
        this->Vertices = v;
        arr = new AdjList [v];
        for (int i = 0; i < Vertices; ++i)
        {
            arr[i].head = NULL;
        }
    }

    Node* newNode(int val)
    {
        Node* temp = new Node;
        temp->val = val;
        temp->next = NULL;
        return temp;

    }

    void addEdge(int src, int dest)
    {
         Node* ptr = newNode(dest);
        ptr->next = arr[src-1].head;
        arr[src-1].head = ptr;
    }

     void removeEdge(int src, int dest)
    {
        Node* ptr = arr[src-1].head;
        arr[src-1].head = ptr->next;
        delete ptr;

    }
    void display()
    {
         int i;
         for (i = 0; i < Vertices; i++)
            {
                Node* ptr = arr[i].head;
                cout<<"\n Adjacency list of vertex "<<i+1<<" is:- ";
                while (ptr)
                {
                    cout<<ptr->val<<" , ";
                    ptr = ptr->next;
                }
                cout<<endl;
            }
    }
};
int main()
{
    int n , ch,i,j,k;
    cout<<"\nEnter the no. of vertices:- ";
    cin>>n;
    Graph obj(n);
    do
    {
        cout<<"\n1.. Add Edges \n2.. Remove Edges \n3.. Display"<<endl;
        cin>>ch;
        switch(ch)
        {
        case 1:
            {
                cout<<"\nEnter the nodes to add an edge:- ";
                cin>>i>>j;
                obj.addEdge(i,j);
                break;
            }
        case 2:
            {
                cout<<"\nEnter the nodes to remove an edge:- ";
                cin>>i>>j;
                obj.removeEdge(i,j);
                break;
            }
        case 3:
            {
                obj.display();
                break;
            }
        }
        cout<<"\nPress 1 to continue:- ";
        cin>>k;
    }while(k==1);
    return 0;
}


