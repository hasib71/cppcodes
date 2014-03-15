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



    template<typename a, typename b>
    ASDFG& operator,(map<a, b> &x)
    {
        cout<<"cam";
        cout<<"("<<x.fr<<", "<<x.sc<<" )";
        return *this;
    }


/*
    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }

    */


}asdfg;



//Header ends here

#define MAXX 100004
    int n, x, y, t;

    vector<paii>problemRoads;
    vector<paii>::iterator it;
    vector<int> graph[MAXX];

    int w8[MAXX];
    bool visited[MAXX];

void dfs(int u)
{
    int p, q;
    visited[u] = true;
    loop(i, SZ(graph[u]))
    {
        int v = graph[u][i];
        if(!visited[v])
        {
            p = u;
            q = v;
            if(p > q)
            {
                swap(p, q);
            }

            //debug(p, q);

            it = lower_bound(all(problemRoads), MP(p, q));

            if( (*it).fr == p && (*it).sc == q)
            {
                w8[v]++;
                //cout<<"increasing node "<<v<<endl;
            }

            dfs(v);
            w8[u] += w8[v];

        }


    }
}


vector<int> result;


void dfs2(int u)
{
    bool totake = true;

    int v;
    visited[u] = true;

    loop(i, SZ(graph[u]))
    {
        v = graph[u][i];
        if(!visited[v])
        {
            if(w8[v])
            {
                totake = false;
                dfs2(v);
            }
        }
    }

    if(totake) result.pb(u);
}





int main()
{


    take(n);
    int cnt = 0;

    FOR(i, 1, n)
    {
        take(x, y, t);
        if(x > y) swap(x, y);

        graph[x].pb(y);
        graph[y].pb(x);

        if(t == 2)
        {
            problemRoads.pb( MP(x, y) );
            cnt++;
            //debug(problemRoads[cnt-1]);
        }
    }

    //debug(problemRoads);

    if(cnt)
    {
        sort(all(problemRoads));
        dfs(1);

        //for(int i=1; i<=n; i++) cout<<w8[i]<<"  ";

        mem(visited, 0);

        dfs2(1);

        cout<<SZ(result)<<endl;

        loop(i, SZ(result))
        {
            if(i) pf(" ");
            pf("%d", result[i]);
        }

    }
    else
    {
        cout<<0<<endl;
    }
















}

