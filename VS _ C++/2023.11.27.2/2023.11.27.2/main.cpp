#include <iostream>
int main() {
	using namespace std;
	double primers[5] = { 1.0,2.0,5.1,4.9,5.4 };
	for (double x : primers)
		cout << x << endl;
	cout << endl;
	for (double& x : primers) {
		cout << x << "\t";
		x *= 0.8;
		cout << x << endl;
	}
	cout << "Good Test";
}