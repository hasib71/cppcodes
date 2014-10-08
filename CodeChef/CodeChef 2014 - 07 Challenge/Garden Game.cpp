#include<bits/stdc++.h>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define MP make_pair
#define pb push_back
#define sf scanf
#define pf printf
#define SZ(a) int(a.size())
#define mem(a, v) memset(a, v, sizeof(a))
#define all(v) v.begin(), v.end()
#define paii pair<int,int>
#define ll long long
#define dump(x) cerr<<#x<<" = "<<x<<endl


///header ends

#define MAXX 100007
#define MOD (1000000007LL)


int N;
int A[MAXX];

set<int>numbers;





int idx[MAXX];
int lowlink[MAXX];
bool inStack[MAXX];
stack<int>S;
int Time;

void tarjan(int u)
{
    idx[u] = lowlink[u] = ++Time;

    S.push(u);
    inStack[u] = true;


    int v = A[u];

    if(idx[v] == -1)
    {
        tarjan(v);
        lowlink[u] = min(lowlink[u], lowlink[v]);
    }
    else if(inStack[v])
    {
        lowlink[u] = min(lowlink[u], idx[v]);
    }


    if(lowlink[u] == idx[u])
    {
        int sccLen = 0;
        while(true)
        {
            v = S.top(); S.pop();
            inStack[v] = false;
            sccLen++;
            if(u == v) break;
        }
        numbers.insert(sccLen);
    }


}








vector<int>primes;

void generatePrimes()
{
    primes.pb(2);

    bool isPrime[MAXX];
    mem(isPrime, 1);

    int root = sqrt(MAXX) + 7;

    for(int i=3; i<root; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<MAXX; j+=2*i)
            {
                isPrime[j] = 0;
            }
        }
    }

    for(int i=3; i<100001; i+=2)
        if(isPrime[i])
            primes.pb(i);
}



ll bigMod(ll base, ll p)
{
    if(p == 0) return 1;

    ll tmp = bigMod(base, p/2);

    tmp = (tmp*tmp)%MOD;

    if(p & 1)
    {
        tmp = (tmp*base)%MOD;
    }

    return tmp;
}




int p[MAXX];

int main()
{

    generatePrimes();


    int kases;
    cin>>kases;

    while(kases--)
    {
        cin>>N;
        for(int i=1; i<=N; i++)
        {
            cin>>A[i];
        }

        numbers.clear();
        mem(idx, -1);

        for(int i=1; i<=N; i++)
            if(idx[i] == -1)
                tarjan(i);


        mem(p, 0);

        for(set<int>::iterator it=numbers.begin(); it != numbers.end(); it++)
        {
            int num = *it;


            for(int i=0; i<SZ(primes) && primes[i] <= sqrt(num); i++)
            {
                int c = 0;

                while(num % primes[i] == 0)
                {
                    c++;
                    num /= primes[i];
                }

                p[ primes[i] ] = max(p[ primes[i] ], c);
            }

            if(num != 1)
            {
                p[num] = max(p[num], 1);
            }

        }



        ll result = 1;


        for(int i=2; i<=N; i++)
        {
            result = (result * bigMod(i, p[i]) ) % MOD;
        }

        cout<<result<<endl;


    }
}
