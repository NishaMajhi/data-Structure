//find next smallest index for all the element of array  
vector<long long> nextSmallerIndex(long long arr[],int n)
 {
        stack<long long> s;
        s.push(-1);
        vector<long long> v(n);
        for(int i=n-1;i>=0;i--)
        {
           long long curr = arr[i];
           while(s.top() != -1 && arr[s.top()] >= curr)
           {
               s.pop();
           }
           
           v[i]=s.top();
           s.push(i);
        }
        return v;
 }
//find previous smallest index for all the element of array  
 vector<long long> prevSmallerIndex(long long arr[],int n)
 {
        stack<long long> s;
        s.push(-1);
        vector<long long> v(n);
        for(int i=0;i<n;i++)
        {
           long long curr = arr[i];
           while(s.top() != -1 && arr[s.top()] >= curr)
           {
               s.pop();
           }
           
           v[i]=s.top();
           s.push(i);
        }
        return v;
 }
    
 //Function to find largest rectangular area possible in a given histogram.
long long getMaxArea(long long arr[], int n)
{
       vector<long long> next(n);
       next = nextSmallerIndex(arr,n);
       vector<long long> prev(n);
       prev = prevSmallerIndex(arr,n);
       
       long long area = INT_MIN;
       for(int i=0; i<n; i++)
       {
           long long  l = arr[i];
           if(next[i] == -1)
              next[i] = n;
           long long b = next[i]-prev[i]-1;
           
           long long newArea = l*b;
           area = max(newArea,area);
       }
       
       return area;
}
/*
output--
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
*/
