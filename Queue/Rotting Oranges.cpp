/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4



Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.



Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> rott;
        int nonEmptyCount = 0, day = 0,cnt = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] != 0)
                    nonEmptyCount++;
                if(grid[i][j] == 2)
                    rott.push({i,j});
            }
        }
        
        //for dimention
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        
        int r = grid.size();
        int c = grid[0].size();

        while(!rott.empty()){
            int k = rott.size();
            cnt += k;
            while(k--){
                int x = rott.front().first, y = rott.front().second;
                rott.pop();
                for(int i=0;i<4;i++){
                    int newX = x+dx[i],newY = y+dy[i];
                    if(newX < 0 || newY < 0 || newX >= r || newY >= c || grid[newX][newY] != 1)
                        continue;
                    grid[newX][newY]=2;
                    rott.push({newX,newY});
                }
            }
            if(!rott.empty())
                day++;
        }
        
        return nonEmptyCount == cnt ? day : -1;
    }
};
