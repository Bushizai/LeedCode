#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/*
DATA：通过 typedef 关键字，将 struct pair 重命名为 DATA。这意味着 DATA 现在可以直接用来声明该结构体的实例。
*LPDATA：通过 typedef 关键字，将 struct pair* 重命名为 LPDATA。这意味着 LPDATA 现在可以直接用来声明该结构体的指针。
*/
typedef struct pair
{
    int key;   // 构造一个键出来 充当哈希地址的求解
    char element[20];  // 数据类型
}DATA, *LPDATA;

typedef struct hashTable
{
    LPDATA *table;  // 便于初始化，以及判断当前hash地址是否存在冲突
    int divisor;    // H(key)=key%p --> 限定hash地址的数目为 [0,p-1]
    int curSize;    // 当前哈希表的大小
}HASH, *LPHASH;

LPHASH createHashTable(int p)
{
    // malloc 函数为 HASH 结构体分配内存，并将其地址赋值给 LPHASH 类型的指针 hash。
    // malloc 返回的是 void* 类型的指针，因此需要进行强制类型转换为 LPHASH。
    LPHASH hash = (LPHASH)malloc(sizeof(HASH));
    assert(hash!= NULL);
    hash->divisor = p;
    hash->curSize = 0;
    hash->table = (LPDATA *)malloc(sizeof(LPDATA) * hash->divisor);
    assert(hash->table!= NULL);
    for (int i = 0; i < hash->divisor; i++)
    {
        hash->table[i] = NULL; // 表示这些位置当前没有存储任何数据。
    }
    return hash;
}

int search(LPHASH hash, int key)
{
    int pos = key % hash->divisor; // 不存在冲突的hash
    // 开放地址法
    int curPos = pos;
    do 
    {
        // key相同，采用覆盖的数据方式
        if (hash->table[curPos] == NULL || hash->table[curPos]->key == key)
            return curPos;
        curPos = (curPos + 1) % hash->divisor; // 寻找下一个空位
    } while (curPos!= pos);
    return curPos;
}

void insertData(LPHASH hash, DATA data)
{
    // 求hash地址
    int pos = search(hash, data.key);
    if (hash->table[pos] == NULL)
    {
        hash->table[pos] = (LPDATA)malloc(sizeof(DATA)); // 分配内存
        memcpy(hash->table[pos], &data, sizeof(DATA));
        hash->curSize++;
    }
    else
    {
        if (hash->table[pos]->key == data.key)
        {
            strcpy(hash->table[pos]->element, data.element); // 覆盖数据
        }
        else
        {
            printf("hash address conflict：哈希表已满，无法插入数据。\n");
        }
    }
}

void printHashTable(LPHASH hash)
{
    for (int i = 0; i < hash->divisor; i++)
    {
        if (hash->table[i]!= NULL)
        {
            printf("key:%d, element:%s\n", hash->table[i]->key, hash->table[i]->element);
        }
        else
        {
            printf("NULL");
        }
    }
}

int main ()
{
    LPHASH hash = createHashTable(10);
    DATA array[5] = {{1, "雷电"}, {11, "banana"}, {23, "orange"}, {44, "grape"}, {56, "pear"}};
    for (int i = 0; i < 5; i++)
    {
        insertData(hash, array[i]);
    }
    printHashTable(hash);
    return 0;
}