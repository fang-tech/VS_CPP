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
		while (!(cin >> golf[i])) {//�������ʧ��
			cin.clear();//��������״̬,ʹcin�������¹���,���Դ����е����ã�
			while (cin.get() != '\n')
				;//���������������������е������
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