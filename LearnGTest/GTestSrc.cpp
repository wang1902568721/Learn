#include <gtest/gtest.h>

int main(int argc,char* argv[])
{
	//ע��ȫ���¼�
	//testing::AddGlobalTestEnvironment(new FooEnviroment);
	testing::InitGoogleTest(&argc,argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}