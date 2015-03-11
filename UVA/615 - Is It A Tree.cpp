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







set<int>NodeList;

set<int>inputNodes;

map<int,int>parent;


int find(int u)
{
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}



void init()
{

}


int main()
{
    init();

    int kaseno = 0;
    int p, q;
    int edge;
    bool possible;

    while(true)
    {
        scanf("%d %d", &p, &q);
        if(p < 0 && q < 0)
        {
            break;
        }
        else
        {
            edge = 0;
            NodeList.clear();
            inputNodes.clear();
            parent.clear();
            possible = true;

            while(p != 0 && q != 0)
            {
                edge++;
                NodeList.insert(p);
                NodeList.insert(q);

                if(parent[p] == 0)
                {
                    parent[p] = p;
                }

                if(parent[q] == 0)
                {
                    parent[q] = q;
                }

                int u = find(p);
                int v = find(q);
                if(u == v)
                {
                    possible = false;
                }

                parent[ v ] = u;

                if(inputNodes.find(q) != inputNodes.end())
                {
                    possible = false;
                }
                else
                {
                    inputNodes.insert(q);
                }

                scanf("%d %d", &p, &q);
            }

            if( edge == 0 || (possible && (edge == SZ(NodeList) - 1) && (edge == SZ(inputNodes)) ) )
            {
                pf("Case %d is a tree.\n", ++kaseno);
            }
            else
            {
                pf("Case %d is not a tree.\n", ++kaseno);
            }

        }
    }



    return 0;
}
