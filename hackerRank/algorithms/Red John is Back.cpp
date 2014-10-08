#include<bits/stdc++.h>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define pb push_back
#define MP make_pair
#define sf scanf
#define pf printf
#define dump(x) cerr<<#x<<" = "<<x<<endl;
#define ll long long
#define SZ(a) int(a.size())
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;



#define MAXX 42

int dp[MAXX];


vector<int>primes;

void generate()
{
    int num = 217286 + 7;
    int root = sqrt(num);
    bool isprime[num];
    mem(isprime, 1);
    primes.pb(2);

    for(int i=3; i<root; i+=2)
    {
        if(!isprime[i]) continue;
        for(int j=i*i; j<num; j+=2*i)
        {
            isprime[j] = false;
        }
    }
    for(int i=3; i<num; i+=2)
        if(isprime[i])
            primes.pb(i);

}



int rec(int due)
{
    if(due == 0) return 1;

    if(due < 4) return 1;


    if(dp[due] != -1)
    {
        return dp[due];
    }
    else
    {
        return dp[due] = rec(due - 4) + rec(due - 1);
    }

}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    generate();

    mem(dp, -1);
    int kases;

    cin>>kases;

    int n;

    while(kases--)
    {
        cin>>n;
        n = rec(n);

        //dump(n);

        int low = 0, high = SZ(primes)-1, mid;

        while(low <= high)
        {
            mid = (low+high)/2;
            if(primes[mid] <= n )
                low = mid + 1;
            else
                high = mid - 1;
        }

        cout<<low<<endl;







    }




}
