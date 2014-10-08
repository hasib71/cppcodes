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

#define f(A, sign, B) MP(A.fr sign B.fr, A.sc sign B.sc)
#define MAXX 2007

paii points[MAXX];
int N;


bool find(paii A)
{
    int low = 0, high = N-1, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(points[mid] < A)
        {
            low = mid + 1;
        }
        else if(points[mid] > A)
        {
            high = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    cin>>N;

    if(N <= 2)
    {
        cout<<4-N<<endl;
    }
    else
    {

        try{

            loop(i, N)
            {
                cin>>points[i].fr>>points[i].sc;
            }

            sort(points, points + N);

            bool ThirdPointFound=0;
            paii A, B, C, D, diff;

            loop(i, N)
            {
                for(int j=i+1; j<N;j++)
                {
                    A = points[i];
                    B = points[j];

                    diff = f(B, -, A);

                    C.fr = A.fr - diff.sc;
                    C.sc = A.sc + diff.fr;

                    D.fr = B.fr - diff.sc;
                    D.sc = B.sc + diff.fr;

                    if(find(C))
                    {
                        ThirdPointFound = true;
                        if(find(D))
                        {
                            //FourthPointFound = true;
                            throw 0;
                        }
                    }

                    C.fr = A.fr + diff.sc;
                    C.sc = A.sc - diff.fr;

                    D.fr = B.fr + diff.sc;
                    D.sc = B.sc - diff.fr;

                    if(find(C))
                    {
                        ThirdPointFound = true;
                        if(find(D))
                        {
                            throw 0;
                        }
                    }

                }
            }

            if(ThirdPointFound)
            {
                throw 1;
            }
            else
            {
                throw 2;
            }
        }catch(int i)
        {
            cout<<i<<endl;
        }
    }






}
