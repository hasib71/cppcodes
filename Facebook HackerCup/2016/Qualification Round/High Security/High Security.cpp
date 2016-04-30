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


#define MAXX 1007

int N;

char grid[2][MAXX];


int solve()
{
    int cnt = 0;



    for(int cc=0; cc < 2; cc++)
    {
        loop(i, N)
        {
            if(grid[cc][i] == '.')
            {
                if( ( (i==0) || (grid[cc][i-1] == 'X') ) && ( (i==(N-1)) || (grid[cc][i+1] == 'X') ) )
                {

                    cnt++;

                    grid[cc][i] = 'X';



                    int tt = cc ^ 1;

                    if(grid[tt][i] == '.')
                    {
                        grid[tt][i] = 'X';

                        for(int j=i+1; j<N; j++)
                        {
                            if(grid[tt][j] == '.')
                            {
                                grid[tt][j] = 'X';
                            }
                            else
                            {
                                break;
                            }
                        }


                        for(int j=i-1; j>=0; j--)
                        {
                            if(grid[tt][j] == '.')
                            {
                                grid[tt][j] = 'X';
                            }
                            else
                            {
                                break;
                            }
                        }


                    }



                }
            }
        }
    }


    for(int cc=0; cc<2; cc++)
    {
        loop(i, N)
        {

            if(grid[cc][i] == '.')
            {
                cnt++;

                while(i < N)
                {
                    if(grid[cc][i] == '.')
                    {
                        grid[cc][i] = 'X';
                    }
                    else
                    {
                        break;
                    }

                    i++;
                }
            }


        }
    }

    return cnt;





}



int main()
{

    #ifdef hasibpc
        read("inputB.txt");
        write("outputB.txt");
    #endif // hasibpc


    int kases, kaseno = 0;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d", &N);


        sf("%s", grid[0]);
        sf("%s", grid[1]);



        pf("Case #%d: %d\n", ++kaseno, solve());
    }



    return 0;
}
