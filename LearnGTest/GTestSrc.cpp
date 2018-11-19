#include <gtest/gtest.h>

int main(int argc,char* argv[])
{
	//注册全局事件
	//testing::AddGlobalTestEnvironment(new FooEnviroment);
	testing::InitGoogleTest(&argc,argv);
	RUN_ALL_TESTS();
	system("pause");
	return 0;
}