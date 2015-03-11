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

#define MAXX 27

int totalItems;
int priceList[MAXX];
int totalNeed;
int cntNeededItems[MAXX];
int menuItems[4];
int menuPrice;





void init()
{

}


int main()
{
    init();


    cin>>totalItems;

    for(int i=1; i<=totalItems; i++)
    {
        cin>>priceList[i];
    }

    cin>>menuPrice;

    loop(i, 4)
    {
        cin>>menuItems[i];
    }

    cin>>totalNeed;

    loop(i, totalNeed)
    {
        int id;
        cin>>id;
        cntNeededItems[id]++;
    }


    int result = 0;

    while(true)
    {
        int sum = 0;

        loop(i, 4)
        {
            if( cntNeededItems[ menuItems[i] ] > 0 )
            {
                sum += priceList[ menuItems[i] ];
            }
        }

        if(sum >= menuPrice)
        {
            result += menuPrice;
            loop(i, 4)
            {
                if( cntNeededItems[ menuItems[i] ] > 0 )
                {
                    //sum += priceList[ menuItems[i] ];
                    cntNeededItems[ menuItems[i] ]--;
                }
            }
        }
        else
        {
            break;
        }
    }



    loop(i, MAXX)
    {
        result += priceList[i] * cntNeededItems[i];
    }

    cout<<result<<endl;





    return 0;
}
