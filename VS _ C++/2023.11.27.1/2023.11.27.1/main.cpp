#include <iostream>
#include <ctime>
int main() {
	using namespace std;
	cout << "Enter the delay time ,in seconds: ";
	int sec = 0;
	cin >> sec;
	clock_t delay = sec * CLOCKS_PER_SEC;
	clock_t star = clock();
	while (clock() - star < delay) 
	;
	cout << "Done \a\n";
}