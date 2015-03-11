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


class Point{
public:
        double x, y;

        Point operator-(Point A)
        {
            Point ret;
            ret.x = this->x - A.x;
            ret.y = this->y - A.y;
            return ret;
        }

};

double sq(double x)
{
    return x*x;
}


double dist(Point A, Point B)
{
    double ret = sq(A.x - B.x) + sq(A.y - B.y);
    return sqrt(ret);
}






void init()
{

}


int main()
{
    init();


    Point A, B, C;

    while(cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y)
    {
        double a, b, c;
        a = dist(A, B);
        b = dist(A, C);
        c = dist(B, C);

        double s = (a + b + c)/2.0;

        double area = sqrt( s * (s - a) * (s - b) * (s - c) );

        double R = (a*b*c)/(4*area);

        double AA, BB, CC, DD, PP, QQ, RR, h, k;

        AA = 2*(B.x - A.x);
        BB = 2*(B.y - A.y);
        CC = sq(B.x) + sq(B.y) - sq(A.x) - sq(A.y);

        PP = 2*(C.x - A.x);
        QQ = 2*(C.y - A.y);
        RR = sq(C.x) + sq(C.y) - sq(A.x) - sq(A.y);

        h = (CC*QQ - BB*RR)/(AA*QQ - BB*PP);
        k = (CC*PP - AA*RR)/(BB*PP - AA*QQ);

        pf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", h>=0? '-' : '+', abs(h), k>=0? '-': '+', abs(k), R);
        pf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n\n", h>=0 ? '-' : '+' , abs(2*h), k>=0? '-' : '+', abs(2*k), sq(h) + sq(k) >= sq(R) ? '+' : '-', abs(sq(h) + sq(k) - sq(R)) );

    }



    return 0;
}
