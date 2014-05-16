/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



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


//Header ends here

#define MAXX 100007


int n;
vector<int>graph[MAXX];

int color[MAXX], expected[MAXX];
bool visited[MAXX];

ll cnt = 0;

vector<int>v;


void dfs(int u, int len, int oddcnt, int evencnt)
{
    visited[u] = true;
    int *p;

    if(len%2)
    {
        p = &oddcnt;
    }
    else
    {
        p = &evencnt;
    }



    if((*p) % 2 )
    {
        color[u] = color[u]?0:1;
    }


    if(color[u] == expected[u])
    {
        loop(i, SZ(graph[u]))
        {
            if(!visited[graph[u][i] ])
                dfs(graph[u][i], len+1, oddcnt, evencnt);
        }
    }
    else
    {
        v.pb(u);
        cnt++;

        if(len%2)
        {
            oddcnt++;
        }
        else
        {
            evencnt++;
        }

        loop(i, SZ(graph[u]))
        {
            if(!visited[graph[u][i] ])
                dfs(graph[u][i], len+1, oddcnt, evencnt );
        }
    }


}






int main()
{
    cin>>n;

    int p, q;
    loop(i, n-1)
    {
        cin>>p>>q;
        graph[p].pb(q);
        graph[q].pb(p);
    }

    for(int i=1; i<=n; i++)
    {
        cin>>color[i];
    }

    for(int i=1; i<=n; i++)
    {
        cin>>expected[i];
    }

    dfs(1, 0, 0, 0);

    cout<<cnt<<endl;
    sort(all(v));
    loop(i, SZ(v))
    {
        cout<<v[i]<<endl;
    }

}
