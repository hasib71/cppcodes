#include<bits/stdc++.h>
#include "template.cpp"
using namespace std;

///-----------------------------------------------///





#ifndef FLOW_CPP
#define FLOW_CPP




namespace FLOW{


    #define MAXX 100 ///number of nodes
    #define INF (1<<29)


    class flow{
    public:
        int capacity[MAXX][MAXX];
        vector<int>graph[MAXX];
        int source, sink;

        void init()
        {
            loop(i, MAXX)
            {
                graph[i].clear();
            }

            mem(capacity, 0);
        }

        void addEdge(int u, int v, int _capacity = 1)
        {
            graph[u].pb(v);
            graph[v].pb(u);

            capacity[u][v] = _capacity;
        }


        int findPath()
        {
            bool visited[MAXX];
            int parent[MAXX];

            mem(parent, -1);
            mem(visited, 0);

            queue<int>Q;

            Q.push(source);

            visited[source] = true;

            bool found = false;

            while(!Q.empty())
            {
                int u = Q.front(); Q.pop();

                loop(i, SZ(graph[u]))
                {
                    int v = graph[u][i];

                    if(!visited[v] && capacity[u][v] > 0)
                    {
                        visited[v] = true;
                        Q.push(v);

                        parent[v] = u;

                        if(v == sink)
                        {
                            found = true;
                            break;
                        }
                    }
                }

                if(found)
                {
                    break;
                }
            }



            int v = sink;

            int pathCapacity = INF;

            while(parent[v] != -1)
            {
                int u = parent[v];
                pathCapacity = min(pathCapacity, capacity[u][v] );

                v = u;
            }

            v = sink;

            while(parent[v] != -1)
            {
                int u = parent[v];

                capacity[u][v] -= pathCapacity;
                capacity[v][u] += pathCapacity;

                v = u;
            }

            return found?pathCapacity:0;

        }


        int getflow()
        {
            int result = 0;

            int pathCapacity;

            while(pathCapacity = findPath())
            {
                result += pathCapacity;
            }

            return result;
        }
    };

};

int main()
{

}





#endif // FLOW_CPP
