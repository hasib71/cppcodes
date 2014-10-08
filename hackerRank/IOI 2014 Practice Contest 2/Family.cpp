#include<bits/stdc++.h>

using namespace std;


#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define fr first
#define sc second
#define MP make_pair
#define pb push_back
#define mem(a, v) memset(a, v, sizeof(a))
#define sf scanf
#define pf printf
#define SZ(a) int(a.size())
#define ll long long
#define pall pair<ll, ll>
#define paii pair<int,int>


#define d(a, sign, b) MP( a.fr sign b.fr, a.sc sign b.sc  )

pall A, B, C;


int main()
{
    cin>>A.fr>>A.sc>>B.fr>>B.sc>>C.fr>>C.sc;


    vector<pall>v;



    v.pb( d(A, +,  d(B, -, C))); //
    v.pb(d(C, + ,  d(B, -, A)) );
    v.pb(d(C, +,   d(A, -, B)));

    sort(v.begin(), v.end());

    loop(i, 3)
    {
        cout<<v[i].fr<<" "<<v[i].sc<<endl;
    }



}
