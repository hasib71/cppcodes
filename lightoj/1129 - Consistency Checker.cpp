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
string str;

bool isPossible;

struct DATA {
    bool endHere;
    bool hasTrace;
    DATA *child[10];

    DATA()
    {
        endHere = false;
        hasTrace = false;
        loop(i, 10) child[i] = NULL;
    }
    ~DATA()
    {
        loop(i, 10)
        {
            if(child[i] != NULL)
                delete child[i];
        }
    }
};

void addString(string &str, DATA *curNode)
{
    if(!isPossible) return;

    loop(i, SZ(str))
    {
        curNode->hasTrace = true;

        str[i] = str[i] - '0';
        if(curNode->child[ str[i] ] == NULL)
            curNode->child[ str[i] ] = new DATA();
        curNode = curNode->child[ str[i] ];


        if(curNode->endHere)
        {
            isPossible = false;
            return;
        }
    }

    if(curNode->hasTrace)
        isPossible = false;

    curNode->endHere = true;
}



void init()
{

}




int main()
{


    init();

    int kases, kaseno = 0;

    sf("%d", &kases);

    while(kases--)
    {
        sf("%d", &N);

        DATA *head = new DATA();

        isPossible = true;

        loop(i, N)
        {
            cin>>str;
            addString(str, head);
            //dump(head);
        }

        delete head;
        if(isPossible)
        {
            pf("Case %d: YES\n", ++kaseno);
        }
        else
        {
            pf("Case %d: NO\n", ++kaseno);
        }
    }



    return 0;
}
