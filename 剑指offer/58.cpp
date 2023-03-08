/**
 * 58-1 翻转单词顺序
 * https://leetcode.cn/problems/fan-zhuan-dan-ci-shun-xu-lcof/
 * 58-2 左旋转字符串
 * https://leetcode.cn/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
 */

class Solution {
public:
    string reverseWords(string s) {
        // 删除前后空格
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);
        if (s.empty()) return s;
        // 按空格分割单词
        vector<string> str_arr;
        string st;
        istringstream iss(s);
        while (iss >> st) {
            str_arr.push_back(st);
        }
        // 拼接
        string ans;
        for (int i = str_arr.size() - 1; i > 0; --i) {
            ans.append(str_arr[i] + " ");
        }
        ans.append(str_arr[0]);
        return ans;
    }
};



class Solution {
public:

    void swapStr(string& s, int i_left, int i_right) {
        while (i_left < i_right) {
            std::swap(s[i_left], s[i_right]);
            ++i_left;
            --i_right;
        }
    }

    string reverseLeftWords(string s, int n) {
        // 反转前n个
        swapStr(s, 0, n - 1);
        // 反转后size-n个
        swapStr(s, n, s.length() - 1);
        // 全部反转
        swapStr(s, 0, s.length() - 1);
        return s;
    }
};

