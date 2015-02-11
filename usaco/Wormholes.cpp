/*
ID: himuhas1
TASK: wormhole
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

#define MAXX 14
int N;
int X[MAXX], Y[MAXX];
int pairTo[MAXX];
int next_to_right[MAXX];

bool cycle_exists()
{
    for(int start = 1; start<=N; start++)
    {
        int cur =  start;

        for(int i=1; i<=N; i++)
        {
            cur = pairTo[cur];
            cur = next_to_right[cur];
        }

        if(cur != 0)
        {
            return true;
        }
    }
    return false;
}



int solve()
{
    int i, ret = 0;
    for(i=1; i<=N; i++)
    {
        if(pairTo[i] == 0)
        {
            break;
        }
    }

    if(i > N)
    {
        //all paired up already
        if(cycle_exists())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }


    for(int j=i+1; j<=N; j++)
    {
        if(pairTo[j] == 0)
        {
            pairTo[i] = j;
            pairTo[j] = i;

            ret += solve();

            pairTo[i] = pairTo[j] = 0;

        }
    }

    return ret;

}


int main()
{
    #ifndef hasibpc
        read("wormhole.in");
        write("wormhole.out");
    #endif // hasibpc

    sf("%d", &N);

    loop(i, N)
    {
        sf("%d %d", &X[i+1], &Y[i+1]);
    }


    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++)
        {
            if( X[j] > X[i] && Y[i] == Y[j]  )
            {
                if(next_to_right[i] == 0)
                {
                    next_to_right[i] = j;
                }
                else if(X[j] < X[ next_to_right[i] ])
                {
                    next_to_right[i] = j;
                }
            }
        }
    }



    pf("%d\n", solve());



}
