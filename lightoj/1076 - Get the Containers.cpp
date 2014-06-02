#include<bits/stdc++.h>

#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define mem(ara, val) memset(ara, val, sizeof(ara))
#define fr first
#define sc second
#define MP make_pair
#define SZ(a) int(a.size())
#define INF (1<<29)
#define pb push_back
#define ll long long
#define dd double
#define PI acos(-1.0)
#define paii pair<int, int>
#define sf scanf
#define pf printf
#define read(nm) freopen(nm, "r", stdin)
#define write(nm) freopen(nm, "w", stdout)


using namespace std;

template<typename T>
ostream& operator<<(ostream &out, vector<T> &v)
{
    out<<"[";   loop(i, SZ(v)) out<<v[i]<<", ";     out<<"]";    return out;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &out, pair<T1, T2> &p)
{
    out<<"("<<p.fr<<", "<<p.sc<<")";    return out;
}

template<typename T>
ostream& operator,(ostream &out, T &v )
{
    out<<v<<" ";    return out;
}

#define dump(x) cerr<<#x<<" = "<<x<<endl;



int main()
{
    int kases, kaseno = 0, n, m;
    sf("%d", &kases);

    while(kases--)
    {
        sf("%d %d", &n, &m);
        vector<ll>v;
        v.resize(n);

        ll low = 0, high = 0;

        loop(i, n)
        {
            sf("%lld", &v[i]);
            high += v[i];
        }

        while(low <= high)
        {
            ll mid = (low+high)/2;
            //dump(mid);

            int cnt = 0;
            ll tmp = mid + 1;
            loop(i, n)
            {
                if(tmp + v[i] > mid)
                {
                    if(v[i] > mid)
                    {
                        cnt = INF;
                        break;
                    }
                    cnt++;
                    tmp = v[i];
                }
                else
                {
                    tmp += v[i];
                }
            }

            if(cnt <=m )
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        pf("Case %d: %lld\n", ++kaseno, low);

    }

}
