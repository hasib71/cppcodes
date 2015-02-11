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


#define MAXX 10007

char command[10];
int N, q;




struct DATA{
    int val;
    DATA *prev;
    DATA()
    {
        val = 0;
        prev = NULL;
    }
};


struct VENDOR{
    DATA *low, *high;
};



VENDOR v[MAXX];




int main()
{
    #ifdef hasibpc
        read("input");

    #endif // hasibpc
    int kases, kaseno = 0;

    take(kases);

    while(kases--)
    {
        pf("Case %d:\n", ++kaseno);
        loop(i, MAXX)
        {
            v[i].low = v[i].high = NULL;
        }

        take(N, q);
        while(q--)
        {
            scanf("%s", command);

            if(command[2] == 's')
            {
                //push command;
                int i, x;

                take(i, x);

                DATA *node = new DATA();

                node->val = x;

                node->prev = v[i].high;

                v[i].high = node;

                if(v[i].low == NULL)
                {
                    v[i].low = node;
                }


            }
            else if(command[2] == 't')
            { //put command

                int i, j;

                take(i, j);

                if(v[j].low != NULL)
                {
                    v[j].low->prev = v[i].high;
                    v[i].high = v[j].high;
                    v[j].low = v[j].high = NULL;
                }

            }
            else if(command[0] == 't')
            {
                //top command

                int i;

                take(i);

                if(v[i].high != NULL)
                {
                    pf("%d\n", v[i].high->val );
                }
                else
                {
                    pf("Empty!\n");
                }
            }
            else
            {
                // pop command

                int i;

                take(i);

                if(v[i].high != NULL)
                {
                     DATA *d = v[i].high;

                    v[i].high = v[i].high->prev;

                    delete d;
                }

            }
        }
    }




}
