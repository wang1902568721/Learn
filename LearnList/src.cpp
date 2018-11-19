// list_class_insert.cpp
// compile with: /EHsc
#include <list>
#include <iostream>
using namespace std;

int func1()
{	
	list <int> c1, c2;
	list <int>::iterator Iter;

	c1.push_back(10);
	c1.push_back(20);
	c1.push_back(30);
	c1.push_back(40);
	c2.push_back(40);
	c2.push_back(50);
	c2.push_back(60);

	cout << "c1 =";
	for (Iter = c1.begin(); Iter != c1.end(); Iter++)
		cout << " " << *Iter;
	cout << endl;

	//Iter = c1.begin();
	////Iter++;
	//c1.insert(Iter, 100);
	//cout << "c1 =";
	//for (Iter = c1.begin(); Iter != c1.end(); Iter++)
	//	cout << " " << *Iter;
	//cout << endl;

	Iter = c1.begin();
	c1.insert(Iter, 66);
	c1.insert(Iter, 77);
	cout << "c1 =";
	for (Iter = c1.begin(); Iter != c1.end(); Iter++)
		cout << " " << *Iter;

	//Iter = c1.begin();
	//Iter++;
	//Iter++;
	//c1.insert(Iter, 2, 200);

	//cout << "c1 =";
	//for (Iter = c1.begin(); Iter != c1.end(); Iter++)
	//	cout << " " << *Iter;
	//cout << endl;

	//c1.insert(++c1.begin(), c2.begin(), --c2.end());

	//cout << "c1 =";
	//for (Iter = c1.begin(); Iter != c1.end(); Iter++)
	//	cout << " " << *Iter;
	//cout << endl;
	cin.get();
	return 0;
}

void testBegin()
{
	list<int> ltest;
	ltest.push_back(1);
	cout << *ltest.begin() << endl;
	ltest.push_back(2);
	cout << *(ltest.begin()++++) << endl;
}
void main()
{
	testBegin();
	system("pause");
	return;
}