#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() == 0) return {};
        unordered_map<int, int> index;
        for(int i = 0; i < nums.size(); i ++){
            int diff = target - nums[i];

            if(index.contains(diff)) return {index[diff], i};

            index[nums[i]] = i;
        }
    }
};
