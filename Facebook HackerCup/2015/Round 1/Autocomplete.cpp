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


#define toInt(ch) int(ch - 'a')

struct DATA{
    DATA *child[27];
    int touched;
    DATA()
    {
        loop(i, 27)
        {
            child[i] = NULL;
            touched = 0;
        }
    }

};



int N;
DATA *head;


int addString(string str)
{
    int result = 0;

    DATA *curNode = head;

    loop(i, SZ(str))
    {
        int k = toInt(str[i]);
        if(curNode->child[k] == NULL)
        {
            curNode->child[k] = new DATA();
        }

        curNode = curNode->child[k];

        curNode->touched++;

        if(!result && (curNode->touched == 1))
        {
            result = i + 1;
        }
    }
    if(result == 0)
    {
        result = SZ(str);
    }
    return result;
}


void emptyTrie(DATA *curNode)
{
    loop(i, 27)
    {
        if(curNode->child[i] != NULL)
        {
            emptyTrie(curNode->child[i]);
        }
    }

    delete curNode;
}

int main()
{
    read("b.txt");
    int kases, kaseno = 0;

    string s;

    cin>>kases;

    while(kases--)
    {
        cin>>N;

        int sum = 0;

        head = new DATA();

        while(N--)
        {
            cin>>s;
            sum += addString(s);
        }
        pf("Case #%d: %d\n", ++kaseno, sum);
    }




}
