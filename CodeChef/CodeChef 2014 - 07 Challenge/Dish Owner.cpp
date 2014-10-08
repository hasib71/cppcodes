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


#define MAXX 10007

int parent[MAXX], maxScore[MAXX];
int N;

int find(int u)
{
    if(u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}


int main()
{
    int kases;
    int Q;

    int x, y, q;

    sf("%d", &kases);
    while(kases--)
    {
        sf("%d", &N);
        for(int i=1; i<=N; i++)
        {
            sf("%d", &maxScore[i]);
            parent[i] = i;
        }

        sf("%d", &Q);
        while(Q--)
        {
            sf("%d", &q);
            if(q == 0)
            {
                sf("%d %d", &x, &y);

                x = find(x);
                y = find(y);

                if(x == y)
                {
                    pf("Invalid query!\n");
                }
                else
                {
                    if(maxScore[x] < maxScore[y])
                    {
                        parent[x] = y;
                    }
                    else if(maxScore[x] > maxScore[y])
                    {
                        parent[y] = x;
                    }
                }
            }
            else
            {
                sf("%d", &x);
                pf("%d\n", find(x));
            }
        }

    }
}
