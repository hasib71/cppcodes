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


#define MAXX 5000002

int phi[MAXX];
unsigned long long table[MAXX];

int main()
{
    for(int i=2; i<MAXX; i++)
    {
        if(phi[i] == 0)
        {
            phi[i] = i-1;

            for(int j=2*i; j<MAXX; j+=i)
            {
                if(phi[j] == 0)
                {
                    phi[j] = j;
                }
                phi[j] -= (phi[j]/i);
            }
        }
    }

    for(int i=2; i<MAXX; i++)
    {
        //table[i] = table[i-1] + (phi[i]*phi[i]); //overflow happes like shit

        table[i]=phi[i];
        table[i]*=phi[i];
        table[i]+=table[i-1];
    }




    int kases, kaseno = 0;
    scanf("%d", &kases);
    int a, b;


    while(kases--)
    {
        scanf("%d %d", &a, &b);
        pf("Case %d: %llu\n",++kaseno, table[b] - table[a-1] );
    }





    return 0;

}

