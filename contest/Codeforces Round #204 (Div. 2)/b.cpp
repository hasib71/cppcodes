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

#define MAXX 100004

int lastpos[MAXX];
int seq[MAXX];
int dist[MAXX];




int main()
{
	int n;
	take(n);
	loop(i, n)
	{
	    take(seq[i]);
	}

	mem(lastpos, -1);
	mem(dist, -1);
	int cnt = 0;

	for(int i=n-1; i>-1; i--)
	{
	    if(dist[ seq[i] ] == -1)
	    {
            dist[ seq[i] ] = 0;
            lastpos[seq[i]] = i;
            cnt++;
	    }
	    else if(dist[seq[i]] == 0)
	    {
	        dist[ seq[i] ] = lastpos[ seq[i] ] - i;
	        lastpos[seq[i]] = i;
	    }
	    else if( dist[ seq[i] ] == (lastpos[ seq[i] ] - i)  )
	    {
	        lastpos[ seq[i]]  = i;
	    }
	    else if(dist[seq[i]] != -2)
	    {
	        cnt--;
	        dist[seq[i]] = -2;
	    }
	}
    pf("%d\n", cnt);
	for(int i= 1; i<100001; i++)
	{
	    if(dist[i] >-1)
	    {
	        pf("%d %d\n", i, dist[i]);
	    }
	}







}

