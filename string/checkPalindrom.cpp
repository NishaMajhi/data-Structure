// only accept a-z A-Z 0-9 ignore other cahacters
#include <iostream>
using namespace std;

int validInput(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return 1;
    else
        return 0;
}

char toLower(char ch)
{
    if((ch>='a' && ch<='z') ||(ch>='0' && ch<='9'))
      return ch;
    else{
        char t = ch - 'A' + 'a';
        return t;
    }
}

bool palindrom(string a,int n)
{
    int i = 0;
    int e = n-1;
    while(i<e){
        if(a[i]!=a[e])
           return false;
        else
           i++;e--;
    }
    return true;
}

bool checkPalindrom(string s)
{
    int n = s.length();
    string temp="";

    //step 1 : check valid input
   for(int i=0;i<n;i++){
    if(validInput(s[i]))
       temp.push_back(s[i]);
   }
   //step 2 : convert into lower case
   for(int i=0;i<temp.length();i++){
    temp[i] = toLower(temp[i]);
   }

   //ste 3 : check palindrom
   return palindrom(temp,temp.length());
}
int main()
{
    string s;
    cout<<"enter a string : ";
    cin >> s;
    cout << s <<endl;
    cout << checkPalindrom(s);
    return 0;
}

/*
output------------
enter a string : na$ma*n
na$ma*n
1
*/
