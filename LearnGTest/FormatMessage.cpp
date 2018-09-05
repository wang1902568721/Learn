#include <gtest/gtest.h>
#include "ToBeTestedHead.h"

#ifdef __FORMAT_MESSAGE__

TEST(FuncTest, anything)
{
	EXPECT_EQ(1, Func(4,10))<<"append some info";
	EXPECT_EQ(2, Func(30, 18));
}


testing::AssertionResult AssertFoo(const char* m_expr,const char* n_expr,const char* k_expr,int m,int n,int k)
{
	if (Func(m, n) == k)
	{
		return testing::AssertionSuccess();
	}
	testing::Message msg;
	msg << "m_expr=[" << m_expr << "] n_expr=["<<n_expr<<"] k_expr=["<<k_expr<<"] m=["<<m<<"] n=["<<n<<"] k=["<<k<<"]";
	return testing::AssertionFailure(msg);
}

TEST(AssertFunc,HandleFail)
{
	EXPECT_PRED_FORMAT3(AssertFoo,3,6,2);
}

#endif