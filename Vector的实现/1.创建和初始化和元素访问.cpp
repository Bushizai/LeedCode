
#include <iostream>
#include <vector>

// std::vector<int> vec1;                                // 空的vector，数据类型为int
// std::vector<int> vec2(4);                             // 4个值为0的vector
// std::vector<int> vec3 (4,10);                         // 4个值为10的vector [10 10 10 10]
// std::vector<int> vec4 (vec3.begin(),vec3.end());      // [10 10 10 10]
// std::vector<int> vec5 (vec3);                         // [10 10 10 10]
// std::vector<int> vec6 = {10, 20, 30, 40};             // [10 20 30 40] 

int main() {
    // 创建一个空的 vector
    std::vector<int> myVector;

    // 使用初始化列表创建 vector
    std::vector<int> myVector2 = {1, 2, 3, 4, 5};

    // 在尾部插入元素
    myVector.push_back(42);

    // 使用下标访问元素
    std::cout << "First element: " << myVector[0] << std::endl;

    // 打印 vector 的大小
    std::cout << "Size of myVector: " << myVector.size() << std::endl;

    return 0;
}
// First element: 42
// Size of myVector: 1