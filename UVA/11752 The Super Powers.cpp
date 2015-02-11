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

#define ull unsigned ll

ull N = 18446744073709551615;
set<ull>s;


void bigMod(ull n, int p)
{
    //cerr<<"n = "<<n<<"p = "<<p<<endl;
    ull ret = 1;

    for(int i=1; i<=p; i++)
    {
        if(ret > (N/n))
        {
            return;
        }
        else
        {
            ret = ret * n;
        }
    }

    s.insert(ret);
    //cout<<ret<<' ';
}

bool isPrime[100];

void generatePrimes()
{

    int up = 100;

    mem(isPrime, 1);

    for(int i=4; i<up; i+=2)
    {
        isPrime[i] = false;
    }


    int root = sqrt(up);

    for(int i=3; i<root; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<up; j+=2*i)
            {
                isPrime[j] = false;
            }
        }
    }


}

int main()
{
    //write("output");
    generatePrimes();

    //cout<<isPrime[4]<<endl;


    for(ull i=2; i<=100000; i++)
    {
        for(int p=4; p<=64; p++)
        {
            if(!isPrime[p])
            {
                bigMod(i, p);
                //return 0;
            }

        }
    }
    cout<<1<<endl;
    for(set<ull>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout<<*it<<endl;
    }



}

