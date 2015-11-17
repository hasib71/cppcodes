#include<bits/stdc++.h>
using namespace std;


int dayOfWeek(int d, int m, int y)
{
    /// 1 <= m <= 12,  y > 1752 (in the U.K.)
    /// returns 0 = Sunday, 1 = Monday, etc.
    /// cout<<dayOfWeek(14, 11, 2015)<<endl;
    /// Source: https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week

    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}




int main()
{
    cout<<dayOfWeek(14, 11, 2015)<<endl;
}
