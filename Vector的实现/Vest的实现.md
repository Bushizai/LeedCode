# 1、vector

std::vector 是一个动态数组，它在内存中以连续的块存储元素。与静态数组相比，std::vector 允许在运行时动态调整大小，而无需手动管理内存。

# 2、内存管理

std::vector 维护了两个重要的状态信息：容量（capacity）和大小（size）。

容量表示当前 vector 分配的内存空间大小，而大小表示 vector 当前包含的元素数量。当向 vector 中添加元素时，如果元素数量超过了容量，就需要进行内存重新分配。

**内存分配和释放是** **std::vector** **内部的重要操作。**

当容量不足以容纳新元素时，std::vector 会分配一块新的内存空间，将原有元素复制到新的内存中，然后释放原内存。这个过程确保了元素的连续存储。

**动态扩容策略：**

为了提高性能，std::vector 采用了一种称为“指数增长（exponential growth）”的策略进行动态扩容。

当需要进行扩容时，std::vector 通常会将容量翻倍，以避免频繁的内存分配操作，从而减少系统开销。

这种指数增长策略确保了平均情况下的插入操作具有常数时间复杂度，而不是线性时间复杂度。

**随机访问和迭代器：**

std::vector 提供了高效的随机访问能力，即通过索引直接访问元素。

这是因为元素在内存中是连续存储的，通过简单的指针运算即可实现 O(1) 时间复杂度的访问。

**性能考虑**

std::vector 在许多场景下表现出色，但需要注意的是，在频繁插入或删除元素的情况下，std::vector 可能不是最佳选择，因为这样的操作可能触发频繁的动态扩容，导致性能下降。

在这种情况下，考虑使用 **std::deque** 或 **std::list** 这样的容器（后面会有讲解），**它们对插入和删除操作有更好的性能。**

# 2、vector的基本用法

它位于  头文件中，使用时需要包含该头文件： 

```c
#include <vector>
```

## 2.1、创建和初始化和元素访问

```cpp
std::vector<int> vec1;                                // 空的vector，数据类型为int
std::vector<int> vec2(4);                             // 4个值为0的vector
std::vector<int> vec3 (4,10);                         // 4个值为10的vector [10 10 10 10]
std::vector<int> vec4 (vec3.begin(),vec3.end());      // [10 10 10 10]
std::vector<int> vec5 (vec3);                         // [10 10 10 10]
std::vector<int> vec6 = {10, 20, 30, 40};             // [10 20 30 40] 
#include <iostream>
#include <vector>

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
First element: 42
Size of myVector: 1
```

## 2.2、[vector的增删查改](https://blog.csdn.net/Crocodile1006/article/details/131797666#2vector_9)

### 2.2.1、push_back尾插

**push_back()****函数用于向容器的末尾添加一个元素。** 它接受一个参数，即要添加的元素的值（或对象）。当向 vector 容器中添加元素时，其大小会动态增长，以容纳新添加的元素。

  下面是push_back()函数的定义和用法示例：

  我们创建了一个空的std::vector容器 numbers。然后使用push_back()函数向容器中添加元素。我们连续添加了三个元素，分别是 10、20 和 30。

  最后，我们打印出容器的大小和元素，可以看到容器的大小为 3，并且容器中的元素分别为 10、20 和 30。

  **通过使用****push_back()****函数，我们可以轻松地向std::vector容器中添加元素，无需手动调整容器的大小。这使得在需要动态添加元素的情况下，使用vector变得更加方便和灵活。**

```cpp
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
```

​             

### 2.2.2、pop_back 尾删

**pop_back()****函数用于移除容器中的最后一个元素。****它不接受任何参数。** 调用pop_back()函数将使容器的大小减小1。

  下面是pop_back()函数的定义和使用示例：

  我们首先创建一个包含5个元素的std::vector容器 numbers。然后打印出容器的初始大小和元素。接下来，我们调用 pop_back() 函数来删除容器中的最后一个元素。

  在这种情况下，最后一个元素 50 被从容器中移除。最后，我们再次打印容器的大小和元素，可以看到容器的大小减小了1，元素变为 10 20 30 40。

  **使用****pop_back()****函数，我们可以方便地从std::vector容器中删除最后一个元素，而无需手动调整容器的大小。这对于需要按照特定顺序添加和删除元素的情况非常有用。**

```cpp
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
```

### 2.2.3、find 查找

**知识点扩充**

[**c++ auto类型说明符**](https://blog.csdn.net/lihao161530340/article/details/77924866)**（**[**https://blog.csdn.net/lihao161530340/article/details/77924866**](https://blog.csdn.net/lihao161530340/article/details/77924866)**）**

 find()函数用于在容器中搜索给定的值，并返回指向第一个匹配元素的迭代器。如果找不到匹配的元素，则返回指向容器末尾的迭代器 end()。

  下面是find()函数的定义和使用示例：

  使用 find() 函数，我们可以方便地在 std::vector 容器中查找指定的值，并获得该元素在容器中的位置。这对于搜索和定位特定元素很有用。请注意，在使用 find() 函数之前，需要包含头文件 < algorithm >。

```cpp
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
```

### 2.2.4、insert 在position之前插入val

insert()函数用于在指定位置之前插入一个或多个元素。它接受两个参数，第一个是要插入的位置的迭代器，第二个是要插入的元素或范围。

  其中，pos是指定插入位置的迭代器，val 是要插入的元素的值。

  使用insert()函数，我们可以向std::vector容器中指定的位置插入一个或多个元素，从而在容器中实现元素的插入操作。这对于在特定位置插入新元素或在容器中间插入一段连续的元素非常有用。

  下面是insert()函数的定义和使用示例：

**1.在指定位置插入一个元素：**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50}; // 创建一个包含5个元素的int类型的vector容器
    
    // 在位置 index=2 插入一个元素 15
    auto it = numbers.insert(numbers.begin() + 2, 15);

    std::cout << "容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}

//容器的元素为：10 20 15 30 40 50
```

**2.在指定位置插入多个元素：**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50}; // 创建一个包含5个元素的int类型的vector容器
    
    // 在位置 index=2 插入三个元素: 15, 25, 35
    numbers.insert(numbers.begin() + 2, {15, 25, 35});

    std::cout << "容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}

//容器的元素为：10 20 15 25 35 30 40 50
```

### 2.2.5、erase 删除指定位置的数据

erase()函数用于从容器中删除一个或一段元素。 它接受一个或两个参数，第一个参数是要删除的位置或范围的迭代器。

  使用erase()函数，我们可以从std::vector容器中删除一个或一段指定位置的元素，实现对容器中元素的删除操作。这对于删除特定位置的元素或删除一段连续的元素非常有用。

  以下是erase()函数的定义和使用示例：

**1.删除指定位置的一个元素:**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50}; // 创建一个包含5个元素的int类型的vector容器
    
    // 删除位置为 index=2 的元素
    auto it = numbers.erase(numbers.begin() + 2);

    std::cout << "容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}

//容器的元素为：10 20 40 50
```

**2.删除指定范围的一段元素:**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50}; // 创建一个包含5个元素的int类型的vector容器
    
    // 删除从 index=1 到 index=3 的元素
    numbers.erase(numbers.begin() + 1, numbers.begin() + 4);

    std::cout << "容器的元素为：";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}

//容器的元素为：10 50
```

### 2.2.6、swap 交换两个vector的数据空间

swap()函数用于交换两个对象的值。 它接受两个参数，即要交换值的对象。

  swap() 函数可用于交换任意类型的对象值，包括基本数据类型、自定义类型和STL容器等。它是一个非常方便的函数，可以快速交换对象的值，避免了手动进行临时变量的赋值操作。

  以下是 函数的定义和使用示例：

```cpp
#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    std::cout << "交换前，a = " << a << ", b = " << b << std::endl;

    std::swap(a, b);

    std::cout << "交换后，a = " << a << ", b = " << b << std::endl;

    return 0;
}

//交换前，a = 10, b = 20
//交换后，a = 20, b = 10
```

### 2.2.7、operator[ ] 像数组一样访问

operator[]是一个重载运算符，用于通过索引访问容器、数组、字符串等类似的可索引的数据结构的元素。 它使我们可以像使用数组一样使用容器。

  通过使用 operator[] 运算符，我们可以根据索引访问容器中的元素，就像使用数组一样。注意，索引从0开始，直到容器的 size()-1。

  需要注意的是，当使用 operator[] 运算符访问容器的元素时，没有边界检查。因此，如果索引超出容器的有效范围，会导致未定义的行为。在实际应用中，确保索引的合法性是非常重要的。

  **以下是operator[]的定义和使用示例：**

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {10, 20, 30, 40, 50};

    std::cout << "容器的元素为：";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

//容器的元素为：10 20 30 40 50
```

## 3、vector 工作原理

C++中vector的数组内存通常是在堆上分配的。当创建一个vector对象时，对象本身（即vector的控制结构，包括指向数据的指针、大小和容量等）通常存储在栈上（如果是局部变量）或其他存储区（如全局/静态存储区），但实际的元素数据是在堆上分配的。

这种设计允许vector在运行时动态增长和收缩，因为堆是用于动态内存分配的区域，没有固定的大小限制（除了可用内存的物理限制）。当调用vector的push_back等方法时，vector可能会重新分配其底层的动态数组以适应新元素。这通常涉及申请新的更大的内存块，复制现有元素到新内存，添加新元素，然后释放旧的内存块。在C++官方实现的vector中，这种动态内存管理通常是通过分配器来完成的，vector使用一个默认的分配器std::allocator，它封装了动态内存分配函数，如new和delete。开发者也可以为vector提供自定义的分配器，以适应特定的内存分配策略。

以上的内容配合下图说明就显得通俗易懂了：

![img](https://cdn.nlark.com/yuque/0/2024/png/42476657/1720329590371-d9780df4-30eb-4cd2-acb8-114726b91e8c.png)图例说明如下：

1. 虚线以上的内存为**栈内存**，虚线以下的内存为**堆内存**
2. 红色区域为vector对象控制结构存储的位置
3. **紫色区域**和**灰色区域**为存储元素的数组的位置, 其中**紫色区域**表示已经使用, **灰色区域**表示未使用

在这个案例中, 有一个vector<int> v对象, 其控制结构存储在在了栈上, 包括size, capacity, data pointer,分别表示数组已经使用的大小、数组的容量、数组的首地址, 最左边表示初始时刻的堆栈状态, 某时刻调用v.push_back(2), 检查发现此操作不会超出容量上限, 因此在中间的堆栈示意图中插入了2, 并更新控制结构中的size = 2, 下一时刻调用v.push_back(3), 此时检查发现此操作要求的容量不足, 因此需要重新在堆内存申请容量为4的内存空间, 如最右边的示意图所示, 并且复制原来的内容到新的地址, 完成此操作后可以丢弃原来的堆内存空间, 并插入3。

## 4、实现vector

Vector 类包含了构造函数、析构函数、拷贝构造函数、拷贝赋值操作符、添加元素、获取元素个数、获取容量、访问元素的功能。

先贴出整体的基本实现代码, 然后再一一解释:

**知识点补充** 

**1、**[**关于C++类模板template＜typename T＞的使用**](https://blog.csdn.net/weixin_43011182/article/details/116806175?ops_request_misc=%7B%22request%5Fid%22%3A%22172034186516800188568137%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=172034186516800188568137&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-116806175-null-null.142^v100^pc_search_result_base8&utm_term=template &spm=1018.2226.3001.4187)

**2、**[**vector容器中resize()与reserve()的区别及用法**](https://blog.csdn.net/dffffffff1/article/details/124245023?ops_request_misc=%7B%22request%5Fid%22%3A%22172036115816800182796488%22%2C%22scm%22%3A%2220140713.130102334..%22%7D&request_id=172036115816800182796488&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-2-124245023-null-null.142^v100^pc_search_result_base8&utm_term=reserve&spm=1018.2226.3001.4187)

```cpp
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
```

- 1、构造函数 构造函数很简单, 就是把所有内容赋值为0或空指针

```cpp
Vector() : elements(nullptr), capacity(0), size(0) {}
```

- 初始化 `Vector` 对象，其中 `elements` 是指向 `T` 类型动态数组的指针，初始时没有分配内存（`nullptr`）；
- `capacity` 表示数组的容量，初始为 0；
- `size` 表示数组中当前元素的数量，初始也为 0。



# 5、双重vector

```cpp
#include <vector>
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    // 定义并初始化 regionList
    vector<vector<Point> > regionList;

    // 创建一些 Point 对象
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};

    // 创建一个内层向量并添加点
    vector<Point> region1;
    vector<Point> region2;
    region1.push_back(p1);
    region1.push_back(p2);
    region2.push_back(p3);

    // 添加内层向量到外层向量
    regionList.push_back(region1);
    regionList.push_back(region2);

    // 输出 regionList 的内容
    for (const auto& region : regionList) {
        std::cout << "Region:" << std::endl;
        for (const auto& point : region) {
            std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
        }
    }

    return 0;
}
// OUT
zhangbushi@zhangbushideMacBook-Air test % ./vector
Region:
(1, 2)
(3, 4)
Region:
(5, 6)
zhangbushi@zhangbushideMacBook-Air test % 
```

注意事项：两种写法都可以。

```cpp
#include <vector>
#include <iostream>

struct Point {
    int x;
    int y;
};

int main() {
    // 定义并初始化 regionList
    std::vector<std::vector<Point>> regionList;

    // 创建一些 Point 对象
    Point p1 = {1, 2};
    Point p2 = {3, 4};
    Point p3 = {5, 6};

    // 创建一个内层向量并添加点
    std::vector<Point> region1 = {p1, p2};
    std::vector<Point> region2 = {p3};

    // 添加内层向量到外层向量
    regionList.push_back(region1);
    regionList.push_back(region2);

    // 输出 regionList 的内容
    for (const auto& region : regionList) {
        std::cout << "Region:" << std::endl;
        for (const auto& point : region) {
            std::cout << "(" << point.x << ", " << point.y << ")" << std::endl;
        }
    }

    return 0;
}
```
