#include <iostream>
#include<vector>
using namespace std;

class Graph
{
private:
      bool** adjMatrix;
      int Vertices;
public:
     vector<int>visited;
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
          int flag=0;
          for(int k=0;k<Vertices;k++)
          {
              if (adjMatrix[i-1][k] == false && k!=j-1)
                flag++;
          }
          if (flag == Vertices-1)
            cout<<"\nCannot be removed";
          else
            adjMatrix[i-1][j-1] = false;
        }

      bool isEdge(int i, int j)
      {
        return adjMatrix[i-1][j-1];
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

    bool find(int ele)
    {
        for(int i=0;i<visited.size();i++)
        {
            if(ele==visited[i])
                return true;
        }
        return false;
    }

    void BFS(int n)
    {

        for(int i=0;i<n;i++)
        {
            if(!find(i))
            {
                    visited.push_back(i+1);
            }
            for(int j=0;j<n;j++)
            {
                if(isEdge(i+1,j+1))
                {
                    if(!find(j))
                    {
                        visited.push_back(j+1);
                    }
                }
            }
        }
    }

    ~Graph()
    {
             delete[] adjMatrix;
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
        cout<<"\n1.. Add Edges \n2.. Remove Edges \n3.. BFS \n4.. Display"<<endl;
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
                obj.BFS(n);

                for(int i=0;i<obj.visited.size();i++)
                {
                    cout<<"\t"<<obj.visited[i];
                }
                break;
            }
        case 4:
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

