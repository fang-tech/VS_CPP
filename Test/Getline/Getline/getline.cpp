#include <iostream>
#include <string>

int main() {
	using namespace std;
	cout << "lineget:" << endl;
	string str;
	getline(cin, str);
	cout << "Your put is " << str << endl;
	return 0;
}