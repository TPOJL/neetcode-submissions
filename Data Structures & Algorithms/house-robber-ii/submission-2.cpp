#include <algorithm>
#include <vector>

class Solution {
private:
    int dp(const vector<int>& nums, int left) {
        vector<int> dp(nums.size() - 1, 0);

        dp[0] = nums[left];
        dp[1] = max(nums[left], nums[left + 1]);

        for(int i = 2; i < dp.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[left + i]);
        }
        return dp[dp.size() - 1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        return max(dp(nums, 0), dp(nums, 1));
    }
};