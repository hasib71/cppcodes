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

int point[28][28];
string ss;
int str[101];
int len;

ll dp[28][101][101];

ll rec(int lastChar, int i, int k)
{
    if(i == len) return 0;

    ll &ret = dp[lastChar][i][k];

    if(ret != -1) return ret;

    ret = point[lastChar][ str[i] ] + rec(str[i], i+1, k);


    if(k >0)
    {
        loop(c, 26)
        {
            if(c != str[i])
            {
                ret = max(ret, point[lastChar][c] + rec(c, i+1, k-1) );
            }
        }
    }


    return ret;



}


int main()
{
    mem(dp, -1);

    int k, rel;
    char a, b;
    int p;
    cin>>ss>>k;
    cin>>rel;

    loop(i, rel)
    {
        cin>>a>>b>>p;

        a = a - 'a';
        b = b - 'a';

      //  cout<<endl<<endl;
      //  debug((int)a, (int)b);

        point[a][b] = p;
    }

    len = SZ(ss);

    loop(i, len)
    {
        str[i] = ss[i] - 'a';
    }

    cout<<rec(27, 0, k);


}

