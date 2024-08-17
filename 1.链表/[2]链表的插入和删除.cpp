
#include <iostream>
using namespace std;

struct ListNode{
	// 数据域
	int val;
	// 指针域，指向下一个节点，也就是保存下一个节点的地址
	ListNode* next;
};

void printList(ListNode* head){
	ListNode* p = head;
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
    cout << endl;
} 

// 尾插法创建链表
void InsertTail(ListNode* &head, int v){

    // 如果这是一个空链表，说明 L == NULL
    if (head == NULL)
    {
        ListNode* newNode = new ListNode;
        head = newNode;
        head -> val = v;
        head -> next = NULL;
        return;
    }
    
    // 先找到尾节点
    // 尾节点的next是指向NULL
    // 定义一个指针p->next  == NULL 说明p已经指向最后一个结点了
    ListNode* p = head;
    // 找到最后一个结点
    while(p->next != NULL){
        p = p->next;
    }
    // 此时p指向最后一个节点
    // 先定义一个节点
    ListNode* newNode = new ListNode();
    newNode -> val = v;
    newNode -> next = NULL;
    // 将新节点插入到最后一个节点后面
    p->next = newNode;
}

// 定义头插法插入节点
void InsertHead(ListNode* &head, int v){
    // 定义一个新节点
    ListNode* newNode = new ListNode();
    newNode -> val = v;
    newNode -> next = head;  // 新节点的next指向NULL
    
    head = newNode;
}

// int main(){
// 	// 创建一个头节点
// 	// C风格：ListNode* L = （ListNode*）malloc(sizeof(ListNode));
// 	ListNode* head = new ListNode();
// 	head->val = 0;
// 	head->next = NULL;

// 	ListNode* l1 = new ListNode();
// 	l1->val = 10;
// 	l1->next = NULL;

// 	ListNode* l2 = new ListNode();
// 	l2->val = 20;
// 	l2->next = NULL;

// 	// 将这三个节点链接起来
// 	head->next = l1;
// 	l1->next = l2;
// 	l2->next = NULL;
// 	// 遍历链表
// 	printList(head);

//     // 通过尾插法，插入新节点
//     InsertTail(head, 30);
//     printList(head);

// 	return 0;
// }
int main(){
    // 通过尾插法，创建链表
    ListNode* head = NULL;
    InsertTail(head, 10);
    InsertTail(head, 20);
    InsertTail(head, 30);

    printList(head);

    // 通过头插法，插入新节点
    InsertHead(head, 40);
    InsertHead(head, 50);
    printList(head);
    return 0;
}