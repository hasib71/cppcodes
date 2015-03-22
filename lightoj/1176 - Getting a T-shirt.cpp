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
#define dump(x) cout<<#x<<" = "<<x<<endl
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
#define INF (1<<29)

int N, M;

int capacity[MAXX][MAXX];
int source, sink;

vector<int>graph[MAXX];

map<string, int>mp;




int findPath()
{
    queue<int>Q;
    bool visited[MAXX];
    int parent[MAXX];
    bool found = false;


    mem(visited, 0);
    mem(parent, -1);

    visited[source] = true;
    Q.push(source);

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        //dump(u);


        loop(i, SZ(graph[u]))
        {
            int v = graph[u][i];

            //return 0;
            if( (!visited[v]) && (capacity[u][v] > 0) )
            {
                //dump(v);
                parent[v] = u;
                visited[v] = true;

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

    //cout<<"Finally here"<<endl;

    int pathCapacity = INF;

    int v = sink, u;

    while(parent[v] != -1)
    {
        u = parent[v];
        pathCapacity = min(pathCapacity, capacity[u][v] );
        v = u;
    }

    //dump(pathCapacity);
    v = sink;

    while(parent[v] != -1)
    {
        u = parent[v];

        capacity[u][v] -= pathCapacity;
        capacity[v][u] += pathCapacity;

        v = u;
    }

    return found?pathCapacity:0;


}



bool FLOW()
{
    int ret = 0;
    int pathCapacity;


    while(pathCapacity = findPath())
    {
        ret += pathCapacity;
    }

    return ret == M;
}



void init()
{
    //to do
    source = 0;
    sink = MAXX - 1;

    string v[] = {"XXL", "XL", "L", "M", "S", "XS"};

    loop(i, 6)
    {
        mp[ v[i] ] = i+1;
    }


}


int main()
{
    //write("output");

    init();

    int kases, kaseno = 0;

    string str;

    sf("%d", &kases);

    while(kases--)
    {
        mem(capacity, 0);
        loop(i, MAXX) graph[i].clear();

        sf("%d %d", &N, &M);


        // to do
        for(int i=1; i<7; i++)
        {
            graph[source].pb(i);
            graph[i].pb(source);

            capacity[source][i] = N;
        }



        for(int i=7; i<M+7; i++)
        {
            loop(j, 2)
            {
                cin>>str;
                int u = mp[str];

                graph[u].pb(i);
                graph[i].pb(u);

                capacity[u][i] = 1;
            }



            graph[i].pb(sink);
            graph[sink].pb(i);

            capacity[i][sink] = 1;
        }


        pf("Case %d: %s\n", ++kaseno, FLOW()?"YES":"NO");
    }



    return 0;
}
