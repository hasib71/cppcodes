#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
#include<set>

#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>



#define FOR(i,s,e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define pb push_back
#define fr first
#define sc second
#define all(v) v.begin(), v.end()
#define sf scanf
#define pf printf
#define MP make_pair
#define PI acos(-1.0)
#define INF (1<<29)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define ll long long
#define dd double
#define SZ(a) int(a.size())
#define paii pair<int, int>
#define pall pair<ll, ll>
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)

#define dump(x) cerr<<#x<<" = "<<x<<endl


using namespace std;



template<typename T>
ostream &operator<<(ostream &out, vector<T>&v)
{
    out<<"[ ";
    if(SZ(v))
    {
        out<<v[0];
    }

    FOR(i, 1, SZ(v))
    {
        out<<", "<<v[i];
    }
    out<<" ]"<<endl;
    return out;
}


template<typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2>&p)
{
    out<<"( "<<p.fr<<", "<<p.sc<<" )"<<endl;
    return out;
}


//header ends here


#define MAXX 100009

int ara[MAXX];
int sign[MAXX];

int edit[MAXX];




int main()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>ara[i];
    }


    int last = ara[n];
    sign[n] = 1;

    for(int i=n-1; i>0; i--)
    {
        if(ara[i] > last)
        {
            edit[i] = -1;
            sign[i] = 1;
            last = ara[i] - last;
        }
        else
        {
            last = last - ara[i];
            sign[i] = -1;
            edit[i] = 1;
        }
    }

    string result;

    int edited = 1;
    edit[0] = 1;
    int mul;


    for(int i=1; i<=n; i++)
    {
        //dump(sign[i]);
        //cerr<<"\t"<<edit[i]<<endl;
        edited *= edit[i-1];
        mul = edited * sign[i];

        if(mul == 1)
        {
            result.pb('+');
        }
        else
        {
            result.pb('-');
        }
    }

    cout<<result<<endl;





}


