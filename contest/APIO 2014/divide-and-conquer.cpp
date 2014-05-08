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


#define MAXX 100007


struct DATA{
    ll x, gold, energy;
    void in(ll X, ll G, ll D)
    {
        x=X;
        gold = G;
        energy = D;
    }
}v[MAXX];



int main()
{
    #ifndef hasibpc
        read("divide.in");
        write("divide.out");
    #endif

    int n;
    ll X, G, D;

    cin>>n;


    for(int i=1; i<=n; i++)
    {
        cin>>X>>G>>D;
        v[i].in(X,G,D);
    }


    ll comuGold[MAXX];

    comuGold[0] = 0;

    for(int i=1; i<=n; i++)
    {
        comuGold[i] = comuGold[i-1] + v[i].gold;
    }


    ll mxGold = comuGold[1];


    ll comuSeries[MAXX];

    comuSeries[0] = -(1<<29);

    comuSeries[1] = v[1].energy;

    ll hate = 0;


    ll diff;


    for(int i=2; i<=n; i++)
    {
        diff = (v[i].x - v[i-1].x);

        hate = hate + v[i].energy - diff;

        comuSeries[i-1] = max(comuSeries[i-2], v[i-1].energy + v[i].energy - diff - hate  );

        comuSeries[i] = -hate;

        //cerr<<comuSeries[i-1]<<"    "<<comuSeries[i]<<endl;


        int low = 1, high = i;

        while(low <= high)
        {
            int mid = (low+high)/2;

            if(- hate <= comuSeries[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        //dump(hate);
        //dump(low);
        //dump( comuGold[i] - comuGold[low-1]);



        mxGold = max(mxGold, comuGold[i] - comuGold[low-1] );

    }

    cout<<mxGold<<endl;





}
