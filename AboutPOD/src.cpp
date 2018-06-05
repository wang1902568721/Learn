#include <iostream>
using namespace std;

class Obj
{
public:
	Obj();
	~Obj();
};
Obj::Obj()
{
	cout << "construct" << endl;
}
Obj::~Obj()
{
	cout << "deconstruct" << endl;
}
void func_class(Obj &obj)
{
	cout << "in func_class" << endl;
}
void func(int iNum)
{
	cout << iNum << endl;
}
int main()
{
	func_class(Obj());
	system("pause");
	return 0;
}