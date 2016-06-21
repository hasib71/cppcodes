/*
user: php
time: 0.032 sec
link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=941
*/
 
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
 
 
#define MAXX 101
#define loop(i, n) for(int i=0; i<n; i++)
#define SZ size()
#define getint(a) scanf("%d", &a)
#define pb push_back
#define inf 1000000
#define MIN(a, b) (a<b?a:b)
 
int dp[MAXX];
int finishline[MAXX];
 
 
 
vector<int> Graph[MAXX];
 
 
int recLongestPath(int u)
{
    if(dp[u] != -1) return dp[u];
 
    if(Graph[u].SZ == 0 )
    {
        finishline[u] = u;
        return dp[u] = 0;
    }
 
    int size = Graph[u].SZ;
    int max = -1;
    loop(i, size)
    {
        if(max == recLongestPath(Graph[u][i])+1)
        {
            finishline[u] = MIN(finishline[u], finishline[Graph[u][i]]);
        }
        else if(max < recLongestPath(Graph[u][i]) + 1)
        {
            max = recLongestPath(Graph[u][i]) + 1;
            finishline[u] = finishline[Graph[u][i]];
        }
    }
    return dp[u] = max;
 
}
 
 
 
int main()
{
    #ifdef hasibpc
        freopen("input.txt", "r", stdin);
        //write("output.txt");
    #endif // hasibpc





    int n, startPoint, p, q, kaseno = 0;
 
    while(true)
    {
        getint(n);
        if(n==0) break;
 
        loop(i, MAXX)
        {
            dp[i] = -1;
            finishline[i] = inf;
        }
 
 
        getint(startPoint);
        while(true)
        {
            getint(p);
            getint(q);
            if(p==0 && q==0) break;
 
            Graph[p].pb(q);
        }
 
        recLongestPath(startPoint);
 
 
 
 
 
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++kaseno, startPoint, dp[startPoint], finishline[startPoint]);
 
        loop(i, n)
        {
            Graph[i].clear();
        }
 
 
    }
 
 
 
 
 
 
 
    return 0;
}
