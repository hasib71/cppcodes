#include<iostream>
#include<cstdio>
using namespace std;

int mod(int x)
{
    if(x<0) return -x;
    return x;
}

int main()
{
    int x, y;
    int inp;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            scanf("%d", &inp );
            if(inp == 1)
            {
                x = i;
                y = j;
            }
        }
    }

    printf("%d", mod(x - 2) + mod(y - 2));

}
