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
#define dump(x) cerr<<#x<<" = "<<x<<endl

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

#define MAXX 300007

typedef pair<pair<int, int>, int> P;



priority_queue<P, vector<P>, greater<P> > Q; // last, first, x
set<P> S; // x, first, last

vector<P> v; // first, last , x


P obj;
set<P>::iterator it;

int main()
{
    #ifndef hasibpc
        read("trading.in");
        write("trading.out");
    #endif
    int n, m;

    int L, R, X;

    cin>>n>>m;

    loop(i, m)
    {
        cin>>L>>R>>X;
        v.pb(MP(MP(L,R), X));
    }

    sort(all(v));

    int pos = 0;

    for(int i=1; i<=n; i++)
    {
        while( pos < SZ(v))
        {
            if(v[pos].fr.fr == i )
            {
                obj = MP(MP(v[pos].fr.sc, v[pos].fr.fr), v[pos].sc - i + 1 );
                Q.push(obj);

                swap(obj.fr.fr, obj.sc);
                S.insert(obj);

                pos++;
            }
            else break;
        }

        while( ! Q.empty() )
        {
            obj = Q.top();
            if(obj.fr.fr < i)
            {
                Q.pop();
                swap(obj.fr.fr, obj.sc);
                S.erase(obj);
            }
            else break;
        }

        if(S.empty())
        {
            cout<<0<<" ";
        }
        else
        {
            it = S.end();
            it--;
            //cerr<<"my first element " << it->fr.fr<<" "<<it->fr.sc<<" "<<it->sc<<endl<<endl;
            cout<<it->fr.fr + i - 1<<" ";
        }





    }








}
