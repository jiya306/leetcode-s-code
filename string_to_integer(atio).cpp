#include<iostream>
#include<string>
#include<climits>
using namespace std;

int myAtoi(string s)
{
    int i = 0, sign = 1;
    long long res = 0;

    while(i < s.length() && s[i] == ' ')
        i++;

    if(i < s.length() && (s[i] == '+' || s[i] == '-'))
    {
        if(s[i] == '-')
            sign = -1;

        i++;
    }

    while(i < s.length() && s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + (s[i] - '0');

        if(res * sign > INT_MAX)
            return INT_MAX;

        if(res * sign < INT_MIN)
            return INT_MIN;

        i++;
    }

    return res * sign;
}

int main()
{
    string s;

    cout << "Enter string: ";
    getline(cin, s);

    cout << "Integer: " << myAtoi(s);

    return 0;
}