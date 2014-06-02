#include<bits/stdc++.h>
using namespace std;

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define mem(ara, val) memset(ara, val, sizeof(ara))
#define SZ(a) int(a.size())
#define fr first
#define sc second
#define pf printf
#define sf scanf
#define pb push_back
#define MP make_pair
#define paii pair<int, int>
#define dd double
#define ll long long
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)
#define INF (1<<29)
#define dump(x) cerr<<#x<<" = "<<x<<endl;
#define debug(args...) cerr<<args; cerr<<endl;


template<typename T>
ostream& operator<<(ostream &out, vector<T> &v)
{
    out<<"["; loop(i, SZ(v)) out<<", "<<v[i]; out<<" ]"; return out;
}


template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> p)
{
    out<<"( "<<p.fr<<", "<<p.sc<<" )"; return out;
}

template<typename T>
ostream& operator,(ostream &out, T &x )
{
    out<<x<<" "; return out;
}

//header ends here


#define MAXX 57

int main()
{
    int kases, kaseno = 0;

    int a[MAXX], b[MAXX], N;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d", &N);

        loop(i, N)
        {
            sf("%d", &a[i]);
        }

        loop(i, N)
        {
            sf("%d", &b[i]);
        }


        sort(a, a+N);
        sort(b, b+N);


        bool used[MAXX];
        mem(used, 0);



        int posA = 0, posB = 0;

        int result = 0;

        while(posA < N && posB < N)
        {
            if(a[posA] > b[posB])
            {
                used[posA] = true;
                posB++;
                result += 2;
            }
            posA++;
        }

        for(int i=N-1; i>-1; i--)
        {
            if(used[i] == false)
            {
                dump(a[i]);
                if(a[i] == b[posB])
                {

                    result++;
                }
                posB++;
            }
        }


        pf("Case %d: %d\n", ++kaseno, result);











    }















    return 0;
}










