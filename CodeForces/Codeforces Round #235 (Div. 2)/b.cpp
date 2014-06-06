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


#define MAXX 4009

int takePart[MAXX];

int main()
{
    int x, k;

    take(x, k);

    int typ, div1, div2;


    loop(i, k)
    {
        cin>>typ;
        if(typ == 2)
        {
            cin>>div2;
            takePart[div2] = 1;
        }
        else
        {
            cin>>div2>>div1;
            takePart[div2] = 1;
            takePart[div1] = 1;
        }
    }


    takePart[0] = 1;

    int maxcnt, mincnt;
    maxcnt = mincnt = 0;

    int st, ed;
    st = ed = 0;

    takePart[x] = 1;


    for(int i=1; i<=x; i++)
    {
        if(takePart[i] == 0)
        {
            //cerr<<"  "<<i<<endl;
            maxcnt++;
            ed++;
        }
        else
        {
            mincnt+= (ed+1 - st)/2;
            st = ed = i;
        }
    }

    cout<<mincnt<<" "<<maxcnt<<endl;

}
