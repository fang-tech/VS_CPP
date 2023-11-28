#include <iostream>
int main() {
	using namespace std;
	char ch = 0;
	cout << "Enter characters ; enter # to quit" << endl;
	do {
		cin.get(ch);
		cout << ch;
	} while (ch != '#');
	
}
// 该程序相较于.3 处理了空白字符地输入问题