class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() == 0 || nums2.size() == 0) return {};
        unordered_set<int> was;
        unordered_set<int> answer;
        for(auto && el : nums1){
            was.insert(el);
        }
        for(auto && el : nums2){
            if(was.find(el) != was.end()){
                answer.insert(el);
            }
        }
        vector<int> answer1;
        for(auto && el : answer) answer1.push_back(el);
        return answer1;
    }
};