#include <iostream>
using namespace std;

class CTest
{
public:
	CTest();
private:
	~CTest();
protected:
	int iNum;
	static int iStaticNum;
};

class C1Function
{
public:
	void Func1();
};

void C1Function::Func1()
{
}

int CTest::iStaticNum = 10;

CTest::CTest()
{
	cout << "construct" << endl;
}

CTest::~CTest()
{
	cout << "deconstruct" << endl;
}

class Construct
{
public:
	Construct();
	Construct(Construct &src);
};

Construct::Construct()
{
	cout << "Construct" << endl;
}
Construct::Construct(Construct &src)
{
	cout << "copy Construct" << endl;
}

//class Base
//{
//private:
//	int k;
//};
//class InitList : public Base
//{
//public:
//	int i;
//	int j;
//public:
//	InitList(InitList&& x) : Base{x.i},j(x.j){}
//};

/*用于测试友元类*/
class Node
{
private:
	int data;
	int key;
	
	friend class BinaryTree;
};

class BinaryTree
{
private:
	Node* root;
	int find(int key);
};

int BinaryTree::find(int key)
{
	if (root->key == key)
	{
		return root->data;
	}
	return 0;
}

class Base
{
public:
	void f(double d)
	{
		cout << "base d" << d << endl;
	}
};

class Derived : public Base
{
public:
	using Base::f;
	void f(int i)
	{
		cout << "derived f" <<i<< endl;
	}
};

class Info
{
public:
	Info() { InitRest(); }
	Info(int a) :Info() {}
	Info(char e) :Info() {}
private:
	void InitRest() {}
};

template<typename T1, typename T2> auto Sum(T1& t1, T2& t2)->decltype(t1 + t2)
{
	return t1 + t2;
}

int main()
{
	
	Derived dc;
	dc.f(4.5);
	cin.get();
	return 0;
}