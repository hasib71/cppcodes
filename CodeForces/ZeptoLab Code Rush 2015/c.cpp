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

ll C, J1, J2, W1, W2;

ll x, y;


void init()
{

}

ll calculateJoy(ll y)
{
    if(W2 * y > C)
    {
        return 0;
    }
    else
    {
        ll x = (C - y*W2)/W1;

        return x*J1 + y*J2;
    }
}



int main()
{
    init();

    cin>>C>>J1>>J2>>W1>>W2;

    if(J1*W2 > W1*J2)
    {
        swap(J1, J2);
        swap(W1, W2);
    }


    x = C/W1;

    y = (C - (x*W1))/W2;

    ll maxJoy = x*J1 + y*J2;

    ll low = y, high = C, mid;

    //dump(maxJoy);

    while(low <= high)
    {

        if(low == high)
        {
            maxJoy = max(maxJoy, calculateJoy(low));
            break;
        }

        ll d = (high - low)/3;

        if(d == 0)
        {
            d = 1;
        }

        ll y1 = low + d - 1;

        ll y2 = low + 2*d - 1;

       // cerr<<"Low "<<low<<" high = "<<high<<" y1 = "<<y1<<" y2 = "<<y2<<endl;



        ll a1 = calculateJoy(y1);
        ll a2 = calculateJoy(y2);

        maxJoy = max(maxJoy, max(a1, a2) );

        if(a1 < a2)
        {
            low = y1 + 1;

        }
        else if(a1 > a2)
        {
            high = y2-1;
            //cerr<<"HERE"<<endl;
        }
        else
        {
            //cerr<<"Here"<<endl;
            low = y1 + 1;
            high = y2 - 1;
        }


    }


    cout<<maxJoy<<endl;







    return 0;
}
