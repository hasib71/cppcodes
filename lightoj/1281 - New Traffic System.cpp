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

#define MAXX 10003

struct graphNode{
    int weight;
    int v;
    bool isProposedRoad;
};
struct node{
    int cost;
    int used;
    int u;

    bool operator<(const node &ob) const
    {
        return this->cost > ob.cost;
    }
};



vector<graphNode>graph[MAXX];
int n, m, k, d;
int dist[11][MAXX];



int dijkstra()
{
    //cerr<<endl;
    node u, v;
    u.u = u.cost = u.used = 0;

    mem(dist, 1);
    dist[0][0] = 0;


    priority_queue<node>Q;
    Q.push(u);


    while(!Q.empty())
    {
        u = Q.top(); Q.pop();
        //cerr<<"dist["<<u.u<<"]["<<u.used<<"] = "<<u.cost<<endl;
        if(u.cost != dist[u.used][u.u]) continue;
        if(u.u == n-1)
        {
            //dump(u.cost);
            return u.cost;
        }

        loop(i, SZ(graph[u.u]))
        {
            //cerr<<u.u<<" -->"<<graph[u.u][i].v<<endl;
            v.u = graph[u.u][i].v;
            v.cost = graph[u.u][i].weight + u.cost;
            v.used = u.used + (graph[u.u][i].isProposedRoad?1:0);


            if(v.used <= d && v.cost < dist[v.used][v.u] )
            {
                dist[v.used][v.u] = v.cost;
                Q.push(v);
                //cerr<<"pushing "<<v.u<<" with cost "<<v.cost<<endl;
            }
        }
    }

    return -1;
}




int main()
{
    int kases, kaseno = 0;

    take(kases);

    while(kases--)
    {



        graphNode aNode;
        take(n, m, k, d);


        loop(i, n) graph[i].clear();

        int u, v, w;
        aNode.isProposedRoad = false;
        loop(i, m)
        {
            take(u, v, w);
            aNode.weight = w;
            aNode.v = v;
            graph[u].pb(aNode);
        }

        aNode.isProposedRoad = true;

        loop(i, k)
        {
            take(u, v, w);
            aNode.weight = w;
            aNode.v = v;
            graph[u].pb(aNode);
        }

        int res = dijkstra();
        if(res == -1) pf("Case %d: Impossible\n", ++kaseno);
        else pf("Case %d: %d\n", ++kaseno, res);


    }



}
