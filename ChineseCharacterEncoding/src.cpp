#include <stdio.h>
#include <iostream>
using namespace std;

void test()
{
	char szAr[] = "消费成功";

	printf("%d %d %s\n", sizeof(szAr),strlen(szAr), szAr);
}

int main()
{
	test();
	cin.get();
	return 0;
}