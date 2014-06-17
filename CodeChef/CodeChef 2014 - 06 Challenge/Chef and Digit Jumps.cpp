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

int dist[MAXX];
string ss;
int N;
vector<int>vv[10];

void bfs(int u)
{
    bool used[MAXX];
    bool colorUsed[10];
    mem(used, 0);
    mem(colorUsed, 0);

    int v;
    queue<int>Q;
    Q.push(u);

    dist[u] = 0;
    used[u] = true;

    while(!Q.empty())
    {
        u = Q.front(); Q.pop();
        //dump(u);
        if(u == N) break;


        if(!colorUsed[ ss[u] ])
        {
            colorUsed[ ss[u] ] = true;
            vector<int> &vec = vv[ ss[u] ];


            loop(i, SZ(vec))
            {
                v = vec[i];
                if( ! used[v] )
                {
                    used[v]  =true;
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }


        if(u > 0)
        {
            if(!used[u-1])
            {
                used[u-1] = true;
                dist[u-1] = 1 + dist[u];
                Q.push(u-1);
            }
        }

        if(u < N)
        {
            if(!used[u+1])
            {
                used[u+1] = true;
                dist[u+1] = 1 + dist[u];
                Q.push(u+1);
            }
        }

    }



}




int main()
{
    cin>>ss;
    N = SZ(ss) - 1;

    loop(i, SZ(ss))
    {
         ss[i] -= '0';
         vv[ ss[i] ].pb(i);
    }


    mem(dist, 1);



    bfs(0);

    cout<<dist[N]<<endl;



}

