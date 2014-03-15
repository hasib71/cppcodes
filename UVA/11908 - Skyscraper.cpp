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
struct DATA{
    int st, ed, ben;
    bool operator<(const DATA &ob) const
    {
        return ed<ob.ed;
    }

    void set(int A, int B, int C)
    {
        st = A;
        ed = A + B;
        ben = C;
    }
};


#define MAXX 30002

int N;
DATA ads[MAXX];

int dp[MAXX];



int calc()
{
    dp[0] = 0;
    int low, high, mid;

    for(int i=1; i<=N; i++)
    {
        low = 0;
        high = i - 1;

        while(low <= high)
        {
            mid = (low+high)/2;

            if(ads[mid].ed <= ads[i].st)
            {
                low = mid + 1;
            }
            else
            {
                high = mid -1;
            }
        }

        //dump(i); dump(low);

        dp[i] = max(dp[i-1], dp[high] + ads[i].ben);
    }

    return dp[N];

}


int main()
{
    int kases, kaseno = 0;
    int A, B, C;

    take(kases);

    ads[0].ed = -1;


    while(kases--)
    {
        take(N);
        for(int i=1; i<=N; i++)
        {
            take(A, B, C);
            ads[i].set(A, B, C);
        }


        sort(ads+1, ads+N+1);

/*
        cerr<<endl<<endl;
        for(int i=1; i<=N; i++)
        {
            cerr<<ads[i].st<<" "<<ads[i].ed<<" "<<ads[i].ben<<endl;
        }
*/
        pf("Case %d: %d\n", ++kaseno, calc());
/*
        for(int i=1; i<=N; i++)
        {
            pf("dp[%d] = %d\n", i, dp[i]);
        }
*/

    }


}
