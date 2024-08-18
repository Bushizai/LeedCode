#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50}; // 创建一个包含5个元素的int类型的vector容器
    
    std::cout << "初始容器的大小为：" << numbers.size() << std::endl;
    std::cout << "初始容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    numbers.pop_back(); // 移除最后一个元素

    std::cout << "调用pop_back()后的容器的大小为：" << numbers.size() << std::endl;
    std::cout << "调用pop_back()后的容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}

//初始容器的大小为：5
//初始容器的元素为：10 20 30 40 50 
//调用pop_back()后的容器的大小为：4
//调用pop_back()后的容器的元素为：10 20 30 40 