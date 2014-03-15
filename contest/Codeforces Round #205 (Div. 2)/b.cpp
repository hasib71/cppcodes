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

#define MAXX 102

int cnt[MAXX];


int main()
{
    paii ara[MAXX];
    int n, tmp;
    take(n);
    tmp = n;
    n = n * 2;
    loop(i, n)
    {
        take(ara[i].fr);

        if(cnt[ ara[i].fr ] < 2)
        {
            cnt[ara[i].fr]++;
        }
        ara[i].sc = i;
    }

    sort(ara, ara+n);
    int pos[2*MAXX];


    set<int>left, right;
    int totalUseless = 0;

    loop(i, n)
    {
        if(i>0 && ara[i].fr == ara[i-1].fr && totalUseless %2 == 1)
        {
            pos[ara[i].sc] = 2;
            right.insert(ara[i].fr);
            pos[ara[++i].sc] = 1;
            left.insert(ara[i].fr);
        }
        else
        {
            pos[ara[i].sc] = 1;
            left.insert(ara[i].fr);
            pos[ara[++i].sc] = 2;
            right.insert(ara[i].fr);
        }

        if(i>0 &&ara[i].fr == ara[i-1].fr)
        {
            totalUseless++;
        }
        if(i>1 && ara[i-1].fr == ara[i-2].fr)
        {
            totalUseless++;
        }
    }

    /*

    long long total = 0;
    loop(i, 101)
    {
        total += cnt[i];
    }

    int x = total / 2;
    int y = total - x;

    cout<<x*y<<endl;
    */

    //test

    /*

    for(set<int>::iterator it = right.begin(); it!=right.end(); it++)
    {
        cout<<*it<<endl;
    }

    */

    dump(totalUseless);



    pf("%d\n", SZ(left)*SZ(right));


    pf("%d", pos[0]);

    FOR(i, 1,  n)
    {
        pf(" %d", pos[i]);
    }

}

