class Solution {
private:
    bool rec(string part, const string& s, int idx, const vector<string>& wordDict, unordered_map<string, bool>& memo) {
        if (idx == s.size()) return part.empty();

        string key = to_string(idx) + "#" + part;
        if (memo.count(key)) return memo[key];

        bool inside = false;
        part += s[idx];

        if (rec(part, s, idx + 1, wordDict, memo)) return memo[key] = true;

        for (auto&& word : wordDict) {
            if (word == part) {
                inside = true;
                break;
            }
        }
        if (inside) {
            part = "";
            if (rec(part, s, idx + 1, wordDict, memo)) return memo[key] = true;
        }

        return memo[key] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.empty()) return false;
        if (s.empty()) return true;

        unordered_map<string, bool> memo;
        return rec("", s, 0, wordDict, memo);
    }
};