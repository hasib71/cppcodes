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

#define MAXX 200007



int n;
int ara[MAXX];
ll dp[107][207];

#define MOD 1000000007



ll bigMod(int base, int pow)
{
    if(pow == 0) return 1;

    ll res = bigMod(base, pow/2);
    res = (res*res) % MOD;


    if(pow & 1)
    {//odd
        res = (res*base)%MOD;
    }
    return res;

}


ll countProgression()
{
    mem(dp, 0);
    loop(i, n)
    {
        for(int j=1; j<=199; j++)
        {
            int diff = j - 100;
            if(diff == 0) continue;
            int prevNum = ara[i] - diff;


            if(1 <= prevNum && prevNum <= 100)
            {
                dp[ ara[i] ][j] += dp[ prevNum ][j];
            }
            dp[ ara[i] ][j] = (1 + dp[ara[i]][j]);

            if(dp[ ara[i] ][j] > MOD)
            {
                dp[ara[i]][j] -= MOD;
            }

            //pf("dp[%d][%d] = %lld\n", ara[i], j, dp[ ara[i] ][j] );
        }
    }




    int counter[107];
    mem(counter, 0);


    loop(i, n)
    {
        counter[ ara[i] ]++;
    }

    /*

    loop(i, n)
    {
        for(int j=1; j<=199; j++)
        {
            if(j == 100) continue;
            dp[ ara[i] ][j]--;
            //pf("dp[%d][%d] = %lld\n", ara[i], j, dp[ ara[i] ][j] );
        }
    }
    */


    ll cnt = - n*198 ;


    for(int i=1; i<=100; i++)
    {
        for(int j=1; j<=199; j++)
        {
            if(dp[i][j] > 0 )
            cnt = (cnt + dp[i][j])%MOD;
        }
    }

    //dump(cnt);



    for(int i=1; i<=100; i++)
    {
        cnt = (cnt + bigMod(2, counter[i]) - 1 )%MOD;
    }


    //dump(cnt);

    return cnt;



}







int main()
{
    //ios_base::sync_with_stdio(0);

    int kases;

    sf("%d", &kases);

    while(kases--)
    {
        cin>>n;
        loop(i, n) sf("%d", &ara[i]);

        //dump(countProgression());

        ll result = ( bigMod(2, n) + 2*MOD - countProgression() - 1 ) % MOD;
        cout<<result<<endl;
    }


}
