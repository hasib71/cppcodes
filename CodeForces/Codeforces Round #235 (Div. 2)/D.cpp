
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

#define MAXX 262199


ll dp[MAXX][102];


string ss;
int len;
int m;

ll mul[20];

//ll fac[20];

ll rec(int mask, int remainder, int pos)
{
    //debug(mask, remainder, pos);
    if(pos < 0)
    {
        if(remainder == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }


    ll &ret = dp[mask][remainder];

    if(ret != -1) return ret;



    ret = 0;
    int used = 0;

    loop(i, len)
    {
        if( (used & 1<<ss[i]) == 0 &&  (mask & (1<<i)) == 0)
        {
            used |= 1<<ss[i];
            ret += rec(mask | (1<<i), (remainder + (ss[i] * mul[pos])%m)%m, pos-1 );
        }
    }


    //dump(ret);



    return ret;


}





int main()
{


    cin>>ss>>m;
    len = SZ(ss);

    loop(i, len)
    {
        ss[i] -= '0';
    }

    mem(dp, -1);


    mul[0] = 1;
    //fac[0] = 1;
    for(int i=1; i<20; i++)
    {
        mul[i] = mul[i-1]*10;
        //fac[i] = fac[i-1] * i;

    }

    ll res = 0;

    int used = 0;

    loop(i, len)
    {
        if(ss[i] != 0 && (used & 1<<ss[i])==0  )
        {
            used |= 1<<ss[i];
            res += rec(1<<i, (ss[i]*mul[len-1])%m, len-2 );
        }
    }


    cout<<res<<endl;



}


