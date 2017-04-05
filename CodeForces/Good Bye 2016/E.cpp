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
//#define dump(args...) cerr,args; cerr<<endl
#define dump(args...) cerr<<"("<<#args<<") = (* ",args,"*)\n";
#define pbp(a,b) pb(MP(a,b))

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


struct DATA{
        int first2, first0, first1, cnt6, cnt7;

        DATA operator+(const DATA &other) const
        {
                DATA ret;
                ret.first0 = MIN(first0, other.first0);
                ret.first1 = MIN(first1, other.first1);
                ret.first2 = MIN(first2, other.first2);

                ret.cnt6 = cnt6 + other.cnt6;
                ret.cnt7 = cnt7 + other.cnt7;

                return ret;
        }
};

#define MAXX 200007
#define INF (1<<29)

int N, Q;
char str[MAXX];

DATA sum[4*MAXX];

void init(int idx, int st, int ed)
{
    if( st == ed)
    {
        int ch = str[st] - '0';

        sum[idx].first0 = sum[idx].first1 = sum[idx].first2 = INF;
        sum[idx].cnt6 = sum[idx].cnt7 = 0;

             if( ch == 0) sum[idx].first0 = st;
        else if( ch == 1) sum[idx].first1 = st;
        else if( ch == 2) sum[idx].first2 = st;
        else if( ch == 6) sum[idx].cnt6++;
        else if( ch == 7) sum[idx].cnt7++;




        return;
    }

    int l = idx*2;
    int r = l + 1;
    int mid = ( st + ed )/2;

    init(l, st, mid);
    init(r, mid+1, ed);

    sum[idx] = sum[l] + sum[r];
}


DATA query(int idx, int st, int ed, int i, int j)
{
    if(st == i && ed == j)
    {
        return sum[idx];
    }


    int l = idx*2;
    int r = l + 1;
    int mid = ( st + ed )/2;

    if( j <= mid)
    {
        return query(l, st, mid, i, j);
    }
    else if( mid < i)
    {
        return query(r, mid+1, ed, i, j);
    }
    else
    {
        return query(l, st, mid, i, mid) + query(r, mid+1, ed, mid+1, j);
    }
}


int main ()
{
    #ifdef hasibpc
        read("input.txt");
        //write("output.txt");
    #endif // hasibpc

    sf("%d %d", &N, &Q);

    sf("%s", str);

    init(1, 0, N-1);

    int p, q;

    int first2, first0, first1, cnt6, cnt7;

    bool possible;
    int cnt;

    while(Q--)
    {
        sf("%d %d", &p, &q);

        possible = true;


        p--;
        q--;

        first2 = query(1, 0, N-1, p, q).first2;

        if(first2 > q)
        {
            possible = false;
            goto hell;
        }

        p = first2;

        first0 = query(1, 0, N-1, p, q).first0;

        if(first0 > q)
        {
            possible = false;
            goto hell;
        }

        p = first0;

        first1 = query(1, 0, N-1, p, q).first1;

        if(first1 > q)
        {
            possible = false;
            goto hell;
        }

        p = first1;

        cnt7 = query(1, 0, N-1, p, q).cnt7;

        if(cnt7 == 0)
        {
            possible = false;
            goto hell;
        }

        cnt6 = query(1, 0, N-1, p, q).cnt6;


        hell:

            if(possible)
            {
                pf("%d\n", cnt6);
            }
            else
            {
                pf("-1\n");
            }



    }


    return 0;
}
