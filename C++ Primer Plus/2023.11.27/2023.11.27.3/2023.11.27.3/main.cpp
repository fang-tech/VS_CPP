#include <iostream>
int main(){
	using namespace std;
	char  ch = 0;
	cout << "Enter characters ; enter # to quit : \n";
	do {
		cin >> ch;
		cout << ch;
	} while (ch != '#');
}
// 有个很有趣的现象是， 1. 输入#后程序并不会停止，
// 可以继续运行但是最后输出的东西里不会有#后面的文字，
//  2. 同时空字符也会被吃掉
// 2.是因为cin在读取基本类型的时候会忽略掉空字符。
// 1.是因为cin读取的内容会被一直发送到缓冲区，直到按下Enter
// 缓冲区内的内容才会被发送给程序，而程序在读取到#后就停止了输出
