#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50}; // 创建一个包含5个元素的int类型的vector容器
    
    // 在位置 index=2 插入一个元素 15
    auto it = numbers.insert(numbers.begin() + 2, 15);

    std::cout << "插入单个元素：容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // 在位置 index=2 插入三个元素: 150, 250, 350
    numbers.insert(numbers.begin() + 2, {150, 250, 350});

    std::cout << "插入多个元素：容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}

// 插入单个元素：容器的元素为：10 20 15 30 40 50 
// 插入多个元素：容器的元素为：10 20 150 250 350 15 30 40 50 