#include <bits/stdc++.h>
using namespace std;

int main()
{
   // using STL
    stack<int> s;

    // push
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    //pop
    s.pop();

    //peek/top
    cout<<"top of the stack : "<<s.top()<<endl;

    // traverse
    while (!s.empty())
    {
        cout << s.top()<<" ";
        s.pop();
    }*/
}
