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





//Header ends here

#define MAXX 10000007


ll A, B, K;

int primacity[MAXX];

vector<int>primes;

void generatePrimes()
{
    int n = sqrt(MAXX) + 7;

    primes.pb(2);

    bool isPrime[n];

    mem(isPrime, 1);

    int root = sqrt(n) + 2;

    for(int i=3; i<root; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<n; j+=2*i)
            {
                isPrime[j] = false;
            }
        }
    }
    for(int i=3; i<n; i+=2)
    {
        if(isPrime[i])
        {
            primes.pb(i);
        }
    }
}

void generatePrimacity()
{
    primacity[1] = 0;
    primacity[2] = 1;
    for(int num=3; num<MAXX; num++)
    {
       // int root = sqrt(num) + 1;
        bool found = false;
        for(int j=0; j<SZ(primes) && primes[j] < num; j++)
        {
            if((num % primes[j]) == 0)
            {
                found = true;
                int k = num/primes[j];
                primacity[num] = primacity[k] + ((k%primes[j]) != 0);
                break;
            }
        }

        if(!found)
        {
            primacity[num] = 1;
        }
    }
}



int main()
{
    read("input");
    write("output");
    generatePrimes();
    generatePrimacity();


    int kases, kaseno=0;

    cin>>kases;

    while(kases--)
    {
        cin>>A>>B>>K;
        pf("Case #%d: ", ++kaseno);
        if(K < 100)
        {
            int cnt = 0;
            for(int i=A; i<=B; i++)
            {
                if(primacity[i] == K)
                {
                    cnt++;
                }
            }
            cout<<cnt<<endl;
        }
        else
        {
            cout<<0<<endl;
        }




    }




}
