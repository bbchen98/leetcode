/**
 * 11 旋转数组的最小数字
 * https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 */

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int n = numbers.size();
        int i_left = 0, i_right = n - 1;
        int i_ans = i_left;
        int mid;
        while (numbers[i_left] >= numbers[i_right]) {
            mid = (i_left + i_right) / 2;
            if (mid == i_left) {
                i_ans = i_right;
                break;
            }
            if (numbers[i_left] == numbers[mid] && numbers[i_right] == numbers[mid] && numbers[i_left] == numbers[i_right]) {
                for (int i = i_left; i <= i_right; ++i) {
                    if (numbers[i] < numbers[i_ans]) {
                        i_ans = i;
                    }
                }
                break;
            }
            if (numbers[mid] >= numbers[i_left]) {
                i_left = mid;
            } else {
                i_right = mid;
            }
        }
        return numbers[i_ans];
    }
};
