/****************************************************************
   ▄█    █▄       ▄████████    ▄████████  ▄█  ▀█████████▄
  ███    ███     ███    ███   ███    ███ ███    ███    ███
  ███    ███     ███    ███   ███    █▀  ███   ███    ███
 ▄███▄▄▄▄███▄▄   ███    ███   ███        ███  ▄███▄▄▄██▀
▀▀███▀▀▀▀███▀  ▀███████████ ▀███████████ ███ ▀▀███▀▀▀██▄
  ███    ███     ███    ███          ███ ███    ███    ██▄
  ███    ███     ███    ███    ▄█    ███ ███    ███    ███
  ███    █▀      ███    █▀   ▄████████▀  █▀   ▄█████████▀
****************************************************************/



#include<bits/stdc++.h>


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

#define take(args...) asdf,args
#define dump(x) cerr<<#x<<" = "<<x<<endl
#define debug(args...) cerr,args; cerr<<endl;
using namespace std;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}




template<typename T>
ostream& operator,(ostream& output, T x)
{
    output<<x<<" ";
    return output;
}



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



//Header ends here


#define MAXX 30007

int n;
int q;
vector<paii>v;
vector<pair<paii, paii> > query;

int T[MAXX];

int lowBit(int x)
{
    return x & -x;
}

int sum(int i)
{
    int result = 0;
    while(i > 0)
    {
        result = result + T[i];
        i = i - lowBit(i);
    }
    return result;
}

int sum(int i, int j)
{
    return sum(j) - sum(i-1);
}


void update(int pos, int value)
{
    while(pos <= n)
    {
        T[pos] += value;
        pos = pos + lowBit(pos);
    }
}


int main()
{

    take(n);
    v.resize(n+1);

    for(int i=1; i<=n; i++)
    {
        cin>>v[i].fr;
        v[i].sc = i;
    }

    take(q);


    loop(abc, q)
    {
        int i, j, k;
        take(i, j, k);

        query.pb(MP(MP(k, abc), MP(i, j)));
    }

    sort(all(v));
    reverse(all(v));

    sort(all(query));
    reverse(all(query));



    mem(T, 0);

    int pos = 0;

    loop(i, SZ(query))
    {
        int p, q, k;

        k = query[i].fr.fr;
        p = query[i].sc.fr;
        q = query[i].sc.sc;


        while(pos < n && v[pos].fr > k)
        {
            update(v[pos].sc, 1);
            pos++;
        }

        int ret = sum(p, q);
        query[i].fr.fr = query[i].fr.sc;
        query[i].fr.sc = ret;

    }

    sort(all(query));

    loop(i, SZ(query))
    {
        pf("%d\n", query[i].fr.sc);
    }

    return 0;








}
