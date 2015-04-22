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






#define MAXX 100007
#define INF 10000000000000000

pair<ll, ll>stoppers[MAXX];
ll B;
ll p = -1, q=-1;

ll ret[MAXX];


int N;


int main()
{
    read("trapped.in");
    write("trapped.out");

    loop(i, MAXX)
    {
        ret[i] = INF;
    }


	sf("%lld %lld", &N, &B);

	loop(i, N)
	{
		sf("%lld %lld", &stoppers[i].sc, &stoppers[i].fr);
	}

	sort(stoppers, stoppers + N);


	if(B < stoppers[0].fr || stoppers[N-1].fr < B)
	{
		pf("-1\n");
	}
	else
	{
	    loop(i, N)
	    {
	        if(stoppers[i].fr > B)
            {
                p = i-1;
                q = i;
                break;
            }
	    }

        int i=p, j = q;

        while(i>=0 && j<N)
        {
            ll d = stoppers[j].fr - stoppers[i].fr;
            if(stoppers[j].sc < d)
            {
                j++;
            }
            else
            {
                if(stoppers[i].sc > d)
                {
                    ret[i] = 0;
                }
                else
                {
                    ret[i] = d - stoppers[i].sc;
                }
                i--;
            }
        }

        i = p, j = q;

        while(i>=0 && j<N)
        {
            ll d = stoppers[j].fr - stoppers[i].fr;

            if(stoppers[i].sc < d)
            {
                i--;
            }
            else
            {
                if(stoppers[j].sc > d)
                {
                    ret[j] = 0;
                }
                else
                {
                    ret[j] = d - stoppers[j].sc;
                }
                j++;
            }
        }

        ll minRet = INF;

        for(i=0; i<N; i++)
        {
            minRet = min(minRet, ret[i]);
        }

        //cout<<minRet<<endl;

        if(minRet == INF)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<minRet<<endl;
        }


	}



    return 0;
}
