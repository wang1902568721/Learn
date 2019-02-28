#include <memory>
#include <iostream>
#include<vector>
using namespace std;

class Foo
{
public:
	Foo();
	~Foo();
	void func();
};

Foo::Foo()
{
	cout << "Foo construct" << endl;
}

Foo::~Foo()
{
	cout << "Foo deconstruct" << endl;
}

void Foo::func()
{
	cout << "call func" << endl;
}

void func(weak_ptr<Foo> &wp)
{
	cout << wp.lock().use_count() << endl;
	shared_ptr<Foo> spFoo = wp.lock();
	spFoo->func();
	cout << spFoo.use_count() << endl;
}

int test_1()
{
	shared_ptr<Foo> pFoo(new Foo);
	//weak_ptr<Foo> wp = pFoo;
	//func(pFoo);
	//cout << wp.lock().use_count() << endl;
	//shared_ptr<Foo> pFoo1 = pFoo;
	//cout << pFoo.use_count() << endl;
	vector<shared_ptr<Foo>> vec;
	vec.push_back(pFoo);
	cout << pFoo.use_count() << " " << vec.size() << endl;
	vec.pop_back();
	cout << pFoo.use_count() << " " << vec.size() << endl;

	return 0;
}

int test_2()
{
	int i = 10;
	shared_ptr<int> pr(new int(i));
	cout << *pr << endl;
	shared_ptr<int> pd(new int(*pr));
	cout << *pd << endl;
	cout << pr.use_count() <<"  "<<pd.use_count()<< endl;
	*pd = 100;
	cout << *pr << " " << *pd << endl;
	pr.swap(pd);
	cout << *pr << " " << *pd << endl;
	return 0;
}
class test
{
private:
	shared_ptr<int> pSource;
public:
	shared_ptr<int> getSource()
	{
		return pSource;
	}
	test::test()
	{
		pSource.reset(new int(6));
	}

	void update1()
	{
		if (!pSource.unique())
		{
			cout << pSource.use_count() << endl;//2
			shared_ptr<int> pTemp(new int(*pSource));
			pSource.swap(pTemp);
		}
		cout << pSource.use_count() << endl;
		cout << "exit update" << endl;
	}
	void update2()
	{
		if (!pSource.unique())
		{
			cout << pSource.use_count() << endl;//2
			//shared_ptr<int> pTemp(new int(*pSource));
			pSource.reset(new int(*pSource));
			cout << pSource.use_count() << endl;//1
		}
		cout << "exit update" << endl;
	}
};

void test_useCount()
{
	test test1;

	shared_ptr<int> p1 = test1.getSource();
	cout << p1.use_count() << endl;
	//test1.update1();
	//cout << p1.use_count() << endl;
	test1.update2();
	cout << p1.use_count() << endl;
}

int main()
{
	test_useCount();
	system("pause");
	return 0;
}