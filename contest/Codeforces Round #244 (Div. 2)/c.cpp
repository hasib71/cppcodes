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
#define MOD 1000000007

int n;
ll cost[MAXX];

ll minCost = 0;
ll way = 1;

vector<int>graph[MAXX];


int lowlink[MAXX], idx[MAXX];

bool inStack[MAXX];

stack<int>S;


int dTime = 0;

void tarjan(int u)
{
    dump(u);
    lowlink[u] = idx[u] = ++dTime;

    inStack[u] = true;

    S.push(u);

    loop(i, SZ(graph[u]))
    {
        int v = graph[u][i];
        cerr<<" --- v = "<<v<<endl;

        if(idx[v] == -1)
        {
            tarjan(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);


            pf("---lowLink[%d] = %d\n", u, lowlink[u]);

        }
        else if(inStack[v])
        {
            lowlink[u] = min(lowlink[u], idx[v]);
        }
    }


    if(lowlink[u] == idx[u])
    {
        int v;
        vector<int>components;

        while(true)
        {
            v = S.top(); S.pop();
            inStack[v] = false;
            components.pb(v);
            if(u == v) break;
        }

        dump(components);

        ll tmp = (1LL<<35);

        loop(i, SZ(components))
        {
            v = components[i];
            tmp = min(tmp, cost[v]);

        }


        minCost += tmp;

        ll cnt = 0;

        loop(i, SZ(components))
        {
            v = components[i];
            if(cost[v] == tmp) cnt++;
        }

        way = (way*cnt)%MOD;

    }

}







int main()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>cost[i];
    }

    int m, p, q;
    cin>>m;

    loop(i, m)
    {
        cin>>p>>q;
        graph[p].pb(q);
    }

    mem(idx, -1);

    for(int i=1; i<=n; i++)
    {
        if(idx[i] == -1) tarjan(i);
    }



    for(int i=1; i<=n; i++)
    {
        pf("lowLink[%d] = %d\n", i, lowlink[i]);
    }




    cout<<minCost<<" "<<way<<endl;











}
