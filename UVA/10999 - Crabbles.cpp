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
#define dump(x) //cerr<<#x<<" = "<<x<<endl
#define debug(args...) //cerr,args; cerr<<endl;
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
#define INF (1<<29)

struct DATA{
	DATA *child[26];
	bool endsHere;

	DATA()
	{
		loop(i, 26)
		{
			child[i] = NULL;
		}
		endsHere = false;
	}
};

int N;
DATA *root;

void addWord(string str, DATA *curNode)
{
	loop(i, SZ(str))
	{
		int k = str[i] - 'a';

		if(curNode->child[k] == NULL)
		{
			curNode->child[k] = new DATA();
		}

		curNode = curNode->child[k];
	}

	curNode->endsHere = true;
}




vector<int>v[26];

int ara[26];

int recurse(DATA *curNode)
{
	int mxResult = -INF;

	loop(i, 26)
	{
		if(curNode->child[i] != NULL)
		{
			if(ara[i] < SZ(v[i]))
			{
				ara[i]++;
				mxResult = max(mxResult, recurse(curNode->child[i]) + v[i][ ara[i] - 1 ] );
				ara[i]--;
			}
		}
	}

	if(mxResult < 0)
	{
		if(curNode->endsHere)
		{
			return 0;
		}
		else
		{
			return -INF;
		}
	}
	return mxResult;
}










int main()
{
	scanf("%d", &N);
	string str;
	root = new DATA();	

	loop(i, N)
	{
		cin>>str;
		addWord(str, root);
	}
	//cerr<<"I am herer"<<endl;


	int Play;

	scanf("%d", &Play);
	
	char ch;
	int point;
	
	loop(habijabi, Play)
	{
		scanf("%d", &N);

		loop(i, 26)
		{
			v[i].clear();
		}
		loop(i, N)
		{
			cin>>ch>>point;
			ch = ch - 'a';

			v[ch].pb(point);
		}
		loop(i, 26)
		{
			sort(all(v[i]));
			reverse(all(v[i]));
		}

		mem(ara, 0);

		int res = recurse(root);
		cout<<res<<endl;
	}

	return 0;
}
