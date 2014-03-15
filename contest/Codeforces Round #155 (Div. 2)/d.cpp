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

int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};


#define MAXX 1003
#define vis(u) visited[u.fr][u.sc]
char graph[MAXX][MAXX];
int cnt[MAXX][MAXX];
int n, m, d;

int visited[MAXX][MAXX];

void dfs(paii u)
{

    mem(visited, 0);


    queue<paii>Q;
    Q.push(u);
    vis(u) = 1;
    paii v;

    while(!Q.empty())
    {
        u = Q.front(); Q.pop();
        if(vis(u) <= d)
        {
            loop(i, 4)
            {
                v.fr = u.fr + dirx[i];
                v.sc = u.sc + diry[i];
                if(graph[v.fr][v.sc] != 'X' && vis(v)==0 )
                {
                    vis(v) = vis(u) + 1;
                    Q.push(v);
                }
            }
        }

    }
}
vector<paii>reached;
int dist[MAXX][MAXX];

void bfs2(paii u)
{
    mem(dist, 0);

    queue<paii>Q;
    Q.push(u);
    dist[u.fr][u.sc] = 1;

    reached.clear();
    paii v;

    while(!Q.empty())
    {
        u = Q.front(); Q.pop();
        cnt[u.fr][u.sc]++;
        reached.pb(u);

        if(dist[u.fr][u.sc] <= d)
        {
            loop(i, 4)
            {
                v.fr = u.fr + dirx[i];
                v.sc = u.sc + diry[i];
                if(graph[v.fr][v.sc]!='X' && dist[v.fr][v.sc] == 0)
                {
                    dist[v.fr][v.sc] = dist[u.fr][u.sc] + 1;
                    Q.push(v);

                }
            }
        }
    }
}



void solve()
{

    take(n, m, d);

    vector<paii>R;

    loop(i, n)
    {
        scanf("%s", graph[i]);
        loop(j, m)
        {
            if(graph[i][j] == 'R')
            {
                R.pb(MP(i, j));
            }
        }
    }

    vector<paii>reached;


    loop(i, SZ(R))
    {
        dfs(R[i]);

        loop(j, SZ(R))
        {
            if(!vis(R[i]))
            {

            }
        }

    }

    vector<paii>result;
    loop(i, n)
    {
        loop(j, m)
        {

        }
    }


}

int main()
{


}
