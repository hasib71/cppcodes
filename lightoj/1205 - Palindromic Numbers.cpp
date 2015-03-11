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



ll countPalindromeOfSize(int len)
{

    int halfLen = len/2;
    if((len%2) == 1)
    {
        halfLen++;
    }

    ll ret = 1;

    for(int i=0; i<halfLen; i++)
    {
        ret *= (ll)10;
    }
    //dump(len);
    //dump(ret);
    return ret;
}




ll countPalindromeTillThisPosition(string str)
{

    loop(i, SZ(str))
    {
        str[i] = str[i] - '0';
    }


    ll ret = 0;


    int len = SZ(str);

    int halfLen = len/2;

    if((len%2) == 1)
    {
        halfLen++;
    }

    for(int i=1; i<len; i++)
    {
        ret += (countPalindromeOfSize(i) / (ll)10)*(ll)9;
        //cerr<<"   ret = "<<ret<<endl;
    }

    //dump(ret);


    loop(i, halfLen)
    {
        if(i == 0)
        {
            ret += (str[i] - 1) * countPalindromeOfSize(len - 2*(i+1));   // -1 for ! zero
        }
        else
        {
            ret += (str[i]) * countPalindromeOfSize(len - 2*(i+1));
        }
    }


    bool flag = true;

    //
    {
        int i, j;
        i = halfLen - 1;
        j = i;

        if((len%2) == 0)
        {
            j++;
        }

        while(i>=0)
        {
            if(str[j] < str[i])
            {
                flag = false;
                break;
            }
            else if(str[j] > str[i])
            {
                break;
            }

            i--;
            j++;
        }
    }

    if(flag) ret++;

    return ret;


}


string toStr(ll num)
{
    if(num == 0)
    {
        return "0";
    }

    string str;

    while(num != 0)
    {
       str.pb( num%10 + '0');
       num /= 10;
    }

    reverse(all(str));

    return str;
}







void init()
{
    //cout<<countPalindromeOfSize(-3);
    //cout<<countPalindromeTillThisPosition("");
    //cout<<toStr(104);

    //read("input");
}


int main()
{
    init();

    int kases, kaseno = 0;

    ll a, b;

    string aa, bb;

    cin>>kases;

    while(kases--)
    {
        cin>>a>>b;

        if(a > b)
        {
            swap(a, b);
        }

        ll res = 0;

        if(a == 0)
        {
            res++;
        }
        else
        {
            a--;
        }

        aa = toStr(a);
        bb = toStr(b);


        res += countPalindromeTillThisPosition(bb) - countPalindromeTillThisPosition(aa);


        pf("Case %d: %lld\n", ++kaseno, res);
    }



    return 0;
}
