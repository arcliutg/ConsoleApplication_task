#include <iostream>
using namespace std;

int main()
{
	char i = 'c';
	cout << "what do you plan to do?" << endl;
	cout << "a : perform addition operations" << endl;
	cout << "b : perform multiplication" << endl;//文本的信息
	cin >> i;
	switch (i)
	{
	case 'a':
		//进行加法的运算(perform addition operations)
		cout << "выполнять операции сложения";
		extern void start_computing_a();
		start_computing_a();
		break;
	case 'b':
		//进行加法的运算(perform multiplication)
		cout << "выполнить умножение";
		extern void start_computing_b();
		start_computing_b();
		break;
	default:
		cout << "error";
		break;
	}

}