/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3
*/

class Solution {
public:
  
    typedef long long ll;
    int merge(vector<int>& nums, int st,int mid,int en)     {
    int n1 = mid - st +1;
    int n2 = en - mid;
    int a[n1];
    int b[n2];
    for(int i = 0 ; i<n1;i++){
        a[i] = nums[i+st];
    }
    for(int i=0;i<n2;i++){
        b[i] = nums[i+mid+1];
    }
    
    int i = 0, j = 0 , k = st;
    int cnt = 0;
    
    
    // calculate the cnt
    int x = 0, y = 0;
    while(x<n1 and y<n2){
        if(a[x] > (ll)2*b[y]){
            cnt+=n1-x;
            y++;                
        }
        else{
            x++;
        }
    }
    
    
    
    
    // merge sort 
    while(i<n1 and j<n2){
        
        if(a[i]>b[j]){
            nums[k++] = b[j++];
        }
        else{
            nums[k++] = a[i++];
        }
    }
    
    
    while(i<n1){
        nums[k++] = a[i++];
    }
    while(j<n2){
        nums[k++] = b[j++];
    }
    return cnt;
    
}

int mergeSort(vector<int>& nums, int st,int en){
    int cnt = 0;
    if(st<en){    
        int mid = (st+en)/2;
        cnt+=mergeSort(nums,st,mid);
        cnt+=mergeSort(nums,mid+1,en);
        cnt+=merge(nums,st,mid,en);        
    }
    return cnt;
}

    int reversePairs(vector<int>& nums) {
   
    int k= mergeSort(nums,0,nums.size()-1);        
    return k;
}
        
        
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]>2 * nums[j])
        //             pairs++;
        //     }
        // }
        // return pairs;
        
   
};
