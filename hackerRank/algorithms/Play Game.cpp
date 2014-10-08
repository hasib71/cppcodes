#include<bits/stdc++.h>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define pb push_back
#define MP make_pair
#define sf scanf
#define pf printf
#define dump(x) cerr<<#x<<" = "<<x<<endl;
#define ll long long
#define SZ(a) int(a.size())
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;



#define MAXX 100007



ll dp[MAXX];

int N;

ll val[MAXX];

ll rec(int pos)
{
    if(pos >= N) return 0;
    ll &ret = dp[pos];
    if(ret != -1) return ret;


    if(N - pos <= 3)
    {
        return ret = val[pos] + val[pos+1] + val[pos+2];
    }

    ll t1 = val[pos] +                         +    min( rec(pos+2), min( rec(pos+3), rec(pos+4) )  );
    ll t2 = val[pos] + val[pos + 1 ]           +    min( rec(pos+3), min( rec(pos+4), rec(pos+5) )  );
    ll t3 = val[pos] + val[pos+1] + val[pos+2] +    min( rec(pos+4), min( rec(pos+5), rec(pos+6) )  );

    return ret = max(max(t1, t2), t3);

}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int kases;
    cin>>kases;

    while(kases--)
    {
        cin>>N;
        loop(i, N) cin>>val[i];
        mem(dp, -1);
        cout<<rec(0)<<endl;
    }





}
