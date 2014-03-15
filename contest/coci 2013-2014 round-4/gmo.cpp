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

#define MAXX 2002

char dnas[4] = {'A', 'C', 'G', 'T'};
int cost[4];

class determinate{
    public:
        int pos[4];


        void setLastCharPos(char ch, int p)
        {
            loop(i, 4)
            {
                if(dnas[i] == ch)
                {
                    pos[i] = p;
                }
            }
        }


        void setDeterminate(determinate &ob, char ch, int p)
        {
            loop(i, 4)
            {
                this->pos[i] =  ob.pos[i];
            }

            setLastCharPos(ch, p);
        }

        int getLastCharPos(char ch)
        {
            loop(i, 4)
            {
                if(dnas[i] == ch)
                {
                    return pos[i];
                }
            }
        }

};



string DNA, swineDNA;
determinate data[MAXX];
int comuCost[MAXX];



int main()
{

    cin>>DNA;
    cin>>swineDNA;
    loop(i, 4) cin>>cost[i];

    swineDNA = '0' + swineDNA+'0';

    comuCost[0] = 0;

    for(int i=1; i<SZ(swineDNA); i++)
    {
        comuCost[i] = comuCost[i-1];

        loop(j, 4)
        {
            if(swineDNA[i] == dnas[j])
            {
                comuCost[i] += cost[j];
                break;
            }
        }
    }

    int len = SZ(swineDNA);

    loop(i, 4)
        data[len-1].pos[i] = len - 1;

    for(int i=SZ(swineDNA) - 2; i>-1; i--)
    {
        data[i].setDeterminate(data[i+1], swineDNA[i], i);
    }


    int next;
    ll tempCost, minCost = (1<<29);

    loop(i, SZ(DNA))
    {
        tempCost = 0;

        int j = i, k = 1;
        while( k < len-1 && j < SZ(DNA)) ///////////////////// j.
        {
            next = data[k].getLastCharPos(DNA[j]);

            tempCost += comuCost[next-1] - comuCost[k-1];

            j++;

            k = next + 1;
        }

        if(k < len-1)
        {
            tempCost+= comuCost[len-1] - comuCost[k-1];
        }


        //dump(tempCost);

        minCost = min(minCost, tempCost);

    }


    cout<<minCost;




}

