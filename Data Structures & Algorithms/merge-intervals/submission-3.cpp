class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> answer;
        sort(intervals.begin(), intervals.end());
        answer.push_back(intervals[0]);
        int start = intervals[0][0];
        int end = intervals[0][1]; 

        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] <= end) {
                if(intervals[i][1] > end){
                    end = intervals[i][1];
                    answer.back()[1] = end;
                } else continue;
            } 
            else{
                answer.push_back(intervals[i]);
                end = intervals[i][1];
            }
        }
        return answer;
    }
};
