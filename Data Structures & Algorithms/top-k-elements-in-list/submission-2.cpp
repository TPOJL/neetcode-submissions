#include <queue>
#include <map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for(auto && el : nums){
            freq[el] ++;
        }

        priority_queue<pair<int, int>> tf;

        for(auto&& [key, val] : freq){
            tf.push({-val, key});
            if(tf.size() > k) tf.pop();
        }
        vector<int> answer;
        while(!tf.empty()){
            answer.push_back(tf.top().second);
            tf.pop();
        }
        return answer;
    }
};
