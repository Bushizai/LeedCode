#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <stdexcept>


// 在大多数情况下，typename 和 class 可以互换使用来声明类型模板参数。
// 在引用依赖于模板参数的嵌套类型时，必须使用 typename。
// 在声明模板模板参数时，必须使用 class。
template <typename T>
class Vector
{
private:
    T *elements;     // 指向动态数组的指针
    size_t capacity; // 数组的容量
    size_t size;     // 数组中元素的个数

public:
    // 构造函数（初始化的作用）
    Vector() : elements(nullptr), capacity(0), size(0) {}

    // 析构函数
    ~Vector()
    {
        delete[] elements;  // 
    }

    // 拷贝构造函数
    Vector(const Vector &other) : capacity(other.capacity), size(other.size)
    {
        elements = new T[capacity];
        std::copy(other.elements, other.elements + size, elements);
    }

    // 拷贝赋值操作符
    Vector &operator=(const Vector &other)
    {
        // 检查自赋值的情况
        if (this != &other)
        {
            delete[] elements;
            capacity = other.capacity;
            size = other.size;
            elements = new T[capacity];
            std::copy(other.elements, other.elements + size, elements);
        }
        return *this;
    }

    // 添加元素到数组末尾
    void push_back(const T &value)
    {
        // // 如果数组中的有效元素与容量相同，进行扩容
        if (size == capacity)
        {
            // 不能简单的将capacity容量翻倍, 需要考虑0的边界情况
            reserve(capacity == 0 ? 1 : 2 * capacity);
        }
        elements[size++] = value;
    }

    // 获取数组中元素的个数
    size_t getSize() const
    {
        return size;
    }

    // 获取数组的容量
    size_t getCapacity() const
    {
        return capacity;
    }

    // 访问数组中的元素
    T &operator[](size_t index)
    {
        // 检查索引是否越界
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }


    /*
    # const版本的访问数组中的元素
    1、const T&：返回类型是一个常量引用。返回一个常量引用意味着调用者不能通过这个引用来修改返回的元素。这种设计可以避免不必要的拷贝，同时保证元素的不可变性。
    2、operator[]：这是下标运算符的重载，使对象可以像数组一样通过下标访问元素。
    3、size_t index：参数是一个 size_t 类型的索引，用来访问特定位置的元素。size_t 是一种无符号整数类型，通常用来表示尺寸或计数。
    4、const（函数后面的修饰符）：表示这是一个 const 成员函数，不能修改类的成员变量。这意味着这个函数可以被 const 对象调用。
    */
    const T &operator[](size_t index) const
    {
        // 检查索引是否越界
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    /*
    # 在指定位置插入元素
    1、参数 value 是一个 const 类型的引用，表示要插入的元素。
    2、使用 const 引用避免了不必要的拷贝，并保证传入的值不会被修改。
    3、T 是一个模板参数，表示该函数可以处理任意类型的元素。
    */
    void insert(size_t index, const T &value)
    {
        if (index > size)
        {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity)
        {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        for (size_t i = size; i > index; --i)
        {
            elements[i] = elements[i - 1];
        }
        elements[index] = value;
        ++size;
    }

    // 删除数组末尾的元素
    void pop_back()
    {
        if (size > 0)
        {
            --size;
        }
    }

    // 清空数组
    void clear()
    {
        size = 0;
    }

    /*
    # 使用迭代器遍历数组的开始位置
    1、返回值是T模板类型的指针
    */
    T *begin()
    {
        return elements;
    }

    // 使用迭代器遍历数组的结束位置
    T *end()
    {
        return elements + size;
    }

    
    /*
    # 使用迭代器遍历数组的开始位置（const版本）
    1、const T&：返回类型是一个常量引用。返回一个常量引用意味着调用者不能通过这个引用来修改返回的元素。这种设计可以避免不必要的拷贝，同时保证元素的不可变性。
    2、const（函数后面的修饰符）：表示这是一个 const 成员函数，不能修改类的成员变量。这意味着这个函数可以被 const 对象调用。    
    */

    const T *begin() const
    {
        return elements;
    }

    // 使用迭代器遍历数组的结束位置（const版本）
    const T *end() const
    {
        return elements + size;
    }

    // 打印数组中的元素
    void printElements() const
    {
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    // 扩展数组容量
    void reserve(size_t newCapacity)
    {
        if (newCapacity > capacity)
        {
            T *newElements = new T[newCapacity];
            std::copy(elements, elements + size, newElements);
            delete[] elements;
            elements = newElements;
            capacity = newCapacity;
        }
    }
};

int main()
{
    // 创建一个 Vector 对象
    Vector<int> myVector;

    int N;
    std::cin >> N;
    // 读走回车
    // getchar();

    std::string line;
    for (int i = 0; i < N; i++)
    {
        // 读取整行
        /*
        1、使用std::getline函数从标准输入（通常是键盘输入）读取一行文本，直到遇到换行符（\n），但不包括换行符本身，
        然后将读取到的内容存储在字符串line中。这样，你就可以一次性获取用户输入的一整行文本。
        ---------------------------------------------------------------------------------------------------------
        2、使用line字符串初始化了一个std::istringstream对象iss。std::istringstream是C++标准库中的一个类，
        它允许你从一个字符串中读取数据，就像从一个文件或标准输入中读取一样。这意味着你可以使用输入操作符（如>>）从iss中读取数据，
        就像从std::cin中读取一样。
        ---------------------------------------------------------------------------------------------------------
        3、这两行代码定义了一个std::string类型的变量command，并使用输入操作符>>从之前创建的iss（即输入字符串流）中读取第一个单词
        （或第一个由空白字符分隔的字符串序列）到command中。这里的“空白字符”通常包括空格、制表符、换行符等。因此，如果line包含多个由
        空格分隔的单词，command将只包含第一个单词。
        */
        std::getline(std::cin, line);
        std::istringstream iss(line);
        std::string command;
        iss >> command;

        if (command == "push")
        {
            int value;
            iss >> value;
            myVector.push_back(value);
        }
        else if (command == "print")
        {
            if (myVector.getSize() == 0) {
                std::cout << "empty" << std::endl;
                continue;
            }
            myVector.printElements();
        }
        else if (command == "size")
        {
            std::cout << myVector.getSize() << std::endl;
        }
        else if (command == "get")
        {
            int index;
            iss >> index;
            std::cout << myVector[index] << std::endl;
        }
        else if (command == "insert")
        {
            int index, value;
            /*
            这行代码的作用是从 iss 中读取两个整数值，分别赋给 index 和 value 变量。
            输入流通过空格、换行符或其他空白字符来分隔这两个值。
            */
            iss >> index >> value;
            myVector.insert(index, value);
        }
        else if (command == "pop")
        {
            myVector.pop_back();
        }
        else if (command == "iterator")
        {
            if (myVector.getSize() == 0)
            {
                std::cout << "empty" << std::endl;
                continue;
            }
            for (auto it = myVector.begin(); it != myVector.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
        else if (command == "foreach")
        {
            if (myVector.getSize() == 0)
            {
                std::cout << "empty" << std::endl;
                continue;
            }
            for (const auto &element : myVector)
            {
                std::cout << element << " ";
            }
            std::cout << std::endl;
        }
        else if (command == "clear")
        {
            myVector.clear();
        }
    }
    return 0;
}