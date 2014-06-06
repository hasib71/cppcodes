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

#define MAXX 100005

int comu[MAXX];

int d[501][501];

int cc[502];

int main()
{
    int n, m, k;
    int a, b, c;
    cin>>n>>m>>k;

    int tmp;

    for(int i=1; i<=k; i++)
    {
        cin>>tmp;

        comu[i] = comu[i-1] + tmp;
    }

    int p, q;

    mem(d, 1);



    loop(i, m)
    {
        cin>>a>>b>>c;

        int *t = lower_bound(comu+1, comu+k+1, a);
        //cerr<<"\t"<<*t<<endl;



        p = lower_bound(comu+1, comu+k+1, a) - comu ;
        q = lower_bound(comu+1, comu+k+1, b) - comu;

        //dump(p);
        //dump(q);



        if(c == 0)
        {
            if(p == q)
            {
                cc[p]++;
            }
        }

        d[p][q] = min(d[p][q], c);
        d[q][p] = d[p][q];
    }

    bool possible = true;


    for(int i=1; i<=k; i++)
    {
        if(comu[i] - comu[i-1] == 1) continue;

        if(comu[i] - comu[i-1] - cc[i] > 1)
        {
            //cerr<<"breaking at "<<i<<endl;
            //dump(cc[i]);
            possible = false;
            break;
        }
    }


    if(possible)
    {
        cout<<"Yes"<<endl;
        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<=k; j++)
            {
                if(j > 1) pf(" ");

                if(i == j)
                {
                    cout<<"0";
                }
                else
                {
                    if(d[i][j] == 16843009)
                        cout<<-1;
                    else
                        cout<<d[i][j];
                }
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"No"<<endl;
    }





}
