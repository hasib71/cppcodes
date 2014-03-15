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

class DATA{
public:
    int s, f;

    bool operator<(const DATA &ob) const
    {
        return f<ob.f;
    }
};


#define MAXX 100007

int N, K;

vector<DATA>customers[MAXX];

map<int, int>mp;

int main()
{

    int kases;
    int cnt;
    int *p;
    int S, F, P;
    int maxid;

    take(kases);
    DATA ob;

    while(kases--)
    {

        mp.clear();
        maxid = 1;

        take(N, K);

        loop(i, N)
        {

            take(S, F, P);
            p = &mp[P];
            if(*p == 0)
            {
                *p = maxid;
                maxid++;
            }

            ob.s = S;
            ob.f = F;
            customers[*p].pb(ob);

        }



        cnt = 0;
        int t;


        for(int i=1; i<maxid; i++)
        {
            t = 0;
            sort(customers[i].begin(), customers[i].end());

            for(int j=0; j<SZ(customers[i]); j++)
            {
                if(t <= customers[i][j].s)
                {
                    t = customers[i][j].f;
                    cnt++;
                }
            }



            customers[i].clear();
        }





        pf("%d\n", cnt);


    }


}
