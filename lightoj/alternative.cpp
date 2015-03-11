#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#include <algorithm>
//#define LL __int64
#define LL long long
#define eps 1e-12
#define PI acos(-1.0)
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 4010;

int dig[20];
LL dp[20][20];
int num[20];

LL dfs(int pos, int len, int first, int up)
{
	if(pos == 0)
		return 1;
	if(!up && !first && dp[pos][len] != -1)
		return dp[pos][len];

	int n = up ? dig[pos] : 9;
	LL res = 0;

	for(int i = 0; i <= n; i++)
	{
		if(first)
		{
			num[len] = i;
			if(i == 0)
				res += dfs(pos-1,len-1,1,up&&i==n);
			else res += dfs(pos-1,len,0,up&&i==n);
		}
		else
		{
			int mid = (len+1)>>1;
			if(len&1)
			{
				if(pos >= mid)
				{
					num[pos] = i;
					res += dfs(pos-1,len,first&&i==0,up&&i==n);
				}
				else
				{
					if(num[2*mid-pos] == i)
						res += dfs(pos-1,len,first&&i==0,up&&i==n);
				}
			}
			else
			{
				if(pos >= (mid+1))
				{
					num[pos] = i;
					res += dfs(pos-1,len,first&&i==0,up&&i==n);
				}
				else
				{
					if(num[len+1-pos] == i)
						res += dfs(pos-1,len,first&&i==0,up&&i==n);
				}
			}
		}
	}

	if(!up && !first)
		dp[pos][len] = res;
	return res;
}

LL cal(LL num)
{
	int len = 0;
	while(num)
	{
		dig[++len] = num%10;
		num/=10;
	}
	return dfs(len,len,1,1);
}
int main()
{
	int test;
	LL a,b;
	scanf("%d",&test);
	memset(dp,-1,sizeof(dp));
	for(int item = 1; item <= test; item++)
	{
		scanf("%lld %lld",&a,&b);
		if(a > b)
			swap(a,b);
		printf("Case %d: %lld\n",item,cal(b) - cal(a-1) );
	}
	return 0;
}
