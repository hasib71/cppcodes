#include<bits/stdc++.h>

using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define MP make_pair
#define pf printf
#define sf scanf
#define SZ(a) int(a.size())
#define all(v) v.begin(), v.end()
#define ll long long
#define dump(x) cerr<<#x<<" = "<<x<<endl;
#define mem(a, v) memset(a, v, sizeof(a))



#define MAXX 100007

#define lowbit(x) (x & -x)


ll T[MAXX];
int ara[MAXX];

int N, Q;


ll getSum(int i)
{
    ll sum = 0;
    while(i>0)
    {
        sum += T[i];
        i -= lowbit(i);
    }
    return sum;
}

void insert(int i)
{
    while(i <= N)
    {
        T[i]++;
        i += lowbit(i);
    }
}



int calc()
{
    ll result = 0;
    mem(T, 0);

    for(int i=N; i>0; i--)
    {
        result += getSum(ara[i]);
        insert(ara[i]);
    }
    return result;
}



int main()
{
    cin>>N>>Q;
    for(int i=1; i<=N; i++)
    {
        cin>>ara[i];
    }

    int x, y;


    loop(i, Q)
    {
        cin>>x>>y;
        dump(calc());
        swap(ara[x], ara[y]);
        cout<<calc()<<endl;
    }

}
