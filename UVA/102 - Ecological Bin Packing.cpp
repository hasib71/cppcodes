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

ll ser[10];



char bottle[] = "BCG";



void solve()
{
    ll minCost = 1LL<<33;

    string ss = "aaa";

    int ord[] = {0, 1, 2};

    ll sum = 0;
    loop(i, 9) sum += ser[i];

    do
    {
        ll temp = sum - ser[ (ord[0]*2)%3 ] - ser[ 3 + (ord[1]*2)%3 ] - ser[6+ (ord[2]*2)%3 ];

        if(temp < minCost)
        {
            minCost = temp;
            loop(i, 3)
            {
                ss[i]  = bottle[ ord[i] ];
            }
        }

    }while(next_permutation(ord, ord+3));

    cout<<ss<<" "<<minCost<<endl;

}



int main()
{
    while(scanf("%lld", &ser[0]) == 1)
    {
        FOR(i, 1, 9)
        {
            take(ser[i]);
        }

        solve();
    }

    return 0;


}
