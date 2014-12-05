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

ll n, x, y, hitNeeded;

string solve()
{
    ll total = x + y;

    hitNeeded = hitNeeded % total;

    ll low = 1, high = x, mid;

    bool flag_x =false, flag_y = false;

    while(low <= high)
    {
        mid = (low+high)/2;

        ll p = (mid*y)/x;
        if( ((mid*y)%x ) == 0 )
            p--;

        ll tmp = p + mid - 1;

        if( tmp == hitNeeded - 1 )
        {
            //dump(mid);
            //dump(tmp);
            flag_x = true;
            break;
        }
        else if( tmp < hitNeeded - 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    low = 1, high = y;

    while(low <= high)
    {
        mid = (low + high)/2;

        ll p = (mid*x)/y;

        if( ((mid*x)%y ) == 0)
            p--;

        ll tmp = p + mid - 1;

        if( tmp == hitNeeded - 1 )
        {
            //dump(p);
            //dump(mid);
            //dump(tmp);
            flag_y = true;
            break;
        }
        else if( tmp < hitNeeded - 1)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(flag_x == flag_y)
    {
        return "Both";
    }
    else if(flag_x)
    {
        return "Vanya";
    }
    else
    {
        return "Vova";
    }

}

int main()
{


    cin>>n>>x>>y;

    loop(adfsa, n)
    {
        cin>>hitNeeded;

        cout<<solve()<<endl;

    }



}
