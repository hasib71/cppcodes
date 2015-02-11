/*
ID: himuhas1
TASK: shopping
LANG: C++
*/

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

#define MAXX 107
#define MAX_N 7

struct DATA{
    int n;
    vector<paii>v;
    int p;
};

DATA offers[MAXX];



int s, b;

map<int, int>cart_elements;
paii cart[MAX_N];

int dp[MAX_N][MAX_N][MAX_N][MAX_N][MAX_N][MAXX];


int rec(int items[MAX_N], int pos)
{
    int &ret = dp[ items[1] ][ items[2] ][ items[3] ][ items[4] ][ items[5] ][pos];
    if(ret != -1)
    {
        return ret;
    }

    if(pos >= s)
    {
        /// applied all the offers.

        ret = 0;
        for(int i=1; i<=5; i++)
        {
            //dump(items[i]);
            ret += (items[i] * cart[i].sc);
        }
        //cout<<endl;
        return ret;
    }
    else
    {
        ret = rec(items, pos+1);

        bool can_take_this_offer = true;

        loop(i, offers[pos].n)
        {
            if( cart_elements.find(offers[pos].v[i].fr) == cart_elements.end() || offers[pos].v[i].sc > items[ cart_elements[offers[pos].v[i].fr] ] )
            {
                can_take_this_offer = false;
            }
        }

        if(can_take_this_offer)
        {
            loop(i, offers[pos].n)
            {
                items[ cart_elements[offers[pos].v[i].fr] ] -= offers[pos].v[i].sc;
            }
        }

        ret = min(ret, rec(items, pos) + offers[pos].p);
        ret = min(ret, rec(items, pos+1) + offers[pos].p);

        if(can_take_this_offer)
        {
            loop(i, offers[pos].n)
            {
                items[ cart_elements[offers[pos].v[i].fr] ] += offers[pos].v[i].sc;
            }
        }



        return ret;



    }
}



int main()
{
    #ifndef hasibpc
        read("shopping.in");
        write("shopping.out");
    #endif // hasibpc

    sf("%d", &s);

    loop(i, s)
    {
        sf("%d", &offers[i].n);

        loop(j, offers[i].n)
        {
            int c, k;

            sf("%d %d", &c, &k);

            offers[i].v.pb(MP(c, k));
        }

        sf("%d", &offers[i].p);
    }

    sf("%d", &b);

    int id, quantity, price;

    int tmp = 1;
    int items[MAX_N];
    mem(items, 0);

    loop(i, b)
    {
        sf("%d %d %d", &id, &quantity, &price);
        cart[i+1] = MP(quantity, price);
        items[tmp] = quantity;
        cart_elements[id] = tmp++;

    }


    mem(dp, -1);
    cout<<rec(items, 0)<<endl;







}
