#include <stdio.h>
#include <iostream>
using namespace std;

void test()
{
	char szAr[] = "���ѳɹ�";

	printf("%d %d %s\n", sizeof(szAr),strlen(szAr), szAr);
}

int main()
{
	test();
	cin.get();
	return 0;
}