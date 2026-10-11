#include <algorithm>
#include <utility>
#include <vector>

class Solution {
public:
    // 有序副本让每个补数都能通过 lower_bound 在 O(log n) 内定位。
    // 副本同时保存原下标；若二分结果是当前元素自身，只能使用紧邻的同值元素。
    // 排序和 n 次二分的总时间为 O(n log n)，额外空间为 O(n)。
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> ordered;
        ordered.reserve(nums.size());

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            ordered.emplace_back(nums[i], i);
        }
        std::sort(ordered.begin(), ordered.end());

        for (const auto& current : ordered) {
            const long long need =
                static_cast<long long>(target) - current.first;
            auto candidate = std::lower_bound(
                ordered.begin(), ordered.end(), need,
                [](const std::pair<int, int>& item, long long value) {
                    return static_cast<long long>(item.first) < value;
                });

            if (candidate == ordered.end() ||
                static_cast<long long>(candidate->first) != need) {
                continue;
            }

            if (candidate->second == current.second) {
                // 同值元素按原下标相邻；跳过当前项后，下一项若仍同值便是另一位置。
                ++candidate;
                if (candidate == ordered.end() ||
                    static_cast<long long>(candidate->first) != need) {
                    continue;
                }
            }

            return {current.second, candidate->second};
        }

        // 题目保证有解；空结果仅作为防御性兜底。
        return {};
    }
};
