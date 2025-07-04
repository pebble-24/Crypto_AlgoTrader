#include <gtest/gtest.h>

#include <common/logger.hpp>

TEST(LoggerTest, SimpleLog)
{
	EXPECT_NO_THROW({  });
}

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}