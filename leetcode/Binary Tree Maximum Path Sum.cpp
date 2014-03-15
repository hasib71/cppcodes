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



/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


struct myTreeNode {

    int val;
    myTreeNode *left, *right;

    int leftMaxValue, rightMaxValue;
    myTreeNode()
    {
        left = NULL;
        right = NULL;
    }

};

#ifdef hasibpc
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif



class Solution {
public:

    int initTree(TreeNode *node, myTreeNode *myNode)
    {
        myNode->val = node->val;

        myNode->leftMaxValue = myNode->rightMaxValue = 0;

        if(node->left != NULL)
        {
            myNode->left = new myTreeNode();
            myNode->leftMaxValue = max( this->initTree(node->left, myNode->left), 0);
        }

        if(node->right != NULL)
        {
            myNode->right = new myTreeNode();
            myNode->rightMaxValue = max( this->initTree(node->right, myNode->right), 0 );
        }

        return myNode->val + max(myNode->leftMaxValue, myNode->rightMaxValue);


    }


    int findMax(myTreeNode *root)
    {
        int ret = root->leftMaxValue + root->rightMaxValue + root->val;

        if(root->left != NULL)
        {
            ret = max(ret, findMax(root->left));
        }

        if(root->right != NULL)
        {
            ret = max(ret, findMax(root->right));
        }
        return ret;
    }




    int maxPathSum(TreeNode *root)
    {
        myTreeNode *myRoot = new myTreeNode();
        this->initTree(root, myRoot);

        return findMax(myRoot);

    }
};



#ifdef hasibpc
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(-9);


    Solution ss;


    cout<<ss.maxPathSum(root);


}

#endif
