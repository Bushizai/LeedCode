#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers; // 创建一个空的int类型的vector容器

    numbers.push_back(10); // 添加元素 10
    numbers.push_back(20); // 添加元素 20
    numbers.push_back(30); // 添加元素 30

    std::cout << "容器的大小为：" << numbers.size() << std::endl;
    std::cout << "容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;
 
    return 0;
}

//容器的大小为：3
//容器的元素为：10 20 30