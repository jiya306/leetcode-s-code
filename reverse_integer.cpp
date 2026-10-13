#include <iostream>
using namespace std;

int reverse(int x)
{
    int rev = 0;

    while (x != 0)
    {
        int digit = x % 10;

        if (rev > 214748364 || rev < -214748364)
            return 0;

        rev = rev * 10 + digit;

        x = x / 10;
    }

    return rev;
}

int main()
{
    int x;
    cin >> x;

    cout << reverse(x);

    return 0;
}