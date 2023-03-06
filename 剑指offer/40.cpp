/**
 * 40 最小的k个数
 * https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/
 */

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> heap(arr.cbegin(), arr.cend());
        make_heap(heap.begin(), heap.end(), greater<int>());

        vector<int> ans;
        while (k > 0) {
            pop_heap(heap.begin(), heap.end(), greater<int>());
            ans.push_back(heap.back());
            heap.pop_back();
            --k;
        }
        return ans;
    }
};
