
struct node {
	int value;
	node* next;
	node* prior;
};

typedef int Status;
typedef struct node Linklist;

const Status ok = 1;
const Status error = 0;

Status add_node(Linklist *head, int i, int* e) {
	int j;
	Linklist *p,*s;
	p = head;
	j = 1;
	while (head && j < i) {

		p = p->next;
		j++;
	}
	if (!head || j > i)
		return error;
	s = new Linklist;
	s->value = *e;
	s->next = p->next;
	p->next = s;
	return ok;
}