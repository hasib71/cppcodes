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
#define MAXX 34
#define MAX_N 100007

ll powOfTwo[MAXX];
bool isPrime[MAX_N];
vector<ll>primes;


void generatePrimes()
{
    mem(isPrime, 1);



    int root = sqrt(MAX_N) + 7;

    for(int i=3; i<root; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<MAX_N; j+=2*i)
            {
                isPrime[j] = false;
            }
        }
    }

    primes.pb(2);

    for(int i=3; i<MAX_N; i+=2)
    {
        if(isPrime[i])
        {
            primes.pb(i);
        }
    }

}



void init()
{
    powOfTwo[0] = 1;
    for(int i=1; i<MAXX; i++)
    {
        powOfTwo[i] = powOfTwo[i-1] * (ll)2;
    }

    generatePrimes();
}



ll solve(ll n)
{
    ll ret = 1;

    loop(i, SZ(primes))
    {

        if((n % primes[i]) == 0)
        {
            int cnt = 0;

            while( (n % primes[i]) == 0 )
            {
                cnt++;
                n /= primes[i];
            }

            ll tmp = 1;

            loop(j, cnt)
            {
                tmp = tmp * primes[i] + 1;
            }

            ret *= tmp;

        }
    }


    if(n != 1)
    {
        ret = ret * (1 + n);
    }
    //dump(ret);
    return ret;


}



int main()
{
    #ifdef hasibpc
        read("input");
        write("output");
    #endif // hasibpc

    init();

    //dump(isPrime[9]);

    //cout<<solve(28);

    int n;

    while(true)
    {
        scanf("%d", &n);

        if(n == 0)
        {
            break;
        }

        ll num = powOfTwo[n-1] * (powOfTwo[n] - 1);


        ll ret1 = (1LL<<n) - 1;

        //dump(ret1);

        ret1 *= solve(ret1);

        if(num*2 == ret1)
        {
            pf("Perfect: %lld!\n", num);
        }
        else if((n%2) == 1 && isPrime[n])
        {
            pf("Given number is prime. But, NO perfect number is available.\n");
        }
        else
        {
            pf("Given number is NOT prime! NO perfect number is available.\n");
        }





    }


}
