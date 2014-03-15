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

#define MAXX 2000002

#define MOD (1000000007)
#define int32 ll

int32 fac[MAXX];



int32 BigMod(int32 a, int32 p)
{
    if(p==0) return 1;

    int32 half = p/2;
    int32 res;

    res = BigMod(a, half);
    res = (res*res)%MOD;

    if((p&1) != 0 )
    {//bijor
        res = (res*a)%MOD;
    }

    //cerr<<a<<"^"<<p<<" = "<<res<<endl;


    return res;
}


int main()
{

    //cerr<<BigMod(2, 10000);
    fac[0] = 1;
    FOR(i, 1, MAXX) fac[i] = (fac[i-1]*i)%MOD;

    int kases, kaseno=0;
    int32 n, k;

    take(kases);

    while(kases--)
    {
        take(n, k);
        k--;

        //cerr<<n<<"    "<<k<<endl;

        int32 result = (fac[k] *fac[n])%MOD;

        result = BigMod(result, MOD-2);

        result = (result*fac[n+k])%MOD;

        //cerr<<result<<endl;

        pf("Case %d: %lld\n", ++kaseno, result);

    }

    return 0;


}

