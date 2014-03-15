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


#define MAXX 502

int parent[MAXX];
int cntConnection[MAXX];
int find(int u)
{
    if(parent[u] == u)
    {
        return u;
    }
    else
    {
        return parent[u] = find(parent[u]);
    }
}


int N, M;

int main()
{
    int kases, kaseno = 0;
    take(kases);
    int u, v;

    while(kases--)
    {
        take(N, M);
        bool valid = true;
        int which = 1;

        mem(cntConnection, 0);

        for(int i=0; i<=N; i++)
        {
            parent[i] = i;
        }

        loop(i, M)
        {
            take(u, v);

            if(valid)
            {
                cntConnection[u]++;
                cntConnection[v]++;

                u = find(u);
                v = find(v);

                if(u == v)
                {
                    valid = false;
                }
                else
                {
                    parent[u] = v;
                }
            }

        }

        if(valid)
        {
            for(int i=0; i<= N; i++)
            {
                if(cntConnection[i] == 3)
                {
                    if(which ==1)
                    {
                        which = 3;
                    }
                    else
                    {
                        valid = false;
                        break;
                    }
                }
                else if(cntConnection[i] == 4)
                {
                    if(which == 1)
                    {
                        which = 4;
                    }
                    else
                    {
                        valid = false;
                        break;
                    }
                }
                else if(cntConnection[i] > 2)
                {
                    valid = false;
                    break;
                }
            }
        }

        pf("Case %d: ", ++kaseno);

        if(valid)
        {

            if(which == 1) pf("I");
            else if(which == 3) pf("Y");
            else pf("X");
        }
        else
        {
            pf("NotValid");
        }


        pf("\n");

    }




}
