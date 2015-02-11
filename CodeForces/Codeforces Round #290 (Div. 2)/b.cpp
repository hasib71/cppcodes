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

#define MAXX 57

char graph[MAXX][MAXX];

int n, m;

paii parent[MAXX][MAXX];


paii find(int i, int j)
{
    if(parent[i][j] == MP(i, j))
    {
        //dump(parent[i][j]);
        return parent[i][j];
    }

    return parent[i][j] = find(parent[i][j].fr, parent[i][j].sc);
}



int main()
{

    cin>>n>>m;

    mem(graph, -1);

    loop(i, n)
    {
        cin>>graph[i];
    }

    loop(i, MAXX)
    {
        loop(j, MAXX)
        {
            parent[i][j] = MP(i, j);
        }
    }


    bool found = false;


    loop(i, n)
    {
        loop(j, m)
        {
            paii A = find(i, j);
            paii B = find(i, j+1);
            paii C = find(i+1, j);

            if(graph[i][j] == graph[i][j+1])
            {
                if(A != B)
                {
                    parent[B.fr][B.sc] = A;
                }
                else
                {
                    found = true;
                }
            }

            if(graph[i][j] == graph[i+1][j])
            {
                if(A != C)
                {
                    parent[C.fr][C.sc] = A;
                    //cerr<<C<<" ->"<<A<<endl;
                }
                else
                {
                    found = true;
                }
            }

        }
    }

    if(found)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }








}
