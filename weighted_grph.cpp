#include<bits/stdc++.h>
using namespace std;

void addEdge(vector <pair<int, int> > adj[], int u,int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

void printGraph(vector <pair<int, int> > adj[], int V)
{
    int v, w;

    for (int u = 0; u < V; u++)
    {
        vector<pair<int,int> >::iterator it= adj[u].begin();

        cout << "Node " << u << " makes an edge with \n";

        while( it!=adj[u].end() )
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
            it++;
        }
        cout << "\n";
    }
 }

int main()
{
    int n1,n2,w,ch=0;
    int V;
    cout<<"\nEnter the no. of vertices:- ";
    cin>>V;
    vector <pair<int, int> > adj[V];
    do
    {
     cout<<"\nEnter node1 node2 and weight:- ";
     cin>>n1>>n2>>w;
     addEdge(adj,n1,n2,w);

     cout<<"\nPress 1 to continue:- ";
     cin>>ch;
    }while(ch==1);
    printGraph(adj,V);
    return 0;
}
