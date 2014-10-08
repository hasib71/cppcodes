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

vector<string>essay;
int n, m;

map<string, paii>mp;


paii ret(string s)
{
    paii x;
    x.fr =  0;

    x.sc = SZ(s);

    loop(i, SZ(s))
    {
        if(s[i] == 'r' || s[i] == 'R')
        {
            x.fr++;
        }
    }
    return x;
}



void tolower(string &ss)
{
    loop(i, SZ(ss))
    {
        if('A' <= ss[i] && ss[i] <= 'Z')
        {
            ss[i] = (ss[i] - 'A') + 'a';
        }
    }
}



int main()
{
    string ss, pp;
    cin>>m;
    loop(i, m)
    {
        cin>>ss;
        essay.pb(ss);

        mp[ss] = ret(ss);
    }

    cin>>n;

    loop(i, n)
    {
        cin>>ss>>pp;
        mp[ss] = min(mp[ss],ret(pp));
    }
    ll x, y;
    x = 0, y = 0;
    paii p;

    loop(i, SZ(essay))
    {
        p = mp[ essay[i] ];
        x += p.fr;
        y += p.sc;
    }

    cout<<x<<" "<<y<<endl;






}

