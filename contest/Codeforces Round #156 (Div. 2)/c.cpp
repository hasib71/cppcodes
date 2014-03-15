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

#define MAXX 1000002
vector<int>vt[MAXX];

void solve(int &n, vector<int>&abc)
{
    set<int>s(all(abc));

    vector<int>st(all(s));



    loop(i, SZ(abc))
    {
        vt[ abc[i] ].pb(i);
    }

    int mxLen = 1;

    int len;

    //dump(SZ(st));



    loop(i, SZ(st))
    {
        loop(j, SZ(st))
        {
            len = 0;
            int p = st[i];
            int q = st[j];
            int a, b;
            a = b = 0;
            int last = -1;

            while(true)
            {
               // cerr<<"i'm here"<<endl;
                //cerr<<len<<endl;
                if(len&1)
                {
                    if(b >= SZ(vt[q]))
                    {
                       // cerr<<"oops!!"<<endl;
                        break;
                    }
                   // cerr<<"first"<<endl;
                    if(last < vt[q][b])
                    {
                        last = vt[q][b];
                        len++;
                    }
                    b++;

                }
                else
                {
                    if(a >= SZ(vt[p]))
                    {
                        break;
                    }
                    //cerr<<"second"<<endl;
                    if(last < vt[p][a])
                    {
                        last = vt[p][a];
                        len++;
                    }
                    a++;
                }
            }

            mxLen = max(mxLen, len);

        }
    }

    cout<<mxLen<<endl;




}



int main()
{
    int n;
    vector<int>v;

    take(n);
    v.resize(n);

    loop(i, n) take(v[i]);


    solve(n, v);


}
