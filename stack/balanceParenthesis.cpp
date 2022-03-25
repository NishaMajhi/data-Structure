
class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for(int i=0; i<x.length(); i++)
        {
            char ch = x[i];
          //if opening braket than push in the stack
            if(ch == '(' || ch == '{' || ch == '[')
              s.push(ch);
            
          //if closing braket than compare the string element with top of the stack
            else
            {
                if(!s.empty())
                {
                    char t = s.top();
                    if((ch == ']' && t == '[') ||
                         (ch == '}' && t == '{') ||
                            (ch == ')' && t == '('))
                       s.pop();
                    else
                       return false;
                }
                else
                {
                    return false;
                }
            }
        }
        if(s.empty())
          return true;
        else
          return false;
    }

};
