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





//Header ends here


#define MAXX 1007

#define isOut ( n <= i || m <= j || i < 0 || j < 0 )



ll a[MAXX][MAXX];
int n, m;




ll dp[8][MAXX][MAXX];

ll rec_0(int i, int j)
{
    if(isOut) return 0;
    ll &ret = dp[0][i][j];
    if(ret != -1) return ret;

    return ret = a[i][j] + max(rec_0(i-1, j), rec_0(i, j-1));
}



ll rec_1(int i, int j)
{
    if(isOut) return 0;
    ll &ret = dp[1][i][j];
    if(ret != -1) return ret;
    return ret = a[i][j] + max(rec_1(i-1, j) , rec_1(i, j+1));
}


ll rec_2(int i, int j)
{
    if(isOut) return 0;
    ll &ret = dp[2][i][j];
    if(ret != -1) return ret;
    return ret = a[i][j] + max(rec_2(i+1, j), rec_2(i, j-1));
}


ll rec_3(int i, int j)
{
    if(isOut) return 0;
    ll &ret = dp[3][i][j];
    if(ret != -1) return ret;
    return ret = a[i][j] + max(rec_3(i+1, j), rec_3(i, j+1));
}





ll recUp(int i, int j)
{
    if(isOut) return 0;
    ll &ret = dp[4][i][j];
    if(ret != -1) return ret;

    ll tmp = rec_0(i, j-1) + max( rec_1(i-1, j), rec_1(i, j+1) );

    tmp = max(tmp, rec_0(i-1, j) + rec_1(i, j+1) );

    return ret = a[i][j] + max(tmp, recUp(i-1, j) );
}


ll recDown(int i, int j)
{
    if(isOut) return 0;
    ll &ret = dp[5][i][j];
    if(ret != -1) return ret;

    ll tmp = rec_2(i, j-1) + max( rec_3(i+1, j), rec_3(i, j+1) );
    tmp = max(tmp,  rec_2(i+1, j) + rec_3(i, j+1) );


    return ret = a[i][j] + max(tmp, recDown(i+1, j) );
}



ll recLeft(int i, int j)
{
    if(isOut) return 0;
    ll &ret = dp[6][i][j];
    if(ret != -1) return ret;

    ll tmp = rec_0(i-1, j) + max( rec_2(i, j-1), rec_2(i+1, j) );
    tmp = max(tmp,  rec_0(i, j-1)  + rec_2(i+1, j) );

    return ret = a[i][j] + max(tmp, recLeft(i, j-1));
}




ll recRight(int i, int j)
{
    if(isOut) return 0;
    ll &ret = dp[7][i][j];
    if(ret != -1) return ret;

    ll tmp = rec_1(i-1, j) + max( rec_3(i, j+1), rec_3(i+1, j));
    tmp = max(tmp,  rec_1(i, j+1) + rec_3(i+1, j) );

    return ret = a[i][j] + max(tmp, recRight(i, j+1));
}




int main()
{
    mem(dp, -1);

    cin>>n>>m;

    loop(i, n)
    {
        loop(j, m)
        {
            cin>>a[i][j];
        }
    }

    ll result = 0;


    loop(i, n)
    {
        loop(j, m)
        {
            ll tmp = recUp(i, j) + recDown(i, j);
            tmp = max(tmp, recLeft(i, j) + recRight(i, j) );
            result = max(result, tmp - 2*a[i][j] );
        }
    }

    cout<<result<<endl;


}
