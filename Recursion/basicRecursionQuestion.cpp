#include <bits/stdc++.h>
using namespace std;
// find factorial using recursion
int factorial(int n)
{
    // base case
    if (n == 0 || n == 1)
        return 1;
    // Recursive relation
    return (n * factorial(n - 1));
}
// find 2's power using recursion
int power(int n)
{
    // base case
    if (n == 0)
        return 1;
    // Recursive relation
    return 2 * power(n - 1);
}
// print number till n
void printHead(int n)
{
    // base case
    if (n == 0)
        return;
    // Recursive relation
    printHead(n - 1);
    // processing
    cout << n << " ";
}
// print number from n to 1
void printTail(int n)
{
    // base case
    if (n == 0)
        return;
    // processing
    cout << n << " ";
    // Recursive relation
    printTail(n - 1);
}
int main()
{
    int a, b, c, d;
    cout << "enter a number for finding factorial : ";
    cin >> a;
    cout << "factorial of " << a << " is : " << factorial(a) << endl;
    cout << "enter a number to find 2's power of it : ";
    cin >> b;
    cout << "2's power of " << b << " is : " << power(b) << endl;
    cout << "enter a number  that print 1 to n : ";
    cin >> c;
    printHead(c);
    cout << endl;
    cout << "enter a number that print n to 1 : ";
    cin >> c;
    printTail(c);
    cout << endl;
    return 0;
}
/*
output:--------------
enter a number for finding factorial : 6
factorial of 6 is : 720
enter a number to find 2's power of it : 5
2's power of 5 is : 32
enter a number  that print 1 to n : 7
1 2 3 4 5 6 7 
enter a number that print n to 1 : 7
7 6 5 4 3 2 1 
*/
