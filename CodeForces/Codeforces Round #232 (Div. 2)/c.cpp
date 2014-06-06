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

vector<int>primes;


#define MOD 1000000007
#define MAXROOT 31624

bool isPrime[MAXROOT];

void generatePrime()
{
    primes.pb(2);
    mem(isPrime, 1);
    int root = sqrt(MAXROOT) + 2;

    for(int i=3; i<root; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<MAXROOT; j+=2*i)
            {
                isPrime[j]  = false;
            }
        }
    }

    for(int i=3; i<MAXROOT; i+=2) if(isPrime[i]) primes.pb(i);
}



ll n, a;

map<int, int>cntPow;

ll nCr[15000][503];

void generatenCr()
{
    loop(i, 15000)
    {
        nCr[i][0] = 1;
    }

    loop(i, 15000)
    {
        int k = min(i, 502);
        for(int j=1; j<=k; j++)
        {
            nCr[i][j] = (nCr[i-1][j] + nCr[i-1][j-1])%MOD;
        }
    }

}




int main()
{
    //cout<<log2(1000000000);
    generatePrime();
    generatenCr();
    //cout<<nCr[4][2];
    cin>>n;
    loop(i, n)
    {
        cin>>a;

        loop(j, SZ(primes))
        {
            while(a%primes[j] == 0)
            {
                cntPow[primes[j]]++;
                a /= primes[j];
            }
        }


        if(a != 1)
        {
            cntPow[a]++;
        }
    }

    n--;

    ll sum = 1;

    for(map<int,int>::iterator it=cntPow.begin(); it!=cntPow.end(); it++)
    {
        sum = (sum * nCr[it->sc + n ][n])%MOD;
    }

    cout<<sum<<endl;

}
