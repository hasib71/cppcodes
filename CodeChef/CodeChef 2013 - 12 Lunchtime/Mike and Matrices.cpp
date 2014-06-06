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

ll ara[MAXX][MAXX];

int main()
{
    int N, M, L, p, q;
    ll M1, M2;
    take(N, M);
    loop(i, N)
    {
        loop(j, M)
        {
            take(ara[i][j]);
        }
    }

    take(L);

    M1 = M2 = 0;

    int mul1, mul2;
    mul1 = mul2 = 1;


    loop(i, L)
    {
        take(p, q);
        p--;
        q--;
        if(-1<p && p < N && -1 < q && q< M)
        {
            M1 += ara[p][q];
        }
        else
        {
            mul1 = -1;
        }

        if(-1 < q && q < N && -1 < p && p < M)
        {
            M2 += ara[q][p];
        }
        else
        {
            mul2 = -1;
        }
    }

    M1 = M1*mul1;
    M2 = M2 * mul2;

    M1 = max(M1, M2);

    if(M1 < 0) cout<<-1<<endl;
    else cout<<M1<<endl;


}
