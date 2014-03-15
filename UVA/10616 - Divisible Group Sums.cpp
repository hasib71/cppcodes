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

#define MAXX 202

#define i32 ll


ll nums[MAXX];
int N;
int D, M;
i32 dp[22][202][13];

i32 rec(ll vagshes, int pos, int neyajabe)
{
    //dump(vagshes);
    //dump(pos);
    //dump(neyajabe);
    //cerr<<"\n\n";


    if(pos >= N )
    {
        if(vagshes == 0 && neyajabe == 0) return 1;
        return 0;
    }

    i32 &ret = dp[vagshes][pos][neyajabe];

    if(ret != -1) return ret;

    ret = 0;

    if(neyajabe)
    {
        for(int i=pos; i<N; i++)
        {
            int tmp = (vagshes + nums[i] ) % D;
            tmp = (tmp+D)%D;
            ret += rec(tmp, i+1, neyajabe-1);
        }
    }
    else
    {
        if(vagshes == 0) ret = 1;
        else ret = 0;
    }

    return ret;

}





int main()
{


    int Q;


    int kaseno = 0;

    while(true)
    {
        cin>>N>>Q;
        if(N==0 && Q == 0) break;


        pf("SET %d:\n", ++kaseno);

        loop(i, N) cin>>nums[i];

        loop(i, Q)
        {
            cin>>D>>M;
            mem(dp, -1);
            pf("QUERY %d: %d\n", i+1, rec(0, 0, M));

        }
    }



    return 0;


}
