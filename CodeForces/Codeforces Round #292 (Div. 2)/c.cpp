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


int len;
string str;


int primes[] = {2, 3, 5, 7};

int cnt[4]; /// two=0, three=1, five=2, seven=3

int fac[10];



void add(int n)
{
    int tmp = fac[n];

    loop(i, 4)
    {
        while( (tmp%primes[i]) == 0 )
        {
            tmp /= primes[i];
            cnt[i]++;
        }
    }
}

void remove(int n)
{
    int tmp = fac[n];

    loop(i, 4)
    {
        while( (tmp % primes[i]) == 0 )
        {
            tmp /= primes[i];
            cnt[i]--;
        }
    }
}



string solve()
{
    string ret = "";

    mem(cnt, 0);

    loop(i, len)
    {
        add(str[i] - '0');
    }

    for(int i=3; i>=0; i--)
    {
        while(cnt[i] > 0)
        {
            ret.pb('0' + primes[i]);

            remove(primes[i]);
        }
    }

    //dump(ret);

    return ret;



}



void init()
{
    fac[0] = 1;

    for(int i=1; i<10; i++)
    {
        fac[i] = i*fac[i-1];
    }
}


int main()
{
    init();


    cin>>len>>str;

    cout<<solve()<<endl;



    return 0;
}
