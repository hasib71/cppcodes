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

#define MAXX 1007


struct DATA{

    int v, w;

    bool operator<(const DATA& x) const
    {
        return w > x.w;
    }

    DATA(int a, int b)
    {
        v = a;
        w = b;
    }

};

vector<DATA>graph[MAXX];

int n, m, k;

int cntVisitedNode;

ll MST()
{
    ll cost = 0;

    cntVisitedNode = 0;

    bool visited[MAXX];

    priority_queue<DATA>Q;

    loop(i, SZ(graph[k]))
    {
        //dump(graph[k][i].w);
        Q.push(graph[k][i]);
    }



    cntVisitedNode = 1;

    mem(visited, 0);

    visited[k] = true;


    while(!Q.empty())
    {
        DATA u = Q.top();

        //cerr<<"u = "<<u.v<<endl;

        Q.pop();

        if(!visited[ u.v ])
        {











            dump(u.v);
            cost += (ll)u.w;

            visited[u.v] = true;

            cntVisitedNode++;

            loop(i, SZ(graph[u.v]))
            {
                Q.push(graph[u.v][i]);
            }
        }
    }

    return cntVisitedNode == n ? cost : -1;
}

int main()
{


    int kases, kaseno = 0;

    take(kases);

    while(kases--)
    {
        loop(i, MAXX)
        {
            graph[i].clear();
        }

        scanf("%d %d %d", &n, &m, &k);

        int u, v, w;

        loop(i, m)
        {
            take(u, v, w);

            graph[u].pb(DATA(v, w));
        }


        ll result = MST();

        pf("Case %d: ", ++kaseno);

        if(result == -1)
        {
            pf("impossible\n");
        }
        else
        {
            pf("%lld\n", result);
        }


    }






}
