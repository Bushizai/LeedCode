#include <iostream>
#include <vector>
#include "../include/maxArea.h"

int main() {
    Solution s;
    std::vector<int> height = {1,8,6,2,5,4,8,3,7};
    std::cout << s.maxArea(height) << std::endl;
    return 0;
}