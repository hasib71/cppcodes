#include<bits/stdc++.h>
using namespace std;


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define MP make_pair
#define pb push_back
#define paii pair<int,int>
#define ll long long
#define sf scanf
#define pf printf
#define SZ(a) int(a.size())
#define mem(a,v) memset(a, v, sizeof(a))


int n, m;

vector<int> graph[57];
bool visited[57];


ll ways = 1;

int dfs(int u)
{
    int len = 1;
    visited[u] = true;

    loop(i, SZ(graph[u]))
    {
        int v = graph[u][i];
        if(!visited[v])
        {
            len += dfs(v);
        }
    }

    return len;

}




int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);


    mem(visited, 0);

    cin>>n>>m;
    int x, y;
    loop(i, m)
    {
        cin>>x>>y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    for(int i=1; i<=n; i++)
        if(!visited[i])
        {
            ll k = dfs(i);
            ways = ways * (1LL<<(k-1));
        }


    cout<<ways<<"\n";



}
