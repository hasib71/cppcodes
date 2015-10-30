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


#define MAXX 100007

ll comuSum[MAXX];

int N, Q;


struct DATA{
    ll incSum, norSum;
    ll lazy;

    int st, ed;

    DATA()
    {
        incSum = norSum = 0;
    }

    void Print()
    {
        cerr<<st<<" - "<<ed<<" -> "<<"incSum = "<<incSum<<", norSum = "<<norSum<<", lazy = "<<lazy<<endl;
    }

    void passLazyToChilds(DATA &A, DATA &B)
    {
        ll cnt;

        cnt = A.ed - A.st + 1;

        A.incSum += (comuSum[cnt] * this->lazy);
        A.norSum += (cnt * this->lazy);
        A.lazy += this->lazy;



        cnt = B.ed - B.st + 1;

        B.incSum += (comuSum[cnt] * this->lazy);
        B.norSum += (cnt * this->lazy);
        B.lazy += this->lazy;



        this->lazy = 0;
    }


    void fillByChilds(const DATA &A, const DATA &B)
    {
        ll cnt = A.ed - A.st + 1;

        this->incSum = A.incSum + B.incSum + B.norSum*cnt;
        this->norSum = A.norSum + B.norSum;

        this->lazy = 0;
    }

    DATA operator+( const DATA &other) const
    {
        DATA ret;
        ret.fillByChilds(*this, other);
        ret.st = this->st;
        ret.ed = other.ed;
        return ret;
    }


};

DATA sum[4*MAXX];





void update(int idx, int i, int j, ll w)
{
    if(sum[idx].st == i && sum[idx].ed == j)
    {
        ll cnt = sum[idx].ed - sum[idx].st + 1;

        sum[idx].incSum += ( comuSum[cnt] * w );

        sum[idx].norSum += ( cnt * w );

        sum[idx].lazy += w;
    }
    else
    {
        int l = idx*2;
        int r = l + 1;

        int mid = (sum[idx].st + sum[idx].ed) / 2;


        sum[idx].passLazyToChilds(sum[l], sum[r]);

        if(j <= mid)
        {
            update(l, i, j, w);
        }
        else if(mid < i)
        {
            update(r, i, j, w);
        }
        else
        {
            update(l, i, mid, w);
            update(r, mid+1, j, w);
        }

        sum[idx].fillByChilds(sum[l], sum[r]);

    }
}


DATA query(int idx, int i, int j)
{
    //debug(i, j);

    DATA ret;

    if(sum[idx].st == i && sum[idx].ed == j)
    {
        ret = sum[idx];
    }
    else
    {
        int l = idx*2;
        int r = l + 1;
        int mid = (sum[idx].st + sum[idx].ed) / 2;

        sum[idx].passLazyToChilds(sum[l], sum[r]);

        if(j <= mid)
        {
            ret = query(l, i, j);
        }
        else if(mid < i)
        {
            ret = query(r, i, j);
        }
        else
        {
            ret = query(l, i, mid) + query(r, mid+1, j);
        }
    }

    //cerr<<" for "<<idx<<"  ";
    //ret.Print();

    return ret;
}


void constructSegmentTree(int idx, int st, int ed)
{
    sum[idx].st = st;
    sum[idx].ed = ed;
    sum[idx].lazy = 0;


    if(st != ed)
    {
        int l = idx*2;
        int r = l + 1;
        int mid = (st + ed)/2;

        constructSegmentTree(l, st, mid);
        constructSegmentTree(r, mid+1, ed);

        sum[idx].fillByChilds(sum[l], sum[r]);
    }
    else
    {
        sum[idx].incSum = 100;
        sum[idx].norSum = 100;
        sum[idx].lazy = 0;
    }
}




void init()
{
    comuSum[0] = 0;
    for(ll i = 1; i<MAXX; i++)
    {
        comuSum[i] = comuSum[i-1] + i;
    }

}

int main()
{
    //read("input.txt");
    init();



    int a, b, w;

    char str[100];

    int kases, kaseno = 0;

    sf("%d", &kases);

    while(kases--)
    {
        pf("Case %d:\n", ++kaseno);
        sf("%d %d", &N, &Q);

        constructSegmentTree(1, 1, N);

        while(Q--)
        {
            sf("%s", str);
            if(str[0] == 'c')
            {
                /// change (i, j, w)

                sf("%d %d %d", &a, &b, &w);

                update(1, a, b, w);

            }
            else
            {
                /// query (i, j)

                sf("%d %d", &a, &b);
                DATA ret = query(1, a, b);
                //dump(ret.incSum);
                pf("%lld\n", ret.incSum);

            }
        }
    }



    return 0;
}
