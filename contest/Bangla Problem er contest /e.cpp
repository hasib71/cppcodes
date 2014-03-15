#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args
#define debug(args...) asdfg,args; cout<<endl


//Header ends here

int main()
{
    #ifndef hasibpc
        read("input.txt");
        write("output.txt");
    #endif

    int n, k;
    paii power[104];
    scanf("%d %d", &n, &k);
    loop(i, n)
    {
        scanf("%d", &power[i].fr);
        power[i].sc = i+1;
    }
    sort(power, power+n);
    pf("%d\n", power[n-k].fr);
    pf("%d", power[n-k].sc);
    for(int i=n-k+1; i<n; i++)
    {
        pf(" %d", power[i].sc);
    }
    pf("\n");

}



