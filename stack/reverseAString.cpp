//Reverse a String using stack
#include<bits/stdc++.h>
using namespace std;

char *reverseString(char *str,int len)
{
    stack<char> st;
    for(int i=0;i<len;i++)
    {
        st.push(str[i]);
    }
    int i=0;
    while(!st.empty())
    {
        str[i]=st.top();
        st.pop();
        i++;
    }
    return str;
}

int main()
{
    int n;
    cout<<"enter size of string : ";
    cin>>n;
    char str1[n];
    cout<<"enter a string : ";
    cin>>str1; 
    cout<<"string is : "<<str1<<endl;
 
    int len = strlen(str1);
    cout<<"reverse string is : "<<reverseString(str1,len);
    return 0;
    
}

/*
output----
enter size of string : 10
enter a string : Nisha
string is : Nisha        
reverse string is : ahsiN
*/
