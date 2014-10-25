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


class PathGameDiv2 {
public:
	int calc(vector <string>);
};

int PathGameDiv2::calc(vector <string> board) {
    int extra = 0;
    int lastPos = -1;

	loop(i, SZ(board[0]))
	{
	    if(board[0][i] == '.' && board[1][i] == '.')
	    {
	        extra++;
	    }
	    else
	    {
	        if(lastPos != -1)
	        {
	            if(board[0][i] == '.' && lastPos == 1)
	            {
	                extra--;
	                lastPos = 0;
	            }

	            if(board[1][i] == '.' && lastPos == 0)
	            {
	                extra--;
	                lastPos = 1;
	            }
	        }
	        else
	        {
	            if(board[0][i] == '.')
	            {
	                lastPos = 0;
	            }
	            else
	            {
	                lastPos = 1;
	            }
	        }
	    }

	    //dump(extra);
	}

	return extra;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
