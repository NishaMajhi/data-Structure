/*
Given two sorted arrays arr1[] of size N and arr2[] of size M.
Each array is sorted in non-decreasing order. 
Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

Example 1:
Input:
N = 4, M = 5
arr1[] = {1, 3, 5, 7}
arr2[] = {0, 2, 6, 8, 9}
Output: 0 1 2 3 5 6 7 8 9
Explanation: Since you can't use any 
extra space, modify the given arrays
to form 
arr1[] = {0, 1, 2, 3}
arr2[] = {5, 6, 7, 8, 9}
*/


//Time Complexity: O((n+m)*log(n+m))
//Auxiliary Space: O(1)
class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	   
	   //int j=0;                  // 245/315  test cases pass
	   //for(int i=0;i<n;i++){
	   //    if(arr1[i] > arr2[0]){
	   //        swap(arr1[i],arr2[0]);
	   //    }
	       
	   //    int f = arr2[0];
	   //    for(j=1;j<m && arr2[j]<f;j++){
	   //        arr2[j-1] = arr2[j];
	   //    }
	   //    arr2[j-1] = f;
	   //}
	   
    
	   int i = n - 1,j = 0;
	   while(arr1[i] > arr2[j]  && j<m && i>=0){
	     swap(arr1[i],arr2[j]);
	     i--;
	     j++;
	   }
	   sort(arr1,arr1+n);
	   sort(arr2,arr2+m);
	 }
};



/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be
merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
*/


//t.c = O(m + n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       int i=m-1,j=n-1,k=i+j+1;
        
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
                 nums1[k--]=nums1[i--];
            else
                nums1[k--]=nums2[j--];
        }
        
        while(j>=0)
            nums1[k--]=nums2[j--];
        
    }
};
