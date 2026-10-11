#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
    // 排序副本中的“数值 + 原始下标”，用双指针寻找目标和。
    // 保存原始下标是必要的：直接排序 nums 会丢失题目要求的下标对应关系。
    // 时间复杂度 O(n log n)，额外空间 O(n)（不计返回结果）。
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> ordered;
        ordered.reserve(nums.size());

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            ordered.emplace_back(nums[i], i);
        }
        std::sort(ordered.begin(), ordered.end());

        int left = 0;
        int right = static_cast<int>(ordered.size()) - 1;
        while (left < right) {
            const long long sum =
                static_cast<long long>(ordered[left].first) +
                ordered[right].first;

            if (sum == target) {
                // 返回保存的原数组下标，而不是排序后的位置。
                return {ordered[left].second, ordered[right].second};
            }
            if (sum < target) {
                // 左端已经与当前最大值仍然偏小，换更大的左值才可能达标。
                ++left;
            } else {
                // 右端已经与当前最小值仍然偏大，换更小的右值才可能达标。
                --right;
            }
        }

        // 题目保证有解；循环结束只表示没有找到（理论上不可达）。
        return {};
    }
};
