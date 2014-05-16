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

#define MXLG 20
#define MAXX 100007


int SortedIndex[MXLG][MAXX];
int N;
string str;
int step;


void buildSA()
{
    pair<paii, int>L[MAXX];
    int doneTill = 1;
    step = 1;


    loop(i, N) SortedIndex[0][i] = str[i];



    while(doneTill < N)
    {
        loop(i, N)
        {
            L[i].fr.fr = SortedIndex[step-1][i];
            L[i].fr.sc = i + doneTill < N ? SortedIndex[step-1][i+doneTill] : -1;
            L[i].sc = i;
        }


        sort(L, L+N);

        loop(i, N)
        {
            if(i == 0)
            {
                SortedIndex[step][ L[i].sc ] = 0;
            }
            else
            {
                if(L[i-1].fr == L[i].fr)
                {
                    SortedIndex[step][ L[i].sc ] = SortedIndex[step][L[i-1].sc];
                }
                else
                {
                    SortedIndex[step][L[i].sc] = i;
                }

            }
        }

        step++;
        doneTill *= 2;
    }

}





int LCP(int x,int y)
{
    if(x == y) return N - x;
    int result = 0;

    for(int i=step-1; i>=0 && x < N && y < N; i--)
    {
        if(SortedIndex[i][x] == SortedIndex[i][y])
        {
            x += (1<<i);
            y += (1<<i);
            result += (1<<i);
        }
    }

    return result;

}



int main()
{
    cin>>str;
    N = SZ(str);

    buildSA();

    ll p[MAXX];

    ll comu[MAXX];

    mem(p, 0);


    for(int i=1; i<N; i++)
    {
        int l = LCP(0, i);
        //cerr<<i<<" "<<l<<endl;
        p[l]++;
    }


    comu[N] = 0;
    ll cnt = 0;
    vector<pair<int, ll> > v;

    for(int i=N-1; i>=0; i--)
    {
        comu[i] = comu[i+1] + p[i];
    }


    for(int len=1; len<=N; len++)
    {
        if(LCP(0, N-len) == len)
        {
            cnt++;
            v.pb(MP(len, comu[len]+1));
            //pf("%d %lld\n", len, comu[len]);
        }
    }

    pf("%lld\n", cnt);

    loop(i, SZ(v))
    {
        pf("%d %lld\n", v[i].fr, v[i].sc);
    }








}
