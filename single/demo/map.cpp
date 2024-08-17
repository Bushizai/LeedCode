//使用find来找到指定map元素
#include <iostream>
#include <map>
using namespace std;
 
int main() 
{
// ===========================================  map的定义和插入  ========================================//
    cout << "==================== map的定义和insert函数 =====================" << endl;
    /*
    一般定义 键的类型为string，值的类型为int,排序方式为值升序排序
    map<string, int> map0;
    */
    //第一种：用insert函数插入pair数据：
    map<int,string> map1;
    map1.insert(pair<int,string>(1,"first"));
    map1.insert(pair<int,string>(2,"second"));

    //第二种：用insert函数插入value_type数据：
    map1.insert(map<int,string>::value_type(3,"three"));
    map1.insert(map<int,string>::value_type(4,"four"));
    
    //第三种：用数组的方式直接赋值：
    map1[5]="five";
    map1[6]="six";


    map<int, string>::iterator it; 
    for(it=map1.begin(); it!=map1.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
    // for (const auto& pair : map1)
    // {
    //     cout << pair.first << " " << pair.second << endl;
    // }

// ===========================================  map的定义和插入  ========================================//

// ===========================================  map的查找find  ========================================//
    cout << "==================== find函数 =====================" << endl;
    map<int, string> ma = {{1, "one"}, {2, "two"}, {3, "three"}};
    
    auto it0 = ma.find(2);
    if (it0 != ma.end()) {
        cout << "Found: " << it0->first << " => " << it0->second << endl;
    } else {
        cout << "Key not found." << endl;
    }
// ===========================================  map的查找find  ========================================//

// ===========================================  erase和for迭代  ========================================//
    cout << "==================== erase函数和map的三种迭代方式 =====================" << endl;
    //erase里的参数可以直接写键，也可以写迭代器。
    map<int, string> map2 = {{1, "zhang"}, {2, "bushi"}, {3, "xiaochou"}};
    /*
    1、用迭代器，成片的删除,一下代码把整个map清空
    2、成片删除要注意的是，也是STL的特性，删除区间是一个前闭后开的集合
    map1.erase( map1.begin(), map1.end() );  
    */ 
    auto it1 = map2.find(1);  
    if (it1 != map2.end())
    {
        map2.erase(it1);                   //如果要删除1，用关键字删除
    } else 
    {
        cerr << "Key 1 not found for deletion." << endl;
    }
         
    int n = map2.erase(1);            //如果删除了会返回1，否则返回0
    // ============= map的三种迭代方式 ================== //
    //第一种：通过迭代器迭代
    for(it=map2.begin(); it!=map2.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    for (const auto& pair1 : map2)
    {
        cout << pair1.first << " " << pair1.second << endl;
    }

    for ( auto pair2 : map2) {
        cout << pair2.first << " " << pair2.second << endl;
    }
    // ============= map的三种迭代方式 ================== //
// ===========================================  erase和for迭代  ========================================//   
 
// ===========================================  find和count函数  ========================================// 
    /*
    查找数据有两种办法，一个使用find函数还有一个是用count函数（当然了，你查找数据，很明显要查找的
    肯定是键吧，没有查找值的吧，哈哈哈）
    （1）find函数
    find函数查找成功会返回指向它的迭代器，没有找到的话，返回的是end这个迭代器
    
    - 使用`find()`时，如果找到了键，你可以直接访问该键对应的值。
    `find()`更适合在找到键时需要对值进行操作的场景。
    
    （2）count函数
    count函数的意思就是查找这个键的出现次数，map中键是唯一的，所以它的值要么是0
    要么是1，是1不就是查找成功吗，不过它的缺点也可以知道，它可以确定是否存在这个
    键，可是却不能确定这个键的位置
    
    - 使用`count()`可以快速检查键是否存在，但它不提供对找到的元素的直接访问。
    `count()`适用于仅需要检查键存在性的场景。
    */
    cout << "==================== find and count函数的使用 =====================" << endl;
    map<int, string> zbs = {{6, "python"}, {16, "c"}, {3, "c++"}, {2, "java"}};
    auto f = zbs.find(2);
    if (f != zbs.end()) {
        cout << "Found: " << f->first << " => " << f->second << endl;
    } else {
        cout << "Key not found." << endl;
    }
    if (zbs.count(2) > 0) {
        cout << "Key found." << endl;
    } else {
        cout << "Key not found." << endl;
    }
    return 0;
}