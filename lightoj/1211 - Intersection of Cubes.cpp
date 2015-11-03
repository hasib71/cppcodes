/****************************************************************
   ▄█    █▄       ▄████████    ▄████████  ▄█  ▀█████████▄
  ███    ███     ███    ███   ███    ███ ███    ███    ███
  ███    ███     ███    ███   ███    █▀  ███   ███    ███
 ▄███▄▄▄▄███▄▄   ███    ███   ███        ███  ▄███▄▄▄██▀
▀▀███▀▀▀▀███▀  ▀███████████ ▀███████████ ███ ▀▀███▀▀▀██▄
  ███    ███     ███    ███          ███ ███    ███    ██▄
  ███    ███     ███    ███    ▄█    ███ ███    ███    ███
  ███    █▀      ███    █▀   ▄████████▀  █▀   ▄█████████▀
****************************************************************/



#include<bits/stdc++.h>


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

#define take(args...) asdf,args
#define dump(x) cerr<<#x<<" = "<<x<<endl
#define debug(args...) cerr,args; cerr<<endl;
using namespace std;


template<typename T>
ostream& operator<<(ostream& output, vector<T>&v)
{
    output<<"[ ";
    if(SZ(v))
    {
        output<<v[0];
    }
    FOR(i, 1, SZ(v))
    {
        output<<", "<<v[i];
    }
    output<<" ]";
    return output;
}

template<typename T1, typename T2>
ostream& operator<<(ostream& output, pair<T1, T2>&p)
{
    output<<"( "<<p.fr<<", "<<p.sc<<" )";
    return output;
}




template<typename T>
ostream& operator,(ostream& output, T x)
{
    output<<x<<" ";
    return output;
}



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



//Header ends here

#define MAXX 107
#define INF (1<<29)

struct Point{
    int x1, y1, z1, x2, y2, z2;
};


int n;
Point points[MAXX];




int main()
{
    Point *p;

    Point ret;



    int kases, kaseno = 0;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d", &n);

        loop(i, n)
        {
            p = &points[i];
            sf("%d %d %d %d %d %d", &(p->x1), &(p->y1), &(p->z1), &(p->x2), &(p->y2), &(p->z2) );
        }

        ret.x1 = ret.y1 = ret.z1 = 0;
        ret.x2 = ret.y2 = ret.z2 = INF;


        loop(i, n)
        {
            ret.x1 = max(ret.x1, points[i].x1);
            ret.x2 = min(ret.x2, points[i].x2);

            ret.y1 = max(ret.y1, points[i].y1);
            ret.y2 = min(ret.y2, points[i].y2);

            ret.z1 = max(ret.z1, points[i].z1);
            ret.z2 = min(ret.z2, points[i].z2);

        }

        ll res = 0;

        if(ret.x1 < ret.x2 && ret.y1 < ret.y2 && ret.z1 < ret.z2)
        {
            res = ((ll)(ret.x2 - ret.x1))*((ll)(ret.y2 - ret.y1))*((ll)(ret.z2 - ret.z1));
        }


        pf("Case %d: %lld\n", ++kaseno, res);



    }







    return 0;
}
