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

#define MAXX 200002

#include<sstream>

ll sum[4*MAXX];
ll lazy[4*MAXX];


int n;

void updateNode(int idx, ll val)
{
    lazy[idx] += val;
    sum[idx] += val;
}



void update(int idx, int st, int ed, int i, int j, ll val)
{
    if(st == i && ed==j)
    {
        sum[idx] += val;
        lazy[idx] += val;
        return;
    }

    int l =idx*2;
    int r = l+1;

    int mid = (st+ed)/2;

    if(lazy[idx] != 0)
    {
        updateNode(l, lazy[idx]);
        updateNode(r, lazy[idx]);
        lazy[idx] = 0;
    }


    if(j<= mid)
    {
        update(l, st, mid, i, j, val);
    }
    else if(mid < i)
    {
        update(r, mid+1, ed, i, j, val);
    }
    else
    {
        update(l, st, mid, i, mid, val );
        update(r, mid+1, ed, mid+1, j, val);
    }


    sum[idx] = min(sum[l], sum[r]);

}


ll query(int idx, int st, int ed, int i, int j)
{
    if(st == i && ed == j)
    {
        return sum[idx];
    }

    int l = idx<<1;
    int r =l + 1;

    int mid = (st+ed)/2;

    if(lazy[idx] != 0)
    {
        updateNode(l, lazy[idx]);
        updateNode(r, lazy[idx]);
        lazy[idx] = 0;
    }


    if(j<=mid)
    {
        return query(l, st, mid, i, j);
    }
    else if(mid < i)
    {
        return query(r, mid+1, ed, i, j);
    }
    else
    {
        return min( query(l, st, mid, i, mid), query(r, mid+1, ed, mid+1, j) );
    }


}


int main()
{

    take(n);
    ll num;


    loop(i, n)
    {
        scanf("%I64d", &num);

        //dump(num);

        update(1, 1, n, i+1, i+1, num );




    }


    int m;
    take(m);

    stringstream ss;
    string sk;

    int lf, rg, v;
    cin.ignore();
    loop(i, m)
    {
        getline(cin, sk);

        ss<<sk;

        ss>>lf>>rg;
        lf++;
        rg++;

        if(ss.good())
        {
            ss>>v;

            if(lf <= rg)
            {
                update(1, 1, n, lf, rg, v);
            }
            else
            {
                update(1, 1, n, lf, n, v);
                update(1, 1, n, 1, rg, v);
            }
        }
        else
        {
            if(lf <= rg)
            {
                cout<<query(1, 1, n, lf, rg)<<endl;
            }
            else
            {
                cout<< min(query(1, 1, n, lf, n), query(1, 1, n, 1, rg))<<endl;
            }

        }

        ss.clear();




    }


}

