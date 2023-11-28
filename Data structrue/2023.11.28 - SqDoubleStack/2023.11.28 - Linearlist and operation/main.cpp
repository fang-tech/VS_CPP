#include <iostream>

const int Max_Size = 50;

typedef int Status;
typedef int SElemType;
const Status OK = 1;
const Status ERROR = 0;
;

struct SqDoublestack {
	SElemType data[Max_Size];
	int top1;//ջ1ջ��ָ��
	int top2;//ջ2ջ��ָ��
};

Status Push(SqDoublestack* S, int e, int stackNumber);

int main() {
	using namespace std;

}

Status Push(SqDoublestack* S, int e, int stackNumber) {//��ĳһ�����ջѹ��
	if (S->top1 + 1 == S->top2) //ջ����
		return ERROR;
	if (stackNumber == 1)
		S->data[++S->top1] = e;
	if (stackNumber == 2)
		S->data[++S->top2] = e;
	return OK;
}
Status Pop(SqDoublestack* S, int* e, int stackNumber) {
	
	if (stackNumber == 1) {
		if (S->top1 == -1)
			return ERROR;
		*e = S->data[S->top1--];//��ջ1��ջ��Ԫ�س�ջ
	}
	if (stackNumber == 2) {
		if (S->top2 == -1)
			return ERROR;
		*e = S->data[S->top2--];//��ջ2��Ԫ�س�ջ
	}
	return OK;
}