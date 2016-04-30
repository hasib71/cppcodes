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




#define MAXX 207
#define MAXK 50007


struct Tile{
    int idxCorners[5];
    int type;
};


Tile tiles[MAXX][MAXX];


int R, C;

char grid[MAXX][MAXX];



int parent[MAXK];
double area[MAXK];


double myarea[] = {PI/4.0, (8.0 - PI)/2.0, PI/4.0, (8.0 - PI)/2.0};

int find(int u)
{
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
}

void connect(int u, int v)
{
        u = find(u);
        v = find(v);

        parent[u] = v;

}

void preprocess()
{
        int k = 0;

        loop(i, R)
        {
                loop(j, C)
                {
                        if(grid[i][j] == '0')
                        {

                                tiles[i][j].type = 0;
                                tiles[i][j].idxCorners[0] = k++;
                                tiles[i][j].idxCorners[2] = k++;
                                tiles[i][j].idxCorners[1] = tiles[i][j].idxCorners[3] = k++;

                        }
                        else
                        {
                                tiles[i][j].type = 1;

                                tiles[i][j].idxCorners[1] = k++;
                                tiles[i][j].idxCorners[3] = k++;
                                tiles[i][j].idxCorners[0] = tiles[i][j].idxCorners[2] = k++;

                        }
                }
        }

        loop(i, k)
        {
                parent[i] = i;
                area[i] = 0.0;
        }


        loop(i, R)
        {
                
                loop(j, C)
                {
                        if((i+1) < R)
                        {
                                connect(tiles[i][j].idxCorners[3], tiles[i+1][j].idxCorners[0]);
                                connect(tiles[i][j].idxCorners[2], tiles[i+1][j].idxCorners[1]);
                        }


                        if( (j+1) < C )
                        {
                                    connect(tiles[i][j].idxCorners[1], tiles[i][j+1].idxCorners[0]);
                                    connect(tiles[i][j].idxCorners[2], tiles[i][j+1].idxCorners[3]);
                        }
                }
        }


        loop(i, R)
        {
                loop(j, C)
                {
                        Tile &T = tiles[i][j];

                        int p = T.type;


                        for(int t = 0; t<3; t++)
                        {
                                area[ find(T.idxCorners[p+t]) ] += myarea[t];
                        }
                }
        }




}


int main ()
{
    #ifdef hasibpc
        read("input.txt");
        //write("output.txt");
    #endif // hasibpc
    
    int kases, kaseno = 0;
    int Q, x, y;

    sf("%d", &kases);

    while(kases--)
    {

        sf("%d %d", &R, &C);

        loop(i, R)
        {
                sf("%s", grid[i]);
        }


        preprocess();

        pf("Case %d:\n", ++kaseno);

        sf("%d", &Q);

        while(Q--)
        {
                sf("%d %d", &x, &y);

                if( (x%2) ^ (y%2) )
                {
                        pf("0.0000\n");
                }
                else
                {
                        if(x&1)
                        {
                                x /= 2;
                                y /= 2;

                                if(tiles[x][y].type == 0)
                                {
                                        x = tiles[x][y].idxCorners[1];
                                }
                                else
                                {
                                        x = tiles[x][y].idxCorners[0];
                                }
                        }
                        else
                        {
                                if(x == 0)
                                {
                                        if(y == 0)
                                        {
                                                x = tiles[0][0].idxCorners[0];
                                        }
                                        else
                                        {
                                                y = (y-1)/2;
                                                x = tiles[x][y].idxCorners[1];
                                        }
                                }
                                else
                                {
                                        if(y == 0)
                                        {
                                                x = (x-1)/2;
                                                x = tiles[x][y].idxCorners[3];
                                        }
                                        else
                                        {
                                                x = (x-1)/2;
                                                y = (y-1)/2;
                                                x = tiles[x][y].idxCorners[2];
                                       }
                                }
                        }

                        x = find(x);

                        pf("%.4lf\n", area[x]);
                }
        }


    }
    return 0;
}
