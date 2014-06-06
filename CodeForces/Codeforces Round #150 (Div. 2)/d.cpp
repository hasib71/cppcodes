#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


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
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args
#define debug(args...) asdfg,args; cout<<endl
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
struct ASDFG{
    template<typename T>
    ASDFG& operator,(vector<T> &v){
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v)){
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }

    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }


}asdfg;



//Header ends here

#define MAXX 100004

int deg[MAXX];

vector<paii> edges;
int h, t;
vector<int>graph[MAXX];
int isAchived[MAXX];

int isValid(int u, int v)
{
    if(deg[u] < h+1 || deg[v] < t+1 )
    {
        return 0;
    }



    loop(i, SZ(graph[u]))
    {
        isAchived[ graph[u][i] ]++;
    }


    int duplicate = 0;

    loop(i, SZ(graph[v]))
    {
        if(isAchived[ graph[v][i] ])
        {
            duplicate++;
            isAchived[graph[v][i] ]++;
        }
    }

    if(deg[u] + deg[v] - duplicate - 2 >= h+t)
    {
        return 1;
    }
    else
    {
        loop(i, SZ(graph[u])) isAchived[ graph[u][i] ] = 0;
        return 0;
    }
}


void generateSolution(int u, int v)
{
    vector<int>v1, v2, com;

    loop(i, SZ(graph[u]))
    {
        if(graph[u][i] == v) continue;
        if(isAchived[ graph[u][i] ] == 1 )
        {
            v1.pb( graph[u][i] );
        }
        else
        {
            com.pb(graph[u][i]);
        }
    }


    loop(i, SZ(graph[v]))
    {
        if(graph[v][i] == u) continue;
        if( isAchived[ graph[v][i] ] == 0 )
        {
            v2.pb(graph[v][i]);
        }
    }


    int pos = 0;
    while(SZ(v1) < h)
    {
        v1.pb(com[pos++]);
    }

    while(SZ(v2) < t)
    {
        v2.pb(com[pos++]);
    }

    pf("YES\n");
    pf("%d %d\n", u, v);

    pf("%d", v1[0]);
    FOR(i,1,h)
    {
        pf(" %d", v1[i]);
    }
    pf("\n");
    pf("%d", v2[0]);
    FOR(i,1,t)
    {
        pf(" %d", v2[i]);
    }
    pf("\n");

}



int main()
{
    int n, m, u, v;

    take(n, m, h, t);

    loop(i, m)
    {
        take(u, v);
        edges.pb(MP(u, v));

        deg[u]++; deg[v]++;

        graph[u].pb(v); graph[v].pb(u);
    }

    bool possible = false;
    loop(i, m)
    {
        if(isValid(edges[i].fr, edges[i].sc))
        {
            possible = 1;
            generateSolution(edges[i].fr, edges[i].sc);
            break;
        }
        else if(isValid(edges[i].sc, edges[i].fr))
        {
            possible=1;
            generateSolution(edges[i].sc, edges[i].fr);
            break;
        }
    }

    if(!possible) cout<<"NO\n";


}
