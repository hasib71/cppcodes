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

#define MAXX 102

int N, C, R;
string headTown;
vector<string>vehicleTown;
string str1, str2;

map<string, int>mp;
int cost[MAXX][MAXX];
char ch1, ch2;
int *x, *y;
int numbering;

#define INF 16843009

int main()
{
    int kaseno = 0;
    int c;
    while(scanf("%d %d %d", &N, &C, &R) && N+C+R != 0)
    {
        mp.clear();
        vehicleTown.clear();
        mem(cost, 1);




        numbering = 1;

        cin>>headTown;

        //cout<<"heading is "<<headTown<<endl;

        mp[headTown] = numbering++;

        for(int i=0; i<C; i++)
        {
            cin>>str1;
            vehicleTown.pb(str1);
        }


        loop(i, R)
        {
            cin>>str1;
            cin>>ch1>>ch2>>c>>ch2>>ch2;
            cin>>str2;
//            pf("        dist from %s to %s is %d\n", str1.c_str(), str2.c_str(), c);
/*
            if(str1==headTown)
            {
                cout<<"found head town, and its map is "<<mp[str1]<<endl;
            }
*/

            x = &mp[str1];
            y = &mp[str2];

            if(*x == 0) *x = numbering++;
            if(*y == 0) *y = numbering++;

            //pf("             %s's mapping to %d\n", str1.c_str(), *x);
            //pf("             %s's mapping to %d\n", str2.c_str(), *y);


            if(ch1 == '<')
            {
                cost[*y][*x] = c;
            }

            if(ch2 == '>')
            {
                cost[*x][*y] = c;
            }

        }

        for(int i=1; i<numbering; i++)
        {
            cost[i][i] = 0;
        }


        for(int k=1; k<numbering; k++)
        {
            for(int i=1; i<numbering; i++)
            {
                for(int j=1; j<numbering; j++)
                {
                    cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
                }
            }
        }

        ll totalCost = 0;


        loop(i, SZ(vehicleTown))
        {
            str1 = vehicleTown[i];
            *x = mp[str1];
            totalCost += cost[1][*x] + cost[*x][1];
        }

        cout<<++kaseno<<". "<<totalCost<<endl;

    }



}
