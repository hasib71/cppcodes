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

#define MAXX 1000000


int n, w;

ll T[MAXX], P[MAXX];

ll pi[MAXX];

int cnt = 0;

void computePrefix()
{
    pi[1] = 0;
    int k = 0;
    for(int q=2; q<w; q++)
    {
        while(k > 0 && P[k+1] != P[q])
        {
            k = pi[k];
        }
        if(P[k+1]==P[q])
        {
            k++;
        }
        pi[q] = k;
    }
}


void kmp()
{
    int q = 0;
    for(int i=1; i<n; i++)
    {
        while(q > 0 && P[q+1] != T[i])
        {
            q = pi[q];
        }
        if( P[q+1] == T[i])
        {
            q = q+1;
        }
        if(q == w - 1)
        {
            cnt++;
            q = pi[q];
        }
    }
}


int main()
{
    cin>>n>>w;

    ll a[MAXX];

    loop(i, n)
    {
        cin>>a[i];
    }

    FOR(i,1,n)
    {
        T[i] = a[i-1] - a[i];
    }

    loop(i, w)
    {
        cin>>a[i];
    }

    FOR(i, 1, w)
    {
        P[i] = a[i-1] - a[i];
    }

    if(w == 1)
    {
        cout<<n<<endl;
    }
    else
    {
        computePrefix();
        kmp();
        cout<<cnt<<endl;
    }










}

