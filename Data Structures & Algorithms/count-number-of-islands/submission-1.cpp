class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j, int rows, int cols, vector<vector<bool>>& visited){
        visited[i][j] = true;
        if(grid[i][j] == '1'){
            if(i - 1 >= 0 && !visited[i-1][j]) DFS(grid, i-1, j, rows, cols, visited);
            if(i + 1 < rows && !visited[i+1][j]) DFS(grid, i+1, j, rows, cols, visited);
            if(j + 1 < cols && !visited[i][j+1]) DFS(grid, i, j+1, rows, cols, visited);
            if(j - 1 >= 0 && !visited[i][j-1]) DFS(grid, i, j-1, rows, cols, visited);
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool> (cols, false));

        int counter = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    counter++;
                    DFS(grid, i, j, rows, cols, visited);
                }
                else{
                    visited[i][j] == true;
                }
            }
        }
        return counter;
    }
};
