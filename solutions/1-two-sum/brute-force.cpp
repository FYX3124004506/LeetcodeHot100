#include <vector>

class Solution {
public:
    // 只枚举 i < j 的下标对，所以每对不同位置恰好检查一次；
    // 命中条件直接对应题意，不需要排序或额外数据结构。
    // 时间复杂度 O(n^2)，额外空间 O(1)（不计返回结果）。
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        const int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // 提升到 long long 后再相加，避免整数加法溢出。
                const long long sum =
                    static_cast<long long>(nums[i]) + nums[j];
                if (sum == target) {
                    return {i, j};
                }
            }
        }

        // 题目保证恰好有一个答案；保留空结果作为防御性兜底。
        return {};
    }
};
