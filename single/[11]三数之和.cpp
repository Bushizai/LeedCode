#include <iostream>
#include <vector>
#include <algorithm> // 包含 min 和 max 函数


class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = std::min(height[l], height[r]) * (r - l);
            ans = std::max(ans, area);
            if (height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout << s.maxArea(height) << std::endl;
    return 0;
}