#include <queue>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto && el : nums) freq[el]++;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> topFreq;
        for(auto && [el, fr] : freq){
            topFreq.push({fr, el});
            if(topFreq.size() > k) topFreq.pop();
        }
        vector<int> answer;
        while(!topFreq.empty()){
            answer.push_back(topFreq.top().second);
            topFreq.pop();
        }
        return answer;
    }
};
