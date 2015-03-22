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

int N;
int curPage;




void solve()
{
    set<int>s;
    s.insert(1);

    int tmp = curPage - 2;


    while(tmp <= N && SZ(s) < 6)
    {
        if(0 < tmp)
        {
            s.insert(tmp);
        }
        tmp++;
    }

    tmp = curPage;

    while(0 < tmp && SZ(s) < 6)
    {
        s.insert(tmp);
        tmp--;
    }





    for(int i=0, cnt=0; cnt<5; i--, cnt++)
    {
        tmp = N + i;
        if(0 < tmp)
        {
            if(s.find(tmp) != s.end())
            {
                //dump(tmp);
                //cerr<<"HERE"<<endl;
                break;
            }

            s.insert(tmp);
        }
    }

    vector<int>v;

    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        v.pb(*it);
    }

    loop(i, 6)
    {
        if(i < SZ(v))
        {
            if(i)
            {
                cout<<" ";
            }
            cout<<v[i];
        }
    }

     if(SZ(v) > 6)
     {
         cout<<" .....";
     }

     for(int i=6; i<SZ(v); i++)
     {
         cout<<" "<<v[i];
     }

     cout<<endl;





}



int main()
{
    int kases, kaseno = 0;

    cin>>kases;

    while(kases--)
    {
        cin>>N;

        pf("Case %d:\n", ++kaseno);

        while(true)
        {
            cin>>curPage;
            if(curPage == 0)
                break;

            solve();
        }
    }





    return 0;
}
