
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
} 

int main(){
	// 创建一个头节点
	// C风格：ListNode* L = （ListNode*）malloc(sizeof(ListNode));
	ListNode* head = new ListNode();
	head->val = 0;
	head->next = NULL;

	ListNode* l1 = new ListNode();
	l1->val = 10;
	l1->next = NULL;

	ListNode* l2 = new ListNode();
	l2->val = 20;
	l2->next = NULL;

	// 将这三个节点链接起来
	head->next = l1;
	l1->next = l2;
	l2->next = NULL;

	// 遍历链表
	printList(head);
	cout << endl;

	return 0;
}