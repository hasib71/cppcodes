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

struct DATA{
    int remainder[3];
    int lazy;
    DATA()
    {
        mem(remainder, 0);
        lazy = 0;
    }

    DATA operator+(DATA x)
    {
        loop(i, 3)
        {
            x.remainder[i] += remainder[i];

        }
        return x;
    }
};

DATA sum[4*MAXX];

int n, q;




void update(int st, int ed, int i, int j, int idx, int val)
{
    //dump(idx);
    if(st == i && ed == j)
    {
        /*
        swap(sum[idx].remainderZero, sum[idx].remainderTwo);
        swap(sum[idx].remainderOne, sum[idx].remainderTwo);
        sum[idx].lazy++;
        */

        val = val % 3;

        if(val != 0)
        {
            for(int i=1; i > -1; i--)
            {
                swap(sum[idx].remainder[i], sum[idx].remainder[i+1]);
            }
        }
        if(val == 2)
        {
            for(int i=1; i > -1; i--)
            {
                swap(sum[idx].remainder[i], sum[idx].remainder[i+1]);
            }
        }

        sum[idx].lazy += val;



        return;

    }
    else
    {
        int l = idx*2;
        int r = l + 1;

        int mid = (st+ed)/2;

        if(sum[idx].lazy > 0)
        {
            update(st, mid, st, mid, l, sum[idx].lazy);
            update(mid+1, ed, mid+1, ed, r, sum[idx].lazy);
            sum[idx].lazy = 0;
        }




        if(j <= mid)
        {
            update(st, mid, i, j, l, 1);
        }
        else if(mid < i)
        {
            update(mid+1, ed, i, j, r, 1);
        }
        else
        {
            update(st, mid, i, mid, l, 1);
            update(mid+1, ed, mid+1, j, r, 1);
        }

        // sum[idx].remainderOne = sum[l].remainderOne + sum[r].remainderOne;
        // sum[idx].remainderTwo = sum[l].remainderTwo + sum[r].remainderTwo;

        loop(i, 3)
        {
            sum[idx].remainder[i] = sum[l].remainder[i] + sum[r].remainder[i];
        }
    }
}

int query(int st, int ed, int i, int j, int idx)
{
    if(st == i && ed == j)
    {
        return sum[idx].remainder[0];
    }
    else
    {
        int l = idx*2;
        int r = l + 1;
        int mid = (st + ed)/2;

        if(sum[idx].lazy > 0)
        {
            update(st, mid, st, mid, l, sum[idx].lazy);
            update(mid+1, ed, mid+1, ed, r, sum[idx].lazy);
            sum[idx].lazy = 0;
        }

        if(j <= mid)
        {
            return query(st, mid, i, j, l);
        }
        else if(mid < i)
        {
            return query(mid+1, ed, i, j, r);
        }
        else
        {
            return query(st, mid, i, mid, l) + query(mid+1, ed, mid+1, j, r);
        }
    }
}


void init(int st, int ed, int idx)
{
    sum[idx].lazy = 0;
    sum[idx].remainder[1] = sum[idx].remainder[2] = 0;
    if(st == ed)
    {
        sum[idx].remainder[0] = 1;
    }
    else
    {
        int l = idx*2;
        int r = l + 1;
        int mid = (st+ed)/2;

        init(st, mid, l);
        init(mid+1, ed, r);
        sum[idx].remainder[0] = sum[l].remainder[0] + sum[r].remainder[0];
    }



}



int main()
{
    int kases, kaseno = 0;

    int cmd, x, y;

    take(kases);

    while(kases--)
    {
        pf("Case %d:\n", ++kaseno);
        take(n, q);

        init(1, n, 1);

        loop(i, q)
        {
            //dump(i);
            take(cmd, x, y);

            x++;
            y++;

            if(cmd == 0)
            {
                update(1, n, x, y, 1, 1);
            }
            else
            {
                pf("%d\n", query(1, n, x, y, 1));
            }
        }
    }



}
