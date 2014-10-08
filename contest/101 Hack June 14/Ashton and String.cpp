#include<bits/stdc++.h>

using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define MP make_pair
#define pb push_back
#define SZ(a) int(a.size())
#define mem(a, v) memset(a, v, sizeof(a))
#define ll long long
#define dd double
#define INF (1<<29)
#define sf scanf
#define pf printf
#define paii pair<int, int>
#define dump(x) cerr<<#x<<" = "<<x<<endl



///header ends here


#define MAXX 100007
#define MAXLG 18

string ss;
int len;
ll K;
int step;

int sortedIndex[MAXLG][MAXX];
int order[MAXX];



void buildSA()
{
    pair<paii, int>L[MAXX];

    for(int i=0; i<len; i++)
    {
        sortedIndex[0][i] = ss[i];
    }


    step = 1;
    int doneTill = 1;


    while(doneTill < len)
    {
        loop(i, len)
        {
            L[i].fr.fr = sortedIndex[step-1][i];
            L[i].fr.sc = i + doneTill < len ? sortedIndex[step-1][i+doneTill] : -1;
            L[i].sc = i;
        }


        sort(L, L + len);

        loop(i, len)
        {
            if(i == 0)
            {
                sortedIndex[step][ L[i].sc ] = 0;
            }
            else
            {
                if( L[i].fr == L[i-1].fr )
                {
                    sortedIndex[step][ L[i].sc ] = sortedIndex[step][ L[i-1].sc ];
                }
                else
                {
                    sortedIndex[step][ L[i].sc ] = i;
                }
            }
        }

        step++;
        doneTill *= 2;

    }
}




int findLCP(int x, int y)
{
    if(y == -1) return 0;
    if(x == y) return len - x;

    int result = 0;

    for(int i=step-1; i>=0; i--)
    {
        if(sortedIndex[i][x] == sortedIndex[i][y])
        {
            x += (1<<i);
            y += (1<<i);
            result += (1<<i);
        }
    }

    return result;
}







char solve()
{
    len = SZ(ss);

    if(len == 1)
    {
        return ss[0];
    }
    else
    {
        buildSA();
        loop(i, len)
        {
            order[ sortedIndex[step-1][i] ] = i;
        }


        int repeat;

        loop(i, len)
        {
            if(i == 0) repeat = 0;
            else repeat = findLCP( order[i], order[i-1] );

            if(repeat >= K)
            {
                return ss[ order[i] + K - 1   ];
            }
            else
            {
                ll x = repeat + 1;
                ll low = x;
                ll high = len - order[i];

                if(high < low) continue;


                while(low <= high)
                {
                    ll mid = (low+high)/2;

                    ll sum =  ((x+mid)*(mid-x+1))/2;

                    if(sum < K)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }


                K = K - ( ((x+high)*(high-x+1))/2 );

                if(low > len - order[i])
                {
                    continue;
                }
                else
                {
                    return ss[  order[i] + K - 1  ];
                }
            }
        }
    }
    return 'f'; //fuck
}


int main()
{
    int kases;
    cin>>kases;
    while(kases--)
    {
        cin>>ss>>K;
        cout<<solve()<<endl;

    }
}
