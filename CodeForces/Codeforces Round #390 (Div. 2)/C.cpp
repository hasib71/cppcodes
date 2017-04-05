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

#define MAXX 107


bool grid[MAXX][MAXX];

int N, M;
vector<string>user;
vector<pair<string, string> >msg;

map<string, int>userset;


int who[MAXX];

void mark(int u, string mymsg)
{
        mymsg = mymsg + "!";


        string str;

        loop(i, SZ(mymsg))
        {
                char ch = mymsg[i];

                if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9') )
                {
                        str += ch;
                }
                else
                {
                        if(SZ(str) > 0)
                        {
                                if(userset.find(str) != userset.end() )
                                {
                                        grid[u][ userset[ str ] ] = 0;
                                }
                        }

                        str.clear();
                }
        }
}


int dp[MAXX][MAXX];


int rec(int prev, int pos)
{
        if(pos >= M)
        {
            return 1; // success!!!
        }


        int &ret = dp[prev][pos];

        if(ret != -2)
        {
                return ret;
        }


        if(who[pos] != -1)
        {
                if(who[pos] == prev)
                {
                        return ret = -1; /// impossible
                }
                else
                {
                        if(rec(who[pos], pos+1) == -1)
                        {
                                return ret = -1;
                        }
                        else
                        {
                                return ret = who[pos];
                        }
                }
        }


        loop(i, N)
        {
                if(grid[pos][i] && i != prev)
                {
                        if(rec(i, pos+1) != -1)
                        {
                                return ret = i;
                        }
                }
        }


        return ret = -1;
}




void solve()
{
        string str;

        loop(i, M)
        {
                str = msg[i].sc;

                loop(j, SZ(str))
                {
                        if(str[j] == ':')
                        {
                                msg[i] = MP( str.substr(0, j), str.substr(j+1, SZ(str)) );
                        }
                }
        }

        //vdump(msg);

        int prevUser = -2;

        int u;


        mem(grid, 1);


        mem(who, -1);

        loop(i, M)
        {
                if(msg[i].fr[0] == '?')
                {
                        if(prevUser > -1)
                        {
                                grid[i][prevUser] = 0;
                        }

                        prevUser = -1;

                        mark(i, msg[i].sc);
                }
                else
                {
                        u = userset[ msg[i].fr ];

                        who[i] = u;

                        if(prevUser == -1)
                        {
                                grid[i-1][u] = 0;
                        }

                        prevUser = u;

                }
        }


        loop(i, MAXX)
        {
                loop(j, MAXX)
                {
                        dp[i][j] = -2;
                }
        }


        if(rec(N, 0) == -1)
        {
                pf("Impossible\n");
        }
        else
        {
                prevUser = N;

                loop(i, M)
                {
                        u = dp[prevUser][i];

                        cout<<user[ u ]<<":"<<msg[i].sc<<endl;


                        prevUser = u;
                }
        }
}



int main ()
{
    #ifdef hasibpc
        read("input.txt");
        //write("output.txt");
    #endif // hasibpc

    int kases, kasneo = 0;

    string str;

    sf("%d", &kases);

    while(kases--)
    {
            user.clear();
            userset.clear();
            msg.clear();


            sf("%d", &N);

            loop(i, N)
            {
                    cin>>str;

                    user.pb( str );
                    userset[str] = i;
            }

            sf("%d", &M);


            cin.ignore();

            loop(i, M)
            {
                    getline(cin, str);

                    msg.pb( MP("", str) );
            }

            solve();
    }


    return 0;
}
