#include <iostream>
using namespace std;

constexpr int Get(int x)
{
	return x;
}

int main()
{
	int i = 6;
	constexpr int ci = Get(66);
	cout << ci << endl;
	system("pause");
	return 0;
}