#include <iostream>

struct Value {
	int number;
	int length;
	};
struct Node {
	struct Point {
		Node* next;
	}p;
	Value num;
};


typedef int Status;
typedef Node* Linklist;
const Status OK = 1;
const Status ERROR = 0;

Node* creat_num_list(void);//创建一个链表，由输入数字来创建,返回链表头
Status GetElement(Linklist L, int i, Value* v);//读入一个表头，然后返回第i个结点的数据。
Status ListInsert(Linklist L, int i, Value* v);//在L中的第i个结点的位置之前插入新的元素v，L的长度加1（将头结点算入
Status ListDelete(Linklist* L, int i, Value* v);//删除L的第i个结点，并用v返回其值，L的长度减一
void CreateListHead(Linklist* L, int n);//随机产生n个元素的值，建立带表头结点的单链表(头插法
void CreateListTail(Linklist* L, int n);//尾插法
Status ClearList(Linklist* L);//删除整个链表

int main() {
	using namespace std;
	Linklist Head = creat_num_list();
	int i;
	Value v;
	cout << "\nPlease enter the number you want to read " << endl;
	cin.clear();
	cin.get();
	cin >> i;
	while (!GetElement(Head, i, &v)) {
		cout << "Please enter a number between " << 1 << " to " << Head->num.length << "\n";
		cin.clear();
		cin.get();
		cin >> i;
	}
	cout << "The number is " << v.number << endl;
	cout << "Enter the position you wanna insert : ";
	cin >> i;
	cout << "\nEnter the element you want to instert : ";
	cin >> v.number;
	ListInsert(Head, i, &v);
	cout << "\n";
	for (Linklist n = Head->p.next; n; n = n->p.next) {
		cout << n->num.number << "\t";
	}
}
Linklist creat_num_list(void) {
	using namespace std;
	Linklist Head = NULL;
	Linklist h_node = new Node;
	h_node->num.length = 0;
	h_node->p.next = NULL;
	Head = h_node;//头指针指向头结点
	int number;
	Linklist q = h_node;
	while (cin >> number) {
		Linklist p = new Node;
		p->num.number = number;
		p->p.next = NULL;//将新结点的数据存放好
		q->p.next = p;
		q = p;
		h_node->num.length++;
	}
	cout << h_node->num.length << "\n";
	for (Linklist n = Head->p.next; n; n = n->p.next) {
		cout << n->num.number << "\t";
	}
	return Head;
}

Status GetElement(Linklist L, int i, Value* v) {
	Linklist p = L->p.next;
	int j = 1;//计数器
	while (p && j < i && i > 0) {//查找到那个元素
		p = p->p.next;
		j++;
	}
	if (!p || j > i) {//当j大于i或者p为空的时候即读取到了链表的末尾的时候
		return ERROR;
	}
	*v = p->num;
	return OK;
}

Status ListInsert(Linklist L, int i, Value* v) {
	Linklist p = NULL, q = NULL;
	int j = 1;
	for (p = L, q = L->p.next; p && q; p = q, q = q->p.next,j++) {
		if (j == i) {
			Linklist N = new Node;
			N->num = *v;
			p->p.next = N;
			N->p.next = q;
			return OK;
		}
	}
	return ERROR;

}
