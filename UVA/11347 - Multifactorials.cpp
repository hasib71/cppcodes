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

#define MAXX 1007
#define MAX_PRIMES 170


vector<int>primes;
int factor[MAXX][MAX_PRIMES];


void generatePrimes()
{
    bool isPrime[MAXX];

    mem(isPrime, 1);

    int root = sqrt(MAXX);


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

void generateFactors()
{
    for(int n=2; n<MAXX; n++)
    {
        int pos = -1;

        loop(i, SZ(primes))
        {
            if((n % primes[i]) == 0)
            {
                pos = i;
                break;
            }
        }

        int before = n/primes[pos];

        loop(i, SZ(primes))
        {
            factor[n][i] = factor[before][i];
        }

        factor[n][pos]++;
    }
}






void init()
{
    generatePrimes();

    generateFactors();
}


void solve(int N, int K)
{
    ll cnt[MAX_PRIMES];

    mem(cnt, 0);

    while(N > 0)
    {
        loop(i, SZ(primes))
        {
            cnt[i]+= factor[N][i];
        }
        N -= K;
    }

    ll limit = 1000000000000000000;

    ll ret = 1;

    bool exceeded = false;

    loop(i, MAX_PRIMES)
    {
        if(ret > (limit/(cnt[i] + 1)))
        {
            exceeded = true;
            break;
        }

        ret = ret * (cnt[i] + 1);
    }

    if(exceeded)
    {
        pf("Infinity\n");
    }
    else
    {
        pf("%lld\n", ret);
    }

}


int main()
{
    init();

    int kases, kaseno = 0;

    sf("%d", &kases);

    char str[27];
    int N;

    while(kases--)
    {
        sf("%d%s", &N, str);

        pf("Case %d: ", ++kaseno);

        solve(N, strlen(str));

    }



    return 0;
}
