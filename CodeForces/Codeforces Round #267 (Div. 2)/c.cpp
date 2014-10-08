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

#define MAXX 5007
#define INF (1<<29)


ll dp[MAXX][MAXX];
ll p[MAXX], comu[MAXX];

int n, m, k;


ll sum(int start)
{
    return comu[start + m - 1] - ( start > 0 ? comu[start - 1] : 0 );
}

ll rec(int start, int bakislot)
{
    if(bakislot == 0)
    {
        return 0;
    }
    else
    {
        if(start + m > n)
        {
            return -INF;
        }
        else
        {
            ll ret = dp[start][bakislot];
            if(ret != -1)
            {
                return ret;
            }
            else
                return ret = max( sum(start) + rec(start + m, bakislot - 1) , rec(start + 1, bakislot) );
        }
    }
}



int main()
{
    read("txt");
    mem(dp, -1);
    cin>>n>>m>>k;
    loop(i, n)
    {
        cin>>p[i];
    }
    comu[0] = p[0];

    for(int i=1; i<n; i++)
    {
        comu[i] = comu[i-1] + p[i];
    }



    cout<<rec(0, k)<<endl;



}

