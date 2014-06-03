#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>



#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>


#define loop(i, n) for(int i=0; i<n; i++)
#define loopfrom1(i, n) for(int i=1; i<n; i++)
#define mem(array, value) memset(array, value, sizeof(array))
#define MIN(a, b) (a<b?a:b)
#define MAX(a, b) (a>b?a:b)
#define pb(a) push_back(a)
#define SZ size()
#define getint(n) scanf("%d", &n)
#define pi acos(-1.0)
#define inf 536870912         // 1<<29
#define debug cout<<"ok"<<endl
#define ll long long int
#define mod(a) (a>0?a:-a)
#define Read(filename) freopen(filename, "r", stdin)


using namespace std;


vector<int> v;


bool comp(int a, int b)
{
    return a > b;
}


int main()
{


    int n, k, inp;
    getint(n); getint(k);

    loop(i, n)
    {
        getint(inp);
        v.pb(inp);
    }

    if(k > v.SZ)
    {
        printf("-1\n");
        return 0;
    }


    sort(v.begin(), v.end(), comp);

    printf("%d %d\n", v[k-1], v[k-1]);



    return 0;
}
