/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


problem link: http://www.codechef.com/problems/MOU1H
algo: Suffix Array, LCP Array
Tutorial: http://discuss.codechef.com/questions/18105/mou1h-editorial

**/



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


//Header ends here

#define MAXX 1000007
#define MAXLG 20

#define INF (1<<29)


int N;
int ara[MAXX];
int SortedIndex[MAXLG][MAXX];

pair<paii, int>L[MAXX];

int step;



void buildSA()
{
    loop(i, N)
    {
        SortedIndex[0][i] = ara[i];
    }


    int doneTill = 1;
    step = 1;

    while(doneTill < N)
    {
        loop(i, N)
        {
            L[i].fr.fr = SortedIndex[step-1][i];
            L[i].fr.sc = (i+doneTill) < N ? SortedIndex[step-1][i+doneTill] : -INF;
            L[i].sc = i;
        }

        sort(L, L+N);

        loop(i, N)
        {
            if(i==0)
            {
                SortedIndex[step][ L[i].sc ] = 0;
            }
            else
            {
                if(L[i-1].fr == L[i].fr)
                {
                    SortedIndex[step][L[i].sc] = SortedIndex[step][ L[i-1].sc ];
                }
                else
                {
                    SortedIndex[step][L[i].sc ] = i;
                }
            }
        }


        step++;
        doneTill *= 2;


    }
}



int findLCP(int x, int y)
{
    int answer = 0;

    for(int i=step-1; i>=0 && x <N && y < N; i--)
    {
        if(SortedIndex[i][x] == SortedIndex[i][y])
        {
            x += (1<<i);
            y += (1<<i);
            answer += (1<<i);
        }
    }
    return answer;
}


void solve()
{
    N--;


    for(int i=0; i<N; i++) ara[i] = ara[i] - ara[i+1];


    buildSA();

    int order[MAXX];

    loop(i, N)
    {
        order[ SortedIndex[step-1][i] ] = i;
    }



    ll lcp = 0;

    ll result = 0;

    //cerr<<"SA complete"<<endl;

    for(int i=1; i<N; i++)
    {
        lcp = findLCP( order[i-1], order[i] );
        result = result - lcp;
    }
    //dump(result);


    result += ((ll)N*(N+1))/2;

    cout<<result%1000000009LL<<endl;
}








int main()
{
    int kases;


    sf("%d", &kases);

    while(kases--)
    {

        sf("%d", &N);
        loop(i, N)
        {
            sf("%d", &ara[i]);
        }


        solve();
    }

    return 0;



}
