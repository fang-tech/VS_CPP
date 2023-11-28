#include <iostream>
#include <string>

int main() {
	using namespace std;
	cout << "Please input some Words for str1:" << endl;
	string str1, str2, str3;
	cin >> str1;
	cout << "Please input some Words for str2:" << endl;
	cin >> str2;
	cout << "str1 is " << str1 << endl;
	cout << "str2 is" << str2 << endl;
	cout << "str1 + str2 = " << str1 + str2 << endl;
	str1 += str2;
	cout << "str1 += str2 = " << str1 << endl;
	int length = str1.size();
	cout << "str1 size is " << length;
	return 0;
}