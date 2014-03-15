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

#define MAXX 100003


struct DATA{
    ll used, unused;
};

DATA dp[MAXX];

int lastpos[95];

#define MOD 1000000007


int main()
{
    int kases, kaseno = 0;


    string ss;

    take(kases);
    int len;
    char ch;



    while(kases--)
    {
        cin>>ss;
        mem(dp, 0);
        mem(lastpos, 0);
        len = SZ(ss);

        dp[0].unused = 1;
        dp[0].used = 0;

        for(int i=1; i<=len; i++)
        {
            ch = ss[i-1];

            dp[i].unused = dp[i-1].unused + dp[i-1].used;
            dp[i].used = dp[i].unused;

            if(lastpos[ch] != 0)
            {
                dp[i].used = (dp[i].used+MOD)-dp[ lastpos[ch] ].unused;
            }

            lastpos[ ch ] = i;

            dp[i].used %= 1000000007;
            dp[i].unused %= 1000000007;


            //pf("dp[%d] = %d\n", i, dp[i]);
        }

        cout<<((dp[len].used+dp[len].unused)%1000000007)<<endl;
    }





}
