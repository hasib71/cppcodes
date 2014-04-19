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






class WolvesAndSheep {
public:
	int getmin(vector <string>);
};

int WolvesAndSheep::getmin(vector <string> field)
{
	int lenX = SZ(field[0]) - 1;
	int lenY = SZ(field) - 1;

	int minxx = 1<<29;
	int minyy = (1<<29);


	lenX = 1<<lenX;
	lenY = 1<<lenY;

	for(int i=0; i<lenX; i++)
	{
	    dump(i);
	    int m = -1;
	    int n = 0;
	    while(n < SZ(field[0]))
	    {
	        if(i & (1<<n))
	        {
	            n++;
	            break;
	        }
	        else
	        {
	            n++;
	        }
	    }



	    while(true)
	    {
	        loop(j, SZ(field))
	        {
	            for(int p = m+1; p<n; p++)
	            {
	                if(field[j][p] == 'W')
	                {
	                    goto hell2;
	                }
	            }
	        }


	        if( n >= SZ(field[0])) break;


	        m = n - 1;

	        while(n < SZ(field[0]))
	        {
	            if(i & (1<<n))
	            {
	                n++;
	                break;
	            }
	            else
                    n++;
	        }

	    }


	    minxx = min(__builtin_popcount(i), minxx);

	    hell2:
             int k;

	}









	for(int i=0; i<lenY; i++)
	{
	    dump(i);
	    int m = -1;
	    int n = 0;
	    while(n < SZ(field))
	    {
	        if(i & (1<<n))
	        {
	            n++;
	            break;
	        }
	        else
	        {
	            n++;
	        }
	    }



	    while(true)
	    {
	        loop(j, SZ(field[0]))
	        {
	            for(int p = m+1; p<n; p++)
	            {
	                if(field[p][j] == 'W')
	                {
	                    goto hell;
	                }
	            }
	        }


	        if( n >= SZ(field)) break;


	        m = n - 1;

	        while(n < SZ(field))
	        {
	            if(i & (1<<n))
	            {
	                n++;
	                break;
	            }
	            else
                    n++;
	        }

	    }


	    minyy = min(__builtin_popcount(i), minyy);

	    hell:
            int k;
	}


	return minxx+minyy;




}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
