#include<bits/stdc++.h>

using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr frist
#define sc second
#define MP make_pair
#define pb push_back
#define sf scanf
#define pf printf
#define mem(a, v) memset(a, v, sizeof(a))
#define dump(x) cerr<<#x<<" = "<<x<<endl;
#define all(v) v.begin(), v.end()
#define ll long long


char ara[16][16];

char ch[] = "GCAT";



int main()
{

    int pt = 0;

    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            if(pt >= 4)
            {
                next_permutation(ch, ch+4);
                pt = 0;
            }
            ara[i][j] = ch[pt++];

        }
    }

    int kases;
    int n, m, k;

    sf("%d", &kases);


    while(kases--)
    {
        sf("%d %d %d", &n, &m, &k);

        loop(i, n)
        {
            loop(j, m)
            {
                pf("%c", ara[i][j]);
            }
            pf("\n");
        }
    }




}
