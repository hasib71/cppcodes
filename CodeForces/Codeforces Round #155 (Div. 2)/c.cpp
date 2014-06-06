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

int tCnt[100];
int cnt[100];
int countK()
{
    int k =0;
    for(int i='A'; i<='Z'; i++)
    {
        if(tCnt[i] < 0)
        {
            //cerr<<(char)i<<" should reduce "<<tCnt[i]<<" times"<<endl;
            k += cnt[i];
        }
    }
    //cerr<<"total place "<<k<<endl;
    return k;
}

int main()
{
    read("input.txt");
    write("output.txt");
    string ss, tt;
    cin>>ss>>tt;

    loop(i, SZ(tt))
    {
        tCnt[ tt[i] ]++;
        //cerr<<(int)tt[i]<<endl<<endl;
    }

    loop(i, SZ(ss))
    {
        tCnt[ ss[i] ]--;
        cnt[ss[i]]++;
    }

    vector<char>v;
    //int k = 0;

    loop(i, 100)
    {
        //dump(tCnt[i]);
        if(tCnt[i] > 0)
        {
            while(tCnt[i])
            {
                v.pb(i);
                tCnt[i]--;
            }
        }
    }

    sort(all(v));
    //debug(v);

    int pos = 0;

    loop(i, SZ(ss))
    {
        //k = countK();
        //debug(i, pos, k);
        //cnt[ss[i]]--;
        if(tCnt[ ss[i]] < 0)
        {
            //cerr<<"planning to give";
            //dump(-tCnt[ss[i]]); dump(cnt[ss[i]]);
            if(-tCnt[ss[i]] < cnt[ss[i]]-- && ss[i] < v[pos] )
            {
                //cerr<<"  oh no!!"<<endl;
                continue;
            }
            tCnt[ss[i]]++;
            ss[i] = v[pos++];
            //cerr<<" donating "<<ss[i]<<endl;
        }

    }
    //cerr<<(int)ss[2]<<endl;

    cout<<SZ(v)<<endl<<ss<<endl;





}
