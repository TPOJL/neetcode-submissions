class Solution {
public:
    bool isPalindrome(string s) {
        int sz = s.size();
        if(sz == 0 || sz == 1) return true;
        int l = 0;
        int r = sz - 1;
        while (true){
            while(('a' > tolower(s[l]) || tolower(s[l]) > 'z') && ('0' > tolower(s[l]) || tolower(s[l]) > '9')) l++;
            while(('a' > tolower(s[r]) || tolower(s[r]) > 'z') && ('0' > tolower(s[r]) || tolower(s[r]) > '9')) r--;
            if(l >= r) break;
            if(tolower(s[l]) != tolower(s[r])) return false;
            l++;
            r--;
         }
        return true;
    }
};
