#pragma once
#include <iostream>
int Func(int a, int b);

class FooCalc
{
public:
	FooCalc()
	{
		std::cout << "FooCalc construct" << std::endl;
	}
	~FooCalc()
	{
		std::cout << "FooCalc dconstruct" << std::endl;
	}
	void Init()
	{
		std::cout << "FooCalc init" << std::endl;
	}
	void Finalize()
	{
		std::cout << "FooCalc Finalize" << std::endl;
	}
	int Calc(int i, int m)
	{
		return i*m;
	}
};