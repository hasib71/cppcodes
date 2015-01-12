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

#define MAXX 107

#define mypair pair<paii, int>

#define sum(a, b) MP(a.fr + b.fr, a.sc + b.sc)


int M, N;

char init[MAXX][MAXX];

char graph[4][MAXX][MAXX];

int dist[4][MAXX][MAXX];

char str[] = ">v<^";

map<char, int> mp;

paii dir[4];

paii source, goal;



int bfs()
{
    mypair u = MP(source, 0);

    mem(dist, -1);

    dist[0][u.fr.fr][u.fr.sc] = 0;

    queue<mypair>Q;

    Q.push(u);

    int ret = 0;

    while( ! Q.empty() )
    {
        u = Q.front(); Q.pop();

        if(goal == u.fr)
        {
            ret = dist[u.sc][u.fr.fr][u.fr.sc];
            break;
        }

        mypair v;

        loop(i, 4)
        {
            v.fr = sum(u.fr, dir[i]);

            v.sc = ( u.sc + 1 ) % 4;

            if(0 <= v.fr.fr && v.fr.fr < M && 0 <= v.fr.sc && v.fr.sc < N )
            {
                if( dist[v.sc][v.fr.fr][v.fr.sc] == -1 && graph[v.sc][v.fr.fr][v.fr.sc] != '#' )
                {
                    dist[v.sc][v.fr.fr][v.fr.sc] = dist[u.sc][u.fr.fr][u.fr.sc] + 1;
                    Q.push(v);
                }
            }
        }
    }

    return ret;


}




int main()
{
    read("input");
    mp['>'] = 0;

    mp['v'] = 1;

    mp['<'] = 2;

    mp['^'] = 3;

    dir[0] = MP(0, 1);

    dir[1] = MP(1, 0);

    dir[2] = MP(0, -1);

    dir[3] = MP(-1, 0);



    int kases, kaseno  = 0;

    cin>>kases;

    while(kases--)
    {
        cin>>M>>N;

        loop(i, M)
        {
            cin>>init[i];
        }

        mem(graph, 0);

        loop(i, 4)
        {
            loop(p, M)
            {
                loop(q, N)
                {
                    int d = init[p][q];
                    if(mp.find(d) != mp.end())
                    {
                        d = (mp[d] + i) % 4;

                        int s = p, t = q;

                        do
                        {

                            graph[i][s][t] = '#';
                            //dump(graph[0][1][2]);

                            //dump(i);
                            //dump(s);
                            //dump(t);

                            s += dir[d].fr;
                            t += dir[d].sc;


                        }while(0 <= s && s < M && 0 <= t && t < N && init[s][t] != '#' &&  ( mp.find(init[s][t]) == mp.end() ) );
                    }
                    else if(d == '#')
                    {
                        graph[i][p][q] = '#';
                    }
                }
            }
        }
        //dump(graph[0][1][2]);

        loop(i, M)
        {
            loop(j, N)
            {
                if(init[i][j] == 'S')
                {
                    source = MP(i, j);
                }
                else if(init[i][j] == 'G')
                {
                    goal = MP(i, j);
                }
            }
        }

        int ret = bfs();

        pf("Case #%d: ", ++kaseno);
        if(ret == 0)
        {
            cout<<"impossible"<<endl;
        }
        else
        {
            cout<<ret<<endl;
        }
    }

}
