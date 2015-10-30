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
#define dump(x) //cerr<<#x<<" = "<<x<<endl
#define debug(args...) //cerr,args; cerr<<endl;
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

#define MAXX 100007
#define INF (1LL<<45)
#define mypair pair<ll, int>

int N, M, S, T, P;
vector<mypair>graph[MAXX];
vector<mypair>revgraph[MAXX];
vector<pair<ll, paii> > edges;

ll dist[MAXX];
ll revdist[MAXX];

void init()
{
    loop(i, MAXX)
    {
        graph[i].clear();
        revgraph[i].clear();
    }

    edges.clear();
}

void dijkstra(int source, int target, vector<mypair> *graph, ll *dist)
{
    loop(i, MAXX) dist[i] = INF;

    dist[source] = 0;

    priority_queue<mypair>Q;

    Q.push(MP(0, source));

    while( ! Q.empty() )
    {
        mypair u = Q.top(); Q.pop();

        if(u.fr > dist[u.sc]) continue;

        loop(i, SZ(graph[u.sc]))
        {
            mypair v;
            v.sc = graph[u.sc][i].sc;
            v.fr = u.fr + graph[u.sc][i].fr;

            if(v.fr < dist[v.sc])
            {
                dist[v.sc] = v.fr;
                Q.push(v);
            }

        }
    }
}




ll solve()
{

    dijkstra(S, T, graph, dist);

    if(dist[T] == INF)
    {
        return -1;
    }
    else
    {
        dijkstra(T, S, revgraph, revdist);

        ll ret = -1;
        ll tmp;

        loop(i, SZ(edges))
        {
            pair<ll, paii> &e = edges[i];

            if( dist[e.sc.fr] != INF && revdist[e.sc.sc] != INF )
            {
                tmp = e.fr + dist[e.sc.fr] + revdist[e.sc.sc];

                if(tmp <= P)
                {
                    //dump(e);
                    ret = max(ret, e.fr);
                }
                else
                {

                }
            }
        }

        return ret;


    }

}

int main()
{

    int kases, kaseno = 0;

    int u, v, c;

    sf("%d", &kases);

    while(kases--)
    {
        init();

        take(N, M, S, T, P);

        loop(i, M)
        {
            sf("%d %d %d", &u, &v, &c);

            graph[u].pb(MP(c, v));
            revgraph[v].pb(MP(c, u));

            edges.pb(MP(c, MP(u, v)));
        }

        pf("Case %d: %lld\n", ++kaseno, solve());
    }




    return 0;
}
