/****************************************************************
   ▄█    █▄       ▄████████    ▄████████  ▄█  ▀█████████▄
  ███    ███     ███    ███   ███    ███ ███    ███    ███
  ███    ███     ███    ███   ███    █▀  ███   ███    ███
 ▄███▄▄▄▄███▄▄   ███    ███   ███        ███  ▄███▄▄▄██▀
▀▀███▀▀▀▀███▀  ▀███████████ ▀███████████ ███ ▀▀███▀▀▀██▄
  ███    ███     ███    ███          ███ ███    ███    ██▄
  ███    ███     ███    ███    ▄█    ███ ███    ███    ███
  ███    █▀      ███    █▀   ▄████████▀  █▀   ▄█████████▀
****************************************************************/



#include<bits/stdc++.h>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)

#define take(args...) asdf,args
#define dump(x) cerr<<#x<<" = "<<x<<endl
#define debug(args...) cerr,args; cerr<<endl;
using namespace std;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}




template<typename T>
ostream& operator,(ostream& output, T x)
{
    output<<x<<" ";
    return output;
}



struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;



//Header ends here

#define MAXX 207

#define INF (1<<29)

int source, sink;

int N;
int M;

int capacity[MAXX][MAXX];

vector<int>graph[MAXX];

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

    if(found)
    {
        return pathCapacity;
    }
    else
    {
        return 0;
    }

}





int FLOW()
{
    int result = 0;

    int pathCapacity;

    while(true)
    {
        pathCapacity = findPath();

        if(pathCapacity == 0)
        {
            break;
        }
        else
        {
            result += pathCapacity;
        }
    }

    return result;
}





int solve()
{
    return FLOW();
}






void init()
{

}


int main()
{
    init();

    int kases, kaseno = 0;

    int B, D;

    int u, v, c;

    sf("%d", &kases);

    while(kases--)
    {
        mem(capacity, 0);


        sf("%d", &N);

        source = 0;

        sink = 2*(N + 1); // A number out of the range of node id.

        for(int i=0; i<=sink; i++)
        {
            graph[i].clear();
        }


        for(int i=1; i<=N; i++)
        {
            u = 2*i - 1;
            v = u + 1;

            graph[u].pb(v);
            graph[v].pb(u);

            sf("%d", &capacity[u][v]);
        }

        sf("%d", &M);

        loop(i, M)
        {
            sf("%d %d %d", &u, &v, &c);

            u = 2*u;
            v = 2*v - 1;

            graph[u].pb(v);
            graph[v].pb(u);

            capacity[u][v] = c;
        }

        sf("%d %d", &B, &D);

        loop(i, B)
        {
            sf("%d", &u);
            u = 2*u  - 1;

            graph[source].pb(u);
            graph[u].pb(source);

            capacity[ source ][u] = INF;
        }

        loop(i, D)
        {
            sf("%d", &v);
            {
                v = 2*v;

                graph[v].pb(sink);
                graph[sink].pb(v);

                capacity[v][sink] = INF;

            }
        }

        pf("Case %d: %d\n", ++kaseno, solve());

    }



    return 0;
}
