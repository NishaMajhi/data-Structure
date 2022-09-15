/*
Sort a stack in descending order

Example 1:
Input:
st = {2,1,5,0}
Output:
{5,2,1,0}

*/


void insert(stack<int> &s,int t){
   if(s.empty() || s.top() < t){
     s.push(t);
     return;
   }
  
  int n = s.top();
  s.pop();
  insert(s,t);
  s.push(n);
  return;
}

void sortStack(stack<int> &s){
   if(s.size() == 0 || s.size() == 1){
    return; 
   }
  
  int t = s.top();
  s.pop();
  sortStack(s);
  insert(s,t);
  return;
}
