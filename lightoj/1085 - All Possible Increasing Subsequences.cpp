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
#define MOD 1000000007

int seg[4*MAXX];
int get(int idx, int st, int ed, int i, int j)
{
    if(st == i && ed == j)
    {
        return seg[idx];
    }

    int l = idx<<1;
    int r = l + 1;
    int mid = (st+ed)/2;

    if(j <= mid)
    {
        return get(l, st, mid, i, j);
    }
    else if(mid < i)
    {
        return get(r, mid+1, ed, i, j);
    }
    else
    {
        return ( get(l, st, mid, i, mid) + get(r, mid+1, ed, mid+1, j) ) % MOD;
    }
}

void update(int idx, int st, int ed, int pos, int val)
{
    if(st == pos && pos == ed)
    {
        seg[idx] += val;
        seg[idx] %= MOD;
        return;
    }


    int mid = (st+ed)/2;
    int l = idx<<1;
    int r = l+1;

    if(pos <= mid)
    {
        update(l, st, mid, pos, val);
    }
    else
    {
        update(r, mid+1, ed, pos, val);
    }

    seg[idx] = (seg[l] + seg[r]) % MOD;

}


int main()
{
//    int k = 1000000007;
//    cout<<k;
    int kases, kaseno = 0;
    take(kases);
    int n;
    int ara[MAXX];



    while(kases--)
    {
        take(n);
        loop(i, n)
        {
            take(ara[i]);
        }
        set<int>idx(ara, ara+n);
        vector<int>v(all(idx));

        mem(seg, 0);
        int num;
        int low, high, mid;
        loop(i, n)
        {
            num = ara[i];
            low = 0;
            high = SZ(v)-1;

            while(low<=high)
            {
                mid = (low+high)/2;
                if(v[mid] < num)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid -1;
                }
            }

            //dump(low);
            //dump(SZ(v));



            if(low == 0)
            {
                update(1, 1, SZ(v), 1, 1);
            }
            else
            {
                int res = get(1, 1, SZ(v), 1, low) + 1;
                res %= MOD;
                //dump(res);
                update(1, 1, SZ(v), low +1, res);
            }

            /*

            FOR(j, 1, 4)
            {
                cout<<seg[j]<<"  ";
            }
            cout<<endl;

            dump(val[i]);
            */

            //cout<<endl<<endl;
        }
        pf("Case %d: %d\n", ++kaseno, seg[1]);


    }

}

