/*
ID: himuhas1
TASK: censor
LANG: C++
*/


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

#define MAXX 1000007


string str, pattern;

bool used[MAXX];

int pi[MAXX];



void compute_prefix_function()
{
    int m = SZ(pattern) - 1;

    pi[1] = 0;
    int k = 0;

    for(int q=2; q<=m; q++)
    {
        while( k > 0 && pattern[k+1] != pattern[q])
        {
            k = pi[k];
        }
        if(pattern[k+1] == pattern[q])
        {
            k++;
        }
        pi[q] = k;
    }
}


void kmp_matcher()
{


    mem(used, 0);

    int n = SZ(str) - 1;

    int m = SZ(pattern) - 1;

    compute_prefix_function();

    int q = 0;

    for(int i=1; i<=n; i++)
    {
        if(used[i])
        {
            continue;
        }


        while(q > 0 && pattern[q+1] != str[i])
        {
            q = pi[q];
        }

        if(pattern[q+1] == str[i])
        {
            q++;
        }

        if(q == m)
        {
            int j = i;

            int cnt = 0;

            while(cnt < m && j > 0)
            {
                if(used[j] == false)
                {
                    used[j] = true;
                    cnt++;
                }
                j--;
            }

            cnt = 1;

            while(cnt < m && j > 0)
            {
                if(used[j] == false)
                {
                    cnt++;
                }
                j--;
            }

            i = j;
            q = 0;
        }
    }

}



void init()
{

}


int main()
{
    init();

    #ifndef hasibpc
        read("censor.in");
        write("censor.out");
    #endif // hasibpc


    cin>>str>>pattern;

    str = " " + str;

    pattern = " " + pattern;

    kmp_matcher();

    for(int i=1; i<SZ(str); i++)
    {
        if(!used[i])
        {
            pf("%c", str[i]);
        }
    }

    cout<<endl;





    return 0;
}
