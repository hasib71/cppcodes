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

#define MAXX 100004

//Header ends here

vector<int>nodes[MAXX];
char color[MAXX];

void doColor(int id)
{
//    dump(id);
    char colorBit = 7;
    loop(i, SZ(nodes[id]))
    {
        colorBit = colorBit & ( ~(color[ nodes[id][i] ]) );
    }
    //dump((int)colorBit);

    loop(i, 3)
    {
        if(colorBit & (1<<i))
        {
            color[id] = 1<<i;
            //dump(i);
            //cout<<"setting color of "<<id<<" "<<(int)color[id]<<endl;
            break;
        }
    }

    //return;

    loop(i, SZ(nodes[id]))
    {
        //cout<<"color of "<<nodes[id][i]<<" = "<<(int)color[nodes[id][i]]<<endl;
        if(color[nodes[id][i]] == 0)
        {
            doColor(nodes[id][i]);
        }
    }
    return;
}

int main()
{
    int n, m;
    int a[3];
    mem(color, 0);

    take(n, m);
    loop(i, m)
    {
        loop(j, 3)
        {
            take(a[j]);
        }

        loop(j, 3)
        {
            nodes[ a[j] ].pb(a[(j+1)%3]);
            nodes[a[j]].pb(a[(j+2)%3]);
        }
    }





    for(int i=1; i<=n; i++)
    {
        if(color[i] == 0)
            doColor(i);
    }

    pf("%d", color[1]==4?3:color[1]);

    for(int i=2; i<=n; i++)
    {
        pf(" %d", color[i]==4?3:color[i]);
    }


}

