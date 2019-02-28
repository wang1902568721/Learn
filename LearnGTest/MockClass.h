#pragma once
#include <gmock/gmock.h>
#include "VirtualHead.h"

class MockHead : public VirtualHead
{
public:
	MOCK_METHOD1(vFunc, int(int x));
};