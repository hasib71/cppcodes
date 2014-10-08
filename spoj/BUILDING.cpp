#include<bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define MP make_pair
#define pb push_back
#define pf printf
#define sf scanf
#define ll long long
#define dd double
#define SZ(a) int(a.size())
#define mem(a, v) memset(a, v, sizeof(a))
#define paii pair<int, int>
#define dump(x) cerr<<#x<<" = "<<x<<endl

using namespace std;

///header ends here


#define MAXX 100007


int L[MAXX];
int R[MAXX];
int h[MAXX];

ll dpLeft[MAXX];
ll dpRight[MAXX];

int n;

int main()
{
    sf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        sf("%d", &h[i]);
    }


    stack<paii>stk;

    stk.push(MP(0,-1));

    for(int i=1; i<=n; i++)
    {
        while(stk.top().sc >= h[i])
        {
            stk.pop();
        }
        L[i] = stk.top().fr;
        stk.push(MP(i, h[i]));
    }


    while(!stk.empty()) stk.pop();



    stk.push(MP(n+1, -1));

    for(int i=n; i>0; i--)
    {
        while(stk.top().sc >= h[i])
        {
            stk.pop();
        }
        R[i] = stk.top().fr;
        stk.push(MP(i, h[i]));
    }


    //dump(L[2]);

    dpLeft[0] = 0;

    ll totalAds = 0;

    for(int i=1; i<=n; i++)
    {
        dpLeft[i] = h[i]*(i - L[i]);
        dpLeft[i] += dpLeft[L[i]];
        totalAds += dpLeft[i];
    }

    dpRight[n+1] = 0;
    for(int i=n; i>0; i--)
    {
        dpRight[i] = h[i]*(R[i] - i);
        dpRight[i] += dpRight[R[i]];
    }



    //dump(totalAds);


    ///converting dp to comulative dp
    for(int i=1; i<=n; i++)
    {
        //pf("dpLeft[%d] = %lld, dpRight[%d] = %lld\n", i, dpLeft[i], i, dpRight[i]);
        dpLeft[i] += dpLeft[i-1];
    }
    for(int i=n; i>0; i--)
    {
        dpRight[i] += dpRight[i+1];
    }



    for(int i=1; i<=n; i++)
    {
        cout<<totalAds - dpLeft[i-1] - dpRight[i+1]<<" ";
    }











}
