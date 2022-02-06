class Solution {
public:
    
    void findIslands(vector<vector<char>> &grid, int i, int j, int row, int col, char c){
        if(i<0 or j<0 or i>=row or j>=col) return;
        if(grid[i][j] == c or grid[i][j] == 'X') return;
        
        grid[i][j] = c;
        findIslands(grid, i-1, j, row, col, c);
        findIslands(grid, i, j-1, row, col, c);
        findIslands(grid, i, j+1, row, col, c);
        findIslands(grid, i+1, j, row, col, c);
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size(); // row
        int n = board[0].size(); // col
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') findIslands(board, i, j, m, n, '2');
            }
        }
        
        for(int j=0; j<n; j++) findIslands(board, 0, j, m, n, 'O');
        for(int i=0; i<m; i++) findIslands(board, i, n-1, m, n, 'O');
        for(int j=0; j<n; j++) findIslands(board, m-1, j, m, n, 'O');
        for(int i=0; i<m; i++) findIslands(board, i, 0, m, n, 'O');
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '2') board[i][j] = 'X';
            }
        }
        return;
    }
};