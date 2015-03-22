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


#define MAXX 1007

int R, m, n;

vector<int>mina;
vector<int>raju;


int dp[MAXX];
int dp2[MAXX];

int rec(int remain);

int rec2(int remain) //for raju
{

    if(remain <= 0)
    {
        return 1; // Mina wins;
    }



    int &ret = dp2[remain];

    if(ret != -1) return ret;

    ret = 1; //mina win

    loop(i, n)
    {
        if(rec( remain - raju[i] ) == 0)
        {
            ret = 0;
            break;
        }
    }

    return ret;

}



int rec(int remain)
{
    if(remain <= 0)
    {
        return 0; //Raju wins;
    }

    int &ret = dp[remain];

    if(ret != -1) return ret;

    ret = 0;

    loop(i, m)
    {
        if(rec2(remain - mina[i]))
        {
            ret = 1;
            break;
        }
    }

    return ret;


}






int main()
{
    int kases, kaseno = 0;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d %d %d", &R, &m, &n);

        mina.clear();
        mina.resize(m);

        raju.clear();
        raju.resize(n);

        loop(i, m)
        {
            sf("%d", &mina[i]);
        }

        loop(i, n)
        {
            sf("%d", &raju[i]);
        }

        mem(dp, -1);
        mem(dp2, -1);


        if(rec(R) || n == 0)
        {
            cout<<"Mina wins"<<endl;
        }
        else
        {
            cout<<"Raju wins"<<endl;
        }



    }




    return 0;
}
