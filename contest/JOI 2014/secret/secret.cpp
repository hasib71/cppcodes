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



#include "secret.h"

#define MAXX 1007

int sum[4*MAXX];
int n;


void setValue(int idx, int st, int ed, int *A)
{
    if(st == ed)
    {
        sum[idx] = A[st];
        return;
    }

    int l = idx*2;
    int r = l + 1;
    int mid = (st+ed)/2;
    setValue(l, st, mid, A);
    setValue(r, mid+1, ed, A);
    sum[idx] = Secret( sum[l], sum[r] );
}


int getValue(int idx, int st, int ed, int p, int q)
{
    if(st == p && ed == q)
    {
        return sum[idx];
    }

    int mid = (st + ed)/2;
    int l = idx*2;
    int r = l + 1;

    if( q <= mid)
    {
        return getValue(l, st, mid, p, q);
    }
    else if(mid < p)
    {
        return getValue(r, mid+1, ed, p, q);
    }
    else
    {
        return Secret( getValue(l, st, mid, p, mid), getValue(r, mid+1, ed, mid+1, q) );

    }

}



void Init(int N, int A[]) {
    n = N - 1;
    setValue(1, 0, n, A);
}

int Query(int L, int R) {
    return getValue(1, 0, n, L, R );
}
