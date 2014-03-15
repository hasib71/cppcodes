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
ll n, r, p, q;


ll count(ll N, ll K)
{
    ll res;
    ll gun = 1;
    ll cnt = 0;
    do{
        gun *= K;
        res = N / gun;
        //dump(res);
        cnt+= res;

    }while(res);

    return cnt;
}


ll countDivisor(ll N, ll a)
{
    ll cnt = 0;
    while(N%a == 0)
    {
        cnt++;
        N /= a;
    }
    return cnt;
}





int main()
{
    /*
    dump(count(1000000, 2));
    dump(count(500000, 2)*2);
    dump(count(1000000, 5));
    dump(count(500000, 5));
    */
    int kases, kaseno = 0;

    take(kases);

    while(kases--)
    {
        take(n, r, p, q);

        ll res = min( countDivisor(p, 5)*q + count(n, 5) - count(r, 5) - count(n-r, 5), countDivisor(p,2)*q + count(n, 2) - count(r, 2) - count(n-r, 2)  );

        pf("Case %d: %lld\n", ++kaseno, res);
    }

    return 0;


}
