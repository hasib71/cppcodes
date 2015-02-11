/*
ID: himuhas1
TASK: camelot
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

#define MAXX 32
#define MYPAIR pair<int, paii>

#define diff(A, B) ( max(abs(A.fr - B.fr), abs(A.sc - B.sc) ) )

int R, C;
int dist[MAXX][MAXX][MAXX*MAXX][2];
paii king;
vector<paii>knights;


int dirx[] = {-1, -2, -2, -1,  1, 2,   2,  1};
int diry[] = {-2, -1,  1,  2, -2, -1,  1,  2};


void dijkstra(int p, int withking)
{
    MYPAIR u;

    u.sc = knights[p];

    u.fr = dist[u.sc.fr][u.sc.sc][p][withking] = withking ? diff(u.sc, king) : 0;

    priority_queue<MYPAIR, vector<MYPAIR>, greater<MYPAIR> > Q;

    Q.push(u);


    //cerr<<"p = "<<p<<", withking = "<<withking<<endl;


    while(! Q.empty() )
    {
        u = Q.top();
        Q.pop();

        MYPAIR v;

        //cerr<<u<<endl;
        loop(i, 8)
        {
            v.sc = MP( u.sc.fr + dirx[i], u.sc.sc + diry[i] );

            if(0 <= v.sc.fr && v.sc.fr < R && 0 <= v.sc.sc && v.sc.sc < C)
            {

                if(withking)
                {
                    v.fr = min(u.fr + 1, dist[v.sc.fr][v.sc.sc][p][0] + diff(king, v.sc) );
                }
                else
                {
                    v.fr = u.fr + 1;
                }

                if(v.fr < dist[v.sc.fr][v.sc.sc][p][withking] )
                {
                    dist[v.sc.fr][v.sc.sc][p][withking] = v.fr;
                    Q.push(v);
                }
            }


        }


    }

}






void solve()
{

    mem(dist, 1);

    loop(i, SZ(knights))
    {
        dijkstra(i, 0);
    }

    loop(i, SZ(knights))
    {
        dijkstra(i, 1);
    }


    int minCost = (1<<29);


    loop(r, R)
    {
        loop(c, C)
        {
            int cost = 0;

            int kingCost = (1<<29);

            loop(i, SZ(knights))
            {
                cost += dist[r][c][i][0];
                kingCost = min(kingCost, dist[r][c][i][1] - dist[r][c][i][0] );
            }

            kingCost = min(kingCost, diff(MP(r,c), king) );

            cost += kingCost;

            minCost = min(minCost, cost);



        }
    }

    cout<<minCost<<endl;




}





int main()
{

    #ifdef hasibpc
        read("input");
    #endif // hasibpc

    #ifndef hasibpc
        read("camelot.in");
        write("camelot.out");
    #endif // hasibpc

    sf("%d", &R);
    sf("%d", &C);


    char str[10];

    sf("%s", str);

    int row, column =  str[0] - 'A';

    sf("%d", &row);

    row--;

    king = MP(row, column);

    while(sf("%s", str) == 1)
    {
        sf("%d", &row);
        row --;
        column = str[0] - 'A';

        knights.pb(MP(row, column));
    }


    solve();

    return 0;

}
