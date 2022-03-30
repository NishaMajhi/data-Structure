/*
Given a binary matrix M of size n X m. Find the maximum area of a rectangle formed only of 1s in the given matrix.

Input---
n = 4, m = 4
M[][] = {{0 1 1 0},
         {1 1 1 1},
         {1 1 1 1},
         {1 1 0 0}}
Output---
8

Explanation: For the above test case the
matrix will look like
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0
the max size rectangle is 
1 1 1 1
1 1 1 1
and area is 4 *2 = 8.
*/

//find next smallest index for all the element of array  
vector<int> nextSmallerIndex(int arr[],int n)
 {
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for(int i=n-1;i>=0;i--)
        {
           int curr = arr[i];
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
 vector<int> prevSmallerIndex(int arr[],int n)
 {
        stack<int> s;
        s.push(-1);
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
           int curr = arr[i];
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
int getMaxArea(int arr[], int n)
{
       vector<int> next(n);
       next = nextSmallerIndex(arr,n);
       vector<int> prev(n);
       prev = prevSmallerIndex(arr,n);
       
       int area = INT_MIN;
       for(int i=0; i<n; i++)
       {
           int  l = arr[i];
           if(next[i] == -1)
              next[i] = n;
           int b = next[i]-prev[i]-1;
           
           int newArea = l*b;
           area = max(newArea,area);
       }
       
       return area;
}

int maxArea(int M[MAX][MAX], int n, int m) {
        //step 1 compute maxarea for row 1
        int area = getMaxArea(M[0],m);
        //step 2 for every remaining row 
        for(int i=1;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                //upar bali row ko current row ke sath add karna hai
                if(M[i][j]!=0)
                   M[i][j] += M[i-1][j];
                   
                else
                    M[i][j]=0;
            }
            
            // compute area
            area = max(area,getMaxArea(M[i],m));
        }
        
        return area;
 }
