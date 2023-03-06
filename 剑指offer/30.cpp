/**
 * 30 栈的压入、弹出序列
 * https://leetcode.cn/problems/zhan-de-ya-ru-dan-chu-xu-lie-lcof/
 */

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i_pop = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[i_pop]) {
                st.pop();
                ++i_pop;
            }
        }
        return st.empty();
    }
};