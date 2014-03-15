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


#define MAXX 1002

int ara[MAXX];


int main()
{
    int len;

    take(len);

    loop(i, len)
    {
        take(ara[i]);
    }

    int elem = ara[len-1];

    for(int i=len-2; i>-1; i--)
    {
        if(elem < ara[i])
        {
            ara[i+1] = ara[i];
            pf("%d", ara[0]);
            for(int j=1; j<len; j++)
            {
                pf(" %d", ara[j]);
            }
            pf("\n");
        }
        else
        {
            ara[i+1] = elem;
            pf("%d", ara[0]);
            for(int j=1; j<len; j++)
            {
                pf(" %d", ara[j]);
            }
            pf("\n");
            break;
        }
    }

    if(elem < ara[0])
    {
        ara[0] = elem;
        pf("%d", ara[0]);
        for(int j=1; j<len; j++)
        {
            pf(" %d", ara[j]);
        }
        pf("\n");
    }

    return 0;


}
