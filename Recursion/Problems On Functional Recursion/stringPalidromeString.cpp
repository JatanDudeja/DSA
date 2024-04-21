#include <iostream>
using namespace std;

bool checkPalindrome(string s, int n, int i)
{
    if (i >= n / 2)
    {
        return true;
    }

    if (s[i] != s[n - i - 1])
    {
        return false;
    }

    return checkPalindrome(s, n, i + 1);
}

int main()
{
    int n = 5;
    string s = "123212";

    if (checkPalindrome(s, s.length(), 0))
    {
        cout << "Yipee its a Palindrome." << endl;
    }
    else
    {
        cout << "It's not a palindrome." << endl;
    }
    return 0;
}