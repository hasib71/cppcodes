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





//Header ends here

#define MAXX 12
#define mypair pair<pair<int, int>, int>

mypair v1[MAXX], v2[MAXX];
vector<mypair> leftPossible, rightPossible;


int main()
{
    read("newyear.in");
    int kases, kaseno = 0;

    cin>>kases;

    while(kases--)
    {
        int gp, gc, gf;

        int n;

        cin>>gp>>gc>>gf;

        cin>>n;

        int leftN = n/2;

        int rightN = n - leftN;

        loop(i, leftN)
        {
            cin>>v1[i].fr.fr>>v1[i].fr.sc>>v1[i].sc;
        }

        loop(i, rightN)
        {
            cin>>v2[i].fr.fr>>v2[i].fr.sc>>v2[i].sc;
        }

        leftPossible.clear();

        rightPossible.clear();

        loop(bit, (1<<leftN))
        {
            mypair nd;
            nd.fr.fr = nd.fr.sc = nd.sc = 0;

            loop(i, MAXX)
            {
                if( (bit & (1<<i)) )
                {
                    nd.fr.fr += v1[i].fr.fr;
                    nd.fr.sc += v1[i].fr.sc;
                    nd.sc += v1[i].sc;
                }
            }
            leftPossible.pb(nd);
        }

        loop(bit, (1<<rightN))
        {
            mypair nd;
            nd.fr.fr = nd.fr.sc = nd.sc = 0;

            loop(i, MAXX)
            {
                if( (bit & (1<<i)) )
                {
                    nd.fr.fr += v2[i].fr.fr;
                    nd.fr.sc += v2[i].fr.sc;
                    nd.sc += v2[i].sc;
                }
            }
            rightPossible.pb(nd);
        }

        if(leftN == 0)
        {
            mypair nd;
            nd.fr.fr = nd.fr.sc = nd.sc = 0;
            leftPossible.pb(nd);
        }



        bool possible = false;

        sort(all(rightPossible));

        loop(i, SZ(leftPossible))
        {
            mypair nd;
            nd.fr.fr = gp - leftPossible[i].fr.fr;
            nd.fr.sc = gc - leftPossible[i].fr.sc;
            nd.sc = gf - leftPossible[i].sc;

            if(binary_search( rightPossible.begin(), rightPossible.end(), nd )  )
            {
                possible = true;
                break;
            }
        }

        pf("Case #%d: ", ++kaseno);

        if(possible)
        {
            pf("yes\n");
        }
        else
        {
            pf("no\n");
        }

    }



}
