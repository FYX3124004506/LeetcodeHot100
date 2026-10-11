#include <unordered_map>
#include <vector>

class Solution {
public:
    // 返回满足 nums[left] + nums[right] == target 的两个不同下标。
    // indexByValue 只保存已扫描前缀中的数值及其下标，因此命中补数时，
    // match->second 一定小于当前下标 i；这也保证同一个元素不会被使用两次。
    // 哈希表操作平均为 O(1)，整体平均时间 O(n)，额外空间 O(n)。
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> indexByValue;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            // 当前元素需要的另一个数；若它已在前缀中，答案立即确定。
            const int need = target - nums[i];
            const auto match = indexByValue.find(need);
            if (match != indexByValue.end()) {
                return {match->second, i};
            }

            // 先查后存：查询范围严格是 i 之前的元素，避免当前元素与自身配对；
            // 插入后，当前值才可供后续下标作为补数使用。重复值也会按下标分别处理。
            indexByValue[nums[i]] = i;
        }

        // 题目保证有解；空向量仅作为防御性兜底。
        return {};
    }
};
