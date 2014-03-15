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

#define MAXX 1000002
#define MOD 1000003


ll fac[MAXX];


ll BigMod(ll a, int p)
{
    if(p == 0)
    {
        return 1;
    }

    int half = p/2;

    ll res = BigMod(a, half);
    res = (res*res) % MOD;
    if((p & 1) > 0)
    {
        res = (res*a)%MOD;
    }
    //cerr<<a<<"^"<<p<<" = "<<res<<endl;
    return res;
}

int main()
{
    //cerr<<(BigMod(2, 1024));
    fac[0] = 1;

    FOR(i, 1, 1000001)
    {
        fac[i] = (fac[i-1]*i)%MOD;
    }

    int kases, kaseno = 0;
    int n, r;
    take(kases);

    while(kases--)
    {
        take(n, r);
        ll nice = (fac[r] * fac[n-r])% MOD;
        nice = BigMod(nice, MOD-2);

        ll res = (fac[n]*nice)%MOD;

        pf("Case %d: %lld\n", ++kaseno, res);

    }
    return 0;


}
