#include "SimpleTron.h"


void SimpleTron::start() {
	cout << "          *** Welcome to Simpletron! ***         " << endl
		<< "*** Please enter your program one instruction ***" << endl
		<< "*** (or data word) at a time. I will type the ***" << endl
		<< "*** location number and a question mark (?).  ***" << endl
		<< "*** You then type the word for that location. ***" << endl
		<< "*** Type the sentinel -99999 to stop entering ***" << endl
		<< "*** your program.                             ***" << endl;

	while (SimpleTron::getcommand() == 1);
	SimpleTron::process();
}

void SimpleTron::halt()
{
	cout << setfill('0');
	cout << "REGISTERS:" << endl;
	cout << "accumulator             " << showpos << setw(5) << internal << accumulator << endl;
	cout << "Counter                    " << noshowpos << setw(2) << counter << endl;
	cout << "instructionRegister     " << showpos << setw(5) << internal << instructionRegister << endl;
	cout << "operationCode              " << noshowpos << setw(2) << operatorCode << endl;
	cout << "operand                    " << noshowpos << setw(2) << operand << endl;

	cout << "MEMORY:" << endl;
	cout << "\t";
	for (short i = 0; i < 10; i++)
	{
		cout << "    " << i << "\t";
	}
	cout << endl;
	for (short i = 0; i < 10; i++)
	{
		cout << 10 * i << "\t";
		for (short j = 0; j < 10; j++)
		{
			cout.width(5);
			cout << memory[10 * i + j] << setfill('0') << internal << showpos << "\t";
		}
		cout << endl;
	}
}

int SimpleTron::getcommand()
{
	int command;
	cout << "? ";
	cin >> command;
	if (command == -99999)
	{
		counter = 0;
		return 0;
	}
	if (command >= 0 && command <= 9999)
	{
		memory[counter++] = command;
	}
	else
	{
		cout << "输入不合法,请重试\n";
		//return 2;//指令不合法
	}
	return 1;
}

int SimpleTron::process()
{
	if (counter != 0) {
		cout << "指令位置异常";
		//return 1;//指令位置异常
	}
	while (operatorCode != 43 && counter <= 99)
	{
		instructionRegister = memory[counter++];
		operatorCode = instructionRegister / 100;
		operand = instructionRegister % 100;
		switch (operatorCode)
		{
		case READ:
			cout << "#";
			//这里用cin会抽风，待解决
			scanf_s("%d", memory + operand);
			break;
		case WRITE:
			cout << memory[operand]<<endl;
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
			if (accumulator < 0)
				counter = operand;
			break;
		case BRANCHZERO:
			if (accumulator == 0)
				counter = operand;
			break;
		case HALT:
			halt();
			break;
		default:
			cout << "警告：指令不正确\n错误位置\t"<<counter;
			operatorCode = HALT;
			break;
		}
	}


	return 0;
}