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

#define MAXX 1002
#define MOD 100000007

ll dp[1050];
int A[MAXX];
bool B[MAXX];

int N, M;

ll BigPow(int a, int p)
{
    if(p == 0)
    {
        return 1;
    }

    int half = p/2;
    ll res = BigPow(a, half);
    res = (res*res)%MOD;

    if(p & 1)
    {
        res = (res*a)%MOD;
    }

    return res;

}

int main()
{
    //cerr<<BigPow(7, 100);
    int kases, kaseno = 0;
    int x, y, z;
    ll cnt;
    take(kases);

    while(kases--)
    {
        take(N, M);

        mem(B, 0);

        loop(i, N)
        {
            take(A[i]);
        }

        loop(i, M)
        {
            take(x);
            B[x] = true;
        }

        mem(dp, 0);

        dp[0] = 1;

        loop(i, N)
        {
            for(int j=0; j<=1023; j++)
            {
                z = j^A[i];
                if(z >= j)
                {
                    dp[j] = (dp[j]+dp[z])%MOD;
                    dp[z] = dp[j];
                }
            }
        }

        cnt = 0;

        for(int i=0; i<=1000; i++)
        {
            if(B[i])
            {
                cnt = (cnt+dp[i])%MOD; //may be prune here
            }
        }

        ll res = (BigPow(2, N)+ MOD - cnt)%MOD;

        pf("Case %d: %lld\n", ++kaseno, res);





    }



}

