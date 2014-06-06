
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

int x[3], y[3];

int isRightAngle()
{
    double d[3];
    double p, q;


    loop(i, 3)
    {
        p = (x[i] - x[(i+1)%3]);
        p = p*p;

        q = (y[i] - y[(i+1)%3]);
        q = q*q;
        d[i] = sqrt(  p + q );
    }
    sort(d, d+3);
    if(abs(d[0]*d[0] + d[1]*d[1] - d[2]*d[2]) < 0.00000001)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int main()
{
    int N;
    scanf("%d", &N);
    int cnt = 0;
    while(N--)
    {
        loop(i, 3)
        {
            scanf("%d %d", &x[i], &y[i]);
        }
        cnt += isRightAngle();
    }

    cout<<cnt;



    return 0;
}
