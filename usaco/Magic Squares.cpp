/*
ID: himuhas1
TASK: msquare
LANG: C++
*/



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
map<string, string>nodes;


void transformA(string &s)
{
    loop(i, 4)
    {
        swap(s[i], s[7-i]);
    }
}

void transformB(string &s)
{
    loop(i, 3)
    {
        swap(s[i], s[3]);
        swap(s[7-i], s[4]);
    }
}

void transformC(string &s)
{
    swap(s[1], s[6]);
    swap(s[5], s[6]);
    swap(s[2], s[5]);
}


int main()
{
    #ifndef hasibpc
        read("msquare.in");
        write("msquare.out");
    #endif

    string target;

    {
        char c;
        loop(i, 8)
        {
            scanf("%c", &c);
            cin.ignore();
            target.push_back(c);
        }
    }

    //dump(target);

    queue<string>Q;
    string current = "12345678";
    nodes[current] = "-";

    Q.push(current);
    string ss;
    string *ptr;


    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();

        //dump(current);

        ss = current;
        transformA(ss);
        //dump(ss);
        ptr = &nodes[ss];
        if((*ptr).size() == 0)
        {
            *ptr = current;
            if(*ptr == target) break;
            Q.push(ss);
        }




        ss = current;
        transformB(ss);
        //dump(ss);
        ptr = &nodes[ss];
        if((*ptr).size() == 0)
        {
            *ptr = current;
            if(*ptr == target) break;
            Q.push(ss);
        }



        ss = current;
        transformC(ss);
        //dump(ss);
        ptr = &nodes[ss];
        if((*ptr).size() == 0)
        {
            *ptr = current;
            if(*ptr == target) break;
            Q.push(ss);
        }
    }



    string result;
    //dump(*ptr);

    while(target != "12345678")
    {
        ptr = &nodes[target];

        if((*ptr)[0] == target[7])
        {
            result.pb('A');
        }
        else if((*ptr)[0] == target[0])
        {
            result.pb('C');
        }
        else
        {
            result.pb('B');
        }

        target = *ptr;
    }

    reverse(all(result));
    pf("%d\n", SZ(result));
    cout<<result<<endl;




    return 0;
}
