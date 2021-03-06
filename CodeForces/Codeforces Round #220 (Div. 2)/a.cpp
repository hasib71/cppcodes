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
#define debug(args...) asdfg,args; cout<<endl
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
struct ASDFG{
    template<typename T>
    ASDFG& operator,(vector<T> &v){
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v)){
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }

    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }


}asdfg;



//Header ends here

#define INF (1<<29)

int n, m, i, j, a, b;


int calc(int px, int py, int cx, int cy)
{
    //debug(px, py, cx, cy);
    int dx = abs(cx - px);
    int dy = abs(cy - py);

    if(dx%a ==0 && dy%b == 0)
    {
        int mx = dx/a;
        int my = dy/b;

        //debug(mx, my);

        int ret = (mx+my) - 2*min(mx, my);

        if(ret %2 == 0)
        {
            //dump((min(mx, my) + 2*ret));
            return (min(mx, my) + ret);
        }
        else
        {
            return INF;
        }
    }
    else
    {
        return INF;
    }
}

int main()
{
    take(n, m, i, j, a, b);

    int ret = calc(i, j, 1, m);
    ret = min(ret, calc(i, j, n, 1));
    ret = min(ret, calc(i, j, n, m));
    ret = min(ret, calc(i, j, 1, 1));

    if(ret == INF)
    {
        cout<<"Poor Inna and pony!"<<endl;
    }
    else
    {
        cout<<ret<<endl;
    }


}
