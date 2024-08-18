#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50, 60, 70, 80}; // 创建一个包含5个元素的int类型的vector容器
    
    // 删除位置为 index=2 的元素
    auto it = numbers.erase(numbers.begin() + 2);

    std::cout << "容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

        // 删除从 index=1 到 index=3 的元素
    numbers.erase(numbers.begin() + 1, numbers.begin() + 4);

    std::cout << "容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
