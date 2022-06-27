/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]


Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
//         int flag = 1;
//          int row=matrix.size(),col=matrix[0].size();
//         for(int i=0;i<row;i++){
            
//             for(int j=0;j<col;j++){
                
//                 if(matrix[i][j] == 0){
//                     flag = 0;
//                     int ind = i-1;
//                     while(ind >= 0 ){
//                         if(matrix[ind][j] != 0)
//                           matrix[ind][j] = -1;
//                         ind--;
//                     }
                    
//                     ind = i+1;
//                     while(ind<row){
//                         if(matrix[ind][j] != 0)
//                           matrix[ind][j] = -1;
//                         ind++;                         

                        
//                     }
                    
//                     ind = j-1;
//                     while(ind>=0){
//                         if(matrix[i][ind] != 0)
//                           matrix[i][ind] = -1;
//                         ind--;     
//                     }
                    
//                     ind = j+1;
//                     while(ind<col){
//                         if(matrix[i][ind] != 0)
//                           matrix[i][ind] = -1;
//                         ind++; 
//                     }
//                 }
//             }
//         }
//         if(flag == 1)
//             return;
//         for(int i=0;i<row;i++){
//             for(int j=0;j<col;j++){
//                 if(matrix[i][j] == -1)
//                      matrix[i][j] = 0;
//             }     
//         }
     
      
      //approach 2
    int row0=1,col=1,row=matrix.size(),cols=matrix[0].size();
    for(int i=0;i<row;i++){
    if(matrix[i][0]==0)
        col=0;
    }
    for(int j=0;j<col;j++)
    {
        if(matrix[0][j]==0)
        {
            row0=0;
        }
    }
    for(int i=0;i<row;i++)
    {
        
        
        for(int j=1;j<cols;j++)
        
            if(matrix[i][j]==0)
            
                matrix[i][0]=matrix[0][j]=0;
            
        
    }
    for(int i=row-1;i>=0;i--)
    {
        for(int j=cols-1;j>=1;j--)
        
        
            if(matrix[i][0]==0||matrix[0][j]==0)
                matrix[i][j]=0;
            if(col==0)
                matrix[i][0]=0;
           
        
        
    }
    for(int j=0;j<cols;j++)
    {
        if(row0==0)
            matrix[0][j]=0;
    }
       
    }
};
