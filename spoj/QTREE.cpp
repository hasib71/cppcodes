/***********Template Starts Here***********/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <climits>
#include <iomanip>
#include <cassert>
//#include <unordered_map>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define ff first
#define ss second
#define POPCOUNT __builtin_popcountll
#define RIGHTMOST __builtin_ctzll
#define LEFTMOST(x) (63-__builtin_clzll((x)))
#define MP make_pair
#define FOR(i,x,y) for(int i = (x) ; i <= (y) ; ++i)
#define ROF(i,x,y) for(int i = (y) ; i >= (x) ; --i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define UNIQUE(V) (V).erase(unique((V).begin(),(V).end()),(V).end())
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define NUMDIGIT(x,y) (((int)(log10((x))/log10((y))))+1)
#define SQ(x) ((x)*(x))
#define ABS(x) ((x)<0?-(x):(x))
#define FABS(x) ((x)+eps<0?-(x):(x))
#define ALL(x) (x).begin(),(x).end()
#define LCM(x,y) (((x)/gcd((x),(y)))*(y))
#define SZ(x) ((int)(x).size())
#define NORM(x) if(x>=mod)x-=mod;

using namespace std;

typedef long long vlong;
typedef unsigned long long uvlong;
typedef pair < int, int > pii;
typedef pair < vlong, vlong > pll;
typedef vector<pii> vii;
typedef vector<int> vi;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

#ifdef forthright48
     #include <ctime>
     clock_t tStart = clock();
     #define debug(args...) {dbg,args; cerr<<endl;}
     #define timeStamp printf("Execution Time: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC)
#else
    #define debug(args...)  // Just strip off all debug tokens
    #define timeStamp
#endif

struct debugger{
    template<typename T> debugger& operator , (const T& v){
        cerr<<v<<" ";
        return *this;
    }
}dbg;

//int knightDir[8][2] = { {-2,1},{-1,2},{1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,-1} };
//int dir4[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

inline vlong gcd ( vlong a, vlong b ) {
    a = ABS ( a ); b = ABS ( b );
    while ( b ) { a = a % b; swap ( a, b ); } return a;
}

vlong ext_gcd ( vlong A, vlong B, vlong *X, vlong *Y ){
    vlong x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y ) {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    *X = x2; *Y = y2;
    return r2;
}

inline vlong modInv ( vlong a, vlong m ) {
    vlong x, y;
    ext_gcd( a, m, &x, &y );
    if ( x < 0 ) x += m; //modInv is never negative
    return x;
}

inline vlong power ( vlong a, vlong p ) {
    vlong res = 1, x = a;
    while ( p ) {
        if ( p & 1 ) res = ( res * x );
        x = ( x * x ); p >>= 1;
    }
    return res;
}

inline vlong bigmod ( vlong a, vlong p, vlong m ) {
    vlong res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}

/***********Template Ends Here***********/

/*********** Hasib Templates Starts Here**********/

#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<(n); i++)
#define sf scanf
#define pf printf
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) (v).begin(), (v).end()
#define PI acos(-1.0)
#define mem(ara, val) memset(ara, val, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define vdump(x) cerr<<#x<<" = "<<x<<endl;
#define dump(args...) cerr,args; cerr<<endl

template<typename T>
ostream& operator<<(ostream& out, vector<T> v)
{
    out<<"[ ";

    loop(i, SZ(v))
    {
        if(i) out<<", ";
        out<<v[i];
    }

    out<<" ]";
    return out;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> p)
{
    out<<"( "<<p.fr<<", "<<p.sc<<")";
    return out;
}

template<typename T>
ostream& operator,(ostream &out, T x)
{
    out<<x<<" ";
    return out;
}


/**********Hasib Templates Ends Here**************/

/**
 *  WARTNING for me:
 *     Never use    FOR
 *     Never use    pii, pll, vi, vi
 *     Never use    ff, ss, phl, sp, nl
 */

#define MAXX 10007



vector<paii>graph[MAXX];
vector<paii>edges;
int N;



int chainId, chainHead[MAXX], whichChain[MAXX];
int subsize[MAXX];
int parent[MAXX];
int depth[MAXX];
bool visited[MAXX];
int sum[4*MAXX];

int baseArray[MAXX], posInBaseArray[MAXX], ptr;

void hld(int cur, int cost, int prev)
{
        if(chainHead[chainId] == -1)
        {
                chainHead[chainId] = cur;
        }

        whichChain[cur] = chainId;
        //chainPos[cur] = chainSize[chainId];
        //chainSize[chainId]++;


        posInBaseArray[cur] = ptr;
        baseArray[ptr] = cost;
        ptr++;

        int idx = -1, mxSize = -1;
        int v;

        loop(i, SZ(graph[cur]))
        {
                v = graph[cur][i].fr;

                if(v == prev) continue;

                if(subsize[v] > mxSize)
                {
                        mxSize = subsize[v];
                        idx = i;
                }
        }

        if(mxSize > -1)
        {
                hld(graph[cur][idx].fr, graph[cur][idx].sc, cur);
        }

        loop(i, SZ(graph[cur]))
        {
                if(i != idx && graph[cur][i].fr != prev)
                {
                        chainId++;
                        hld(graph[cur][i].fr, graph[cur][i].sc, cur);
                }
        }
}


void dfs(int u, int _depth)
{
        visited[u] = true;

        depth[u] = _depth;

        subsize[u] = 1;

        loop(i, SZ(graph[u]))
        {
                int v = graph[u][i].fr;

                if(!visited[v])
                {
                        parent[v] = u;
                        dfs(v, _depth+1);
                        subsize[u] += subsize[v];
                }
        }
}




void buildSegTree(int idx, int st, int ed)
{
        //vdump(st); vdump(ed);
        if(st == (ed) )
        {
                sum[idx] = baseArray[st];
                return;
        }


        int lft = idx*2;
        int rgt = lft + 1;
        int mid = (st + ed)/2;

        buildSegTree(lft, st, mid);
        buildSegTree(rgt, mid+1, ed);

        sum[idx] = max(sum[lft], sum[rgt]);
}


void update(int idx, int st, int ed, int pos, int val)
{
        if( st == (ed) )
        {
                sum[idx] = val;
                return;
        }


        int lft = idx*2;
        int rgt = lft + 1;
        int mid = (st + ed)/2;

        if(pos <= mid)
        {
                update(lft, st, mid, pos, val);
        }
        else
        {
                update(rgt, mid+1, ed, pos, val);
        }

        sum[idx] = max(sum[lft], sum[rgt]);
}


int LCA(int u, int v)
{
        if(whichChain[u] == whichChain[v])
        {
                return depth[u] < depth[v] ? u : v;
        }

        

        if(depth[ chainHead[ whichChain[v]] ] > depth[ chainHead[ whichChain[u] ] ])
        {
                v = chainHead[ whichChain[v] ];

                v = parent[v];
        }
        else
        {
                u = chainHead[ whichChain[u] ];

                u = parent[u];
        }

        return LCA(u, v);

}


int query(int idx, int st, int ed, int a, int b)
{
        if(st == a && ed == b)
        {
                return sum[idx];
        }

        int lft = idx*2;
        int rgt = lft + 1;

        int mid = (st + ed)/2;

        if(b <= mid)
        {
                return query(lft, st, mid, a, b);
        }
        else if(mid < a)
        {
                return query(rgt, mid+1, ed, a, b);
        }
        else
        {
                return max( query(lft, st, mid, a, mid), query(rgt, mid+1, ed, mid+1, b));
        }


}


/// v is ancestor of u
int query_up(int u, int v)
{
        if(u == v) return 0;

        if(whichChain[u] == whichChain[v])
        {
                return query(1, 1, N, posInBaseArray[v]+1, posInBaseArray[u]);

        }

        int ret = query(1, 1, N, posInBaseArray[ chainHead[ whichChain[u] ] ], posInBaseArray[u]);

        return max(ret, query_up(  parent[ chainHead[ whichChain[u] ] ]  , v ));
}



void init()
{
        chainId = 0;
        ptr = 1;
        mem(chainHead, -1);

        mem(subsize, 0);
        mem(parent, 0);
        mem(depth, 0);
        mem(visited, 0);

        dfs(1, 0);

        hld(1, 0, 0);

        buildSegTree(1, 1, N);
}


int main ()
{
    #ifdef hasibpc
        read("input.txt");
        //write("output.txt");
    #endif // hasibpc

    int u, v, cost;

    int kases;
    sf("%d", &kases);

    while(kases--)
    {


        sf("%d", &N);

        for(int i=1; i<=N; i++)
        {
                graph[i].clear();
        }
        edges.clear();

        for(int i=1; i<N; i++)
        {
                sf("%d %d %d", &u, &v, &cost);

                graph[u].pb(MP(v, cost));
                graph[v].pb(MP(u, cost));

                edges.pb(MP(u, v));
        }


        init();

        char str[100];


        while(true)
        {

                sf("%s", str);

                if(str[0] == 'D')
                {
                        break;
                }
                else
                {
                        sf("%d %d", &u, &v);

                        if(str[0] == 'Q')
                        {
                                /// query

                                int lca = LCA(u, v);

                                pf("%d\n", max(query_up(u, lca), query_up(v, lca)));
                        }
                        else
                        {
                                /// update

                                int val = v;
                                u--;

                                v = edges[u].sc;
                                u = edges[u].fr;

                                if(u != parent[v])
                                {
                                        swap(u, v);
                                }

                                update(1, 1, N, posInBaseArray[v], val);
                        }

                }



        }

    }




    return 0;
}
