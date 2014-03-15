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
#define MAXX 152
ll dp[MAXX];



ll gcd(ll a, ll b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}



int main()
{
    int kases, kaseno = 0;
    int n, x;
    take(kases);
    while(kases--)
    {
        take(n, x);
        mem(dp, 0);
        dp[0] = 1;
        //dump(x);


        loop(i, n)
        {
            for(int j=149; j>-1; j--)
            {
                if(dp[j])
                {
                    for(int k=1; k<7; k++) dp[j+k] += dp[j] ;
                }
            }
        }


        ll high = 0;
        for(int i=x; i<151; i++)
        {
            high += dp[i];
        }

        ll total = pow(6, n);

        if(high == 0)
        {
            pf("Case %d: 0\n", ++kaseno);
        }
        else if(high == total)
        {
            pf("Case %d: 1\n", ++kaseno);
        }
        else
        {
            ll by = gcd(total, high);
            //by = 1;

            total = total / by;
            high = high / by;
            cout<<"Case "<<++kaseno<<": "<<high<<"/"<<total<<endl;
        }
    }



    return 0;
}
