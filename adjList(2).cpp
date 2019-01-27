#include<iostream>
#include<list>
using namespace std;
class Graph
{
private:
    int vertices;
    list<int> *adjlist;
public:
    Graph(int n)
    {
        this->vertices = n;
        adjlist = new list<int> [n];
    }

    void addEdge(int src, int dest)
    {
        adjlist[src-1].push_back(dest);
    }

     void removeEdge(int src, int dest)
    {
        adjlist[src-1].remove(dest);
    }
    void display()
    {
         int i;
         for (i = 0; i < vertices; i++)
            {
                list<int>::iterator it = adjlist[i].begin();
                cout<<"\n Adjacency list of vertex "<<i+1<<" is:- ";
                while(it != adjlist[i].end())
                {
                    cout<<"\t" << *it ;
                    it++;
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



