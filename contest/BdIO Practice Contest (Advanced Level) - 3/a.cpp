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


#define MAXX 10002

#define int_type ll
#define INF (1<<29)

#define ANDD 1
#define ORR 0


struct DATA{

    int get;
    bool changeAble;
    int val;
};

int_type dp[MAXX][2];

DATA node[MAXX];

int innerNodes;

int_type rec(int pos, int target)
{

    if(pos > innerNodes)
    {
        if(node[pos].val != target)
        {
            return INF;
        }
        else
        {
            return 0;
        }
    }



    int_type &ret = dp[pos][target];

    if(ret != -1) return ret;


    ret = INF;

    if(target == 1)
    {
        if(node[pos].get == ANDD)
        {
            ret = rec(2*pos, 1) + rec(2*pos + 1, 1);
        }
        else
        {
            ret = min( rec(2*pos, 1), rec(2*pos+1, 1) );
        }
    }
    else
    {
        // target = 0

        if(node[pos].get == ORR)
        {
            ret = rec(2*pos, 0) + rec(2*pos+1, 0);
        }
        else
        {
            ret = min(rec(2*pos, 0) , rec(2*pos + 1, 0) );
        }
    }


    if(node[pos].changeAble)
    {
        if(target == 1)
        {
            if(node[pos].get == ANDD)
            {
                ret = min(ret, min( rec(2*pos, 1), rec(2*pos + 1, 1) ) + 1  );
                ret = min(ret, rec(2*pos, 1) + rec(2*pos+1, 1) );
            }
            else
            {
                ret = min(ret, min(rec(2*pos, 1), rec(2*pos + 1, 1))  );
            }
        }
        else
        {
            // target = 0
            if(node[pos].get == ANDD)
            {
                ret = min( ret, min( rec(2*pos, 0), rec(2*pos+1, 0) )  );
            }
            else
            {
                ret = min(ret, rec(2*pos, 0) + rec(2*pos + 1, 0) );
                ret  = min(ret, 1 +  min( rec(2*pos, 0), rec(2*pos + 1, 0)) );
            }
        }
    }



    return ret;
}

int main()
{
    int kases, kaseno = 0;

    int M, V;
    int G, C;

    take(kases);

    while(kases--)
    {
        take(M, V);
        innerNodes = (M-1)/2;
        for(int i=1; i<=innerNodes; i++)
        {
            take(G, C);

            if(C)
                node[i].changeAble = true;
            else
                node[i].changeAble = false;

            node[i].get = G;
        }

        for(int i=innerNodes+1; i<=M; i++)
        {
            take(node[i].val);
        }


        mem(dp, -1);

        pf("Case #%d: ", ++kaseno);

        int_type res = rec(1, V);

        if(res >= INF)
        {
            pf("IMPOSSIBLE");
        }
        else
        {
            pf("%lld", res);
        }
        pf("\n");
    }

}
