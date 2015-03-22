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

#define MAXX 107
#define INF (1<<29)



int capacity[MAXX][MAXX];

int parent[MAXX];

vector<int>graph[MAXX];

int source, sink, N, m;


int findPath()    // BFS
{
    bool visited[MAXX];

    mem(visited, 0);

    queue<int>Q;

    Q.push(source);

    visited[source] = true;

    mem(parent, -1);

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        loop(i, SZ(graph[u]))
        {
            int v = graph[u][i];

            if(!visited[v] && capacity[u][v] > 0)
            {
                Q.push(v);
                visited[v] = true;
                parent[v] = u;

                if(v == sink)
                {
                    break;
                }
            }
        }
    }


    int v = sink, path_capacity = INF;

    while(parent[v] != -1)
    {
        int u = parent[v];

        path_capacity = min(path_capacity, capacity[u][v] );

        v = u;
    }




    v = sink;

    while(parent[v] != -1)
    {
        int u = parent[v];

        capacity[u][v] -= path_capacity;

        capacity[v][u] += path_capacity;

        v = u;
    }

    if(path_capacity == INF)
        return 0;
    else
        return path_capacity;
}




int FLOW()
{
    int result = 0;

    while(true)
    {
        int pathCapacity = findPath();

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

    int u, v, c;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d", &N);
        sf("%d %d %d", &source, &sink, &m);

        for(int i=0; i<=N; i++)
        {
            graph[i].clear();
        }

        mem(capacity, 0);

        loop(i, m)
        {
            sf("%d %d %d", &u, &v, &c);

            graph[u].pb(v);

            graph[v].pb(u);

            capacity[u][v] = capacity[v][u] = capacity[u][v] + c;
        }

        pf("Case %d: %d\n", ++kaseno, solve());

    }



    return 0;
}
