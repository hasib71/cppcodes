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



#include <bits/stdc++.h>



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

int n;
vector<paii>v;



struct compare{
    bool operator()(paii a, paii b)
    {
        return a.sc > b.sc;
    }
};







int main()
{



    int kases, kaseno = 0;

    sf("%d", &kases);

    while(kases--)
    {
        v.clear();
        sf("%d", &n);
        v.resize(n);
        loop(i, n)
        {
            sf("%d %d", &v[i].fr, &v[i].sc);
        }

        sort(all(v));

        //dump(v);

        priority_queue<paii, vector<paii>, compare>Q;


        int cnt = 0;



        loop(i, n)
        {
            if(!Q.empty())
            {
                paii f = Q.top();

                if(f.sc < v[i].fr)
                {
                    Q.pop();
                }
                else
                {
                    cnt++;
                }
            }
            else
            {
                cnt++;
            }


            Q.push(v[i]);


        }


        pf("Case %d: %d\n", ++kaseno, cnt);





    }





}
