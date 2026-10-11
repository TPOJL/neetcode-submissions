class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool zero_row = false;
        bool zero_col = false;

        for(auto && el : matrix[0]) if(el == 0) zero_row = true;
        for(int i = 0; i < matrix.size(); i ++) if(matrix[i][0] == 0) zero_col = true;

        for(int i = 0; i < matrix.size(); i ++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                for(int k = 0; k < matrix[0].size(); k++){
                    matrix[i][k] = 0;
                }
            }
        }

        for(int i = 1; i < matrix[0].size(); i++){
            if(matrix[0][i] == 0){
                for(int k = 0; k < matrix.size(); k++){
                    matrix[k][i] = 0;
                }
            }
        }
        if(zero_row){
            for(auto && el : matrix[0]) el = 0;
        }
        if(zero_col){
            for(int i = 0; i < matrix.size(); i ++) matrix[i][0] = 0;
        }

    }
};
