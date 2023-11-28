#include <iostream>
#include <fstream>
#include <cstdlib> // support for exit()
const int SIZE = 50;
int main() {//��ָ�����ļ������ж�ȡһϵ�е����֣�ָ�������ж��ٸ�ֵ�������ƽ��ֵ
	//�������ļ������ȡ���
	using namespace std;
	char filename[SIZE]{};
	cout << "Enter the name of file : ";
	cin.getline(filename, SIZE);//�����ı�����
	ifstream inFile;//���������ļ����������봦����ofstream ���������
	inFile.open(filename);//open�����Ͼ��Ƕ�ȡһ���ַ�����char��ַ
	// inFile.open(filename) == inFile.open("filetest.txt")
	if (!inFile.is_open()) {
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);//������ļ�ʧ�ܣ��˳����򲢷��ش�����Ϣ
	}
	int count = 0;
	int value = 0;
	int sum = 0;
	do {
		inFile >> value;
		count++;
		sum += value;
	} while (inFile.good());
	if (inFile.eof())//�����ȡ�����ļ�β���򷵻�ture��else ���� false
		cout << "End of file reached";
	else if (inFile.fail())//�����ȡ�����ļ�β�������Ķ�ȡ���Ͳ�ƥ��ʱ
						   //�򷵻�ture��else ���� false
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unkown reason.\n";
	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum * 1.0 / count << endl;
	}
	inFile.close();
	return 0;
}