#include <iostream>
#include <ctime>

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
Status ListDelete(Linklist L, int i, Value* v);//删除L的第i个结点，并用v返回其值，L的长度减一
void CreateListHead(Linklist L, int n);//随机产生n个元素的值，建立带表头结点的单链表(头插法
void CreateListTail(Linklist L, int n);//尾插法
Status ClearList(Linklist L);//删除整个链表
void PrintList(Linklist L);

int main() {
	using namespace std;
	Linklist Head = creat_num_list();
	Linklist p = NULL, q = NULL;
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
	while (!ListInsert(Head, i, &v)) {
		cout << "Please enter a number between " << 1 << " to " << Head->num.length << "\n";
		cin.clear();
		cin.get();
		cin >> i;
	}
	cout << "\n";
	PrintList(Head);
	cout << endl;
	cout << "Enter which node you wanna delete : ";
	cin >> i;
	cout << endl;
	if (ListDelete(Head, i, &v)) {
		PrintList(Head);
	}
	else {
		cout << "ERROR Delete ";
	}
	cout << "\nEnter how many node you wanna add at the head:";
	int n = 0;
	cin >> n;
	cout << "\nNow tht new Linklist will be displayed \n";
	CreateListHead(Head,n); 
	cout << endl;
	PrintList(Head);
	cout << "\nEnter how many node you wanna add at the tail:";
	cin >> n;
	CreateListTail(Head, n);
	for (Linklist m = Head->p.next; m->p.next; m = m->p.next) {
		cout << m->num.number << "\t";
	}
	cout << endl << "Now let us clear the Linklist and try to print it :" << endl;
	ClearList(Head);
	PrintList(Head);
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
			N->p.next=q;
			L->num.length++;
			return OK;
		}
	}
	return ERROR;

}
Status ListDelete(Linklist L, int i, Value* v) {
	Linklist p = NULL;
	p = L;
	int j = 1;
	while (p->p.next && j < i) {//寻找第i-1个结点
		p = p->p.next;
		j++;
	}
	if (!(p->p.next) || j > i)//当第i个结点不存在
		return ERROR;
	Linklist q = p->p.next;
	p->p.next = q->p.next;
	*v = q->num;
	delete q ;
	return OK;
}

void CreateListHead(Linklist L, int n) {//始终让新结点在第一的位置
	using namespace std;
	Linklist p = NULL;
	srand(unsigned int (time(0)));
	if(!L){
		Linklist hnode = new Node;
		L = hnode;//如果，头指针指向空，创建头指针与头结点
		hnode->num.length = 0;
	}
	int i;
	for (i = 0; i < n; i++) {
		Linklist in = new Node;
		in->num.number = rand() % 100 + 1;
		in->p.next = NULL;
		L->num.length++;
		if (L->p.next) {//如果头结点下面还由结点，则插入，否则创建该结点
			in->p.next = L->p.next;
			L->p.next = in;
		}
		else
			L->p.next = in;
	}
}
void CreateListTail(Linklist L, int n) {
	Linklist p = NULL, r = NULL;
	int i = 1;
	srand(unsigned int(time(0)));
	for (p = L; p->p.next; p = p->p.next)
		;
	for (i = 0; i < n; i++) {
		Linklist q = new Node;
		q->num.number = rand() % 100 + 1;
		q->p.next = NULL;
		p->p.next = q;//将新结点链接上链表末端
		p = q; //刷新最后的结点的位置 
		L->num.length++;
	}
	
}
Status ClearList(Linklist L) {
	Linklist q = NULL, p = NULL;
	p = L->p.next;
	while (p) {
		q = p->p.next;
		delete p;
		p = q;
	}
	L->p.next = NULL;
	/*if (L && L->p.next) {
		for (p = L->p.next, q = p->p.next; q->p.next; p = q, q = q->p.next) {
			delete p;
		}
	}
	else delete L;*/
	return OK;
}
void PrintList(Linklist L) {
	using namespace std;
	Linklist p = L->p.next;
	Linklist q = NULL;
	while (p) {
		q = p->p.next;
		cout << p->num.number << "\t";
		p = q;
	}

}