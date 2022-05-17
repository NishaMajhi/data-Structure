//finonacci series --  0 1 1 2 3 5 8 13 21 ........

// term at nth position from Fibonacci series
#include <bits/stdc++.h>
using namespace std;

int fibonacciSeries(int n)
{

    if (n == 0 || n == 1)
        return n;
    return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
}

int main()
{
    int n;
    cout << "enter a position : ";
    cin >> n;
    cout << fibonacciSeries(n);
    return 0;
}

/*
output:------
enter a position : 4
3

enter a position : 8
21
*/


//Given a positive integer n, find the nth fibonacci number. Since the answer can be very large, return the answer modulo 1000000007.
class Solution {
  public:
    
    long long int nthFibonacci(long long int n){
        long long int t1=1,t2=1,ans=0;
        if(n==1 || n==2)
           return 1;
        for(int i=3;i<=n;i++)
        {
            ans = t1%1000000007 + t2%1000000007;
            ans = ans%1000000007;
            swap(t1,t2);
            t2=ans;
        }
        return ans;
    }
};


// Fibonacci series
#include <bits/stdc++.h>
using namespace std;

int fibonacciSeries(int n)
{

    if (n == 0 || n == 1)
        return n;
    return fibonacciSeries(n - 1) + fibonacciSeries(n - 2);
}

int main()
{
    int n;
    cout << "enter a position : ";
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cout << fibonacciSeries(i) << " ";
    }
    return 0;
}

/*
output:------------------
enter a position : 5
0 1 1 2 3 5

enter a position : 8
0 1 1 2 3 5 8 13 21
*/
