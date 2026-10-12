class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;

        int jumps = 0;
        int cur_end = 0;
        int cur_farthest = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            cur_farthest = max(cur_farthest, i + nums[i]);

            if (i == cur_end) {
                jumps++;
                cur_end = cur_farthest;
            }
        }

        return jumps;
    }
};