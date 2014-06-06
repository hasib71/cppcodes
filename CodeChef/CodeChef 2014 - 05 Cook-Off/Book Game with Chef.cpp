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



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


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
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args

struct ASDF{
    ASDF& operator,(int &a) {
        sf("%d", &a);
        return *this;
    }
    ASDF& operator,(long int &a){
        sf("%ld", &a);
        return *this;
    }
    ASDF& operator,(long long int &a){
        sf("%lld", &a);
        return *this;
    }
    ASDF& operator,(char &c){
        sf("%c", &c);
        return *this;
    }
    ASDF& operator,(double &d){
        sf("%lf", &d);
        return *this;
    }

    template<typename T>
    ASDF& operator,(T &a){
        cin>>a;
        return *this;
    }
}asdf;


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


//Header ends here

#define MAXX 20


int digit;

int ara[MAXX];

int len;

ll p[MAXX];

ll N;



ll rec(int pos)
{
    if(pos > len) return 1;


    if(ara[pos] == digit)
    {
        return digit * p[len - pos];
    }
    else
    {
        ll sum = rec(pos+1);


        if(ara[pos] > 0)
        {
            sum += (ara[pos] - 1) * p[len-pos];
        }



        if( digit > ara[pos] )
        {
            sum += p[len - pos];
        }

        return sum;
    }

}



void fill(ll n)
{
    len = 0;

    while(n != 0)
    {
        ara[len] = n%10;
        n /= 10;
        len++;
    }

    reverse(ara, ara+len);

    len--;
}




int main()
{
    p[0] = 1;
    for(int i=1; i<MAXX; i++)
    {
        p[i] = p[i-1]*9;
    }

    int kases;
    cin>>kases;

    while(kases--)
    {
        cin>>N;

        fill(N);


        /*
        vector<int>v(ara, ara+len+1);
        dump(v);
        dump(len);



        /**/


        ll success = 0;



        digit = 0;

        for(int i=0; i<len; i++)
        {
            success +=  ( -p[len-i] ) ;
        }

        success = success - rec(0);

        //dump(success);

        success = N  + success;

        dump(success);

        for(digit = 1; digit <10; digit++)
        {
            success = success - rec(0) + N+1;
            dump(success);

        }

        N = N*10;


        ll g = __gcd(success, N);
        success /= g;
        N /= g;

        cout<<success<<"/"<<N<<endl;



    }



}
