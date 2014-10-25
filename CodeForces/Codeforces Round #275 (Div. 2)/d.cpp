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

int bitMat[32][MAXX];
int comuZeroBit[32][MAXX];

vector<paii>v[32];


int main()
{
    int n, m;
    int l, r, q;

    cin>>n>>m;
    loop(tmp, m)
    {
        cin>>l>>r>>q;
        loop(i, 32)
        {
            if( (q & (1<<i)))
            {
                bitMat[i][l]++;
                bitMat[i][r+1]--;
            }
            else
            {
                v[i].pb(MP(l, r));
            }
        }

    }

    loop(i, 32)
    {
        int sum = 0;

        for(int j=1; j<=n; j++)
        {
            sum += bitMat[i][j];
            if(sum > 0)
            {
                bitMat[i][j] = 1;
            }
            else
            {
                comuZeroBit[i][j] = 1;
            }

            comuZeroBit[i][j] += comuZeroBit[i][j-1];

        }
    }

    bool pos= 1;

    loop(i, 32)
    {
        loop(j, SZ(v[i]))
        {
            l = v[i][j].fr;
            r = v[i][j].sc;

            if( (comuZeroBit[i][r] - comuZeroBit[i][l-1]) == 0)
            {
                pos = false;
            }

        }
    }
    if(pos)
    {
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++)
        {
            int num = 0;
            loop(j, 32)
            {
                if(bitMat[j][i] == 1)
                {
                    num = num | (1<<j);
                }
            }
            cout<<num<<' ';
        }
    }
    else
    {
        cout<<"NO"<<endl;
    }



    //dump(bitMat[29][3]);
















}
