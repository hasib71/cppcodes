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

#define dump(x) //cerr<<#x<<" = "<<x<<endl
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

#define MAXLEN 100007

struct data{
    ll endsHere;
    data *child[52];
    data()
    {
        endsHere = 0;
        loop(i, 52)
        {
            child[i] = NULL;
        }
    }
};

data *head;

void addString(char *str)
{
    int len = strlen(str);
    loop(i, len)
    {
        if('a' <= str[i] && str[i] <= 'z')
            str[i] = str[i] - 'a';
        else
            str[i] = str[i] - 'A' + 26;
    }


    if(str+1 < str+len-1)
        sort(str+1, str+len-1);

    data *curnode = head;

    loop(i, len)
    {
        int j = str[i];

        if(curnode->child[j] == NULL)
            curnode->child[j] = new data();
        curnode = curnode->child[j];
    }

    curnode->endsHere++;
}

ll find(string str_real)
{
    char str[MAXLEN];

    loop(i, SZ(str_real))
    {
        if('a' <= str_real[i] && str_real[i] <= 'z')
            str[i] = str_real[i] - 'a';
        else
            str[i] = str_real[i] - 'A' + 26;
    }

    data *curNode = head;

    int len = SZ(str_real);

    dump(len);

    if(str+1 < str+len-1)
        sort(str+1, str+len-1);
    dump("and i finished sorting");

    loop(i, len)
    {
        int j = str[i];
        if(curNode->child[j] == NULL)
        {
            return 0;
        }
        curNode = curNode->child[j];
    }
    return curNode->endsHere;
}

void clear(data *node)
{
    loop(i, 52)
    {
        if(node->child[i] != NULL)
            clear(node->child[i]);
    }
    delete node;
}

int main()
{
    #ifdef hasibpc
        read("input");
    #endif // hasibpc
    int kases, kaseno = 0;

    char str[MAXLEN];

    sf("%d", &kases);

    while(kases--)
    {
        pf("Case %d:\n", ++kaseno);
        int n;

        sf("%d", &n);

        head = new data();

        loop(adfadsfasdfadsfasf, n)
        {
            sf("%s", str);

            addString(str);
        }

        int m;

        sf("%d", &m);

        cin.ignore();

        loop(dfajfj, m)
        {
            ll result = 1;
            stringstream strstream;
            string ss;
            getline(cin, ss);
            strstream<<ss;

            dump(result);

            while(strstream.good())
            {
                strstream>>ss;
                dump(ss);
                result = result*find(ss);
                dump(result);
            }

            pf("%lld\n", result);
        }

        clear(head);


    }



}
