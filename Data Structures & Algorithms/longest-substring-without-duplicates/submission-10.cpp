class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        if(s.size() == 1) return 1;
        unordered_map <char, int> letter;
        int left = 0;
        int max = 0;
        int cur_len = 0;
        for(int i = 0; i < s.size(); i++){
            if(letter.count(s[i])){
                if(letter[s[i]] >= left){
                    left = letter[s[i]] + 1;
                }
                letter[s[i]] = i;
            }else{
                letter[s[i]] = i;
            }
            if(max < i - left + 1){max = i - left + 1;}
        }
        return max;
    }
};
