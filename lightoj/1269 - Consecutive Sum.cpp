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

#define MAXX 50007
#define INF (1LL<<32)
#define BIT 30

int n; 
ll ara[MAXX];


struct DATA{
	//bool value;
	DATA *left, *right;
	DATA()
	{
		left = right = NULL;
	}

	~DATA()
	{
		//cout<<"Deleting!!!"<<endl;
		delete left;
		delete right;
	}
};

ll find(DATA *root, ll num, int cmd)
{
	DATA *cur = root;
	ll ret = 0;

	for(int i=BIT; i>=0; i--)
	{
		int on;
		int tmp = 0;

		if( (num & (1LL<<i) ) != 0 )
		{
			on = 1;
		}
		else
		{
			on = 0;
		}

		if( (on xor cmd) )
		{
			if(cur->right != NULL)
			{
				cur = cur->right;
				tmp = 1;
				////cout<<"I am editing"<<endl;
			}
			else if(cur->left != NULL)
			{
				cur = cur->left;
			}
			
		}
		else
		{
			if(cur->left != NULL)
			{
				cur = cur->left;
			}
			else if(cur->right != NULL)
			{
				cur = cur->right;
				tmp = 1;

				////cout<<"I am editing"<<endl;
			}
		}
		if( (on xor tmp) )
		{
			ret |= (1LL<<i);
		}
	}
	return ret;
}


void add(DATA *root, ll num)
{
	DATA *cur = root;
	for(int i=BIT; i>=0; i--)
	{
		if( (num & (1LL<<i)) != 0 )
		{
			if(cur->right == NULL)
			{
				cur->right = new DATA();
			}

			cur = cur->right;

		}
		else
		{
			if(cur->left == NULL)
			{
				cur->left = new DATA();
			}

			cur = cur->left;
		}
	}
}


int main()
{
	//cout<<(1 xor 1)<<endl;
	//cout<<(1LL<<32)<<endl;
	int kases, kaseno = 0;
	
	sf("%d", &kases);
	while(kases--)
	{

		sf("%d", &n);
		loop(i, n)
		{
			sf("%lld", &ara[i]);
		}
		vector<ll>v;
		ll now = 0;

		loop(i, n)
		{
			now = ara[i] xor now;
			v.pb(now);
		}

		ll minVal = INF;
		ll maxVal = -INF;
		
		DATA *root = new DATA();
		loop(i, SZ(v))
		{
			ll num = v[i];
			//dump(num);
			
			minVal = min(minVal, find(root, num, 0));
			maxVal = max(maxVal, find(root, num, 1));
			add(root, num);
			minVal = min(minVal, num);
			maxVal = max(maxVal, num);
			//dump(minVal);
			//dump(maxVal);

		}
		pf("Case %d: %lld %lld\n", ++kaseno, maxVal, minVal);
		delete root;

	}

    return 0;
}
