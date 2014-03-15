#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<set>


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
#define dump(x) cout<<#x<<" = "<<x<<endl

using namespace std;

#define take(args...) asdf,args
#define debug(args...) asdfg,args; cout<<endl
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
struct ASDFG{
    template<typename T>
    ASDFG& operator,(vector<T> &v){
        pf("[");
        cout<<v[0];
        FOR(i, 1, SZ(v)){
            cout<<", "<<v[i];
        }
        pf("]");
        return *this;
    }

    template<typename T>
    ASDFG& operator,(T x) {
        cout<<x<<" ";
        return *this;
    }


}asdfg;



//Header ends here






int Ask(int i, int j)
{
    cout<<"Ask "<<i<<" "<<j<<endl;
    cout<<flush;
    int num;
    cin>>num;
    return num;
}

struct node{
    bool completed;
    node *left, *right;

    node()
    {
        this->completed  = 0;
    }
};


node *head;

int n;




#define MAXSZ 10
#define heapSZ 11


void rec(node *p, int pos, int num)
{
    if(pos == -1)
    {
        p->completed = true;
        return;
    }
    node *left, *right;
    left = p->left;
    right = p->right;

    if(left->completed)
    {
        rec(right, pos-1, num);
    }
    else if(right->completed)
    {
        rec(left, pos-1, num);
    }
    else
    {
        int k = Ask(num, pos);
        if(k == 0)
        {
            rec(left, pos-1, num);
        }
        else
        {
            rec(right, pos-1, num);
        }
    }

    if(left->completed && right->completed)
    {
        p->completed = true;
    }
}

void solve()
{

    cin>>n;

    for(int i=1; i<n; i++)
    {
        rec(head, 10, i);
    }
}

int find()
{
    node *p = head;
    vector<int>result;


    loop(i, 11)
    {
        //cerr<<i<<" done"<<endl;
        if(p->left->completed == false)
        {
            result.pb(0);
            p = p->left;
        }
        else
        {
            result.pb(1);
            p = p->right;
        }
    }



    //1debug(result);

    reverse(all(result));

    int nm = 0;


    loop(i, SZ(result))
    {
        nm = nm + result[i] * (1<<i);
    }


    return nm;

}





void freeNode(node *p, int pos)
{
    if(pos == 1<<11)
    {
        //cerr<<pos<<" is done"<<endl;
        p->completed = 1;
        return;
    }

    //cerr<<pos<<" = 0"<<endl;
    p->completed = 0;

    if(p->left != NULL)
    {
        freeNode(p->left, pos*2);
    }
    if(p->right != NULL)
    {
        freeNode(p->right, pos*2 + 1);
    }
}


void buildTree(node *p, int layer)
{
    if(layer == heapSZ)
    {
        return;
    }

    p->left = new node();
    p->right = new node();

    buildTree(p->left, layer+1);
    buildTree(p->right, layer+1);

}





int main()
{
    head = new node();
    buildTree(head, 0);
    int kases;
    cin>>kases;

    while(kases--)
    {
        freeNode(head, 1);
        solve();
        //cerr<<"asking done";
        cout<<"Answer "<<find()<<endl;
        cout<<flush;
    }


}
