#include<iostream>
#define V 5
#define INF 99999
using namespace std;

void printSolution(int dist[][V]);
void floydWarshall (int graph[][V])
{
      int dist[V][V], i, j, k;
     for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < V; k++)
    {

        for (i = 0; i < V; i++)
        {

            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
  printSolution(dist);
}

void printSolution(int dist[][V])
{
    cout<< "The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                cout<<"\tINF";
            else
                cout<<"\t" <<dist[i][j];
        }
        cout<<"\n";
    }
}

int main()
{
    /* Let us create the following weighted graph
            10
       (0)------->(3)
        |         /|\
      5 |          |
        |          | 1
       \|/         |
       (1)------->(2)
            3           */
    int graph[V][V] = { {0,   2,  INF, 12,INF},
                        {INF, 0,   3, INF, INF},
                        {INF, INF, 0,   5 ,INF},
                        {INF, INF, INF, 0 ,6},
                        {4,INF,INF,INF,0}
                      };

    floydWarshall(graph);
    return 0;
}
