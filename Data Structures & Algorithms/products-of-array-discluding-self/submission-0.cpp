class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref;
        vector<int> post;
        vector<int> answer;
        pref.push_back(1);
        post.push_back(1);
        for(int i = 0; i < nums.size() - 1; i++){
            pref.push_back(pref[i] * nums[i]);
        }
        for(int i = 0; i < nums.size() - 1; i++){
            post.push_back(post[i] * nums[nums.size() - 1 - i]);
        }
        for(int i = 0; i < nums.size(); i++){
            answer.push_back(pref[i] * post[nums.size() - 1 - i]);
        }
        return answer;
        
    }
};


