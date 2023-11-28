#include <iostream>
#include <cstring>
int main() {
	using namespace std;
	const int Size = 15;
	char namel[Size];
	cin >> namel;
	cout << "your name is " << namel << endl;
	cout << "it has " << strlen(namel) << " char";

	cin.get();
	return 0;
}