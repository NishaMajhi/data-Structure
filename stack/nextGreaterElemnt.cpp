//find next greater element for all the element of array
vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        stack<long long> s;
        vector<long long> v(n);
        
        for(int i = n-1; i>=0; i--)
        {
            while(!s.empty() && s.top() <= arr[i])
               s.pop();
            if(s.empty())
               v[i] = -1;
            else
              v[i] = s.top();
              
            s.push(arr[i]);
        }
        return v;
}

/*
output---
Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1
Explanation:
In the array, the next larger element 
to 1 is 3 , 3 is 4 , 2 is 4 and for 4 ? 
since it doesn't exist, it is -1.
*/
