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

int n, m;
ll a[MAXX], b[MAXX];


ll sum(ll mid)
{
    ll cnt = 0;

    loop(i, n)
    {
        if(a[i] < mid)
        {
            cnt += (mid - a[i]);
        }
        else
        {
            break;
        }
    }


    for(int i=m-1; i>-1; i--)
    {
        if(b[i] > mid)
        {
            cnt += (b[i] - mid);
        }
        else
        {
            break;
        }
    }

    return cnt;

}


int main()
{



    sf("%d %d", &n, &m);

    loop(i, n)
    {
        sf("%lld", &a[i]);
    }

    loop(i, m)
    {
        sf("%lld", &b[i]);
    }

    sort(a, a+n);
    sort(b, b+m);



    ll low = 1, high = 1000000000;

    ll result;


    while(low <= high)
    {
        ll mid = (low + high)/2;


        ll p = sum(mid-1);
        ll q = sum(mid);
        ll r = sum(mid + 1);

        if(q <= p && q <= r )
        {
            result = q;
            break;
        }

        if(p <= q && q <= r  )
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout<<result<<endl;



}

