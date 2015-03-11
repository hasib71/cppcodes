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


#define MAXX 10007



ll A, C;
vector<ll>primes;



void generatePrimes()
{

    bool isPrime[MAXX];

    mem(isPrime, 1);

    int root = sqrt(MAXX) + 7;

    for(int i=3; i<root; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<MAXX; j+=2*i)
            {
                isPrime[j] = false;
            }
        }
    }

    primes.pb(2);



    for(int i=3; i<MAXX; i+=2)
    {
        if(isPrime[i])
        {
            primes.pb(i);
        }
    }

}

void init()
{
    generatePrimes();

}


void solve()
{
    if((C%A) != 0)
    {
        pf("NO SOLUTION\n");
    }
    else
    {
        ll root = sqrt(C);

        ll ret = 1;

        for(int i=0; i<SZ(primes) && primes[i] <= root; i++)
        {
            if((C%primes[i]) == 0)
            {
                ll tmp = 1;

                while( (C%primes[i]) == 0 && (A % primes[i]) == 0 )
                {
                    tmp*=primes[i];
                    C /= primes[i];
                    A /= primes[i];
                }

                if( (C % primes[i]) == 0 )
                {
                    do {
                        tmp *= primes[i];
                        C /= primes[i];
                    }while( (C%primes[i]) == 0 );

                    ret *= tmp;

                }

                root = sqrt(C);
            }
        }

        if(C != 1)
        {
            if(A != C)
            {
                ret *= C;
            }
        }

        pf("%lld\n", ret);
    }
}


int main()
{
    init();

    int kases;

    take(kases);

    while(kases--)
    {
        take(A, C);

        solve();
    }



    return 0;
}
