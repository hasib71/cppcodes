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



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


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
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args

struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;


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


//Header ends here


#define MAXX 200007


int sum[4*MAXX];

#define set settt




void set(int idx, int st, int ed, int pos, int val)
{
    if(st == ed && st == pos)
    {
        sum[idx] = val;
        return;
    }
    else
    {
        int l = idx*2;
        int r = l + 1;

        int mid = (st+ed)/2;

        if(pos<=mid)
        {
            set(l, st, mid, pos, val);
        }
        else
        {
            set(r, mid+1, ed, pos, val);
        }

        sum[idx] = max(sum[l], sum[r]);

    }
}


int get(int idx, int st, int ed, int s, int e)
{
    if(st == s && ed == e)
    {
        return sum[idx];
    }
    else
    {
        int l = idx*2;
        int r = l+1;

        int mid = (st+ed)/2;

        if(e <= mid)
        {
            return get(l, st, mid, s, e);
        }
        else if(mid < s)
        {
            return get(r, mid+1, ed, s, e);
        }
        else
        {
            return max( get(l, st, mid, s, mid), get(r, mid+1, ed, mid+1, e) );
        }
    }
}










int main()
{
    int n;
    int t, c;

    int num;

    cin>>n>>t>>c;

    for(int i=1; i<=n; i++)
    {
        cin>>num;
        set(1, 1, n, i, num);
    }



    int cnt = 0;

    for(int i=1; i<=n; i++)
    {
        int j = i + c - 1;

        if(j > n)
        {
            break;
        }


        if( get(1, 1, n, i, j) <= t ) cnt++;


    }

    cout<<cnt<<endl;


}
