#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;

class demo 
{
public:
	demo() :dat(0) 
	{
		std::cout << "demo constructor called" << std::endl;
	}
	~demo() 
	{
		std::cout << "demo destructor called" << std::endl;
	}
	void *operator new(std::size_t size)
	{
		cout << size << endl;
		if (size != sizeof(demo))return ::operator new(size);//�������Ĵ�С������ת����ȫ��new����
		void *p(nullptr);
		std::new_handler handler(std::set_new_handler(nullptr));
		std::set_new_handler(handler);
		while (true) {
			if (p = malloc(size))return p;
			if (handler)handler();
			else throw std::bad_alloc();
		}
	}
	void operator delete(void *p, std::size_t size)
	{
		cout << "In delete"<<size << endl;
		if (p) 
		{
			if (size != sizeof(demo))return ::operator delete(p);//�����С������ת����ȫ��delete����
			free(p);
		}
	}
	void *operator new[](std::size_t size)
	{
		//ֱ�ӽ����ν���demo�е�operator new
		//��operator newֱ��mallo����һƬraw memory��û�о����κβ�����һ���ڴ棩
		return operator new(size);
		//��ȻҲ����ֱ��malloc
		//return malloc(size);
	}
	void operator delete[](void *p,size_t size)
	{
		cout << "in delete []" << size << endl;
		if (p)free(p);
	}
private:
	int dat;
};

int testFunc1() {
	demo *p = new demo;
	delete p;
	std::cout << "\n\n";
	demo *px(new demo[3]);
	delete[] px;
	system("pause");
	return 0;
}


class A
{
public:
	~A()
	{
		//
		cout << "A destructor" << endl;
	}
private:
	int iNum;
};
int testFunc2()
{
	//int *p = new int(10);
	//int *p2 = new int(20);

	//cout << p2 - p << endl;
	int *p = new int[10];
	delete[] p;

	A  *pA = new A[5];
	delete (pA - 1);
	//cout <<  << endl;
	//delete[] pA;
	system("pause");
	return 0;
}

template<class T1, class T2>inline void construct(T1* p, const T2& value)
{
	new (p) T1(value);
}

void testConstruct()
{
	auto p = new int[12];
	for (int i = 0; i < 12; i++)
	{
		*(p + i) = i;
	}
	construct(p+5, 12);
	for (int i = 0; i < 12; i++)
	{
		cout << *(p + i) << endl;
	}
	system("pause");
}
int main()
{
	
	testConstruct();
	return 0;
}