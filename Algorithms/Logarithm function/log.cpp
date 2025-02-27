#include <iostream>

using namespace std;

int logn(double n)
{
    int i = 0;
    while (n > 1)
    {
        n /= 2;
        i++;
    }
    return i;
}

int main()
{
    int x = 16;
    cout << "log(" << x << ") = " << logn(x) << endl;
    return 0;
}
