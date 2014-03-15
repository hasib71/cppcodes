/*
ID: himuhas1
TASK: ratios
LANG: C++
*/



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

int target[3], inp[3][3];
int temp[3];
int minSolution[5];


int main()
{
    #ifndef hasibpc
        read("ratios.in");
        write("ratios.out");
    #endif
    mem(minSolution, 0);
    minSolution[3] = (1<<29);
    loop(i, 3) take(target[i]);
    loop(i, 3) loop(j, 3) take(inp[i][j]);
    bool possible;
    loop(i, 100)
    {
        loop(j, 100)
        {
            loop(k, 100)
            {
                loop(l, 3)
                {
                    temp[l] = i*inp[0][l] + j*inp[1][l] + k*inp[2][l];
                }

                if(temp[0] % target[0] == 0)
                {
                    int mul = temp[0] / target[0];
                    if(target[1]*mul == temp[1] && target[2]*mul == temp[2] && i+j+k < minSolution[3] && i+j+k != 0)
                    {
                        minSolution[3] = i + j + k;
                        minSolution[0] = i;
                        minSolution[1] = j;
                        minSolution[2] = k;
                        minSolution[4] = mul;
                    }
                }
            }
        }
    }
    if(minSolution[0] == 0 && minSolution[1] == 0 && minSolution[2] == 0)
    {
        pf("NONE\n");
    }
    else
    {
        pf("%d %d %d %d\n", minSolution[0], minSolution[1], minSolution[2], minSolution[4]);
    }





    return 0;
}
