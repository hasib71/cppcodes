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

#define MAXX 208

#define INF (1<<29)





int capacity[MAXX][MAXX], tmpCapacity[MAXX][MAXX];
int N;
double D;
pair<double, double>points[MAXX/2];
vector<int>graph[MAXX];
int source, sink;
int total;

double sq(double x)
{
    return x*x;
}

double dist(pair<double, double>A, pair<double, double>B)
{
    return sqrt( sq(A.fr - B.fr) + sq(A.sc - B.sc) );
}


int findPath()
{
    bool visited[MAXX];

    bool found = false;

    int parent[MAXX];

    mem(parent, -1);
    mem(visited, 0);

    queue<int>Q;

    Q.push(source);
    visited[source] = true;

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        loop(i, SZ(graph[u]))
        {
            int v = graph[u][i];

            if(!visited[v] && tmpCapacity[u][v] > 0)
            {
                visited[v] = true;
                parent[v] = u;
                Q.push(v);

                if(v == sink)
                {
                    found = true;
                    break;
                }
            }
        }

        if(found)
        {
            break;
        }
    }

    int pathCapacity = INF;
    int u, v = sink;

    while(parent[v] != -1)
    {
        u = parent[v];

        pathCapacity = min(pathCapacity, tmpCapacity[u][v]);

        v = u;

    }


    v = sink;

    while(parent[v] != -1)
    {
        u = parent[v];

        tmpCapacity[u][v] -= pathCapacity;
        tmpCapacity[v][u] += pathCapacity;

        v = u;
    }

    return found?pathCapacity:0;
}






int FLOW()
{
    loop(i, MAXX)
    {
        loop(j, MAXX)
        {
            tmpCapacity[i][j] = capacity[i][j];
        }
    }

    int ret = 0;

    int pathCapacity;

    while(pathCapacity = findPath())
    {
        ret += pathCapacity;
    }
    return ret;
}





void init()
{

}


int main()
{
    init();

    int kases, kaseno = 0;

    int n, c;

    int u, v;

    sf("%d", &kases);

    while(kases--)
    {

        mem(capacity, 0);
        loop(i, MAXX) graph[i].clear();
        total = 0;

        sf("%d %lf", &N, &D);


        source = 0;


        for(int i=1; i<=N; i++)
        {
            sf("%lf %lf %d %d", &points[i].fr, &points[i].sc, &n, &c);

            total += n;

            v = 2*i;
            u = v - 1;


            graph[u].pb(v);
            graph[v].pb(u);

            capacity[u][v] = c;

            graph[source].pb(u);
            graph[u].pb(source);

            capacity[source][u] = n;
        }


        for(int i=1; i<=N; i++)
        {
            for(int j=1; j<=N; j++)
            {
                if(i == j) continue;

                if(dist(points[i], points[j]) <= D)
                {
                    u = 2*i;
                    v = 2*j - 1;

                    capacity[u][v] = INF;

                    graph[u].pb(v);
                    graph[v].pb(u);
                }
            }
        }


        vector<int>vv;
        for(int i=1; i<=N; i++)
        {
            sink = 2*i - 1;

            if(FLOW() == total)
            {
                vv.pb(i);
            }
        }

        printf("Case %d:", ++kaseno);

        if(SZ(vv) == 0)
        {
            printf(" -1");
        }
        else
        {
            loop(i, SZ(vv))
            {
                printf(" %d", vv[i] - 1);
            }
        }

        pf("\n");











    }



    return 0;
}
