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

ll busyNess[MAXX];

int n;
int m;
int q;

vector<paii>edges;

ll dist[MAXX];

ll cube(ll x)
{
    return x*x*x;
}

/*
void floydWarshall()
{
    //mem(dist, 1);

    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                pf("dist[%d][%d] = %lld\n", i, j, dist[i][j]);
            }
        }
    }
}
*/

void bellmanFord()
{
    for(int i=1; i<=n; i++)
    {
        dist[i] = INF;
    }

    dist[1] = 0;

    loop(i, n-1)
    {

        loop(j, SZ(edges))
        {
            int u = edges[j].fr;
            int v = edges[j].sc;
            ll x = cube( busyNess[v] - busyNess[u] );

            if( (dist[u] != INF) &&  (dist[v] > dist[u] + x) )
            {
                dist[v] = dist[u] + x;
            }

        }

    }

    loop(i, 1)
    {
        loop(j, SZ(edges))
        {
            int u = edges[j].fr;
            int v = edges[j].sc;
            ll x = cube( busyNess[v] - busyNess[u] );

            if((dist[u] != INF) && (dist[v] > dist[u] + x) )
            {
                dist[v] = -1;
            }
        }
    }



}


int main()
{
    int kases, kaseno = 0;

    take(kases);

    while(kases--)
    {
        take(n);

        for(int i=1; i<=n; i++)
        {
            take(busyNess[i]);
        }

        take(m);

        int u, v;

        edges.clear();

        loop(i, m)
        {
            take(u, v);
            edges.pb(MP(u, v));
        }

        bellmanFord();


        take(q);

        pf("Case %d:\n", ++kaseno);

        while(q--)
        {
            take(v);

            if(dist[v] < 3 || dist[v] == INF)
                pf("?\n");
            else
                pf("%lld\n", dist[v]);
        }


    }




}
