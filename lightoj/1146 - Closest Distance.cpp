/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



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





//Header ends here

#define point pair<double, double>

#define devide(A, B, m1, m2) MP( (m1*B.fr + m2*A.fr)/(m1+m2) , (m1*B.sc + m2*A.sc)/(m1+m2) )

#define EPS (1e-9)


template<typename T>
T sq(T x) { return x*x; }




point A, B, C, D;




double calcDistance(point A, point B)
{
    return sqrt( sq(A.fr - B.fr) + sq(A.sc - B.sc) );
}


double solve()
{

    int steps = 100;

    while(steps--)
    {
        point left_1 = devide(A, B, 1,2);
        point left_2 = devide(A, B, 2,1);

        point right_1 = devide(C, D, 1,2);
        point right_2 = devide(C, D, 2,1);



        double dist_1 = calcDistance(left_1, right_1);
        double dist_2 = calcDistance(left_2, right_2);

        //debug(left_1, right_1);
        //debug(dist_1);

        if(abs(dist_1 - dist_2) < EPS)
        {
            A = left_1;
            B = left_2;
            C = right_1;
            D = right_2;
        }
        else if(dist_1 > dist_2)
        {
            A = left_1;
            C = right_1;
        }
        else
        {
            B = left_2;
            D = right_2;
        }
    }

    //debug(A, B, C, D);


    return calcDistance( devide(A, B, 1,1), devide(C, D, 1,1) );



}





int main()
{




    int kases, kaseno = 0;

    cin>>kases;

    while(kases--)
    {
        cin>>A.fr>>A.sc>>B.fr>>B.sc>>C.fr>>C.sc>>D.fr>>D.sc;
        double dist = solve();
        pf("Case %d: %.7lf\n", ++kaseno, dist);
    }

    return 0;


}
