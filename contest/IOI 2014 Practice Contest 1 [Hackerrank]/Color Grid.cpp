#include<bits/stdc++.h>

using namespace std;


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define MP make_pair
#define pb push_back
#define mem(a, v) mem(a, v, sizeof(a))
#define ll long long
#define all(v) v.begin(), v.end()
#define sf scanf
#define pf printf



///header ends here

#define MAXX 6007


pair<ll, int> rows[MAXX], columns[MAXX];
int N, P;

char ch[10];
int I, V;

int main()
{

    sf("%d %d", &N, &P);

    loop(p, P)
    {
        sf("%s %d %d", ch, &I, &V);


        if(ch[0] == 'C')
        {
            rows[I] = MP(V, p);
        }
        else
        {
            columns[I] = MP(V, p);
        }
    }


    ll sum = 0;


    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if( rows[j].sc < columns[i].sc )
            {
                sum += columns[i].fr;
            }
            else
            {
                sum += rows[j].fr;
            }
        }
    }

    cout<<sum<<endl;






}
