/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



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

vector<int>primes;

void generatePrime()
{
    bool isprime[1007];
    mem(isprime, 1);

    int root = sqrt(1007) + 1;

    for(int i=3; i<root; i+=2)
    {
        if(isprime[i])
        {
            for(int j=i*i; j<1007; j+=2*i)
            {
                isprime[j] = 0;
            }
        }
    }

    primes.pb(2);
    for(int i=3; i < 1007; i+=2)
        if(isprime[i])
            primes.pb(i);

}



int main()
{
    generatePrime();

    int kases;
    ll num;


    cin>>kases;

    while(kases--)
    {
        cin>>num;
        if((num % 4) != 0)
        {
            cout<<0<<endl;
        }
        else
        {
            num /= 4;
            if(num == 1)
            {
                cout<<"0"<<endl;
            }
            else
            {
                ll xtra = sqrt(num);
                if(xtra*xtra == num)
                {
                    xtra = -1;
                }
                else
                {
                    xtra = 0;
                }

                ll p, q, x;
                p = 1;
                q = 1;


                for(int i=0; i<SZ(primes) && primes[i] <= sqrt(num); i++)
                {
                    x = 0;
                    while( (num%primes[i]) == 0 )
                    {
                        x++;
                        num /= primes[i];
                    }
                    p = p * int( (x+2)/2 );
                    q = q * (x+1 + (primes[i] == 2 ? 2 : 0) );
                }

                if(num > 1)
                {
                    q *= (2 + (num==2 ? 2 : 0) );
                }

                q--;
                p += xtra;

                ll gcd = __gcd(p, q);
                p /= gcd;
                q /= gcd;

                cout<<p<<"/"<<q<<endl;

            }
        }
    }




}
