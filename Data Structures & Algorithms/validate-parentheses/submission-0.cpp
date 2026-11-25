class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        vector<char> el;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(el.empty()) return false;
                if(el.back() != '(') return false;
                el.pop_back();
                continue;
            }
            if(s[i] == '}'){
                if(el.empty()) return false;
                if(el.back() != '{') return false;
                el.pop_back();
                continue;
            }
            if(s[i] == ']'){
                if(el.empty()) return false;
                if(el.back() != '[') return false;
                el.pop_back();
                continue;
            }
            el.push_back(s[i]);
        }
        if(el.empty()) return true;
        return false;        
    }
};
