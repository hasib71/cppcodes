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

vector<int>graph[MAXX];


int main()
{

    int n;
    cin>>n;

    int difficulty;

    for(int i=1; i<=n; i++)
    {
        cin>>difficulty;
        graph[difficulty].pb(i);
    }

    bool c = 0;

    vector<int>v;

    for(int i=1; i<MAXX; i++)
    {
        if(graph[i].size() > 1)
        {
            v.pb(i);
        }
        if(graph[i].size() > 2)
        {
            c = 1;
        }
    }

    if(c)
    {
        cout<<"YES\n";

        for(int t= 0; t<3; t++)
        {
            for(int i=1; i<MAXX; i++)
            {
                next_permutation(graph[i].begin(), graph[i].end());
                loop(j, SZ(graph[i]))
                {
                    cout<<graph[i][j]<<" ";
                }


            }
            cout<<endl;
        }

    }
    else if(SZ(v) > 1)
    {
        cout<<"YES"<<endl;

        for(int i=1; i<MAXX; i++)
        {
            loop(j, SZ(graph[i]))
            {
                cout<<graph[i][j]<<" ";
            }
        }

        cout<<endl;

        swap( graph[ v[0] ][0], graph[ v[0] ][1] );

        for(int i=1; i<MAXX; i++)
        {
            loop(j, SZ(graph[i]))
            {
                cout<<graph[i][j]<<" ";
            }
        }

        cout<<endl;

        swap( graph[ v[1] ][0], graph[ v[1] ][1] );

        for(int i=1; i<MAXX; i++)
        {
            loop(j, SZ(graph[i]))
            {
                cout<<graph[i][j]<<" ";
            }
        }


    }
    else
    {
        cout<<"NO"<<endl;
    }



}

