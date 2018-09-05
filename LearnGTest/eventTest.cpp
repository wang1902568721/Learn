#include <gtest/gtest.h>
#include "ToBeTestedHead.h"

#ifdef __EVENT_TEST__

//ȫ���¼� ��Ҫ����������ע���¼�testing::AddGlobalTestEnvironment
class FooEnviroment : public testing::Environment
{
public:
	//���в��԰���ִ��ǰ
	virtual void SetUp()
	{
		std::cout << "FooEnviroment SetUp" << std::endl;
	}
	//���в��԰���ִ�к�
	virtual void TearDown()
	{
		std::cout << "FooEnviroment TearDown" << std::endl;
	}
};

//��԰������¼� ִֻ��һ�� �����й����Ĳ���֮ǰ��֮��
class FooTest:public testing::Test
{
protected:
	//����ִ��ǰ
	static void SetUpTestCase()
	{
		std::cout << "FooTest--SetUpTestCase" << std::endl;
	}
	//����ִ�к�
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

//��ÿһ��TEST_F֮ǰ��֮��ִ�� ������SetUp֮ǰ���죬��TearDown֮������
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