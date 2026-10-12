class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return true;
        int max = nums[0];
        for(int i = 0; i <= max; i++){
            if(nums[i] + i >= max){
                max = nums[i] + i;
            }
            if(max >= nums.size() - 1) return true;
        }
        return false;
    }
};
