#include<iostream>
using namespace std;

// convert in lower case
char toLower(char ch)
{
    if(ch>='a' && ch<='z')
      return ch;
    else{
        char t = ch - 'A' + 'a';
        return t;
    }
}
// convert in upper case
char toUpper(char ch)
{
    if(ch>='A' && ch<='Z')
      return ch;
    else{
        char t = ch - 'a' + 'A';
        return t;
    }
}
//get length
int getLength(char n[])
{
    int count = 0;
    for(int i=0;n[i]!='\0';i++){
        count++;
    }
    return count;
}
//reverse a char array
void reverse(char a[],int n)
{
    int i=0;
    int e = n-1;
    while(i<e){
        swap(a[i++],a[e--]);
    }
    
}
//palindrom without extra space
bool palindrom(char a[],int n)
{
    int i = 0;
    int e= n-1;
    while(i<e){
        if(a[i]!=a[e])
           return false;
        else
           i++;e--;
    }
    return true;
}

int main()
{
    cout<<"enter a  character array : ";
    char name[20];
    cin>>name;
    cout<<"entered character array is : "<<name<<endl;
    
    //get length
    int len = getLength(name);
    cout<<"length of "<<name<<" is : "<<len<<endl;

    //reverse 
   reverse(name,len);
   cout<<"reversed char array is : "<<name<<endl;

   //palindrom
   cout<<name<<" is palindrom or not : "<<palindrom(name,len)<<endl;

   //lower conversion
   cout<<"lower case : "<<toLower('a')<<endl;
   cout<<"lower case : "<<toLower('G')<<endl;

   //upper conversion
   cout<<"upper case : "<<toUpper('N')<<endl;
   cout<<"upper case : "<<toUpper('b')<<endl;

}
