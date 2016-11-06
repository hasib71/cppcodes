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


#define putMaximumSizeHere 507
#define modValueHere 2



#ifndef MATRIXEXPO_H
#define MATRIXEXPO_H

namespace matrixexpo{
    /**
     * Declare:       Matrix mat(100, 100);
     * Assign Value:  mat[1][2] = 3;
     * Matrix expo:   mat^1000;
     * Matrix multiplication: mat*mat;
     */
    template<typename T>
    struct Matrix{
        T ara[putMaximumSizeHere][putMaximumSizeHere];
        int row, col;

        Matrix()
        {
            Matrix(100, 100);
        }

        Matrix(int r, int c)
        {
            row = r;
            col = c;
            clr();
        }

        void clr()
        {
            memset(ara, 0, sizeof(ara));
        }

        void init(int r, int c)
        {
                row = r;
                col = c;
                clr();
        }

        void identity()
        {
            clr();
            for(int i=0; i<row; i++) ara[i][i] = 1;
        }

        T* operator[](int i)
        {
            return ara[i];
        }

        Matrix operator*(Matrix &other)
        {
            Matrix ret(row, other.col);

            for(int i=0; i<row; i++)
            {
                for(int j=0; j<other.col; j++)
                {
                    for(int k=0; k<col; k++)
                    {
                        ret.ara[i][j] = ( ara[i][k] & other.ara[k][j]);
                        if(ret.ara[i][j])
                        {
                                break;
                        }
                    }
                }
            }

            return ret;
        }


        Matrix operator^(long long p)
        {
            Matrix ret(row, col); ret.identity();
            Matrix tmp = *this;

            while(p)
            {
                if(p & 1)
                {
                    //ret *= tmp;

                    ret = ret * tmp;
                }
                //tmp *= tmp;

                tmp = tmp * tmp;

                p = p>>1;
            }
            return ret;
        }
    };

    /*** The following is only for debugging ***/
    template<typename T>
    ostream& operator<<(ostream& out, Matrix<T>mat)
    {
        out<<string(2*mat.col + 3, '-')<<endl;
        for(int i=0; i<mat.row; i++)
        {
            out<<"| ";
            for(int j=0; j<mat.col; j++)
            {
                out<<mat[i][j]<<" ";
            }
            out<<"|"<<endl;
        }
        out<<string(2*mat.col + 3, '-')<<endl;
        return out;
    }
}

#endif // MATRIXEXPO_H





using namespace matrixexpo;


#define MAXX 507


int N, M, k, x;
Matrix<int>matrix(MAXX,MAXX), ret(MAXX, MAXX);







int main ()
{
    #ifdef hasibpc
        read("input.txt");
        //write("output.txt");
    #endif // hasibpc


    sf("%d", &N);

    matrix.init(N, N);

    loop(i, N)
    {
            loop(j, N)
            {
                    sf("%d", &matrix.ara[i][j]);
            }
    }

    sf("%d", &M);

    int cnt;

    while(M--)
    {
            sf("%d %d", &k, &x);

            if(k == 0)
            {
                     pf("1\n%d\n", x);
            }
            else
            {
                    ret = matrix^k;

                    cnt = 0;

                    x--;

                    loop(i, N)
                    {
                            if(ret.ara[x][i])
                            {
                                    cnt++;
                            }
                    }


                    pf("%d\n", cnt);

                    if(cnt == 0) pf("-1");

                    bool f = false;

                    loop(i, N)
                    {
                            if(ret.ara[x][i])
                            {
                                    if(f) pf(" ");
                                    f = true;
                                    pf("%d", i+1);
                            }
                    }

                    pf("\n");

            }
    }





    return 0;
}
