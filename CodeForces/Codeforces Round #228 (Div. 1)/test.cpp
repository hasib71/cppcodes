#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long k ;
    int len;
    cin>>k;
    //k = 1000000;
    len = pow(k, 0.2);
    k = k - pow(len, 5);
    cout<<k<<endl<<endl;
}
