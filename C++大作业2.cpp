// C++大作业2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <iomanip>
#include <stdio.h>

#define READ 10
#define WRITE 11
#define LOAD 20
#define STORE 21
#define ADD 30
#define SUBTRACT 31
#define DIVIDE 32
#define MULTIPLY 33
#define BRANCH 40
#define BRANCHNEG 41
#define BRANCHZERO 42
#define HALT 43

using namespace std;

class SimpleTron
{
public:
	SimpleTron();
	~SimpleTron();
	void start();
	void halt();
private:
	int getcommand();
	int process();

	short accumulator = 0, counter = 0, operatorCode = 0, operand = 0, instructionRegister = 0;
	short memory[100] = {0};
};

SimpleTron::SimpleTron()
{
}

SimpleTron::~SimpleTron()
{
}

void SimpleTron::start() {
	cout << "Welcome to SimpleTron"<<endl;
	while (SimpleTron::getcommand()==1);
	SimpleTron::process();
}

void SimpleTron::halt()
{
	cout << "\t";
	for (short i = 0; i < 10; i++)
	{
		cout <<"    "<< i << "\t";
	}
	cout << endl;
	for (short i = 0; i < 10; i++)
	{
		cout << 10 * i << "\t";
		for (short j = 0; j < 10; j++) 
		{
			cout.width(5);
			cout <<memory[10 * i + j] << setfill('0') <<internal<< setiosflags(ios::showpos) << "\t";
		}
		cout << endl;
	}
}

int SimpleTron::getcommand()
{
	short command;
	cout << "? ";
	cin >> command;
	if (command == -99999) 
	{
		counter = 0;
		return 0;
	}
	if (command >= 0 && command<= 9999) 
	{
		memory[counter++] = command;
	}
	else
	{
		return 2;//指令不合法
	}
	return 1;
}

int SimpleTron::process()
{
	//if (counter != 0) {
	//	return 1;//指令位置异常
	//}
	counter = 0;
	while (operatorCode!=43&&counter<=99)
	{
		instructionRegister = memory[counter++];
		operatorCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		switch (operatorCode)
		{
		case READ:
			scanf_s("%d", memory+operand);
			break;
		case WRITE:
			cout << memory[operand];
			break;
		case LOAD:
			accumulator = memory[operand];
			break;
		case STORE:
			memory[operand] = accumulator;
			break;
		case ADD:
			accumulator += memory[operand];
			break;
		case SUBTRACT:
			accumulator -= memory[operand];
			break;
		case DIVIDE:
			accumulator /= memory[operand];
			break;
		case MULTIPLY:
			accumulator *= memory[operand];
			break;
		case BRANCH:
			counter = operand;
			break;
		case BRANCHNEG:
			if(accumulator<0)
				counter = operand;
			break;
		case BRANCHZERO:
			if(accumulator==0)
				counter = operand;
			break;
		default:
			break;
		}
	}

	
	return 0;
}

int main()
{
	SimpleTron test;
	test.start();
	test.halt();
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
