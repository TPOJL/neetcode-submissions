class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int counter = 1;
        int end = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++){
            if(intervals[i][0] >= end) {counter ++; end = intervals[i][1];}
            else if(intervals[i][1] < end) {end = intervals[i][1];}
            else {continue;}
        }
        return intervals.size() - counter;
    }
};
