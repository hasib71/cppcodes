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

class node{
    public:
        int value;
        node *nextNode;
        node *prevNode;
        node()
        {
            nextNode = NULL;
            prevNode = NULL;
        }
};


bool possible(int m, int n)
{
    node *root  = new node();
    root->value = 0;

    node *curNode;
    curNode = root;


    for(int i=1; i<n; i++)
    {
        curNode->nextNode = new node();
        curNode->nextNode->prevNode = curNode;
        curNode->nextNode->value = i;
        curNode = curNode->nextNode;
    }

    curNode->nextNode = root;
    root->prevNode = curNode;

    curNode = root;


    node *tmp;


    while(curNode->nextNode != curNode)
    {
        tmp = curNode;

        curNode->prevNode->nextNode = curNode->nextNode;
        curNode->nextNode->prevNode = curNode->prevNode;

        loop(i, m)
        {
            curNode = curNode->nextNode;
        }

        delete tmp;
    }

    return curNode->value == 12;




}




int main()
{
    int n;

    while(cin>>n && n != 0)
    {
        for(int i=1; i<=n; i++)
        {
            if(possible(i, n))
            {
                cout<<i<<endl;
                break;
            }
        }
    }




}
