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
class PackingBallsDiv1 {
public:
	int minPacks(int, int, int, int, int);
};

int PackingBallsDiv1::minPacks(int K, int A, int B, int C, int D)
{
    ll X[MAXX];

    X[0] = A;
    FOR(i, 1, K)
    {
        X[i] = (X[i-1]*B + C)%D + 1;
    }

    sort(X, X+K);

    int result = 1<<29;

    int tt;


    loop(i, K)
    {
        if(i> 0 && X[i] == X[i-1]) continue;
        int tmp = X[i];
        if(tmp >= result) break;
        FOR(j, i+1, K)
        {
           tt = X[j] - X[i];
           tmp += tt / K;

           if(tt % K > 0)
                tmp++;
            if(tmp > result) break;
        }
        result = min(tmp, result);
    }
    return result;
}

<%:testing-code%>
//Powered by [KawigiEdit] 2.0!
