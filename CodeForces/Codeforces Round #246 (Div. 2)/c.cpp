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


//Header ends here

#define MAXX 100007
#define stop return 0;


vector<int>v;
bool isPrime[MAXX];



void generatePrime()
{
    bool isPrime[MAXX];
    mem(isPrime, 1);

    v.pb(2);

    for(int i=3, sqroot = sqrt(MAXX) + 2; i< sqroot; i+=2)
    {
        if(isPrime[i])
        {
            for(int j = i*i; j<MAXX; j+= 2*i)
            {
                isPrime[j] = 0;
            }
        }
    }

    for(int i=3; i<MAXX; i+=2)
        if(isPrime[i])
            v.pb(i);
}


int getPrime(int n)
{
    int low =0, high = SZ(v) - 1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(v[mid] <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return v[high];
}




int main()
{
    generatePrime();


    int N;
    int pos[MAXX];
    int ara[MAXX];


    cin>>N;

    for(int i=1; i<=N; i++)
    {
        cin>>ara[i];
        pos[ ara[i] ] = i;
    }


    vector<paii>result;

    int A, Apos, B, Bpos;


    for(int i=1; i<=N; i++)
    {
        int dist = pos[i] - i;

        while(dist != 0)
        {
            //dump(dist);

            dist++;


            int prime = getPrime( dist ) - 1;

            //dump(prime);


            Bpos = pos[i];
            B = i;


            Apos = Bpos - prime;
            A = ara[Apos];


            result.pb(MP(Apos, Bpos));


            swap(A, B);
            //swap(Apos, Bpos);

            //dump(A); dump(Apos); dump(B); dump(Bpos);
            //stop


            pos[A] = Apos;
            pos[B] = Bpos;

            ara[Apos] = A;
            ara[Bpos] = B;


            dist = pos[i] - i;

        }
    }



    cout<<SZ(result)<<endl;

    loop(i, SZ(result))
    {
        cout<<result[i].fr<<" "<<result[i].sc<<endl;
    }








}
