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

#define MAXX 502

int cnt[MAXX][MAXX];
int totalEdge[MAXX];

int main()
{
    mem(cnt, 0);
    mem(totalEdge, 0);
    int n, m;
    int x, y;
    take(n, m);

    loop(i, m)
    {
        take(x, y);
        cnt[x][y]++;



        if(x != y)
        {
            totalEdge[y]++;
            totalEdge[x]++;
        }

    }

    int needed = (1<<29), tmpneeded;



    int ache;

    int centerIndex;


    for(int i=1; i<=n; i++)
    {
        tmpneeded = 0;

        for(int j=1; j<=n; j++)
        {
            if(i==j) continue;
            ache = cnt[i][j] + cnt[j][i];

            tmpneeded = tmpneeded + (2 - ache);

            tmpneeded = tmpneeded + totalEdge[j] - ache;


        }

        needed = min(needed, tmpneeded - (1- cnt[i][i])  );


    }





    for(int i=1; i<=n; i++)
    {
        needed = needed + (1-cnt[i][i]);
    }

    cout<<needed<<endl;






}
