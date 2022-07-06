/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.


Input: matrix = 
[[1,3,5,7],
 [10,11,16,20],
 [23,30,34,60]], 

target = 3

Output: true

Explanation: As the given integer(target) exists in the given 2D matrix, the function has returned true.
*/


class Solution {
public:
  
  //t.c = O(n^2)
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r=matrix.size();
    int c=matrix[0].size();
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        if(matrix[i][j]==target)
          return true;
      }
      
    }
    
  }
  
  
  
  //t.c=O(log(m*n))
 bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r=matrix.size();
        int c=matrix[0].size();
        int i=0,j=c-1;
        while(i<r && j>=0){
            
                if(matrix[i][j]==target)
                      return true;
                else if(matrix[i][j]>target)
                    j--;
                else
                    i++;
            }
      
        return false;
        
    }
};
