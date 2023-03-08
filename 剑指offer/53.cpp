/**
 * 53-1 数字在排序数组中出现的次数
 * https://leetcode.cn/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
 * 53-2 0～n-1中缺失的数字
 * https://leetcode.cn/problems/que-shi-de-shu-zi-lcof/
 */

class Solution {
public:

    int binarySearch(vector<int>& nums, int i_left, int i_right, int target, bool to_left) {
        if (i_left > i_right)
            return -1;
        int i_mid = (i_left + i_right) / 2;
        if (nums[i_mid] == target) {
            if (to_left) {
                if (i_mid == 0 || nums[i_mid - 1] != target)
                    return i_mid;
                else
                    i_right = i_mid - 1;
            } else {
                if (i_mid == nums.size() - 1 || nums[i_mid + 1] != target)
                    return i_mid;
                else
                    i_left = i_mid + 1;
            }
        } else if (nums[i_mid] < target) {
            i_left = i_mid + 1;
        } else {
            i_right = i_mid - 1;
        }
        return binarySearch(nums, i_left, i_right, target, to_left);
    }

    int search(vector<int>& nums, int target) {
        int firstK = binarySearch(nums, 0, nums.size() - 1, target, true);;
        int lastK = binarySearch(nums, 0, nums.size() - 1, target, false);
        cout << firstK << ", " << lastK << endl;
        if (firstK != -1 && lastK != -1)
            return lastK - firstK + 1;
        else
            return 0;
    }
};


class Solution {
public:

    int binarySearch(vector<int>& nums, int i_left, int i_right) {
        if (i_left > i_right)
            return i_right + 1;
        int i_mid = (i_left + i_right) / 2;
        if (nums[i_mid] == i_mid) {
            i_left = i_mid + 1;
        } else {
            i_right = i_mid - 1;
        }
        return binarySearch(nums, i_left, i_right);
    }

    int missingNumber(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};