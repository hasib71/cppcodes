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
//#define dd double
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

int monthList[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

#define digit(c) (c-'0')






int main()
{
    string ss;
    cin>>ss;
    map<int, int>mp;
    int ln = SZ(ss) - 9;
    loop(i, ln)
    {
        bool correct = true;

        loop(j, 10)
        {
            if(j == 2 || j == 5)
            {
                correct = (ss[i+j] == '-');
            }
            else
            {
                correct = (ss[i+j] != '-');
            }

            if(!correct) break;
        }


        if(correct)
        {
            int dd, mm, yyyy;
            dd =  digit(ss[i])*10 + digit(ss[i+1]);

            mm = digit(ss[i+3])*10 + digit(ss[i+4]);

            yyyy = digit(ss[i+6])*1000 + digit(ss[i+7])*100 + digit(ss[i+8])*10 + digit(ss[i+9]);

            if(2012 < yyyy && yyyy < 2016 && 0 < mm && mm < 13 && 0 < dd && dd <= monthList[mm])
            {
                mp[dd*1000000 + mm*10000 + yyyy]++;
            }
        }
    }

    int cnt = 0;
    int res;
    for(map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    {
        if(it->sc > cnt)
        {
            res = it->fr;
            cnt = it->sc;
        }
    }


    int dd, mm, yy;
    dd = (int(res/1000000));
    mm = ((int)res/10000)%100;
    yy = (res%10000);

    pf("%02d-%02d-%d", dd, mm, yy);



}

