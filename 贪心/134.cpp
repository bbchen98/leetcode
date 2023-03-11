/**
 * 134 加油站
 * https://leetcode.cn/problems/gas-station/
 * 一遍计算总油耗，一遍计算当前油耗。
 * 如果总油数够跑完一圈，那就说明一定存在解。
 * 如果当前剩余的油数不够到下一个加油站，那就说明目前的起始位置不对，将其更新为下一个加油站
 */

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i_start = 0;
        int total_rest = 0;
        int cur_rest = 0;
        int n = gas.size();
        for (int i = 0; i < n; ++i) {
            total_rest += gas[i] - cost[i];
            cur_rest += gas[i] - cost[i];
            if (cur_rest < 0) {
                i_start = (i + 1) % n;
                cur_rest = 0;
            }
        }
        if (total_rest < 0)
            return -1;
        else
            return i_start;
    }
};

