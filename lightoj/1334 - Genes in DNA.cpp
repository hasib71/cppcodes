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

#define MAXX 50007






void calculatePrefixFunction(string &pattern, int pi[], int occur[])
{
    int m = SZ(pattern);
    pi[0] = -1;
    int k = -1;

    occur[0] = 1;

    for(int i=1; i<m; i++)
    {
        while(k > -1 && pattern[k+1] != pattern[i])
            k = pi[k];
        if(pattern[k+1] == pattern[i])
            k++;
        pi[i] = k;

        occur[i] = 1;

        if(k > -1)
            occur[i] += occur[k];
    }
}



void KMP(string &str, string &pattern, int pi[], int occur[], int dp[])
{
    int n = SZ(str);
    int m = SZ(pattern);

    int q = -1;
    loop(i, n)
    {
        while(q>-1 && pattern[q+1] != str[i])
            q = pi[q];
        if(pattern[q+1] == str[i])
            q++;
        if(q == m-1)
            q = pi[q];

        //as the problem says proper
        dp[i] = occur[q];

    }
}







ll solve()
{
    string str, pattern;
    int pi[MAXX];
    int occur[MAXX];

    string revStr, revPattern;
    int revPi[MAXX];
    int revOccur[MAXX];


    cin>>str>>pattern;

    revStr = str;
    revPattern = pattern;

    reverse(all(revStr));
    reverse(all(revPattern));

    calculatePrefixFunction(pattern, pi, occur);
    calculatePrefixFunction(revPattern, revPi, revOccur);

    int dp[2][MAXX];

    KMP(str, pattern, pi, occur, dp[0]);
    KMP(revStr, revPattern, revPi, revOccur, dp[1]);

    //dump(dp[0][9]);
    //dump(dp[1][3]);

    ll res = 0;

    for(int i=0, j=SZ(str)-2; j>-1; i++, j--)
    {
        res += (ll)dp[0][i]*(ll)dp[1][j];
        //pf("[%d] = %lld\n",i, dp[0][i]*dp[1][j]);
    }

    return res;

}




int main()
{
    //read("input");
    int kases, kaseno = 0;

    sf("%d", &kases);

    while(kases--)
    {
        pf("Case %d: %lld\n", ++kaseno, solve());
    }



    return 0;
}
