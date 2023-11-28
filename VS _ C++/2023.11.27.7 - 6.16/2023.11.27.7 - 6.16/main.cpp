#include <iostream>
#include <fstream>
#include <cstdlib> // support for exit()
const int SIZE = 50;
int main() {//打开指定的文件，从中读取一系列的数字，指出其中有多少个值，求和与平均值
	//并检验文件打开与读取情况
	using namespace std;
	char filename[SIZE]{};
	cout << "Enter the name of file : ";
	cin.getline(filename, SIZE);//读入文本名字
	ifstream inFile;//用于链接文件，并做输入处理，而ofstream 做输出处理
	inFile.open(filename);//open本质上就是读取一个字符串的char地址
	// inFile.open(filename) == inFile.open("filetest.txt")
	if (!inFile.is_open()) {
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);//如果打开文件失败，退出程序并返回错误信息
	}
	int count = 0;
	int value = 0;
	int sum = 0;
	do {
		inFile >> value;
		count++;
		sum += value;
	} while (inFile.good());
	if (inFile.eof())//如果读取到了文件尾，则返回ture，else 返回 false
		cout << "End of file reached";
	else if (inFile.fail())//如果读取到了文件尾或者最后的读取类型不匹配时
						   //则返回ture，else 返回 false
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