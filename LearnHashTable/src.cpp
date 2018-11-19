#include <hash_set>
#include <iostream>
using namespace std;

int main()
{
	hashtable<int, int, hash<int>, identity<init>, equal_to<int>, alloc> iht(50, hash<int>, equal_to<int>());
	return 0;
}