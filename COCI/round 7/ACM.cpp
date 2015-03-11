/****************************************************************
   ▄█    █▄       ▄████████    ▄████████  ▄█  ▀█████████▄
  ███    ███     ███    ███   ███    ███ ███    ███    ███
  ███    ███     ███    ███   ███    █▀  ███   ███    ███
 ▄███▄▄▄▄███▄▄   ███    ███   ███        ███  ▄███▄▄▄██▀
▀▀███▀▀▀▀███▀  ▀███████████ ▀███████████ ███ ▀▀███▀▀▀██▄
  ███    ███     ███    ███          ███ ███    ███    ██▄
  ███    ███     ███    ███    ▄█    ███ ███    ███    ███
  ███    █▀      ███    █▀   ▄████████▀  █▀   ▄█████████▀
****************************************************************/



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

#define take(args...) asdf,args
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



//Header ends here




#define INF (1<<20)


#define MAXX 150007
#define MAX_MASK 16
#define MAX_USER 4


#define type int

int N;
type cost[3][MAXX];

type dp[MAXX][MAX_MASK][MAX_USER];

type rec(int pos, int mask, int lastUser)
{
    type &ret = dp[pos][mask][lastUser];

    if(ret != -1) return ret;


    if(pos >= N)
    {
        if(mask == 7)
        {
            return ret = 0;
        }
        else
        {
            return ret = INF;
        }
    }


    ret = INF;

    loop(i, 3)
    {
        if(lastUser == i)
        {
            ret = min(ret, rec(pos+1, mask, lastUser) + cost[lastUser][pos]);
        }
        else
        {
            if( (mask & (1<<i)) == 0 )
            {
                ret = min(ret, rec(pos+1, mask | (1<<i), i ) + cost[i][pos]);
            }
        }
    }


    return ret;

}


void init()
{
    mem(dp, -1);
}


int main()
{

    init();

    sf("%d", &N);

    loop(i, 3)
    {
        loop(j, N)
        {
            sf("%d", &cost[i][j]);
        }
    }


    type ret = INF;

    loop(i, 3)
    {
        ret = min(ret, rec(1, 1<<i, i) + cost[i][0] );
    }

    cout<<ret<<endl;



    return 0;
}
