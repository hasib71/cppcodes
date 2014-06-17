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

#define MAXX ((1<<20) + 7)

#define MAXCOIN 22


int n;
string ss;

int dp[MAXX];

int pos[MAXCOIN];







int rec(int mask, int step)
{
    //dump(mask);
    if(mask == 0) return 0;

    int &ret = dp[mask];
    if(ret != -1) return ret;

    ret = 0;

    loop(i, MAXCOIN)
    {
        if(mask & (1<<i) && step < pos[i])
        {
            int tmpMask = mask & ~(1<<i);
            int tmpStep = step + 1;

            if(tmpMask == 0)
            {
                ret = 1;
                break;
            }

            bool possible = true;


            loop(j, MAXCOIN)
            {
                if(tmpMask & (1<<j) && tmpStep < pos[j])
                {
                    if(rec(tmpMask & ~(1<<j), tmpStep+1 ) == 0)
                    {
                        possible = false;
                        break;
                    }
                }
            }

            if(possible)
            {
                ret = 1;
                break;
            }

        }
    }



    return ret;
}






void solve()
{

    mem(dp, -1);


    int p = 0;

    loop(i, n)
    {
        if(ss[i] == '1')
        {
            pos[p++] = i+1;
        }
    }

    if(rec( (1<<(p)) - 1, 0 ))
    {
        cout<<"Adam"<<endl;
    }
    else
    {
        cout<<"Betka"<<endl;
    }

}






int main()
{
    read("g1.in");
    write("g1.out");
    int kases;
    cin>>kases;

    while(kases--)
    {
        cin>>n;
        cin>>ss;

        solve();

    }




}
