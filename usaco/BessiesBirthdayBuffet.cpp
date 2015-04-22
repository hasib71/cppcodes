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


#define MAXX 1007
#define INF (1<<29)

struct DATA{
    ll Q;
    int id;
    bool operator < (const DATA &another) const
    {
        return Q < another.Q;
    }
}nodes[MAXX];



ll Q[MAXX];
int dist[MAXX][MAXX];
int N;
ll E;

vector<int>graph[MAXX];

ll dp[MAXX][MAXX];

ll rec(int lastTaken, int pos)
{
    if(pos > N)
    {
        return 0;
    }
    else
    {
        ll &ret = dp[lastTaken][pos];

        if(ret != -1)
        {
            return ret;
        }
        else
        {
            ret = rec(lastTaken, pos+1);

            ret = max(ret, rec(pos, pos+1) + Q[ nodes[pos].id ] - ((ll)dist[ nodes[lastTaken].id ][ nodes[pos].id ])*E);

            return ret;
        }
    }
}


void bfs(int u)
{
    queue<int>Q;

    bool visited[MAXX];

    mem(visited, 0);

    Q.push(u);

    visited[u] = true;

    dist[u][u] = 0;

    int source = u;

    while(!Q.empty())
    {
        u = Q.front(); Q.pop();

        loop(i, SZ(graph[u]))
        {
            int v = graph[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                dist[source][v] = dist[source][u] + 1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    read("buffet.in");
    write("buffet.out");
    sf("%d %lld", &N, &E);

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            dist[i][j] = INF;
        }
    }

    for(int i=1; i<=N; i++)
    {
        int edges;
        sf("%lld %d", &nodes[i].Q, &edges);




        int v;

        loop(j, edges)
        {
            sf("%d", &v);
            graph[i].pb(v);
        }
        nodes[i].id = i;
    }

    sort(nodes+1, nodes + 1 + N);


    for(int i=1; i<=N; i++)
    {
        Q[ nodes[i].id ] = nodes[i].Q;
    }

    for(int i=1; i<=N; i++)
    {
        bfs(i);
    }


/*
    for(int k=1; k<=N; k++)
    {
        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
*/

    mem(dp, -1);

    for(int i=1; i<=N; i++)
    {
        dist[0][i] = 0;
    }

    Q[0] = 0;

    cout<<rec(0, 1)<<endl;


    /// debugging

    //cout<<graph[2]<<endl;
    //dump(dist[1][5]);






    return 0;
}

