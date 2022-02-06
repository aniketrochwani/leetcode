class Solution {
public:
    int ans = INT_MIN;
    void findIslands(vector<vector<int>> &grid, int i, int j, int row, int col, int *count){
        if(i<0 or j<0 or i>=row or j>=col) return;
        if(grid[i][j] == 2 or grid[i][j] == 0) return;
        
        grid[i][j] = 2;
        *count = *count+1;
        findIslands(grid, i-1, j, row, col, count);
        findIslands(grid, i, j-1, row, col, count);
        findIslands(grid, i, j+1, row, col, count);
        findIslands(grid, i+1, j, row, col, count);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int count = 0;
                    findIslands(grid, i, j, m, n, &count);
                    // decision yha hoga
                    ans = max(count, ans);
                }
            }
        }
        
        if(ans == INT_MIN) return 0;
        
        return ans;
    }
};