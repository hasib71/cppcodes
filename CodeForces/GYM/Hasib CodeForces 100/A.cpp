#include<bits/stdc++.h>

using namespace std;


#define FOR(i, s,e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define ll long long
#define pb push_back
#define MP make_pair
#define SZ(a) int(a.size())
#define PI acos(-1.0)
#define pf printf
#define sf scanf
#define mem(a, v) memset(a, v, sizeof(a))

///header ends here

#define MAXX 1000007

vector<int>graph[MAXX];
int n;


int cntStronglyConnected = 0;

int lowlink[MAXX];
int idx[MAXX];
bool inStack[MAXX];
stack<int>stk;
int ttime = 0;


void tarjan(int u)
{
    idx[u] = lowlink[u] = ++ttime;
    inStack[u] = true;
    stk.push(u);
    int v;

    loop(i, SZ(graph[u]))
    {
        v = graph[u][i];

        if(idx[v] == -1)
        {
            tarjan(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }
        else if(inStack[v])
        {
            lowlink[u] = min(lowlink[u], idx[u]);
        }
    }


    if(lowlink[u] == idx[u])
    {
        cntStronglyConnected++;
        cerr<<"found "<<u<<endl;
        while(true)
        {
            v = stk.top(); stk.pop(); inStack[v] = false;
            if(v == u) break;
        }

    }

}




int main()
{
    string str;
    cin>>str;
    n = SZ(str);
    loop(i, n)
    {
        if(str[i] == '0')
        {
            graph[i].pb( (i+1)%n );
        }
        else
        {
            graph[ (i+1)%n  ].pb(i);
        }
    }

    mem(idx, -1);

    loop(i, n)
    {
        if(idx[i] == -1)
        {
            tarjan(i);
        }
    }

    cout<<cntStronglyConnected<<endl;




}
