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
#define debug(args...) asdfg,args; cout<<endl
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
struct ASDFG{
    template<typename T>
    ASDFG& operator,(vector<T> &v){
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v)){
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }

    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }


}asdfg;



//Header ends here

string s;
int n, m;



int getType(string &s)
{
    if(s=="11") return 0;
    if(s=="10") return 1;
    if(s=="00") return 2;
}
int types[4];


#define MAXX 1004

int main()
{
    cin>>n>>m;
    int mot = 0;
    loop(i, n)
    {
        loop(j, m)
        {
            cin>>s;

            if(s[0] < s[1]) swap(s[0], s[1]);

            //dump(s);
            //dump(getType(s));
            mot += 2 - getType(s);
            types[getType(s)]++;
        }
    }

    loop(i, 3)
    {
        dump(types[i]);
    }

    int xm = 2*m;
    int gor = mot/xm;
    //2 dump(gor); dump(mot);
    if(mot%xm) gor++;

    vector<string>column[MAXX];

    loop(i, m)
    {
        int left, right;
        left= right = 0;

        while(left < gor && SZ(column[i]) < n )
        {
            if(types[0])
            {
                column[i].pb("11");
                left++;
                right++;
                types[0]--;
            }
            else if(types[1])
            {
                column[i].pb("10");
                left++;
                types[1]--;
            }
            else
            {
                break;
            }
        }

        while(right < gor && SZ(column[i]) < n)
        {
            if(types[1])
            {
                column[i].pb("01");
                right++;
                types[1]--;
            }
            else
            {
                break;
            }
        }
    }


    loop(i, m)
    {
        while(SZ(column[i]) < n)
        {
            column[i].pb("00");
        }
    }

    loop(i, n)
    {
        loop(j, m)
        {
            if(j) pf(" ");
            pf("%s", column[j][i].c_str());
        }
        pf("\n");
    }


}
