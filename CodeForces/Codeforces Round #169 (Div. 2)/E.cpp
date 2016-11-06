
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

#define MAXX 100007
#define lowbit(x) ( x & -x)


int N;

int lazyChain[4*MAXX];
int T[MAXX];


void updateT(int pos, int v)
{
    //vdump(pos);
    //vdump(v);
    while(pos < MAXX)
    {
        T[pos] += v;
        //pf("T[%d] = %d\n", pos, T[pos]);
        pos += lowbit(pos);
    }
}

int getT(int pos)
{
    int sum = 0;

    while(pos > 0)
    {
        sum += T[pos];

        pos -= lowbit(pos);
    }

    return sum;
}

int getmyT(int pos)
{
    //vdump(N);
    //vdump(getT(N-1));

    return getT(N-1) - getT(pos-1);
}




void updateLazyChain(int idx, int i, int j, int a, int b, int v)
{
    if(i == a && j == b)
    {
        lazyChain[idx] += v;
    }
    else
    {
        int lft = idx*2;
        int rgt = lft + 1;

        lazyChain[lft] += lazyChain[idx];
        lazyChain[rgt] += lazyChain[idx];

        lazyChain[idx] = 0;

        int mid = (i+j)/2;

        if(b <= mid)
        {
            updateLazyChain(lft, i, mid, a, b, v);
        }
        else if(mid < a)
        {
            updateLazyChain(rgt, mid+1, j, a, b, v);
        }
        else
        {
            updateLazyChain(lft, i, mid, a, mid, v);
            updateLazyChain(rgt, mid+1, j, mid+1, b, v);
        }
    }
}

int getLazyChain(int idx, int st, int ed, int pos)
{
    if(st == ed)
    {
        return lazyChain[idx];
    }

    int mid = (st + ed)/2;
    int lft = idx*2;
    int rgt = lft + 1;


    lazyChain[lft] += lazyChain[idx];
    lazyChain[rgt] += lazyChain[idx];

    lazyChain[idx] = 0;

    if(pos <= mid)
    {
        return getLazyChain(lft, st, mid, pos);
    }
    else
    {
        return getLazyChain(rgt, mid+1, ed, pos);
    }
}





vector<int>graph[MAXX];

int rootValue = 0;

int where[MAXX];
int uporeAche[MAXX], niceAche[MAXX];  /// i'th index == segment tree te i'th position e jeta ache setar upor nice koyta ache.

bool visited[MAXX];

int curPos;

void dfs(int u)
{
    visited[u] = true;
    curPos++;
    where[u] = curPos;

    int v;
    loop(i, SZ(graph[u]))
    {
        v = graph[u][i];
        if( !visited[ v ] )
        {
            dfs(v);
        }
    }

}


void init()
{
    visited[1] = true;

    int u;
    curPos = 0;

    int p, q;

    loop(i, SZ(graph[1]))
    {
        p = curPos + 1;

        u = graph[1][i];
        dfs(u);

        q = curPos;

        for(int i=p, cnt = 0; i<=q; i++)
        {
            uporeAche[i] = cnt;
            cnt++;
        }

        for(int i=q, cnt = 0; i >= p; i--)
        {
            niceAche[i] = cnt;
            cnt++;
        }

    }



}



/*
 * v = vertex
 * x = add x
 * d = distance
*/
void updateQuery(int v, const int x, int d)
{
    if(v == 1)
    {
        rootValue += x;

        updateT(d, x);


        return;
    }

    /// update lower side.


    int st, ed;

    int pos = where[v];
    int down = MIN(niceAche[pos], d);
    ed = pos + down;




    int up = MIN(uporeAche[pos], d);

    int extra = d - up;



    if(extra == 0)
    {
        st = pos - up;

        /// todo
    }
    else if(extra == 1)
    {
        rootValue += x;
        st = pos - uporeAche[pos];
    }
    else
    {
        rootValue += x;

        //vdump(pos);
        //vdump(uporeAche[pos]);
        //vdump(extra);

        extra--;

        st = pos - uporeAche[pos] + extra;




            //cerr<<"updating flow at dist = "<<extra<<", value = "<<x<<endl;
        updateT(extra, x);


    }

    //st = min(st, ed);

    //cerr<<"updating chain from st = "<<st<<", "<<" ed = "<<ed<<", x = "<<x<<endl;

    //vdump(st);
    //vdump(ed);

    if(st <= ed)
    {
        updateLazyChain(1, 1, N-1, st, ed, x);
    }





}


int getNodeValue(int v)
{
    if(v == 1) return rootValue;
    //int tmp = 1 + uporeAche[ where[v] ];
    //vdump(tmp);
    return getLazyChain(1, 1, N-1, where[v]) + getmyT(1 + uporeAche[ where[v] ]);
}


int main ()
{
    #ifdef hasibpc
        read("input.txt");
        //write("output.txt");
    #endif // hasibpc

    int Q;


    int type, u, v, x, d;


    sf("%d %d", &N, &Q);

    for(int i=1; i<N; i++)
    {
        sf("%d %d", &u, &v);
        graph[u].pb(v);
        graph[v].pb(u);
    }


    init();


    while(Q--)
    {
        sf("%d %d", &type, &v);

        if(type == 1)
        {
            //cout<<"answer of input: ";
            pf("%d\n", getNodeValue(v));


        }
        else
        {

            sf("%d %d", &x, &d);

            //cerr<<"Query: update node "<<v<<", dist = "<<d<<", value  = "<<x<<endl;

            updateQuery(v, x, d);
        }
    }


    //vdump(T[1]);

    return 0;
}
