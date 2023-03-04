/**
 * 893 特殊等价字符串组
 * https://leetcode.cn/problems/groups-of-special-equivalent-strings/description/
 * 我的思路：对奇偶位置排序，使得“特殊等价”的字符串有着相同的表示（最小字典序）。逐个放入set，如果存在，说明同一组
 * 官方思路：用大小为52的数组表示一个字符串，前26个表示奇数位置某个字符是否出现，后26个表示偶数位置。
 */
// 我的代码
class Solution {
public:
 string process(string s) {
     int n = s.length();
     if (n == 1) return s;
     vector<vector<string>> v(2);
     for (int i = 0; i < n; i++) {
         v[i % 2].push_back(s.substr(i, 1));
     }
     sort(v[0].begin(), v[0].end());
     sort(v[1].begin(), v[1].end());
     string st = "";
     for (int i = 0; i < n / 2; i++) {
         st += v[0][i] + v[1][i];
     }
     if (n % 2 == 1) {
         st += v[0][n / 2 + 1];
     }
     return st;
 }
 int numSpecialEquivGroups(vector<string>& words) {
     set<string> word_set;
     string st;
     int ans = 0;
     for (auto w : words) {
         st = process(w);
         if (word_set.find(st) == word_set.end()) {
             word_set.insert(st);
             ++ans;
         }
     }
     return ans;
 }
};

// 官方
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> word_set;
        vector<int> pre(52, 0);
        for (auto w : words) {
            fill(pre.begin(), pre.end(), 0);
            for (int i = 0; i < w.size(); ++i)
                ++pre[w[i] - 'a' + 26 * (i % 2)];
            word_set.insert(string(pre.begin(), pre.end()));
        }
        return word_set.size();
    }
};
