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

#define MAXX 1007

int main()
{
    int n;

    int ara[MAXX];

    cin>>n;


    int comu[MAXX];

    comu[0] = 0;

    int mx, mn;

    mx = mn = 0;

    for(int i=1; i<=n; i++)
    {
        cin>>ara[i];

        if(i%2)
        {
            comu[i] = comu[i-1] + ara[i];
        }
        else
        {
            comu[i] = comu[i-1] - ara[i];
        }


        mx = max(mx, comu[i]);
        mn = min(mn, comu[i]);
    }



    int N = mx - mn;

    char res[N][MAXX];


    mem(res, 0);



    int curr = N + mn;
    int x = 0;

    //dump(N);
    //dump(curr);


    for(int i=1; i<=n; i++)
    {
        if(i%2 == 1)
        {
            int cnt = 0;

            while(cnt < ara[i])
            {
                curr--;
                res[curr][x] = '/';
                cnt++;
                x++;
            }
        }
        else
        {
            int cnt = 0;

            while(cnt < ara[i])
            {
                res[curr][x] = '\\';
                cnt++;
                x++;
                curr++;
            }
        }
    }




    loop(i, N)
    {
        loop(j, x)
        {
            if(res[i][j] == 0)
            {
                pf(" ");
            }
            else
            {
                pf("%c", res[i][j]);
            }
        }

        cout<<endl;



    }






















}
