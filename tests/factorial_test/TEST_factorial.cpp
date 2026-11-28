#include <cstdint>
#include <gtest/gtest.h>

namespace {

uint32_t factorial(uint32_t number)
{
    return number > 1 ? number * factorial(number - 1) : 1U;
}

} // namespace

TEST(FactorialTest, HandleZeroInput)
{
    EXPECT_EQ(factorial(0), 1);
}

TEST(FactorialTest, HandlePositiveValues)
{
    EXPECT_EQ(factorial(1), 1);
    EXPECT_EQ(factorial(2), 2);
    EXPECT_EQ(factorial(3), 6);
    EXPECT_EQ(factorial(4), 24);
    EXPECT_EQ(factorial(5), 120);
}
