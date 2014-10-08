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


///header ends

int main()
{
    int kases;
    cin>>kases;
    while(kases--)
    {
        string ss;
        cin>>ss>>ss;
        ll cnt = 0;
        loop(i, SZ(ss))
        {
            if(ss[i] == '1') cnt++;
        }


        cnt = (cnt*(cnt+1))/2;
        cout<<cnt<<endl;

    }
}
