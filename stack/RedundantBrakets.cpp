//------find Redundant brakets are there are not------
//Redundant Brakets - extra brakets 
//e.g: (1) ((a+b)) - redundant braket are there
//e.g: (2) (a+(b+c)) - there are no redundant brakets

#include <bits/stdc++.h>
using namespace std;

bool reduntantBrakets(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);

        else
        {
            if (ch == ')')
            {
                bool isRedundant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isRedundant = false;
                    }
                    st.pop();
                }

                if (isRedundant == true)
                    return true;

                st.pop();
            }
        }
    }
    return false;
}

int main()
{
    string s;
    cout << "enter a string : ";
    cin >> s;
    if (reduntantBrakets(s))
        cout << "there is  reduntant braket" << endl;
    else
        cout << "there is  no reduntant brakets" << endl;

    return 0;
}
/*
output-----
enter a string : ((a+b))
there is  reduntant braket

enter a string : (a+(b+c))
there is  no reduntant brakets
       

*/
