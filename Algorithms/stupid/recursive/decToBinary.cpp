#include <iostream>

using namespace std;

string findBinary(int decimal)
{
    if (decimal == 0)
    {
        return "";
    }
    else
    {
        return findBinary(decimal / 2) + to_string(decimal % 2);
    }
}

int sum(int n)
{
    if (n == 0)
        return 0;
    return n + sum(n - 1);
}

int sumN(int n)
{
    int result = 0;

    for (size_t i = 1; i <= n; i++)
    {
        result += i;
    }
    return result;
}

bool isPalR(string s)
{
    if (s.length() < 2)
        return true;
    if (s[0] == s[s.length() - 1])
        return isPalR(s.substr(1, s.length() - 2));
    return false;
}

bool isPal(string s)
{
    int i = 0, j = s.length() - 1;
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}



int main()
{
    // int decimal;
    // cout << "Enter a number: ";
    // cin >> decimal;

    // int result = sum(decimal);

    cout << "Asnwer: " << isPalR("racecar") << endl;

    return 0;
}