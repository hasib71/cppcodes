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



#define MAXX 1007

vector<int>factors[MAXX];

vector<int>primes;

void generatePrimes()
{
    bool isPrime[MAXX];

    mem(isPrime, 1);

    int root = sqrt(MAXX) + 7;

    for(int i=3; i<root; i++)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<MAXX; j+=(2*i))
            {
                isPrime[j] = false;
            }
        }
    }

    for(int i=2; i<MAXX;)
    {
        if(isPrime[i])
        {
            for(int j=2; i*j < MAXX; j++)
            {
                factors[i*j].pb(i);
            }
        }

        if(i == 2)
        {
            i++;
        }
        else
        {
            i += 2;
        }
    }
}


void init()
{
    generatePrimes();
}




int bfs(int source, int target)
{
    bool visited[MAXX];

    int dist[MAXX];

    mem(dist, -1);

    mem(visited, 0);


    queue<int>Q;

    Q.push(source);

    visited[source] = true;
    dist[source] = 0;

    while(!Q.empty())
    {
        int u = Q.front(); Q.pop();

        loop(i, SZ(factors[u]))
        {
            int v = u + factors[u][i];

            if( (v <= target) && !visited[v] )
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                if(v == target)
                {
                    break;
                }
                Q.push(v);
            }
        }
    }

    return dist[target];
}


int main()
{
    init();


    int kases, kaseno = 0;

    int s, t;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d %d", &s, &t);
        pf("Case %d: %d\n", ++kaseno, bfs(s, t));
    }

    return 0;
}
