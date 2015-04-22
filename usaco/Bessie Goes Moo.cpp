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




int N;

int mp[255][10];
int choice[255];


string ss = "BESIGOM";

ll result = 0;


void rec(int pos)
{
	if(pos >= 7)
	{
		//final case

		string first = "BESSIE";
		string second = "GOES";
		string third = "MOO";

		int fn, sn, tn;
		fn = sn = tn = 0;

		loop(i, SZ(first))
		{
			fn += choice[first[i]];

		}

		loop(i, SZ(second))
		{
			sn += choice[second[i]];
		}

		loop(i, SZ(third))
		{
			tn += choice[third[i]];
		}

		if((fn%7 == 0) || (sn%7 == 0) || (tn%7 ==0))
		{
			ll ret = 1;
			loop(i, 7)
			{
				ret *= mp[ss[i]][choice[ss[i]]];
			}

			result+= ret;
		}

		return;

	}

	loop(i, 7)
	{
		choice[ ss[pos] ] = i;
		rec(pos+1);
	}

}



int main()
{
    read("bgm.in");
    write("bgm.out");
	sf("%d", &N);
	char str[4];

	mem(mp, 0);

	int k;

	loop(i, N)
	{
		sf("%s %d", str, &k);
		mp[str[0]][k%7]++;
	}

	rec(0);

	cout<<result<<endl;





    return 0;
}
