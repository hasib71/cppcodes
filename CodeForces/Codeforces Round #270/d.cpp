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

ll mat[MAXX][MAXX];


int parent[MAXX];

int find(int u)
{
    if(u == parent[u]) return u;
    else return parent[u] = find(parent[u]);
}



int main()
{
    int n;
    cin>>n;

    loop(i, n)
    {
        loop(j, n)
        {
            cin>>mat[i][j];
        }
    }

    loop(i, n)
    {
        parent[i] = i;
    }

    int u, v;



    bool poss = 1;

    for(int i=0; i<n; i++)
    {
        for(int j = i; j<n; j++)
        {
            if(i == j)
            {
                if(mat[i][j] != 0)
                {
                    poss = 0;
                    goto hell;
                }
            }
            else
            {
                if(mat[i][j] != mat[j][i] || mat[i][j] == 0)
                {
                    poss = false;
                    goto hell;
                }


                ll minDist = 10000000000;

                for(int k=0; k<n; k++)
                {
                    if(k==i || k == j)
                    {
                        continue;
                    }


                    minDist = min(minDist, mat[i][k] + mat[k][j] );

                }
                /*
                if(minDist < mat[i][j]) //ghure aste kom somoy lage.
                {
                    //cerr<<"for "<<i<<" "<<j<<endl;
                    poss = 0;
                    goto hell;
                }
                else */if(minDist == mat[i][j])
                {
                    u = find(i);
                    v = find(j);
                    if(u != v)
                    {
                        parent[u] = v;
                    }
                }
                else
                {
                    u = find(i);
                    v = find(j);
                    if(u == v)
                    {
                        //cerr<<" For "<<i<<" "<<j<<endl;
                        poss = 0;
                        goto hell;
                    }
                    else
                    {
                        parent[u] = v;
                    }
                }
            }
        }
    }


    hell:

    if(poss)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }




}
