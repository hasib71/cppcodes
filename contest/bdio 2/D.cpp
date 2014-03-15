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


pair<double, double> schedule[9];


int N;

int perm[8];


bool canBeDone(double diff)
{
    /*
    loop(i, N)
    {
        cout<<perm[i]<<" ";
    }
    cout<<"    "<<diff<<endl<<endl;
    */

    double last = schedule[perm[0]].fr;
    for(int i=1; i<N; i++)
    {
        last = last + diff;

        if(last <= schedule[perm[i]].sc )
        {
            last = max(last, schedule[perm[i]].fr);
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool can(double diff)
{
    loop(i, N) perm[i] = i;


    bool r = false;

    do
    {
        if(canBeDone(diff))
        {
            r = true;
            break;
        }
    }while(next_permutation(perm, perm+N));

    return r;
}


int main()
{
    int kases, kaseno = 0;

    while(scanf("%d", &N) && N != 0)
    {
        loop(i, N)
        {
            cin>>schedule[i].fr>>schedule[i].sc;
            schedule[i].fr *= 60;
            schedule[i].sc *= 60;
        }



        double low = 0, high = 86404;
        double mid;
        int cnt = 90;
        while(cnt--)
        {
            mid = (low+high)/2.0;

            if(can(mid))
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }


        int res = (int)(mid+0.5);
        int min =  res/60;
        res = res%60;

        pf("Case %d: %d:", ++kaseno, min);
        if(res < 10)
        {
            pf("0");
        }
        pf("%d\n", res);
    }


}
