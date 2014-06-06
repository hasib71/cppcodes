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

#define MAXX 100007


int main()
{
    int n, k, p;

    int ara[MAXX];


    cin>>n>>k>>p;

    int cntOdd, cntEven;
    cntOdd=cntEven = 0;

    vector<int>even, odd;


    loop(i, n)
    {
        cin>>ara[i];
        if(ara[i]%2)
        {
            cntOdd++;
            odd.pb(ara[i]);
        }
        else
        {
            cntEven++;
            even.pb(ara[i]);
        }
    }



    int s = k - p;

    if(cntOdd < s)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    else
    {
        int rightSideOdd = cntOdd - s;

        if(rightSideOdd % 2 == 1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            if(rightSideOdd/2 + cntEven < p)
            {
                cout<<"NO"<<endl;
            }
            else
            {
                cout<<"YES"<<endl;

                //dump(s); dump(p);

                int oddpos, evenpos;
                oddpos = evenpos = 0;


                loop(i, s)
                {
                    cout<<1<<" "<<odd[oddpos++]<<endl;
                }

                for(int i=1; i<p; i++)
                {
                    if(oddpos < SZ(odd))
                    {
                        cout<<2<<" "<<odd[oddpos]<<" "<<odd[oddpos+1]<<endl;
                        oddpos += 2;
                    }
                    else
                    {
                        cout<<1<<" "<<even[evenpos++]<<endl;
                    }
                }

                if(SZ(odd) - oddpos + SZ(even) - evenpos <= 0)
                    return 0;

                cout<<SZ(odd) - oddpos + SZ(even) - evenpos<<" ";

                while(oddpos < SZ(odd))
                {
                    cout<<odd[oddpos++]<<" ";
                }

                while(evenpos < SZ(even))
                {
                    cout<<even[evenpos++]<<" ";
                }

                cout<<endl;







            }
        }
    }




























}
