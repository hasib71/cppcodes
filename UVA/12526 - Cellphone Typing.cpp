/**
   __      __            ______             _________     __     ______
  |  |    |  |          /  __  \           /   _____ \   |  |   |   __  \
  |  |    |  |         /  /  \  \          |  |     \/   |  |   |  |  \  \
  |  |    |  |        /  /    \  \         |  |          |  |   |  |   \  \
  |  |____|  |       /  /######\  \        |  |______    |  |   |  |___*  /
  |   ____   |      /              \       |______   |   |  |   |   ___  X
  |  |    |  |     /  /##########\  \             |  |   |  |   |  |   *  \
  |  |    |  |    /  /            \  \            |  |   |  |   |  |   /  /
  |  |    |  |   /  /              \  \   /\______|  |   |  |   |  |__/  /
  |__|    |__|   \_/                \_/   \__________|   |__|   |_______/


**/



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

struct Node{
    bool endHere;
    Node *child[26];
    Node()
    {
        endHere = 0;
        loop(i, 26) child[i] = NULL;
    }
};

void insertString(string str, int pos, Node *cur)
{
    if(pos == SZ(str))
    {
        cur->endHere = true;
        return;
    }

    char ch = str[pos] - 'a';
    if(cur->child[ ch ] == NULL)
        cur->child[ch] = new Node();

    insertString(str, pos+1, cur->child[ch]);

}

double total;

void calcTotal(Node *cur, double cost)
{
    vector<int>v;
    loop(i, 26)
    {
        if(cur->child[i] != NULL)
        {
            v.pb(i);
        }
    }

    loop(i, SZ(v))
    {
        //cerr<<"node =>"<<char(v[i]+'a')<<endl;
        calcTotal(cur->child[ v[i] ], cost + (SZ(v) > 1 || cur->endHere));
    }

    if(cur->endHere)
    {
        //dump(cost);
        total += cost;
    }
    delete cur;
}


int main()
{
    int N;

    while(cin>>N)
    {
        Node *root = new Node();
        string ss;
        loop(i, N)
        {
            cin>>ss;
            insertString(ss, 0, root);
        }

       total = 0;

       int tmp = 0;

       loop(i, 26)
       {
           if(root->child[i] != NULL) tmp++;
       }

       if(tmp != 1) tmp = 0;

       calcTotal(root, tmp);

       pf("%.2lf\n", total/N);


    }

    return 0;


}
