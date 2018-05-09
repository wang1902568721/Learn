#include <iostream>
#include <set>
using namespace std;

void Output(set<int> &s)
{
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		cout << *it<<" ";
	}
}
int main()
{
	//set<int,less<int>> s1;
	set<int> s1(less<int>());
	s1.insert(50);
	s1.insert(40);
	s1.insert(60);
	Output(s1);
	cin.get();
	return 0;
}