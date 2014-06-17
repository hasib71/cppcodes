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

#define MAXX 2007


bool usedA[MAXX], usedB[MAXX];



vector<paii>v1, v2;

    int n, x;
    int t, h, m;

int calc(int cur)
{
    mem(usedA, 0);
    mem(usedB, 0);

    int cnt = 0;

    int height = x;

    while(true)
    {
        if(cur == 0)
        {
            int pos = -1;

            loop(i, SZ(v1))
            {
                if( ! usedA[i] && v1[i].sc <= height )
                {
                    usedA[i] = 1;
                    height += v1[i].fr;
                    cnt++;
                    pos = i;
                    break;
                }
            }

            if(pos == -1) break;

            //cerr<<"taking "<<v1[pos]<<endl;


        }
        else
        {
            int pos = -1;
            loop(i, SZ(v2))
            {
                if( !usedB[i] && v2[i].sc <= height )
                {
                    usedB[i] = 1;
                    height += v2[i].fr;
                    cnt++;
                    pos = i;
                    break;
                }
            }
            if(pos == -1) break;

            //cerr<<"taking "<<v2[pos]<<endl;
        }

        cur = 1 - cur;
    }

    return cnt;
}



int main()
{



    cin>>n>>x;




    loop(i, n)
    {
        cin>>t>>h>>m;
        if(t)
        {
            v1.pb(MP(m, h));
        }
        else
        {
            v2.pb(MP(m, h));
        }
    }

    sort(all(v1)); reverse(all(v1));
    sort(all(v2)); reverse(all(v2));



    cout<<max(calc(0), calc(1))<<endl;















}
