/**
 * 1487 保证文件名唯一
 * https://leetcode.cn/problems/making-file-names-unique/
 * 思路：使用map存放已分配的文件名和该文件名的最小后缀数。对于一个文件名，如果未分配，就将其放入map中，后缀数为0.
 * 如果已分配，那么寻找合适的后缀数（从最小后缀数开始，累加并检查是否已分配），放入map中即可。
 */

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        map<string, int> has_dis;
        vector<string> ans;
        string st;
        int k = 0;
        for (auto name : names) {
            // 未分配
            if (has_dis.find(name) == has_dis.end()) {
                ans.push_back(name);
                has_dis[name] = 0;
            } else {
                k = has_dis[name] + 1;
                // 如果已存在，就++k
                st = name + "(" + to_string(k) + ")";
                while (has_dis.find(st) != has_dis.end()) {
                    ++k;
                    has_dis[name] += 1;
                    st = name + "(" + to_string(k) + ")";
                }
                ans.push_back(st);
                has_dis[st] = 0;
            }
        }
        return ans;
    }
};