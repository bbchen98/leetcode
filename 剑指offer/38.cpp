/**
 * 38 字符串的排列
 * https://leetcode.cn/problems/zi-fu-chuan-de-pai-lie-lcof/
 */

class Solution {
public:

    void backTrack(string s, vector<bool>& visited, vector<char>& path, int len, unordered_set<string>& ans) {
        if (len == s.size()) {
            ans.insert(string(path.cbegin(), path.cend()));
        }
        for (int i = 0; i < s.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                path.push_back(s[i]);
                backTrack(s, visited, path, len + 1, ans);
                visited[i] = false;
                path.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        int n = s.length();
        vector<bool> visited(n, false);
        vector<char> path;
        unordered_set<string> ans;
        backTrack(s, visited, path, 0, ans);
        return vector<string>(ans.cbegin(), ans.cend());
    }
};