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

pair<ll, int> nodes[MAXX];
int idx[MAXX];



int main()
{
    int N, K, P;
    sf("%d %d %d", &N, &K, &P);

    loop(i, N)
    {
        sf("%lld", &nodes[i].fr);
        nodes[i].sc = i+1;
    }

    sort(nodes, nodes+N);

    int id = 0;
    ll last = nodes[0].fr;

    loop(i, N)
    {
        if( nodes[i].fr - last <= K)
        {
            idx[ nodes[i].sc ] = id;
        }
        else
        {
            idx[ nodes[i].sc ] = ++id;
        }

        last = nodes[i].fr;
    }

    int x, y;


    loop(i, P)
    {
        sf("%d %d", &x, &y);

        if(idx[x] == idx[y])
        {
            pf("Yes\n");
        }
        else
        {
            pf("No\n");
        }
    }











}
