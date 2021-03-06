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

int N, M;
ll D;
vector<ll>nums;
vector<ll>solutions;



void rec(ll sum, int pos)
{
    //cerr<<"calling "<<sum<<" "<<pos<<endl;
    if(pos >= SZ(nums))
    {
        solutions.pb(sum);
        return;
    }
    else
    {
        rec(sum, pos+1);
        rec(sum + nums[pos], pos+1);
    }
}

void solve()
{
    solutions.clear();
    rec(0, 0);
    sort(all(solutions));


    ll S, T, E = -1;

    loop(i, SZ(solutions))
    {
        ll e = solutions[i] + D - 1;

        int low = i, high = SZ(solutions) - 1, mid;

        while(low <= high)
        {
            mid = (low + high)/2;

            if(solutions[mid] <= e)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        if(low - i > E)
        {
            S = i;
            T = e;
            E = low - i;
        }
    }

    pf("%lld %lld %lld\n", S, T, E);


}


int main()
{
    ll x;
    while(sf("%d %d", &N, &M) == 2)
    {
        nums.clear();

        loop(i, N)
        {
            sf("%lld", &x);
            nums.pb(x);
        }

        loop(i, M)
        {
            sf("%lld", &x);
            nums.pb(-x);
        }

        sf("%lld", &D);

        solve();
    }

}
