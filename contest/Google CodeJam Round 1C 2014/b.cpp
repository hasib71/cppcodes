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

struct DATA{
    int midd, left, right, full;
    DATA()
    {
        midd = left = right = full = 0;
    }
};


#define MAXX 107

#define MOD (1000000007)



DATA node[MAXX];

string ss[MAXX];

ll fac[MAXX];

int N;



bool buildNode(int u, char ch)
{

    DATA &p = node[u];
    p.left = p.right = p.midd = p.full = 0;

    int l, r;
    l = 0;

    while(l < SZ(ss[u]))
    {
        if(ss[u][l] != ch)
        {
            break;
        }
        l++;
    }


    r = SZ(ss[u]) - 1;

    while(r >= 0)
    {
        if(ss[u][r] != ch)
        {
            break;
        }
        r--;
    }




    dump(r), dump(l);

    if( r < l)
    {
        p.full = 1;
    }
    else
    {

        if(l > 0)
        {
            p.left = 1;
        }

        if(r < SZ(ss[u]) - 1)
        {
            p.right = 1;
        }

    }



    while(l <= r)
    {
        if(ss[u][l] == ch)
        {
            if(p.midd == 1)
            {
                if(ss[u][l-1] != ch)
                {
                    cerr<<"yeah! from here"<<endl;
                    return true;
                }
            }

            p.midd = 1;
        }

        l++;
    }


    if(! p.full)
    {
        if(p.midd + p.left + p.right >= 2)
        {
            pf("for string %s and char %c, l=%d, r=%d, mid=%d, full=%d\n", ss[u].c_str(), ch, p.left, p.right, p.midd, p.full);
            cerr<<" so here??"<<endl;
            dump(p.midd);
            dump(p.left);
            dump(p.right);
            return true;
        }
    }




    return false;


}



int main()
{
    fac[0] = 1;
    for(int i=1; i<MAXX; i++) fac[i] = (fac[i-1]*i)%MOD;


    int kases, kaseno = 0;

    cin>>kases;

    while(kases--)
    {
        cin>>N;
        loop(i, N)
        {
            cin>>ss[i];
        }

        bool possible = true;



        ll leftCnt, rightCnt, fullCnt;

        ll result = 1;
        ll cntSet = 0;






        for(char ch='a'; ch<='z'; ch++)
        {

            leftCnt = rightCnt = fullCnt = 0;
            loop(i, N)
            {
                if(buildNode(i, ch))
                {
                    cerr<<"here for node "<<i<<endl;
                    possible = false;
                    goto hell;
                }

                leftCnt += node[i].left;
                rightCnt += node[i].right;
                fullCnt += node[i].full;

            }


            if(leftCnt > 1 || rightCnt > 1)
            {
                cerr<<"for cnt? for char = "<<ch<<endl;
                dump(leftCnt), dump(rightCnt);

                possible = false;
                break;
            }
            else
            {
                result = (result * fac[ fullCnt ]  ) % MOD;
                if(leftCnt + rightCnt == 0 && fullCnt > 0)
                {
                    cntSet++;
                }
            }
        }

        hell:

        dump(possible);
        dump(cntSet);


        if(possible)
        {
            result = (result * fac[cntSet])%MOD;
        }
        else
        {
            result = 0;
        }

        dump(result);










    }



}
