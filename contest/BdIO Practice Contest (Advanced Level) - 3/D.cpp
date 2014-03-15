#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


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
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args
#define debug(args...) asdfg,args; cout<<endl
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
struct ASDFG{
    template<typename T>
    ASDFG& operator,(vector<T> &v){
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v)){
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }

    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }


}asdfg;



//Header ends here

int dirx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int diry[] = {-1, 0, 1,  -1, 1, -1, 0, 1};

#define MAXX 103


#define INF (1<<29)

#define isChar(ch) ('A'<=ch && ch <= 'Z')

#define isValid(s, n) (-1<s && s<n)

char graph[MAXX][MAXX];
bool visited[MAXX][MAXX];
int dist[MAXX][MAXX];
bool used[28];

vector<paii>jadu[28];

int n, m;



paii mew, gheu;



int dfs(int p, int q)
{

    mem(used, 0);
    char ch;

    queue<paii>Q;

    paii u, v;

    mem(visited, 0);
    dist[p][q] = 0;
    visited[p][q] = true;

    Q.push( MP(p, q) );

    while(!Q.empty())
    {
        u = Q.front(); Q.pop();

        //cerr<<"visiting "<<u.fr<<", "<<u.sc<<endl;




        ch = graph[u.fr][u.sc];

        if(isChar(ch) && !used[ch-'A'])
        {
            ch = ch - 'A';

            used[ch] = true;

            loop(i, SZ(jadu[ch]))
            {
                v = jadu[ch][i];

                if(!visited[v.fr][v.sc] && graph[v.fr][v.sc] != '#')
                {
                    visited[v.fr][v.sc] = true;
                    dist[v.fr][v.sc] = dist[u.fr][u.sc];
                    Q.push(v);
                }
            }

        }


        loop(i, 8)
        {
            v.fr = u.fr + dirx[i];
            v.sc = u.sc + diry[i];


            if(isValid(v.fr, n) && isValid(v.sc, m))
            {
                if( !visited[v.fr][v.sc] && graph[v.fr][v.sc] != '#' )
                {
                    visited[v.fr][v.sc] = true;
                    dist[v.fr][v.sc] = dist[u.fr][u.sc] + 1;
                    Q.push(v);
                }
            }
        }
    }


    if(visited[mew.fr][mew.sc] && visited[gheu.fr][gheu.sc])
    {
        return max(dist[mew.fr][mew.sc], dist[gheu.fr][gheu.sc]);
    }
    else
    {
        return INF;
    }

}



int main()
{
    take(n, m);

    int p, q;

    loop(i, n)
    {
        scanf("%s", graph[i]);
        //dump(graph[i]);
        loop(j, m)
        {
            if(graph[i][j] == '*')
            {
                p = i;
                q = j;

                graph[i][j] = '#';

            }
            else if(graph[i][j] == '!')
            {
                mew = MP(i, j);
            }
            else if(graph[i][j] == '$')
            {
                gheu = MP(i, j);
            }


            if(isChar(graph[i][j]))
            {
                jadu[ graph[i][j] -'A' ].pb(MP(i, j));
            }
        }
    }

    //dump(p), dump(q);




    int x, y;

    int res = INF;

    loop(i, 8)
    {
        x = p + dirx[i];
        y = q + diry[i];

        if(isValid(x, n) && isValid(y, m) && graph[x][y] != '#')
        {
            res = min(res, dfs(x, y));
        }
    }





    if(res == INF)
    {
        cout<<"Impossible"<<endl;
    }
    else
    {
        cout<<res+1<<endl;
    }










}
