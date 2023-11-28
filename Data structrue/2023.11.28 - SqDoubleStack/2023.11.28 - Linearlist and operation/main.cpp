#include <iostream>

const int Max_Size = 50;

typedef int Status;
typedef int SElemType;
const Status OK = 1;
const Status ERROR = 0;
;

struct SqDoublestack {
	SElemType data[Max_Size];
	int top1;//栈1栈顶指针
	int top2;//栈2栈顶指针
};

Status Push(SqDoublestack* S, int e, int stackNumber);

int main() {
	using namespace std;

}

Status Push(SqDoublestack* S, int e, int stackNumber) {//将某一方向的栈压入
	if (S->top1 + 1 == S->top2) //栈已满
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
		*e = S->data[S->top1--];//将栈1的栈顶元素出栈
	}
	if (stackNumber == 2) {
		if (S->top2 == -1)
			return ERROR;
		*e = S->data[S->top2--];//将栈2的元素出栈
	}
	return OK;
}