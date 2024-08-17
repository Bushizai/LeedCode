#include "../include/maxArea.h"
#include <algorithm>

int Solution::maxArea(std::vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while (l < r) {
        int area = std::min(height[l], height[r]) * (r - l);
        ans = std::max(ans, area); // 使用 std::max
        if (height[l] <= height[r]) {
            ++l;
        }
        else {
            --r;
        }
    }
    return ans;
}
