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

Node* creat_num_list(void);//����һ����������������������,��������ͷ
Status GetElement(Linklist L, int i, Value* v);//����һ����ͷ��Ȼ�󷵻ص�i���������ݡ�
Status ListInsert(Linklist L, int i, Value* v);//��L�еĵ�i������λ��֮ǰ�����µ�Ԫ��v��L�ĳ��ȼ�1����ͷ�������
Status ListDelete(Linklist* L, int i, Value* v);//ɾ��L�ĵ�i����㣬����v������ֵ��L�ĳ��ȼ�һ
void CreateListHead(Linklist* L, int n);//�������n��Ԫ�ص�ֵ����������ͷ���ĵ�����(ͷ�巨
void CreateListTail(Linklist* L, int n);//β�巨
Status ClearList(Linklist* L);//ɾ����������

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
	Head = h_node;//ͷָ��ָ��ͷ���
	int number;
	Linklist q = h_node;
	while (cin >> number) {
		Linklist p = new Node;
		p->num.number = number;
		p->p.next = NULL;//���½������ݴ�ź�
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
	int j = 1;//������
	while (p && j < i && i > 0) {//���ҵ��Ǹ�Ԫ��
		p = p->p.next;
		j++;
	}
	if (!p || j > i) {//��j����i����pΪ�յ�ʱ�򼴶�ȡ���������ĩβ��ʱ��
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
