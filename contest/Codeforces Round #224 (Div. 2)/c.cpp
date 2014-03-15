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

#define MAXX 100002

int main()
{
    int n, seq[MAXX];
    map<int, int>diffs;


    take(n);

    loop(i, n)
    {
        take(seq[i]);
    }




    sort(seq, seq+n);


    if(n == 1)
    {
        cout<<-1<<endl;
    }
    else if(n == 2)
    {

        int dist = seq[1] -seq[0];

        if(dist == 0)
        {
            cout<<1<<endl<<seq[0]<<endl;
        }
        else
        {
            if(dist & 1)
            {
                cout<<2<<endl;
            }
            else
            {
                cout<<3<<endl;
            }


            cout<<seq[0] - dist;
            if((dist & 1) == 0)
            {
                cout<<" "<<seq[0]+dist/2;
            }

            cout<<" "<<seq[1]+dist<<endl;
        }


    }
    else
    {
        for(int i=1; i<n; i++)
        {
            diffs[ seq[i] - seq[i-1] ]++;
        }

        if(SZ(diffs) > 2)
        {
            cout<<0<<endl;

           // cerr<<"came";
        }
        else
        {
            int dist = diffs.begin()->first;

            if(diffs[dist] >= n-2)
            {
                if(SZ(diffs) == 2)
                {
                    for(int i=1; i<n; i++)
                    {
                        if(seq[i] != seq[i-1] + dist)
                        {
                            if(seq[i] - seq[i-1] == 2*dist)
                            {
                                cout<<1<<endl<<seq[i-1] +dist<<endl;
                            }
                            else
                            {
                                cout<<0<<endl;
                            }
                            break;
                        }
                    }

                }
                else if(SZ(diffs) == 1)
                {
                    if(seq[1] - seq[0] != 0)
                        cout<<2<<endl<<seq[0]-dist<<" "<<seq[n-1]+dist<<endl;
                    else
                        cout<<1<<endl<<seq[0];
                }
            }
            else
            {
                cout<<0<<endl;
            }
        }
    }






}
