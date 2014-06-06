/*
prob: CF-355-B
id: amlansaha
lang: C++
date: 13/10/2013
algo:
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long LLU;
typedef vector<int> VI;
typedef vector<long long> VLL;
typedef map<int, int> MAPII;
typedef map<string,int> MAPSI;

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define ROF(i,a,b) for(i=a;i>=b;i--)
#define FR(i,n)	for(i=0;i<n;i++)
#define RF(i,n) for(i=n;i>0;i--)
#define CLR(a) memset ( a, 0, sizeof ( a ) )
#define RESET(a) memset ( a, -1, sizeof ( a ) )
#define MALLOC(type,size) (type *) malloc ( sizeof ( type ) * size )
#define PB(a)	push_back ( a )
#define dump(x) cout<<#x<<" = "<<x<<endl

int main ()
{
    int i, j, k, l, temp, b, t, n, m, ans, caseno = 0;
    int c1, c2, c3, c4;
    string str;

    while ( cin >> c1 >> c2 >> c3 >> c4 )	{
    	cin >> n >> m;
    	b = 0, t = 0, ans = 0;
    	while ( n-- )	{
    		cin >> i;
    		temp = i*c1;
    		b+= min ( temp, c2 );
    	}
    	b = min ( b, c3 );
    	while ( m-- )	{
    		cin >> i;
    		temp = i*c2;
    		t+= min ( temp, c2 );
    	}
    	t = min ( t, c3 );

    	dump(b);
    	dump(t);


    	ans = b+t;
    	ans = min ( ans, c4 );
    	cout << ans << endl;
    }
    return 0;
}
