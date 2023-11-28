#include <iostream>
#include <fstream>
int main() {
	using namespace std;
	ofstream outfile;
	int price;
	cout << "Please enter a number : \n";
	cin >> price;
	outfile.open("file test.txt");

	cout << "Just have fun!!! \n";
	cout << "Your price is " << price;

	outfile << "Just have fun!!! \n";
	outfile << "Your price is " << price;
}