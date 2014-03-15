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

#define MAXX 100004

int comu[11][MAXX];

char str[MAXX];

int n, k, w;


int main()
{

    take(n, k, w);

    cin>>(str+1);




    for(int i=1; i<=k; i++)
    {
        for(int j=i; j<=n; j++)
        {
            if( (j-i+1)%k == 0 )
            {
                if(str[j] == '0')
                {
                    comu[i][j] = comu[i][j-1] + 1;
                    //pf("\tcomu[%d][%d] = %d\n", i, j, comu[i][j]);
                }
                else
                {
                    comu[i][j] = comu[i][j-1];
                }
            }
            else
            {
                if(str[j] == '1')
                {

                    comu[i][j] = comu[i][j-1] +1 ;
                    //pf("comu[%d][%d] = %d\n", i, j, comu[i][j]);
                }
                else
                {
                    comu[i][j] = comu[i][j-1];
                }
            }
        }
    }

    int l, r;

    int s;

    loop(p, w)
    {
        take(l, r);
        s = l%k;
        if(s == 0)
        {
            s = k;
        }

       // dump(s), dump(r), dump(l-1);
       // dump(comu[s][r]);

        cout<<comu[s][r] - comu[s][l-1]<<endl;
    }



}
