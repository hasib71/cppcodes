/*
ID: himuhas1
TASK: kimbits
LANG :C++
*/


#include <fstream>


unsigned int size[33][33];


//Recursive
void solve (unsigned int N, unsigned int L, unsigned int I, std::ofstream *out)
{
    //If we've reached the end
    if (N == 0)
        return;


    //If it's smaller, then it'll be a 1
    if (size[N - 1][L] <= I)
    {
        *out << '1';
        solve (N - 1, L - 1, I - size[N - 1][L], out); //Solve for '1', with level and '1's --, and the index -size
    }
    else
    {
        *out << '0';
        solve (N - 1, L, I, out); //Solve for '0', with level --, and the orig index since size is bigger
    }
}


int main ()
{
    std::ifstream in;
    std::ofstream out;
    unsigned int N, L, I;
    int a, b;


    in.open ("kimbits.in");
    in >> N >> L >> I;
    in.close ();


    out.open ("kimbits.out");


    //Calculate size of different sets
    for (a = 0;a < 33;a++)
        size[0][a] = 1;


    for (a = 1;a < 33;a++)
    {
        for (b = 0;b < 33;b++)
        {
            //Else: size is the sum of the ones starting with 1 (b - 1) and the ones starting with 0 (b)
            if (b == 0)
                size[a][b] = 1;
            else
                size[a][b] = size[a - 1][b] + size[a - 1][b - 1];
        }
    }


    //Solve for I - 1
    solve (N, L, I - 1, &out);
    out << "\n";
    out.close ();


    return 0;
}

