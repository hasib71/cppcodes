#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, v, a , b;
    cin>>n>>v;
    int foo[4000] = {0}, bar[4000] = {0};
    for(int i=0; i<n; i++)
    {
        cin>>a>>b;
        foo[a]+=b;
    }
    int res = 0;
    for(int i=0; i<=3000; i++)
    {
        int cur = min(v, bar[i]);
        int left = v - cur;
        res += cur;
        cur = min(left, foo[i]);
        res += cur;
        left = left - cur;
        bar[i+1] += foo[i] - cur;
    }
    cout<<res<<endl;
}
