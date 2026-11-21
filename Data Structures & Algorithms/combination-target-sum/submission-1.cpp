class Solution {
private:
    void backtrack(const vector<int>& nums, int idx, int rem, vector<int>& curr,  vector<vector<int>>& answer){
        if(rem == 0){ 
            answer.push_back(curr);
            return;
        }
        if(rem < 0 || idx == nums.size()){
            return;
        }
        curr.push_back(nums[idx]);
        backtrack(nums, idx, rem - nums[idx], curr, answer);

        curr.pop_back();
        backtrack(nums, idx + 1, rem, curr, answer);
    }    
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> answer;
        vector<int> curr;
        backtrack(nums, 0, target, curr, answer);
        return answer;
    }
};
