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


#define MAXX 1007

struct DATA{
    int a, b, out;
    ll cost;
};


bool used[MAXX];
int N, M;
DATA nol[17];


int main()
{
    ll minCost = 1LL<<60;

    int A, B, C;
    ll D;
    cin>>M>>N;

    for(int i=0; i<M; i++)
    {
        cin>>A>>B>>C>>D;
        nol[i].a = A;
        nol[i].b = B;
        nol[i].out = C;
        nol[i].cost = D;
    }





    for(int s=0; s<1024; s++)
    {
        mem(used, 0);
        ll cost = 0;
        set<int>S;

        for(int j=1; j<=N; j++)
        {
            int pp = j;
            for(int i=0; i<M; i++)
            {
                if( (s & (1<<i) )== 0) continue;
                if( nol[i].a <= pp && pp <= nol[i].b)
                {
                    pp = nol[i].out;
                }
            }
            S.insert(pp);
        }

        if(SZ(S) == 1)
        {
            loop(i, M)
            {
                if(s & (1<<i))
                {
                    cost += nol[i].cost;
                }
            }
            minCost = min(minCost, cost);
        }

    }
    if(minCost == (1LL<<60))
        cout<<-1<<endl;
    else
        cout<<minCost<<endl;





}
