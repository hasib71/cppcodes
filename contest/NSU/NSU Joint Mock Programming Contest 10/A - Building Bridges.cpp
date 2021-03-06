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

#define MAXX 107

#define in(a, b) ( 0 <= (a) && (a) < (b) )

int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[] = {-1,  0,  1,-1, 1,-1, 0,-1};


int N, M;
char grid[MAXX][MAXX];


int parent[MAXX*MAXX];


int find(int u)
{
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
}


void solve()
{
        int t = 0;
        int till = N*M;

        loop(i, till)
        {
                parent[i] = i;
        }
        
        int p, q;

        int a, b;

        loop(i, N)
        {
                loop(j, M)
                {
                        if(grid[i][j] == '#')
                        {
                                loop(k, 8)
                                {
                                        p = i + dirx[k];
                                        q = j + diry[k];

                                        if(in(p, N) && in(q, M) && grid[p][q] == '#')
                                        {
                                                a = (i*M) + j;
                                                b = (p*M) + q;

                                                parent[ find(a) ] = find(b);

                                        }
                                }

                        }
                }
        }


        vector<pair<int, paii> > edges;



        loop(i, N)
        {
                loop(j, M)
                {
                        if(grid[i][j] == '.') continue;

                        for(int k=j+1; k<M; k++)
                        {
                                for(int p=i-1; p<=i+1; p++)
                                {
                                    if( ! in(p, N) ) continue;

                                    if( grid[p][k] == '#')
                                    {
                                            a = (i*M) + j;

                                            b = (p*M) + k;

                                            a = find(a);
                                            b = find(b);

                                            if(a != b)
                                            {
                                                   edges.pb( MP(k - j - 1,  MP(a, b) ) );
                                            }


                                            break;
                                    }

                                }
                        }
                }
        }




        loop(j, M)
        {
                loop(i, N)
                {
                        if(grid[i][j] == '.') continue;

                        for(int k=i+1; k<N; k++)
                        {
                                for(int p=j-1; p<=j+1; p++)
                                {
                                    if(! in(p, M) ) continue;

                                
                                    if(grid[k][p] == '#')
                                    {
                                            a = (i*M) + j;

                                            b = (k*M) + p;

                                            a = find(a);
                                            b = find(b);

                                            if(a != b)
                                            {
                                                    edges.pb( MP(k - i - 1, MP(a, b))  );
                                            }
                                    }
                                }
                        }
                }
        }


        sort(all(edges));

        pair<int, paii> e;

        ll totalCost = 0;
        int cntBridge = 0;


        loop(i, SZ(edges))
        {
                e = edges[i];

                a = e.sc.fr;
                b = e.sc.sc;

                a = find(a);
                b = find(b);

                if(a != b)
                {
                        totalCost += e.fr;
                        cntBridge++;

                        parent[a] = b;
                }
        }


        set<int>s;


        loop(i, N)
        {
                loop(j, M)
                {
                        if(grid[i][j] == '#')
                        {
                                s.insert( find(i*M + j));
                        }
                }
        }


        if(SZ(s) < 2 && cntBridge == 0)
        {
                pf("No bridges are needed.\n");
        }
        else
        {
                if(cntBridge == 0)
                {
                        pf("No bridges are possible.\n");
                        pf("%d disconnected groups\n", SZ(s));
                }
                else
                {
                        cout<<cntBridge<<" bridge"<<(cntBridge>1 ? "s":"")<<" of total length "<<totalCost<<endl;
                        if(SZ(s) > 1)
                        {
                            pf("%d disconnected groups\n", SZ(s));
                        }
                }
        }





        

}




int main ()
{
    #ifdef hasibpc
        //read("input.txt");
        //write("output.txt");
    #endif // hasibpc

    int kaseno = 0;


    while(sf("%d %d", &N, &M) == 2)
    {
            if(N==0 && M==0) break;

            loop(i, N)
            {
                    sf("%s", grid[i]);
            }
            
            if(kaseno) pf("\n");
            pf("City %d\n", ++kaseno);

            solve();


    }


    return 0;
}
