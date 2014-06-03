#include<bits/stdc++.h>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define mem(ara, val) memset(ara, val, sizeof(ara))
#define SZ(a) int(a.size())
#define fr first
#define sc second
#define pf printf
#define sf scanf
#define pb push_back
#define MP make_pair
#define paii pair<int, int>
#define dd double
#define ll long long
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define INF (1<<29)
#define dump(x) cerr<<#x<<" = "<<x<<endl;
#define debug(args...) cerr<<args; cerr<<endl;


template<typename T>
ostream& operator<<(ostream &out, vector<T> &v)
{
    out<<"["; loop(i, SZ(v)) out<<", "<<v[i]; out<<" ]"; return out;
}


template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> p)
{
    out<<"( "<<p.fr<<", "<<p.sc<<" )"; return out;
}

template<typename T>
ostream& operator,(ostream &out, T &x )
{
    out<<x<<" "; return out;
}

//header ends here


#define MAXX 57


int dp[MAXX][MAXX];

int a[MAXX], b[MAXX], N;


int rec(int i, int j)
{
    if(i< 0 || j < 0) return 0;

    int &ret = dp[i][j];
    if(ret != -1) return ret;

    int point = 0;
    if(a[i] > b[j]) point = 2;
    else if(a[i] == b[j]) point = 1;

    return ret = max( max(rec(i-1, j), rec(i, j-1)), rec(i-1, j-1) + point );
}

int main()
{
    int kases, kaseno = 0;



    sf("%d", &kases);

    while(kases--)
    {
        mem(dp, -1);

        sf("%d", &N);

        loop(i, N)
        {
            sf("%d", a+i);
        }
        loop(i, N)
        {
            sf("%d", b+i);
        }


        sort(a, a+N); reverse(a, a+N);
        sort(b, b+N); reverse(b, b+N);


        pf("Case %d: %d\n", ++kaseno, rec(N-1, N-1));










    }















    return 0;
}










