class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> unique_triplets;
        sort(nums.begin(), nums.end());

        for (int el = 0; el < nums.size(); el++) {
            int left = el + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[el] + nums[left] + nums[right];
                if (sum < 0) left++;
                else if (sum > 0) right--;
                else {
                    unique_triplets.insert({nums[el], nums[left], nums[right]});
                    left++;
                    right--;
                }
            }
        }

        return vector<vector<int>>(unique_triplets.begin(), unique_triplets.end());
    }
};