#include <unordered_map>
#include <vector>

class Solution {
public:
    // 第一遍记录每个数值的一个原始下标，第二遍查询当前值的补数。
    // 表中也可能包含当前位置，因此必须排除 found->second == i 的自我配对。
    // 哈希操作平均 O(1)，整体平均时间 O(n)，额外空间 O(n)。
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> firstIndex;
        firstIndex.reserve(nums.size());

        // emplace 保留每个数值最早出现的位置，重复值不会覆盖已有下标。
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            firstIndex.emplace(nums[i], i);
        }

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int need = target - nums[i];
            const auto found = firstIndex.find(need);
            if (found != firstIndex.end() && found->second != i) {
                return {i, found->second};
            }
        }

        // 题目保证恰好有一个答案；保留空结果作为防御性兜底。
        return {};
    }
};
