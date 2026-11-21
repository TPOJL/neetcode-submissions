#include <map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> hashes (strs.size(), vector<int>(26, 0));
        
        for(int i = 0; i < strs.size(); i++){
            for(auto && el : strs[i]){
                int id = el - 'a';
                hashes[i][id]++;
            }
        }

        map<vector<int>, vector<string>> group;
        for(int i = 0; i < strs.size(); i++){
            group[hashes[i]].push_back(strs[i]);
        }

        vector<vector<string>> answer;
        for(auto && [key, value] : group){
            answer.push_back(value);
        }

        return answer;
        
    }
};
