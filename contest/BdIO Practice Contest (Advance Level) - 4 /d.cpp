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


#define MAXX 200003


//Header ends here

#define lowbit(i) (i & -i)

int nums[MAXX];
int allnums[MAXX];
int cnt;
int T[MAXX];


void update(int i)
{
    while(i<=cnt)
    {
        T[i]++;
        i+=lowbit(i);
    }
}

ll sum(int i)
{
    ll s = 0;
    while(i > 0)
    {
        s += T[i];
        i -= lowbit(i);
    }
    return s;
}


int main()
{
    int kases, kaseno = 0;

    take(kases);

    while(kases--)
    {
        take(cnt);
        loop(i, cnt)
        {
            take(nums[i]);
            allnums[i] = nums[i];
        }


        sort(allnums, allnums+cnt);

        mem(T, 0);

        int pos;
        ll res = 0;



        loop(i, cnt)
        {
            //dump(i);
            pos = lower_bound(allnums, allnums+cnt, nums[i] ) - allnums;

            pos = cnt - pos;

            //dump(pos);

            res += sum(pos);

            //dump(res);
            update(pos);
/*
            loop(i, 4)
            {
                pf("T[%d] = %d\n", i, T[i]);
            }
*/


        }

        cout<<res<<endl;


    }


}
