/*
ID: himuhas1
TASK: butter
LANG: C++
*/



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
int N, P, C;

#define MAXP 802

int cntCows[MAXP];
ll dist[MAXP];
vector<paii>paths[MAXP];
bool visited[MAXP];

struct comp{
    bool operator()(paii a, paii b)
    {
        return a.fr > b.fr;
    }
};

void bfs(paii u)
{
    int _cost[MAXP];
    mem(_cost, 127);
    mem(visited, 0);

    paii v;

    priority_queue<paii, vector<paii>, comp>Q;
    Q.push(u);
    _cost[u.sc] = 0;
    int mul = cntCows[u.sc];
    //visited[u.sc] = 1;

    while(!Q.empty())
    {
        u = Q.top();

        Q.pop();
        if(!visited[u.sc])
        {
            visited[u.sc] = 1;
            dist[u.sc] += (_cost[u.sc]*mul);  //here to modify
            loop(i, SZ(paths[u.sc]))
            {
                v.sc = paths[u.sc][i].fr;
                if(!visited[v.sc] && _cost[u.sc]+paths[u.sc][i].sc < _cost[v.sc])
                {
                    //dump(i);
                    _cost[v.sc] = _cost[u.sc]+paths[u.sc][i].sc;
                    v.fr = _cost[v.sc];
                    //dump(v.sc);
                    //dump(v.fr);


                    Q.push(v);
                }
            }
        }
    }
}


int main()
{
    #ifndef hasibpc
        read("butter.in");
        write("butter.out");
    #endif

    take(N, P, C);
    int a,b,cost;

    loop(i, N)
    {
        take(a);
        cntCows[a]++;
    }

    loop(i, C)
    {
        take(a, b, cost);
        paths[a].pb(MP(b, cost));
        paths[b].pb(MP(a, cost));
    }

    for(int i=1; i<=P; i++)
    {
        if(cntCows[i])
        {
            bfs(MP(0, i));
        }
    }

    ll result = 1<<29;

    for(int i=1; i<=P; i++)
    {
        //dump(dist[i]);
        result = min(result, dist[i]);
    }

    cout<<result<<endl;







    return 0;
}
