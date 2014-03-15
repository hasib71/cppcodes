#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<utility>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define paii pair<int, int>
#define pall pair<ll, ll>
#define PI acos(-1.0)
#define INF (1<<29)
#define SZ(a) ((int)a.size())
#define read(nm) freopen(nm, 'r', stdin)
#define write(nm) freopen(nm, "w", stdout)
#define dump(x) cout<<#x<<" = "<<x<<endl;


using namespace std;


#define take(args...) asdf,args



struct ASDF{

    ASDF& operator,(int &a)
    {
        sf("%d", &a);
        return *this;
    }

    ASDF& operator,(long int &a)
    {
        sf("%ld", &a);
        return *this;
    }

    ASDF& operator,(ll &a)
    {
        sf("%lld", &a);
        return *this;
    }

    ASDF& operator,(char &c)
    {
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(dd &d)
    {
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a)
    {
        cin>>a;
        return *this;
    }
}asdf;




int main()
{
    dd a, b, r;
    int kases, kaseno = 0;

    take(kases);

    while(kases--)
    {
        take(b, r, r,r);
        a = ((b*b*r)/ (1+r));
        a = sqrt(a);
        pf("Case %d: %.10lf\n", ++kaseno, a);
    }

}
