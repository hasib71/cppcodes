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
#define all(v) v.begin(), v.end()
#define ll long long
#define paii pair<int, int>


///

int main()
{
    int kases;
    cin>>kases;
    while(kases--)
    {
        vector<int>v;
        int n;
        cin>>n;
        v.resize(n);
        loop(i, n) cin>>v[i];
        sort(all(v));
        cout<<v[0]+v[1]<<endl;
    }
    return 0;
}
