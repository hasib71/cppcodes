
/*
Bismillahir Rahmanir Rahim
Coder: Ahmad Faiyaz
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>


# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)

#define EPS 1e-11
#define inf 1234567891
#define LL long long

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))

#define pb push_back
#define FORIT(i,m) for(__typeof((m).begin()) i=(m).begin();i!=(m).end();i++)
#define pii pair<int,int>
#define UNIQUE(c) (c).resize( unique( all(c) ) - (c).begin() )

#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
#define CIN ios_base::sync_with_stdio(0);
///int rrr[]={1,0,-1,0};int ccc[]={0,1,0,-1}; //4 Direction
///int rrr[]={1,1,0,-1,-1,-1,0,1};int ccc[]={0,1,1,1,0,-1,-1,-1};//8 direction
///int rrr[]={2,1,-1,-2,-2,-1,1,2};int ccc[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
///int rrr[]={2,1,-1,-2,-1,1};int ccc[]={0,1,1,0,-1,-1}; //Hexagonal Direction
///int month[]={31,28,31,30,31,30,31,31,30,31,30,31}; //month

using namespace std;

#define MAX 20
char grid [MAX][MAX];

int row [MAX][MAX]; // row te value ta ase kina
int col [MAX][MAX]; // column e value ta ase kina
int square [MAX][MAX]; // ekta square e kara ase

int squareNum [MAX][MAX];


int getSquareNum(int r, int c){

    if(squareNum[r][c] > -1){
        return squareNum[r][c];
    }
    int rr = r, cc = c;
    r/=4;

    c/= 4;

    r *= 4;

    return squareNum[rr][cc] = r + c;
}

bool isValid(int r, int c, int v){
    int sqNum = getSquareNum(r, c);

   // cout<<" "<<squareNum[sqNum][v]<<" "<<row[r][v]<<" "<<col[c][v]<<endl;;
    return (!square[sqNum][v] && !row[r][v] && !col[c][v]);
}


pii getBest(){
    pii ret = pii(-1, -1);
    int bst = inf;
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            if(grid[i][j] != '.') continue;
            int cnt = 0;
            for(int k=1;k<=16;k++){
                if(isValid(i, j, k)){
                    cnt++;
                }
            }

            //cout<<i<<" "<<j<<" "<<cnt<<endl;
            if(cnt < bst){
                ret = pii(i, j);
                bst = cnt;
            }
        }
    }

   // cout<<bst<<" "<<ret.first<<" "<<ret.second<<endl;
    return ret;
}



bool solve(){
    pii ret = getBest();

    if(ret == pii(-1, -1)) return true;

    int r = ret.first;
    int c = ret.second;

    int sqNum = getSquareNum(r, c);
    for(int i=1;i<=16;i++){
        if(isValid(r, c, i) == false) continue;
        square[sqNum][i] = 1;
        row[r][i] = 1;
        col[c][i] = 1;
        grid[r][c] = char('A' + i - 1);
        if(solve()){
            return true;
        }
        square[sqNum][i] = 0;
        row[r][i] = 0;
        col[c][i] = 0;
        grid[r][c] = '.';
    }

    return false;
}


int main(){
    #ifdef hasibpc
        freopen("input.txt", "r", stdin);
    #endif


    ms(squareNum, -1);

    int t, chk = 1;

    //scanf("%d", &t);

    t = 1;

    while(t--){
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++){
                row[i][j] = 0;
                col[i][j] = 0;
                square[i][j] = 0;
            }
        }
        for(int i=0;i<16;i++){
            scanf("%s",grid[i]);

            for(int j=0;j<16;j++){
                if(grid[i][j] == '-')
                {
                        grid[i][j] = '.';
                        continue;
                }
                int num = grid[i][j] - 'A' + 1;
                row[i][num] = 1;
                col[j][num] = 1;
                square[getSquareNum(i, j)][num] = 1;
            }
        }
        solve();
        //getBest();
        for(int i=0;i<16;i++){
            for(int j=0;j<16;j++){
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
