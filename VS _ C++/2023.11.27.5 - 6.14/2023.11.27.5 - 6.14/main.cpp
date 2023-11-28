#include <iostream>
const int MAX = 5;
int main() {
	using namespace std;
	int golf[MAX];
	cout << "Please enter your golf scores. \n";
	cout << "You must enter " << MAX << "rounds \n";
	int i;
	for (i = 0; i < MAX; i++) {
		cout << "rounds #" << i + 1 << ": ";
		while (!(cin >> golf[i])) {//如果读入失败
			cin.clear();//清除错误的状态,使cin可以重新工作,（自带换行的作用）
			while (cin.get() != '\n')
				;//清除错误的输入流（面向行的清除）
			cout << "Please enter a number : ";
		}
	}
	int sum = 0;
	double average;
	for (i = 0; i < MAX; i++) {
		sum += golf[i];
	}
	average = sum * 1.0 / MAX;
	cout << "Your average score = " << average;
}