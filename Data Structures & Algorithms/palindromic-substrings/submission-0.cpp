class Solution {
public:
    int countSubstrings(string s) {
        int counter = 0;
        int m = 0;
        int p = 0;
        for(int i = 0; i < s.size(); i++){
            m = i;
            p = 0;
            while(m  - p >= 0 && m + p < s.size()){
                if(s[m - p] != s[m + p]) break;
                
                counter++;
                p++;
            }
        }
        for(int i = 0; i < s.size(); i++){
            m = i;
            p = 0;
            while(m  - p >= 0 && m + p < s.size()){
                if(s[m - p] != s[m + 1 + p]) break;
                
                counter++;
                p++;
            }
        }


        return counter;
    }
};
