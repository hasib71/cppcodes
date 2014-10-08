/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



#include<bits/stdc++.h>


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

#define dump(x) cerr<<#x<<" = "<<x<<endl
#define debug(args...) cerr,args; cerr<<endl;
using namespace std;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}




template<typename T>
ostream& operator,(ostream& output, T x)
{
    output<<x<<" ";
    return output;
}





//Header ends here
#define MAXX 100007
#define MOD 1000000007

ll A[MAXX], B[MAXX], C[MAXX];

int N, M;
int cnt[MAXX];


ll bigMod(ll base, int pow)
{
    if(pow == 0) return 1;
    ll t = bigMod(base, pow/2);
    t = (t*t)%MOD;
    if(pow & 1) t = (t*base)%MOD;
    return t;

}



ll mul[MAXX];



int main()
{
    //read("in");

    loop(i, MAXX) mul[i] = 1;

    cin>>N>>M;

    for(int i=1; i<=N; i++) cin>>A[i];
    for(int i=1; i<=M; i++) cin>>B[i];
    for(int i=1; i<=M; i++) cin>>C[i];


    for(int i=1; i<=M; i++)
    {
        mul[ B[i] ] =  (mul[B[i]] * C[i] ) % MOD;
    }

    for(int i=1; i<=MAXX; i++)
    {
        if(mul[i] > 1)
        {
            for(int s=i; s<=N; s+=i)
            {
                A[s] = (A[s] * mul[i]) % MOD;
            }
        }
    }

    for(int i=1; i<=N; i++) cout<<A[i]<<" ";






}





















