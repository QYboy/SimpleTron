#pragma once

#include <iostream>
#include <iomanip>

//���еĲ���
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
	SimpleTron() {}
	~SimpleTron() {}
	void start();
private:
	int getcommand();
	int process();
	void halt();

	short accumulator = 0, counter = 0, operatorCode = 0, operand = 0, instructionRegister = 0;
	short memory[100] = { 0 };
};