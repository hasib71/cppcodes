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

#define MAXX 33

ll ara[MAXX];
ll cum[MAXX];
ll powOfTwo[MAXX];


ll rec(ll n)
{
    if(n < 2) return 0;
    int k = log2(n+1);

    ll till = powOfTwo[k] - 1;


    ll res = cum[k-1];
    ll remain = n - till;



    res = res + max((remain - powOfTwo[k-1]), (ll)0);
    remain--;
/*
    dump(k);
    dump(till);
    dump(res);
    dump(remain);
    dump(n);
    cout<<endl<<endl;
*/
    res += rec(remain);



    return res;
}



int main()
{

    ara[0] = 0;
    cum[0] = 0;
    powOfTwo[0] = 1;

    for(int i=1; i<32; i++)
    {
        ara[i] = cum[i-1] + powOfTwo[i-1];
        cum[i] = cum[i-1] + ara[i];
        powOfTwo[i] = powOfTwo[i-1]*2;
    }


    int kases, kaseno = 0;
    take(kases);
    ll in;
    while(kases--)
    {
        take(in);
        pf("Case %d: %lld\n", ++kaseno, rec(in));
    }



}
