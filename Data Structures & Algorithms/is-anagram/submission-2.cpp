#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.empty() && t.empty()) return true;
        
        unordered_map<char, int> counter1;
        unordered_map<char, int> counter2;
        for(auto&& c : s) counter1[c]++; 
        for(auto&& c : t) counter2[c]++; 

        if(counter1 == counter2) return true;
        return false;   
    }
};
