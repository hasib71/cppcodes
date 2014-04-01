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






class MinimumSquareEasy {
public:
	long long minArea(vector <int>, vector <int>);
};

long long MinimumSquareEasy::minArea(vector <int> x, vector <int> y)
{
	paii points[52];
	int cnt = SZ(x);

	loop(i, cnt)
	{
	    points[i] = MP(x[i], y[i]);
	}



	ll low = 0, high = 2000000005;

	while(low <= high)
	{
	    ll mid = (low + high) / 2;

	    sort(points, points+cnt);

	    bool success = false;

	    loop(i, 3)
	    {
	        int target = points[i].fr + mid;
            int j;
	        for(j=cnt-1; j>-1; j--)
	        {
	            if(points[j].fr <= target)
	            {
	                break;
	            }
	        }

	        int remain = i + (cnt - 1 - j);

	        if(remain > 2) break;

	        remain = 2 - remain;



	        for(int k=i; k<=j; k++) swap(points[k].fr, points[k].sc);

	        sort(points+i, points+j+1);


	        loop(p, 3)
	        {
	            if(p > remain) break;


	            if( points[i+p].fr + mid >= points[j - remain + p].fr  )
	            {
	                success = true;
	                break;
	            }
	        }


	        for(int k=i; k<=j; k++) swap(points[k].fr, points[k].sc);

	        if(success) break;



	    }

	    if(success)
	    {
	        high = mid - 1;
	    }
	    else
	    {
	        low = mid + 1;
	    }

	}

	low = low + 2;
	return low*low;


}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
