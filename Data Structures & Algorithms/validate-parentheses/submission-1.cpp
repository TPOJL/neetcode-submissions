class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 != 0) return false;
        vector<char> el;

        for (char c : s) {
            switch (c) {
                case ')':
                    if (el.empty() || el.back() != '(') return false;
                    el.pop_back();
                    break;
                case '}':
                    if (el.empty() || el.back() != '{') return false;
                    el.pop_back();
                    break;
                case ']':
                    if (el.empty() || el.back() != '[') return false;
                    el.pop_back();
                    break;
                default:
                    el.push_back(c);
            }
        }
        
        return el.empty();
    }
};