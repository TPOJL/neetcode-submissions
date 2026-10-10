class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int w = matrix[0].size();
        int h = matrix.size();
        vector<int> answer; int k = 0; int i = 0; int j = 0;
        int total = w * h;

        while (answer.size() < total) {
            while(i != w - k && answer.size() < total){
                answer.push_back(matrix[j][i]);
                i++;
            }
            i--; j++;
            while(j != h - k && answer.size() < total){
                answer.push_back(matrix[j][i]);
                j++;
            }
            i--; j--;
            while(i != k - 1 && answer.size() < total){
                answer.push_back(matrix[j][i]);
                i--;
            }
            i++; j--;
            k++;
            while(j != k - 1 && answer.size() < total){
                answer.push_back(matrix[j][i]);
                j--;
            }
            i++; j++;

        }
        return answer;
    }
};
