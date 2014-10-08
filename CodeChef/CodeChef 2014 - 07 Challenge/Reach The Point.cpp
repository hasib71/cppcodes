#include<bits/stdc++.h>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define MP make_pair
#define pb push_back
#define sf scanf
#define pf printf
#define SZ(a) int(a.size())
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define paii pair<int,int>
#define ll long long
#define dump(x) cerr<<#x<<" = "<<x<<endl


///header ends



int main()
{
    int kases;
    cin>>kases;


    ll x, y, a, b;
    ll m;
    ll result;


    while(kases--)
    {
        cin>>a>>b;

        a = abs(a);
        b = abs(b);

        m = min(a, b);
        result = 2*m;



        x = a - m;
        y = b - m;

        result += (x*2) + (x%2) + (y*2) - (y%2) ;

        cout<<result<<endl;



    }
}
