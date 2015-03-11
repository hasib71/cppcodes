#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int main()
{
    int cases,caseno=0;
    double r;
    cin>>cases;
    double result;
    while(cases--)
    {
        cin>>r;
        result=r*r*(4-acos(-1));
        printf("Case %d: %.2lf\n", ++caseno, result);

    }
    return 0;
}
