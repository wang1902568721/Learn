//#include <iostream>
//#include <new>
//#include <cstdlib>
//using namespace std;
//
//class demo 
//{
//public:
//	demo() :dat(0) 
//	{
//		std::cout << "demo constructor called" << std::endl;
//	}
//	~demo() 
//	{
//		std::cout << "demo destructor called" << std::endl;
//	}
//	void *operator new(std::size_t size)
//	{
//		cout << size << endl;
//		if (size != sizeof(demo))return ::operator new(size);//如果分配的大小不符，转交给全局new处理
//		void *p(nullptr);
//		std::new_handler handler(std::set_new_handler(nullptr));
//		std::set_new_handler(handler);
//		while (true) {
//			if (p = malloc(size))return p;
//			if (handler)handler();
//			else throw std::bad_alloc();
//		}
//	}
//	void operator delete(void *p, std::size_t size)
//	{
//		cout << "In delete"<<size << endl;
//		if (p) 
//		{
//			if (size != sizeof(demo))return ::operator delete(p);//如果大小不符，转交给全局delete处理
//			free(p);
//		}
//	}
//	void *operator new[](std::size_t size)
//	{
//		//直接将责任交给demo中的operator new
//		//而operator new直接mallo返回一片raw memory（没有经过任何操作的一块内存）
//		return operator new(size);
//		//当然也可以直接malloc
//		//return malloc(size);
//	}
//	void operator delete[](void *p,size_t size)
//	{
//		cout << "in delete []" << size << endl;
//		if (p)free(p);
//	}
//private:
//	int dat;
//};
//
//int main() {
//	demo *p = new demo;
//	delete p;
//	std::cout << "\n\n";
//	demo *px(new demo[3]);
//	delete[] px;
//	system("pause");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class A
//{
//public:
//	~A()
//	{
//		//
//		cout << "A destructor" << endl;
//	}
//private:
//	int iNum;
//};
//
//
//int main()
//{
//	//int *p = new int(10);
//	//int *p2 = new int(20);
//
//	//cout << p2 - p << endl;
//	int *p = new int[10];
//	delete[] p;
//
//	A  *pA = new A[5];
//	delete (pA - 1);
//	//cout <<  << endl;
//	//delete[] pA;
//	system("pause");
//	return 0;
//}

// new_set_new_handler.cpp
// compile with: /EHsc
#include<new>
#include<iostream>
using namespace std;

void __cdecl newhandler()
{
	cout << "The new_handler is called:" << endl;
	throw bad_alloc();
	return;
}

int main()
{
	set_new_handler(newhandler);
	try
	{
		while (1)
		{
			new int[5000000];
			cout << "Allocating 5000000 ints." << endl;
		}
	}
	catch (exception e)
	{
		cout << e.what() << endl;
	}

	return 0;
}