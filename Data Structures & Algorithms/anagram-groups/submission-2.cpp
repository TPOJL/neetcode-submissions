#include <map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> hashes(strs.size(), vector<int>(26, 0));
        for(int i = 0; i < strs.size(); i++){
            for(int j = 0; j < strs[i].size(); j++){
                int pos = strs[i][j] - 'a';
                hashes[i][pos] += 1;
            }
        }
        map<vector<int>, vector<string>> groups;
        for(int i = 0; i < hashes.size(); i++){
            groups[hashes[i]].push_back(strs[i]);
        }
        vector<vector<string>> output;
        for(auto&& [key, vals] : groups){
            output.push_back(vals);
        }
        return output;
    }
};
