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

#define mypair pair<int, char>
#define INF (1<<20)


#define MAXX 50

mypair dp[MAXX][MAXX];

bool visited[MAXX][MAXX];


string from, to;



//#define min something

/*
template<typename T>
T min(T a, T b)
{
    if(a.fr == b.fr)
    {
        T p, q;
        p = a;
        q = b;

        if(p.sc == 'D')
            p.sc = 0;
        else if(p.sc == 'I')
            p.sc = 1;
        else if(p.sc == 'C')
            p.sc = 2;
        else
            p.sc = 3;

        if(q.sc == 'D')
            q.sc = 0;
        else if(p.sc == 'I')
            p.sc = 1;
        else if(p.sc == 'C')
            p.sc = 2;
        else
            p.sc = 3;


        if(p <= q)
            return a;
        else
            return b;
    }

    return (a<=b)?a:b;
}
*/


int rec(int i, int j)
{


    mypair &ret = dp[i][j];

    if(visited[i][j]) return ret.fr;

    visited[i][j] = true;

    if(i>= SZ(from) && j >= SZ(to))
    {
        ret = MP(0, 'F');
        return ret.fr;
    }
    else if(i >= SZ(from))
    {
        ret = MP(SZ(to) - j, 'F');
        return ret.fr;
    }
    else if(j >= SZ(to))
    {
        ret = MP(SZ(from) - i, 'F');
        return ret.fr;
    }



    ret = MP(INF, '\0');

    ret = min(ret, MP(rec(i+1, j) + 1, 'D'));

    if(from[i] == to[j])
    {
        ret = min(ret, MP( rec(i+1, j+1), 'N' ));
    }
    else
    {
        ret = min(ret, MP(rec(i+1, j+1) + 1, 'C' ));
        ret = min(ret, MP(rec(i, j+1) + 1, 'I') );
    }

    //cerr<<"rec("<<i<<", "<<j<<") = "<<ret<<endl;


    return ret.fr;
}




void solve()
{
    mem(visited, 0);

    rec(0, 0);

    int i = 0, j = 0;

    int ch = 0;

    int cnt = 0;

    while(true)
    {
        ch = dp[i][j].sc;

        if(ch == 'F')
        {
            break;
        }
        else
        {
            if(ch == 'D')
            {
                pf("D%c%02d", from[i], i+1+cnt );
                i++;
                cnt--;
            }
            else if(ch == 'C')
            {
                pf("C%c%02d", to[j], i+1 + cnt);
                i++;
                j++;
            }
            else if(ch == 'I')
            {
                pf("I%c%02d", to[j], i + 1 + cnt);
                j++;
                cnt++;
            }
            else if(ch == 'N')
            {
                i++;
                j++;
            }
        }
    }

    while(true)
    {
        if(i>= SZ(from) && j >= SZ(to))
        {
            break;
        }
        else if(i>=SZ(from))
        {
            printf("I%c%02d", to[j], i+1+cnt);
            j++;
            cnt++;
        }
        else if(j>=SZ(to))
        {
            printf("D%c%02d", from[i], i+1+cnt);
            i++;
            cnt--;
        }
    }

    printf("E\n");



}





void init()
{
    #ifdef hasibpc
       // read("input");
       // write("output");
    #endif // hasibpc
}


int main()
{
    init();

    while(true)
    {
        cin>>from;

        if(from[0] == '#') break;

        cin>>to;

        solve();
    }


    return 0;
}
