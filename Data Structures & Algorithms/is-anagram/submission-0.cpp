#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int> amount;
        for(auto && letter : s){
            amount[letter] += 1;
        }
        for(auto && letter : t){
            amount[letter] -= 1;
        }
        for(auto && [key, val] : amount){
            if(val != 0) return false;
        }
        return true;
    }
};
