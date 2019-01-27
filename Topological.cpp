#include <iostream>
#include<queue>

using namespace std;

class Graph
{
private:
      bool** adjMatrix;
      int Vertices;
public:
      Graph(int nv)
      {
            this->Vertices = nv;
            adjMatrix = new bool*[nv];
            for (int i = 0; i < nv; i++)
            {
                  adjMatrix[i] = new bool[nv];
                  for (int j = 0; j < nv; j++)
                        adjMatrix[i][j] = false;
            }
    }

      void addEdge(int i, int j)
      {
          adjMatrix[i-1][j-1] = true;
    }

      void removeEdge(int i, int j)
      {
          adjMatrix[i-1][j-1] = false;
        }

    void display()
    {
        int i;
        cout<<"    ";
        for(i=0;i<Vertices;i++)
            cout << i+1 << " ";
        cout<<endl;
        for (i = 0; i < Vertices; i++)
        {
            cout << i+1 << " : ";
            for (int j = 0; j < Vertices; j++)
            {
                cout<<adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void indegree (int *arr)
    {
        for(int i=0;i<Vertices;i++)
          {
              for(int j=0;j<Vertices;j++)
              {
                  if(adjMatrix[i][j])
                  {
                      *(arr+j)+=1;
                  }
              }
          }
    }

    void Topological_sort()
    {
        int arr[Vertices];
        queue<int> q ;
        int i , j , hold;
        cout<<"\nTest 1";
        for(i=0;i<Vertices;i++)
        {
            arr[i] = 0;
        }
        cout<<"\nTest 2";
        indegree(arr);
        cout<<"\nTest 3";
        do
        {
            q.pop();
            cout<<"\nTest 4";
            for(i=0;i<Vertices;i++)
            {
                cout<<"\nTest 5";
                if(arr[i]==0)
                    q.push(i);
            }
            cout<<"\nTest 6";
            hold = q.front();
            cout<<"\nTest 7";
            for(j=0;j<Vertices;j++)
            {
                cout<<"\nTest 8";
                if (adjMatrix[hold][j])
                {
                    arr[j]--;
                    adjMatrix[hold][j] = false;
                    cout<<"\nTest 9";
                }
            }
            cout<<"\nTest 10";
            cout<<" "<<(hold+1);
            cout<<"\nTest 11";
        }while(!q.empty());
    }
};


int main()
{
    int n , ch,i,j;
    cout<<"\nEnter the no. of vertices:- ";
    cin>>n;
    Graph obj(n);
    do
    {
        cout<<"\n1.. Add Edges \n2.. Remove Edges \n3.. Topological Sort \n4.. Display"<<endl;
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
                obj.Topological_sort();
                break;
            }
        case 4:
            {
                obj.display();
                break;
            }
        }
        cout<<"\nPress 1 to continue:- ";
        cin>>n;
    }while(n==1);
    return 0;
}


