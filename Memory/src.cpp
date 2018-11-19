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
//		if (size != sizeof(demo))return ::operator new(size);//�������Ĵ�С������ת����ȫ��new����
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
//			if (size != sizeof(demo))return ::operator delete(p);//�����С������ת����ȫ��delete����
//			free(p);
//		}
//	}
//	void *operator new[](std::size_t size)
//	{
//		//ֱ�ӽ����ν���demo�е�operator new
//		//��operator newֱ��mallo����һƬraw memory��û�о����κβ�����һ���ڴ棩
//		return operator new(size);
//		//��ȻҲ����ֱ��malloc
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