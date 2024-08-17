/*
**[3]删除列表中的中间节点：
1、方式一：不单独添加头节点
2、方式二：添加一个空的头节点，在链表的最前端

**[4]在链表中插入一个新的结点
+ 情况1：空链表插入
+ 情况2：普通链表插入
*/
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

// 定义如何删除值为 val 的节点
// 不添加虚拟头节点
ListNode* removeNode(ListNode* head, int v)
{
    // 判断头节点是不是我们要删除的节点
    if (head != NULL && head->val == v) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    // 删除中间的非头节点的值为 v 的节点
    ListNode* cur = head;
    while (cur->next != NULL)
    {
        if (cur->next->val == v) {
            // 先定义一个temp，一会释放内存
            ListNode* temp = cur->next;
            // 保证不断链
            cur->next = cur->next->next;
            delete temp;
        }
        else {
            cur = cur->next;
        }
    }
    return head;
}
/*
ListNode* removeNode(ListNode* head, int v)、void fun(ListNode** L);、void fun(ListNode* &L)；三个之间的区别：
1、ListNode* removeNode(ListNode* head, int v)
这里但指针为什么可以改变指针变量，因为其返回类型是ListNode*指针，调用方式如下：
ListNode* head = NULL;  // 定义一个空列表
。。。。。（添加了一些节点）
head = removeNode(head, v);
也就是说removeNode返回的head赋值给前面的定义的空head

2、void fun(ListNode** L);
双指针的方式：是直接对传入的参数进行改变。
*/

// 添加虚拟头节点方式
ListNode* dummyRemoveNode(ListNode* head, int v)
{
    // 定义虚拟头节点
    ListNode* dummyhead = new ListNode;
    dummyhead -> next = head;  // 让虚拟头节点指向真实头节点
    dummyhead -> val = 0;  // 这个虚拟头节点的val值不会被使用可以随便设定，这里设定为0;
    // 删除中间的非头节点的值为 v 的节点
    ListNode* cur = dummyhead;
    while (cur->next != NULL)
    {
        if (cur->next->val == v) {
            // 先定义一个temp，一会释放内存
            ListNode* temp = cur->next;
            // 保证不断链
            cur->next = cur->next->next;
            delete temp;
        }
        else {
            cur = cur->next;
        }
    }
    return dummyhead->next;
}

ListNode* addNode(ListNode* head, int v, int insert_num)
{
    // 先定义虚拟头结点
    ListNode*dummyHead = new ListNode;
    dummyHead -> val = 0;
    dummyHead -> next = head;

    ListNode* cur = dummyHead;
    while(cur != NULL)
    {
        if(cur->val == v)
        {
            if (cur->val == v){
                // 创建一个新的结点
                ListNode* node = new ListNode;
                node->val = insert_num;
                node->next = cur->next;  // 先和cur后面的链表链接
                cur->next = node;  
            }
        }
        cur = cur->next;
    }
    return dummyHead->next;  // 返回虚拟头结点的下一个节点
}
void printList(ListNode* head)
{
    while (head != NULL)
    {
        cout << head -> val << " ";
        head = head -> next;
    }
    cout << endl;
}   

int main()
{
    ListNode* head = new ListNode;
    head -> val = 10;
    head -> next = NULL;

    ListNode* node1 = new ListNode;
    node1 -> val = 20;
    head -> next = node1;

    ListNode* node2 = new ListNode;
    node2 -> val = 30;   
    node1 -> next = node2;  
    node2 -> next = NULL;       

    printList(head);
    head = removeNode(head, 20);
    printList(head);
    head = dummyRemoveNode(head, 30);
    printList(head);

    // 给20后面插入一个8
    head = addNode(head, 10, 40);
    printList(head);
    return 0;
}