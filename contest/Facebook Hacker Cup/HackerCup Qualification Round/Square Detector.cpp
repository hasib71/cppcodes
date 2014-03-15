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

bool isEmpty(string &ss, int len)
{
    loop(i, len)
    {
        if(ss[i] == '#')
        {
            return false;
        }
    }
    return true;
}


int main()
{
    //read("input.in");
    //write("output.out");
    int kases, kaseno = 0;
    cin>>kases;

    string graph[21];


    while(kases--)
    {
        int n;
        cin>>n;

        loop(i, n)
        {
            cin>>graph[i];
        }

        int firstPos;

        loop(i, n)
        {
            if(isEmpty(graph[i], n) == false)
            {
                firstPos = i;
                break;
            }
        }


        bool possible = true;

        int changed = 0;
        int active = 0;

        for(int i=1; i<n; i++)
        {
            if(graph[firstPos][i] != graph[firstPos][i-1])
            {
                changed++;
            }

            if(graph[firstPos][i] == '#')
            {
                active++;
            }
        }

        if(changed > 2)
        {
            possible = false;
            goto result;
        }

        if(graph[firstPos][0] == '#')
        {
            active++;
        }

        int pos;
        active = active + firstPos;

        for(pos=firstPos+1; pos<active; pos++)
        {
            if(graph[pos] != graph[firstPos])
            {
                possible = false;
                goto result;
            }
        }

        for(; pos < n; pos++)
        {
            if(isEmpty(graph[pos], n) == false)
            {
                possible = false;
                goto result;
            }
        }









        result:
            if(possible)
            {
                pf("Case #%d: YES\n", ++kaseno);
            }
            else
            {
                pf("Case #%d: NO\n", ++kaseno);
            }




    }

}
