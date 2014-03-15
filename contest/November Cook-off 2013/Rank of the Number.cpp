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

ll fac[19];


void setFac()
{
    fac[1] = 1;
    fac[2] = 2;
    fac[3] = 6;
    fac[4] = 24;
    fac[5] = 120;
    fac[6] = 720;
    fac[7] = 5040;
    fac[8] = 40320;
    fac[9] = 362880;
    fac[10] = 3628800;
    fac[11] = 39916800;
    fac[12] = 479001600;
    fac[13] = 6227020800;
    fac[14] = 87178291200;
    fac[15] = 1307674368000;
    fac[16] = 20922789888000;
    fac[17] = 355687428096000;

}


string input;
int len;




ll rec(int pos)
{
    if(pos == len)
    {
        return 0;
    }

    ll ret = rec(pos + 1);
    int cnt[10];
    mem(cnt, 0);

    for(int i=pos+1; i<=len; i++)
    {
        cnt[ input[i] ]++;
    }

    int choto = 0;

    for(int i=0; i<input[pos]; i++)
    {
        if(cnt[i]) choto++;
    }




}


int main()
{
    setFac();

}
