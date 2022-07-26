// print spelling of given number

/*
example 1:

enter number : 435678
four three five six seven eight 


example 2:

enter number : 3400
three four zero zero 

*/

#include <bits/stdc++.h>
using namespace std;

void printSpell(int n, unordered_map<int, string> mp)
{
    // base condition
    if (n == 0)
        return;

    // recursive call
    printSpell(n / 10, mp);

    // processing/printing
    cout << mp[n % 10] << " ";
}

int main()
{
    int n;
    cout << "enter number : ";
    cin >> n;
    // map number with their spelling
    unordered_map<int, string> mp;
    mp[0] = "zero";
    mp[1] = "one";
    mp[2] = "two";
    mp[3] = "three";
    mp[4] = "four";
    mp[5] = "five";
    mp[6] = "six";
    mp[7] = "seven";
    mp[8] = "eight";
    mp[9] = "nine";

    printSpell(n, mp);

    return 0;
}
