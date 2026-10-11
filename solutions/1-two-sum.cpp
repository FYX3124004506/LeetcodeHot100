#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> indexByValue;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int need = target - nums[i];
            const auto match = indexByValue.find(need);
            if (match != indexByValue.end()) {
                return {match->second, i};
            }

            // 只记录已遍历的位置，避免把当前元素与自身配对。
            indexByValue[nums[i]] = i;
        }

        return {};
    }
};
