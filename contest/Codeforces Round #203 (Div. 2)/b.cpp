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

#define MAXX 100003

bool isHotel[MAXX];
vector<int>allHotelPos;
int mapping[MAXX];
char onlyOneCameHere[MAXX];

int dfs(int u)
{
    //dump(u);
    if(mapping[u] != -1 && onlyOneCameHere[mapping[u]] < 2 && !isHotel[mapping[u]] )
    {
        return dfs(mapping[u]) + 1;
    }
    else
    {
        return 1;
    }
}




int main()
{
    mem(onlyOneCameHere, 0);

    int n;
    take(n);
    int k;
    loop(i, n)
    {
        take(k);
        isHotel[i] = (k>0?true:false);
        if(k)
        {
            allHotelPos.pb(i);
        }
    }

    loop(i, n)
    {
        take(mapping[i]);
        mapping[i]--;
        if(onlyOneCameHere[mapping[i]] < 2)
        {
            onlyOneCameHere[mapping[i]]++;
        }
    }

    //dump("done");

    int maxLenght = -1;
    int hotel;

    loop(i, SZ(allHotelPos))
    {
        int k = dfs(allHotelPos[i]);
        if(maxLenght < k)
        {
           maxLenght = k;
           hotel = allHotelPos[i];
        }
        //dump("first dfs is done");
    }


    pf("%d\n", maxLenght);

    vector<int>path;
    int u = hotel;

    while(true)
    {
        //dump(u);
        path.pb(u);
        u = mapping[u];

        if(u == -1 || isHotel[u] || onlyOneCameHere[u] >= 2)
        {
            break;
        }
    }
    reverse(all(path));
    pf("%d", path[0]+1);


    FOR(i, 1, SZ(path))
    {
        pf(" %d", path[i] + 1);
    }
    cout<<endl;
}
