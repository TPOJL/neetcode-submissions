class Solution {
private:
    int dp(int m, int n){
        vector<vector<int>> u(m, vector<int>(n,0));
        u[0][0] = 0;
        for(int i = 0; i < n; i++){
            u[0][i] = 1;
        }
        for(int i = 0; i < m; i++){
            u[i][0] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                u[j][i] = u[j-1][i] + u[j][i-1];
            }
        }
        return u[m-1][n-1];
    }
public:
    int uniquePaths(int m, int n) {
        return dp(m, n);
    }
};
