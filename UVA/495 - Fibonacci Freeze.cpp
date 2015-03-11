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

struct Math{
    string num;

    Math operator+(Math &other)
    {
        Math output;

        output.num = "";

        int len = max(SZ(num), SZ(other.num));


        int hate = 0;
        int sum;


        loop(i, len)
        {
            //dump(i);
            sum = hate;
            hate = 0;

            if(i < SZ(num))
            {
                sum += num[i];
            }

            if(i < SZ(other.num))
            {
                sum += other.num[i];
            }

            output.num.push_back(sum%10);
            hate = sum/10;

            //cerr<<"done"<<endl;
        }

        while(hate != 0)
        {
            output.num.push_back(hate % 10);
            hate /= 10;
        }

    return output;

    }


    void print()
    {
        for(int i = SZ(num)-1; i>-1; i--)
        {
            printf("%c", num[i] + '0');
        }
        printf("\n");
    }

};



#define MAXX 5007

int main()
{
    Math fib[MAXX];

    fib[0].num.push_back(0);
    fib[1].num.push_back(1);

    for(int i=2; i<MAXX; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }







    int n;

    while(cin>>n)
    {
        pf("The Fibonacci number for %d is ", n);
        fib[n].print();
    }




}

