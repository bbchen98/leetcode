/**
 * 9 用两个栈实现队列
 * https://leetcode.cn/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
 */

class CQueue {
private:
    stack<int> inStack, outStack;
public:
    CQueue() {}

    void appendTail(int value) {
        inStack.push(value);
    }

    int deleteHead() {
        int ret = -1;
        if (inStack.empty() && outStack.empty()) return ret;
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        ret = outStack.top();
        outStack.pop();
        return ret;
    }
};
