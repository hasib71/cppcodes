/***********Template Starts Here***********/
#include<bits/stdc++.h>

using namespace std;

#include<bits/stdc++.h>
using namespace std;

#define loop(i, n) for(int i=0; i<(n); i++)
#define sf scanf
#define pf printf
#define ll long long

struct DATA{
    ll mxSum, mxLeftSum, mxRightSum, sum;
    
    void set( ll x )
    {
            mxSum = mxLeftSum = mxRightSum = sum = x;
    }

    DATA operator+(const DATA &other)
    {
        DATA ret;
        ret.sum = sum + other.sum;
        ret.mxLeftSum = max( mxLeftSum, sum + other.mxLeftSum );
        ret.mxRightSum = max( other.mxRightSum, mxRightSum + other.sum );

        ret.mxSum = max( mxSum, other.mxSum );
        ret.mxSum = max( ret.mxSum, mxRightSum + other.mxLeftSum );

        return ret;

    }

};

#define MAXX 50007
int N;

DATA T[4*MAXX];

void update( int idx, int st, int ed, int pos, ll val )
{
        if( st == ed )
        {
                T[idx].set( val );
        }
        else
        {
                int mid = ( st + ed )/2;
                int l = idx*2;
                int r = l + 1;

                if( pos <= mid )
                {
                        update( l, st, mid, pos, val );
                }
                else
                {
                        update( r, mid+1, ed, pos, val );
                }

                T[idx] = T[l] + T[r];
        }
}
DATA query( int idx, int st, int ed, int i, int j )
{
        if( st == i && ed == j )
        {
                return T[idx];
        }
        else
        {
                int mid = ( st + ed )/2;
                int l = idx * 2;
                int r = l + 1;

                if( j <= mid )
                {
                        return query( l, st, mid, i, j );
                }
                else if( mid < i )
                {
                        return query( r, mid + 1, ed, i, j );
                }
                else
                {
                        return query( l, st, mid, i, mid ) + query( r, mid + 1, ed, mid + 1, j );
                }
        }

}
int main ()
{
    #ifdef hasibpc
        //read("input.txt");
        //write("output.txt");
    #endif // hasibpc

    ll x, y;
    int cntQuery;
    int q;

    sf( "%d", &N );

    for( int i=1; i<=N; i++ )
    {
            sf( "%lld", &x );

            update( 1, 1, N, i, x );
    }
    
    sf( "%d", &cntQuery );

    while( cntQuery-- )
    {
            sf( "%d %lld %lld", &q, &x, &y );

            if( q == 0 )
            {
                    update( 1, 1, N, x, y );
            }
            else
            {
                    pf( "%lld\n", query( 1, 1, N, x, y ).mxSum );
            }
    }
    return 0;
}
