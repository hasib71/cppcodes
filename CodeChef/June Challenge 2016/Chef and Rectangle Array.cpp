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


#define MAXX 1002

int ara[MAXX][MAXX];

paii sum[4*MAXX][4*MAXX];
int N, M;


void update(int idx1, int idx2, int a, int b, int c, int d)
{
        /*
        cerr<<"----------"<<endl;
        cerr<<"( "<<idx1<<", "<<idx2<<")"<<endl;
        vdump(MP( MP(a, b), MP(c,d) ));

        cerr<<"----------"<<endl;
        */
        
        if(a == b)
        {
                /// reached to a single row

                if(c == d)
                {
                        /// reached to a single column

                        sum[idx1][idx2].fr = sum[idx1][idx2].sc = ara[a][c];
                }
                else
                {
                        int mid = (c+d)/2;
                        int l = 2 * idx2;
                        int r = l + 1;

                        update(idx1, l, a, b, c, mid);
                        update(idx1, r, a, b, mid+1, d);

                        sum[idx1][idx2].fr = max(sum[idx1][l].fr, sum[idx1][r].fr);

                        sum[idx1][idx2].sc = sum[idx1][l].sc + sum[idx1][r].sc;
                }
        }
        else
        {
                int mid = (a+b)/2;
                int l = 2 * idx1;
                int r = l + 1;

                update(l, idx2, a, mid, c, d);
                update(r, idx2, mid+1, b, c, d);

                sum[idx1][idx2].fr = max(sum[l][idx2].fr, sum[r][idx2].fr);

                sum[idx1][idx2].sc = sum[l][idx2].sc + sum[r][idx2].sc;
        }

        if(c != d)
        {
                        int mid = (c+d)/2;
                        int l = 2 * idx2;
                        int r = l + 1;

                        update(idx1, l, a, b, c, mid);
                        update(idx1, r, a, b, mid+1, d);
        }



}

paii query(int idx1, int idx2, int a, int b, int c, int d, int aa, int bb, int cc, int dd)
{
        /*
        cerr<<"----------";
        cerr<<"( "<<idx1<<", "<<idx2<<")"<<endl;
        vdump(MP( MP(a, b), MP(c,d) ));
        vdump( MP(MP(aa, bb), MP(cc, dd) ));
        cerr<<"----------";
        
        step++;

        if(step >= 30)
        {
                //return MP(0, 0);
        }
        */

        if(a == aa && b == bb)
        {
                //return MP(sum[idx1][idx2][0], sum[idx1][idx2][1]);

                if(c == cc && d == dd)
                {
                    return sum[idx1][idx2];
                }
                else
                {
                        int mid = (c + d)/2;
                        int l = 2*idx2;
                        int r = l + 1;

                        if(mid < cc)
                        {
                                return query(idx1, r, a, b, mid+1, d, aa, bb, cc, dd);
                        }
                        else if(dd <= mid)
                        {
                                return query(idx1, l, a, b, c, mid, aa, bb, cc, dd);
                        }
                        else
                        {
                                paii ret1 = query(idx1, l, a, b, c, mid, aa, bb, cc, mid);
                                paii ret2 = query(idx1, r, a, b, mid+1, d, aa, bb, mid+1, dd);

                                return MP(MAX(ret1.fr, ret2.fr), ret1.sc + ret2.sc);
                        }
                }
        }
        else
        {
                int mid = (a+b)/2;
                int l = 2*idx1;
                int r = l + 1;

                if(mid < aa)
                {
                        return query(r, idx2, mid+1, b, c, d, aa, bb, cc, dd);
                }
                else if(bb <= mid)
                {
                        return query(l, idx2, a, mid, c, d, aa, bb, cc, dd);
                }
                else
                {
                        paii ret1 = query(l, idx2, a, mid, c, d, aa, mid, cc, dd);
                        paii ret2 = query(r, idx2, mid+1, b, c, d, mid+1, bb, cc, dd);

                        return MP(MAX(ret1.fr, ret2.fr), ret1.sc + ret2.sc);
                        
                }
        }
}



void answer(int a, int b)
{
        int mn = 1000000009;

        int tmp;

        loop(i, N)
        {
                if(i+a-1 >= N) break;
                loop(j, M)
                {
                        if(j + b - 1 >= M) break;
                        paii ret = query(1, 1, 0, N-1, 0, M-1, i, i+a-1, j, j+b-1);

                        tmp = ret.fr*a*b - ret.sc;

                        mn = min(mn, tmp);


                }
        }

        pf("%d\n", mn);

}


void init()
{
        update(1, 1, 0, N-1, 0, M-1);
}


int main ()
{
    #ifdef hasibpc
        read("input.txt");
        //write("output.txt");
    #endif // hasibpc

    int cntQueries;

    sf("%d %d", &N, &M);

    loop(i, N)
    {
            loop(j, M)
            {
                    sf("%d", &ara[i][j]);
            }
    }


    init();

    sf("%d", &cntQueries);

    int a, b;

    while(cntQueries--)
    {
            sf("%d %d", &a, &b);

            answer(a, b);
    }








    return 0;
}
