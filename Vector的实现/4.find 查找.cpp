#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50}; // 创建一个包含5个元素的int类型的vector容器
    
    // 在容器中查找值为 30 的元素
    auto it = std::find(numbers.begin(), numbers.end(), 30);

    if (it != numbers.end()) {
        std::cout << "找到值为 30 的元素在容器中的位置：" << std::distance(numbers.begin(), it) << std::endl;
    }
    else {
        std::cout << "未找到值为 30 的元素" << std::endl;
    }

    return 0;
}

//找到值为 30 的元素在容器中的位置：2