// find power of any number  , any times times


/*
example 1:

enter number : 3400
three four zero zero 

*/


#include <bits/stdc++.h>
using namespace std;

// fast exponential
int myPow(int n, int p)
{
    // base case
    if (p == 0)
        return 1;

    // recursive call
    int ans = myPow(n, p / 2);

    // if answer is odd - e.g => 2^3 = 2^2(2*2) * 2^1
    if (p % 2 == 1)
        return 2 * ans * ans;

    // even e.g => 2^4 = (2^2)^2
    else
        return ans * ans;
}

int myPowFunc(int n)
{
    // base case
    if (n == 0)
        return 1;
    // recursive call
    int ans = 2 * myPowFunc(n - 1);
    return ans;
}

int main()
{
    int n, p;
    cout << "enter number and power : ";
    cin >> n >> p;
    int ans = myPow(n, p);
    cout << n << " ki power " << p << " = " << ans << endl;
}
