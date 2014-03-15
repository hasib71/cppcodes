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

#define MAXX 1000004





int cnt[MAXX];
paii elem[MAXX];


struct DATA{
    int worthPaoyaGeche;
    int Dhore;
};


DATA people[1005];





int main()
{

    int kases;
    int N, K;
    take(kases);
    int pos;

    while(kases--)
    {
        mem(people, 0);
        pos = 0;
        take(N, K);
        loop(i, N)
        {
            int a;
            take(a);
            people[i].Dhore = a;
            loop(j, a)
            {
                take(elem[pos].fr);
                elem[pos].sc = i;
                pos++;
            }
        }

        int res = 0;

        sort(elem, elem+pos);

        int cnt = 0, fullfilled = 0;



        loop(i, pos)
        {
            int &w = people[ elem[i].sc  ].worthPaoyaGeche;
            int &d = people[elem[i].sc].Dhore;


            //pf("for val=%d, w=%d, dhore=%d", elem[i].fr, w, d);

            //pf("\t\t cnt = %d\n", cnt);
            if(w > 0)
            {
                if(fullfilled < K && cnt + fullfilled >= K)
                {
                    res++;
                }
            }
            else if(w == 0)
            {
                if(fullfilled < K && cnt+1+fullfilled >= K)
                {
                    res++;
                }
            }

            //pf("   res = %d\n", res);



            w++;


            if(w == d)
            {
                fullfilled++;
                cnt--;
            }

            if(w == 1)
            {
                cnt++;
            }

        }


        cout<<res<<endl;

    }


}
