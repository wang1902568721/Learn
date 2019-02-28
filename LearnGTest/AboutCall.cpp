#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "MockClass.h"
#include "VirtualHead.h"

using namespace std;

TEST(AboutCall, Call)
{
	MockHead *pMockHead_1 = new MockHead();
	MockHead *pMockHead_2 = new MockHead();

	EXPECT_CALL(*pMockHead_1,vFunc(testing::_)).WillRepeatedly(testing::Return(1));
	//EXPECT_CALL(*pMockHead_2, vFunc(testing::_)).WillRepeatedly(testing::Return(2));

	cout<<pMockHead_1->vFunc(1)<<endl;
	cout<<pMockHead_2->vFunc(2)<<endl;
}
