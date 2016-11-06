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
//#define read(nm) freopen(nm, "r", stdin)
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



// Big Integer

const int base = 1000000000;
const int base_digits = 9;

struct bigint{
        vector<int>a;
        int sign;

        bigint() : sign(1){

        }

        bigint(ll v) {
                *this = v;
        }

        bigint(const string &s)
        {
                //read(s);
        }

        void operator=(const bigint &v)
        {
                sign = v.sign;
                a = v.a;
        }

        void operator=(ll v)
        {
                sign = 1;
                if(v < 0)
                        sign = -1, v = -v;
                for(;v>0; v = v/base)
                {
                        a.pb(v % base);
                }
        }


        bigint operator+(const bigint &v) const
        {
                if(sign == v.sign)
                {
                        bigint res = v;

                        for(int i =0, carry=0; i<(int) max(a.size(), v.a.size()) || carry; ++i )
                        {
                                if(i == (int) res.a.size()) res.a.pb(0);

                                res.a[i] += carry + (i<SZ(a) ? a[i] : 0);
                                carry = res.a[i]  >= base;
                                if(carry) res.a[i] -= base;
                        }
                        return res;
                }
                return *this - (-v);
        }

        bigint operator-(const bigint &v) const
        {
                if(sign == v.sign)
                {
                        if(abs() >= v.abs())
                        {
                                bigint res = *this;
                                for(int i=0, carry = 0; i<SZ(v.a) || carry; ++i)
                                {
                                        res.a[i] -= carry + (i < SZ(v.a) ? v.a[i] : 0);
                                        carry = res.a[i] < 0;
                                        if(carry) res.a[i] += base;
                                }
                                res.trim();
                                return res;
                        }

                        return -(v - *this);
                }
                return *this + (-v);
        }

        bigint operator-() const{
            bigint res = *this;
            res.sign = -sign;
            return res;
        }


        friend bigint gcd(const bigint &a, const bigint &b)
        {
                //debug(a, b);
                return b.isZero() ? a : gcd(b, a % b);
        }

        friend bigint lcm(const bigint &a, const bigint &b)
        {
                return (a / gcd(a, b)) * b;
        }

        bool isZero() const
        {
                return a.empty() || (SZ(a) == 1 && !a[0]);
        }

        typedef vector<ll> vll;

        bigint operator*(const bigint &v) const
        {
            //cerr<<"Multiplication"<<endl;
                vector<int> a6 =  convert_base(this->a, base_digits, 6);
                //cerr<<"Done 1"<<endl;
                vector<int> b6 = convert_base(v.a, base_digits, 6);

                vll a(all(a6));
                vll b(all(b6));

                while(SZ(a) < SZ(b)) a.pb(0);

                while(SZ(b) < SZ(a)) b.pb(0);

                while(SZ(a) & (SZ(a) - 1))
                {
                        a.pb(0); b.pb(0);
                }



                vll c = karatsubaMultiply(a, b);
                bigint res;
                res.sign = sign * v.sign;

                for(int i=0, carry = 0; i < SZ(c); i++)
                {
                        ll cur = c[i] + carry;
                        res.a.pb((int)(cur%1000000));
                        carry = (int) (cur/1000000);
                }
                res.a = convert_base(res.a, 6, base_digits);
                res.trim();
                return res;
        }

        static vll karatsubaMultiply(const vll &a, const vll &b)
        {
                int n = SZ(a);
                vll res(n+n);

                if(n <= 32)
                {
                        loop(i, n)
                        {
                                loop(j, n)
                                {
                                        res[i + j] += a[i] * b[j];
                                }
                        }
                        return res;
                }

                int k = n>>1;
                vll a1(a.begin(), a.begin() + k);
                vll a2(a.begin() + k, a.end());

                vll b1(b.begin(), b.begin() + k);
                vll b2(b.begin() + k, b.end());

                vll a1b1 = karatsubaMultiply(a1, b1);
                vll a2b2 = karatsubaMultiply(a2, b2);

                loop(i, k)
                {
                        a2[i] += a1[i];
                }

                loop(i, k)
                {
                        b2[i] += b1[i];
                }

                vll r = karatsubaMultiply(a2, b2);

                loop(i, SZ(a1b1)) r[i] -= a1b1[i];
                loop(i, SZ(a2b2)) r[i] -= a2b2[i];

                loop(i, SZ(r)) res[i+k] += r[i];
                loop(i, SZ(a1b1)) res[i] += a1b1[i];
                loop(i, SZ(a2b2)) res[i+n] += a2b2[i];
                return res;
        }


        void trim()
        {
                while(!a.empty() && !a.back()) a.pop_back();
                if(a.empty()) sign = 1;
        }

        static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits)
        {
            //cerr<<"Converting Base"<<endl;

                vector<ll> p (max(old_digits, new_digits) + 1);
                p[0] = 1;
                for(int i=1; i<SZ(p); i++)
                {
                        p[i] = p[i-1] * 10;
                }

                vector<int>res;

                ll cur = 0;
                int cur_digits = 0;
                //vdump(SZ(a));
                for(int i=0; i<SZ(a); i++)
                {
                    //vdump(i);
                        cur += a[i] * p[cur_digits];
                        cur_digits += old_digits;

                        while(cur_digits >= new_digits)
                        {
                            //cerr<<"loop"<<endl;
                                res.pb(int(cur%p[new_digits]));
                                cur /= p[new_digits];
                                cur_digits -= new_digits;
                        }
                }

                //cerr<<"almost done"<<endl;

                res.pb((int) cur);

                while(!res.empty() && !res.back()) res.pop_back();
                return res;
        }

        bigint operator%(const bigint &v) const
        {
                return divmod(*this, v).second;
        }

        friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1)
        {

                //cerr<<"Bigmod"<<endl;
                int norm = base / (b1.a.back() + 1);

                bigint a = a1.abs() * norm;

                bigint b = b1.abs() * norm;

                bigint q, r;
                q.a.resize(a.a.size());

                for(int i=a.a.size() - 1; i >= 0; i--)
                {
                        r = r * base;
                        r += a.a[i];
                        int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
                        int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
                        int d = ((ll)base * s1 + s2) / b.a.back();
                        r = r -  b*d;
                        while(r < 0)
                        {
                                r += b, --d;
                        }
                        q.a[i] = d;
                }

                q.sign = a1.sign * b1.sign;
                r.sign = a1.sign;
                q.trim(); r.trim();
                return MP(q, r/norm);
        }

        bigint operator/(int v) const
        {
                bigint res = *this;
                res /= v;
                return res;
        }


        void operator /= (int v)
        {
                if(v < 0)
                {
                        sign = -sign, v = -v;
                }

                for(int i = SZ(a) - 1, rem = 0; i>=0; i--)
                {
                        ll cur = a[i] + rem * (ll)base;
                        a[i] = (int) (cur/v);
                        rem = (int) (cur % v);
                }
                trim();
        }

        void operator+= (const bigint &v)
        {
                *this = *this + v;
        }


        bool operator<(const bigint &v) const
        {
                if(sign != v.sign)
                        return sign < v.sign;
                if(a.size() != v.a.size())
                {
                        return a.size() * sign < v.a.size() * v.sign;
                }

                for(int i=a.size() - 1; i>=0; i--)
                {
                        if(a[i] != v.a[i]) return a[i] * sign < v.a[i] * sign;
                }

                return false;
        }

        bool operator>=(const bigint &v) const{
                return !(*this < v);
        }


        bigint abs() const
        {
                bigint res = *this;
                res.sign *= res.sign;
                return res;
        }

        bigint operator/(const bigint &v) const
        {
                return divmod(*this, v).fr;
        }


        friend ostream& operator<<(ostream &stream, const bigint &v)
        {
            if(v.sign == -1)
            {
                stream<<'-';
            }

            stream<<(v.a.empty() ? 0 : v.a.back());

            for(int i=(int)v.a.size()-2; i>=0; i--)
            {
                stream<<setw(base_digits)<<setfill('0')<<v.a[i];
            }

            return stream;
        }
};


int main ()
{
    #ifdef hasibpc
        //read("input.txt");
        freopen("input.txt", "r", stdin);
        //write("output.txt");
    #endif // hasibpc

    int kases, kaseno = 0;

    int N, x;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d", &N);

        bigint res;
        res = 1;

        while(N--)
        {
            sf("%d", &x);
            res = lcm(res, x);
        }

        pf("Case %d: ", ++kaseno);

        cout<<res<<endl;
    }



    return 0;
}
