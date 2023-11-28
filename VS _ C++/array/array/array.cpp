#include <iostream>
int main() {
	using namespace std;
	int yam[3];
	yam[0] = 7;
	yam[1] = 8;
	yam[2] = 6;
	int yamcosts[3] = { 20 ,30 ,5 };
	cout << "yams =  " << yam[0]<<yam[1]<<yam[2]<< endl;
	cout << "\nSize of yams array = " << sizeof yam << "bytes";
	cout << endl;
	cout << "Size of one element = " << sizeof yam[0] << "bytes";
	return 0;
}