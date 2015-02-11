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

#define MAXX 1007
#define maxofthree(a, b, c) max(max(a,b), c)

#define LEFT 0
#define RIGHT 1

char matrix[MAXX][MAXX];

int coromPositions[MAXX][2];

int rows, columns;




int main()
{
	loop(i, MAXX)
	{
		loop(j, MAXX)
		{
			matrix[i][j] = '.';
		}
	}


	cin>>rows>>columns;

	loop(i, rows)
	{
		cin>>matrix[i];
	}

	mem(coromPositions, -1);

	loop(i, rows)
	{
	    for(int j=0; j<columns; j++)
        {
            if(matrix[i][j] == 'J')
            {
                coromPositions[i][LEFT] = j;
                break;
            }
        }

        for(int j = columns-1; j>=0; j--)
        {
            if(matrix[i][j] == 'J')
            {
                coromPositions[i][RIGHT] = j;
                break;
            }
        }
	}

	int Direction = RIGHT;
	int curPos = 0;

	int result = 0;

	int last = rows - 1;

	for(int i=rows-1; i>=0; i--)
    {
        int r = coromPositions[i][RIGHT];
        int l = coromPositions[i][LEFT];


        int sum = 0;

        if(l != -1)
        {
            if(Direction == LEFT)
            {
                sum = abs(r-curPos) + (r-l);
            }
            else if(Direction == RIGHT)
            {
                sum = abs(l - curPos) + (r - l);
            }
        }

        //dump(sum);

        result += sum;

        if( (Direction == RIGHT && r != -1) )
        {
            curPos = r;
        }
        else if(Direction == LEFT && l != -1)
        {
            curPos = l;
        }
        Direction = Direction ^ 1;

        if(l != -1)
        {
            last = i;
        }
    }

   // dump(rows - 1 - last);




    cout<<result  + rows - 1 - last<<endl;









}
