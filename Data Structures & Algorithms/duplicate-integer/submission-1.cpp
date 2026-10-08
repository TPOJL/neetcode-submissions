#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int, int> amount;
        for(auto && el : nums) {
            amount[el] += 1;
        }
        for(auto && [key, vals] : amount) {
            if(vals > 1) return true;
        }
        return false;
    }
};