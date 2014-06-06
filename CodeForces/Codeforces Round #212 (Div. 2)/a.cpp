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

bool cnt[8][8];
string board[8];
int dist[8][8];

int x[] = {2, 2, -2, -2};
int y[] = {2, -2, 2, -2};

bool isValid(int i, int j)
{
    return -1 < i && i< 8 && -1 < j && j < 8;
}

bool search(int i, int j)
{
    //debug(i, j);
    //pf("dist[%d][%d] = %d\n", i, j, dist[i][j]);

    cnt[i][j] = true;
    if(board[i][j] == 'K')
    {
        return dist[i][j] % 2 == 0;
    }
    else
    {
        bool res = false;
        loop(k, 4)
        {
            int xx, yy;
            xx = i + x[k];
            yy = j + y[k];
            if(isValid(xx, yy) && cnt[xx][yy] == false)
            {
                dist[xx][yy] = dist[i][j] + 1;
                //pf("setting dist[%d][%d] = %d\n", xx,yy, dist[xx][yy]);
                res = res | search(xx, yy);
            }

        }
        return res;
    }

}



int main()
{

    #ifdef hasibpc
        read("input.in");
    #endif
    int kases;

    scanf("%d", &kases);
    bool result;


    while(kases--)
    {
        cin.ignore();
        loop(i, 8)
        {
            getline(cin, board[i]);
        }




        mem(cnt, 0);
        //mem(dist, 0);

        loop(i, 8)
        {
            loop(j, 8)
            {
                if(board[i][j] == 'K')
                {
                    dist[i][j] = 0;
                    board[i][j] = '.';
                    result = search(i, j);
                    goto hell;
                }
            }
        }
        hell:
            if(result)
            {
                cout<<"YES"<<endl;
            }
            else
            {
                cout<<"NO"<<endl;
            }


    }



}
