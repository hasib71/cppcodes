/****************************************************************
   ▄█    █▄       ▄████████    ▄████████  ▄█  ▀█████████▄
  ███    ███     ███    ███   ███    ███ ███    ███    ███
  ███    ███     ███    ███   ███    █▀  ███   ███    ███
 ▄███▄▄▄▄███▄▄   ███    ███   ███        ███  ▄███▄▄▄██▀
▀▀███▀▀▀▀███▀  ▀███████████ ▀███████████ ███ ▀▀███▀▀▀██▄
  ███    ███     ███    ███          ███ ███    ███    ██▄
  ███    ███     ███    ███    ▄█    ███ ███    ███    ███
  ███    █▀      ███    █▀   ▄████████▀  █▀   ▄█████████▀
****************************************************************/



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

#define take(args...) asdf,args
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



//Header ends here




struct BigInteger {
    string num;

    BigInteger operator+(BigInteger other)
    {
        BigInteger ret;

        int maxLen = max( SZ(num), SZ(other.num) );

        int hate = 0;

        loop(i, maxLen)
        {
            int sum = (i<SZ(num)?num[i] : 0) + (i<SZ(other.num) ? other.num[i]:0) + hate;
            ret.num.push_back(sum%10);
            hate = sum/10;
        }
        while(hate != 0)
        {
            ret.num.push_back(hate%10);
            hate /= 10;
        }
        return ret;
    }


    void operator+=(BigInteger other)
    {
        num = (*this + other).num;
    }

};


#define MAXX 10107




string str, pattern;

BigInteger dp[MAXX][107];
bool visited[MAXX][107];



BigInteger rec(int i, int j)
{
    //dump(i);
    //dump(j);
    BigInteger &ret = dp[i][j];

    if( visited[i][j] ) return ret;

    visited[i][j] = true;

    ret.num.clear();

    if(j >= SZ(pattern))
    {
        ret.num.pb(1);
        return ret;
    }
    else if(i >= SZ(str))
    {

        ret.num.pb(0);
        return ret;
    }
    else
    {

        ret = rec(i+1, j);

        if(str[i] == pattern[j])
        {
            ret = ret+ rec(i+1, j+1);
        }

        return ret;
    }

}



void solve()
{
    mem(visited, 0);
    string res = rec(0, 0).num;
    reverse(all(res));
    loop(i, SZ(res))
    {
        res[i] = res[i] + '0';
    }

    cout<<res<<endl;

}



void init()
{

}


int main()
{
    init();

    int kases;

    take(kases);

    while(kases--)
    {
        cin>>str>>pattern;

        solve();
    }



    return 0;
}
