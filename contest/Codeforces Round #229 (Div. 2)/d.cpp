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

#define MAXX 52



int main()
{
    int n, m, k;

    cin>>n>>m>>k;


    vector<pair<int, paii> >v;
    int dist = 2;
    ll sum = 0;

    while(true)
    {
        for(int i= max(1, dist-m ) ; i<dist; i++)
        {
            if(SZ(v) == k)
            {
                goto hell;
            }

            int j = dist - i;

            if(i>n)
            {
                break;
            }
            else if(j <= m)
            {
                v.pb(MP(dist, MP(i, j)));
                sum += dist-1;
            }

        }
        dist++;
    }


    int p, q;
    hell:
        sort(all(v));
        reverse(all(v));

        cout<<sum<<endl;
        loop(i, SZ(v))
        {
            p = v[i].sc.fr;
            q = v[i].sc.sc;

            //debug(p, q);

            for(int i=1; i<=p; i++)
            {
                pf("(%d,%d) ", i, 1);
            }

            for(int i=2; i<=q; i++)
            {
                pf("(%d,%d) ", p, i);
            }
            pf("\n");
        }




}
