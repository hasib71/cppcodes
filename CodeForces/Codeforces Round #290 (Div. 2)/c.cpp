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

#define MAXX 107
#define MAXLETTER 27

#define white 0
#define ash 1
#define black 2

string str[MAXX];
int n;


#define time bal


pair<int, char>endTime[MAXLETTER];
int color[MAXLETTER];

vector<int>graph[MAXLETTER];


int f(char ch)
{
    return ch - 'a';
}


int time = 0;

bool possible = true;


void dfs(int u)
{
    color[u] = ash;
    time++;

    loop(i, SZ(graph[u]))
    {
        int v = graph[u][i];
        if(color[v] == white)
        {
            dfs(v);
        }
        else if(color[v] == ash)
        {
            //dump(u);
            //dump(v);
            possible = false;
        }
    }

    color[u] = black;
    time++;
    endTime[u].fr = time;
}





int main()
{
    cin>>n;

    loop(i, n)
    {
        cin>>str[i];
    }

    mem(color, white);


    loop(i, n-1)
    {
        int len = min(SZ(str[i]), SZ(str[i+1]));

        loop(j, len)
        {
            if(str[i][j] != str[i+1][j])
            {
                graph[ f(str[i][j]) ].pb(f(str[i+1][j]));
                break;
            }
        }
    }

    loop(i, MAXLETTER)
    {
        endTime[i] = MP(0, 'a' + i);
    }




    loop(i, 26)
    {
        if(color[i] == white)
            dfs(i);
    }


    sort(endTime, endTime + 26);
    reverse(endTime, endTime + 26);

    if(possible)
    {
        loop(i, 26)
        {
            cout<<endTime[i].sc;
        }
    }
    else
    {
        cout<<"Impossible";
    }

    cout<<endl;



















}
