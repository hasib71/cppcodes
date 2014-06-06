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

int used[32];
int N, M, P;


struct compare2{
    bool operator()(int a, int b)
    {
        if(used[a] == used[b])
        {
            return a > b;
        }
        else
        {
            return used[a] > used[b];
        }
    }
};


class myClass{
    public:
        vector<int>v;
        int pos;

        int top()
        {
            int maxUsed = -1;
            loop(i, SZ(v))
            {
                if(used[v[i]] > maxUsed)
                {
                    maxUsed = used[ v[i] ];
                    pos = i;
                }
                else if(used[v[i]] == maxUsed)
                {
                    if(v[pos] < v[i])
                    {
                        pos = i;
                    }
                }
            }
            return v[pos];
        }

        void push(int n)
        {
            v.pb(n);
        }

        void play()
        {
            for(vector<int>::iterator it=v.begin(); it != v.end(); it++)
            {
                used[*it]++;
            }
        }
};


int main()
{
    //read("input.in");
    //write("output.out");
    int kases, kaseno = 0;
    cin>>kases;

    while(kases--)
    {
        mem(used, 0);
        cin>>N>>M>>P;

        myClass teamA, teamB;
        priority_queue<int, vector<int>, compare2>benchA, benchB;

        for(int i=0; i<2*P; i+=2)
        {
            teamA.push(i);
            teamB.push(i+1);
        }

        for(int i=2*P; i<N; i+=2)
        {
            benchA.push(i);
        }

        for(int i=2*P+1; i<N; i+=2)
        {
            benchB.push(i);
        }


        for(int i=1; i<=M; i++)
        {
            teamA.play();
            teamB.play();

            benchA.push( teamA.top() );
            benchB.push( teamB.top() );

            teamA.v[teamA.pos] = benchA.top();
            teamB.v[teamB.pos] = benchB.top();

            benchA.pop();
            benchB.pop();

        }

        //debug(teamA.v);
        //debug(teamB.v);

        pair<pair<int, int>, string>allPlayers[32];
        int faltu;

        loop(i, N)
        {
            cin>>allPlayers[i].sc>>allPlayers[i].fr.fr>>allPlayers[i].fr.sc;
        }

        sort(allPlayers, allPlayers+N);
        reverse(allPlayers, allPlayers+N);


        vector<string>result;

        loop(i, P)
        {
            result.pb( allPlayers[ teamA.v[i] ].sc );
            result.pb( allPlayers[teamB.v[i] ].sc );
        }



        sort(all(result));
        pf("Case #%d:", ++kaseno);
        loop(i, 2*P)
        {
            cout<<" "<<result[i];
        }
        cout<<endl;
    }
    return 0;

}
