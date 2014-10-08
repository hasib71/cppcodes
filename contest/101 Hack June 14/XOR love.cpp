/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



#include<bits/stdc++.h>


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)

#define dump(x) cerr<<#x<<" = "<<x<<endl
#define debug(args...) cerr,args; cerr<<endl;
using namespace std;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}




template<typename T>
ostream& operator,(ostream& output, T x)
{
    output<<x<<" ";
    return output;
}





//Header ends here

#define MAXX 100007

#define lowbit(a) ( a & -a )



int sum[33][MAXX];

int elm;

int n;

void buildTree( int which, int pos)
{
    while(pos <= n)
    {
        sum[which][pos]++;
                                                    ///pf("sum[%d][%d] = %d\n", which, pos, sum[which][pos]);
        pos += lowbit(pos);
    }
}


ll getSum(int which, int pos)
{
    ll s = 0;
    while(pos > 0)
    {
        s += sum[which][pos];
        pos -= lowbit(pos);
    }
    return s;
}

int getSum(int which, int p, int q)
{
    return getSum(which, q) - getSum(which, p-1);
}

#define MOD 1000000007

int main()
{

    cin>>n;



    for(int i=1; i<=n; i++)
    {
        cin>>elm;
        loop(j, 21)
        {
            if( (elm & (1<<j) ) )
            {
                buildTree(j, i);
            }
        }

    }


    ///cout<<getSum(0, 1, 3);




    int K, P, R;

    int cntQuery;
    cin>>cntQuery;
    while(cntQuery--)
    {
        cin>>K>>P>>R;
        if(P == R)
        {
            cout<<0<<endl;
        }
        else
        {
            ll result = 0;


            ll total = R - P + 1;
            loop(which, 21)
            {
                ///dump(which);
                ll ones = getSum(which, P, R);
                ll zeros = total - ones;

                ll oo = ones*zeros;
                ll zz = (total*(total-1))/2   -  oo;
                ///dump(oo);
                ///dump(zz);
                if(K & (1<<which))
                {
                    result += ( zz * (1LL<<which)  );

                }
                else
                {
                    result += (oo * (1LL<<which));
                }

                result %= MOD;

            }
            cout<<result<<endl;
        }
    }
}


