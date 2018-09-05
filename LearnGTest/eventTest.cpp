#include <gtest/gtest.h>
#include "ToBeTestedHead.h"

#ifdef __EVENT_TEST__

//全局事件 需要在主函数里注册事件testing::AddGlobalTestEnvironment
class FooEnviroment : public testing::Environment
{
public:
	//所有测试案例执行前
	virtual void SetUp()
	{
		std::cout << "FooEnviroment SetUp" << std::endl;
	}
	//所有测试案例执行后
	virtual void TearDown()
	{
		std::cout << "FooEnviroment TearDown" << std::endl;
	}
};

//针对案例的事件 只执行一次 在所有关联的测试之前和之后
class FooTest:public testing::Test
{
protected:
	//案例执行前
	static void SetUpTestCase()
	{
		std::cout << "FooTest--SetUpTestCase" << std::endl;
	}
	//案例执行后
	static void TearDownTestCase()
	{
		std::cout << "FooTest--TearDownTestCase" << std::endl;
	}
};
TEST_F(FooTest,Test1)
{
	EXPECT_EQ(4, Func(30, 18));
}
TEST_F(FooTest, Test2)
{
	EXPECT_EQ(5, Func(30, 18));
}

//在每一个TEST_F之前和之后执行 对象在SetUp之前构造，在TearDown之后析构
class FooCalcTest :public testing::Test
{
protected:
	virtual void SetUp()
	{
		std::cout << "Call SetUp" << std::endl;
		mFooCalc.Init();
	}
	virtual void TearDown()
	{
		std::cout << "Call TearDown" << std::endl;
		mFooCalc.Finalize();
	}
	FooCalc mFooCalc;
};
TEST_F(FooCalcTest, Equal)
{
	EXPECT_EQ(3, mFooCalc.Calc(2, 3));
	EXPECT_EQ(7, mFooCalc.Calc(2, 4));
}
TEST_F(FooCalcTest, NotEqual)
{
	EXPECT_NE(6, mFooCalc.Calc(2, 3));
}

#endif