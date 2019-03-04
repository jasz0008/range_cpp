#include <range_cpp/range.hpp>
#include <gtest/gtest.h>

// Negative step
// Start > stop
// Start or stop near size_t max/min
// Large step
// Step over stop

TEST(range_cpp, ThrowsOnZeroStep)
{
    EXPECT_THROW(range_cpp::range(0, 1, 0), std::logic_error);
}

TEST(range_cpp, HandlesTrivialCases)
{
    // Returns empty when start == stop
    EXPECT_TRUE(range_cpp::range(0, 0).empty());
    EXPECT_TRUE(range_cpp::range(1, 1).empty());
    EXPECT_TRUE(range_cpp::range(-1, -1).empty());

    // Returns empty when start > stop and step > 0
    EXPECT_TRUE(range_cpp::range(1, 0, 1).empty());

    // Returns empty when start < stop and step < 0
    EXPECT_TRUE(range_cpp::range(0, 1, -1).empty());
}

TEST(range_cpp, ReturnsCorrectSize)
{
    // Returns N elements 0, 1, 2, ..., N-1
    EXPECT_EQ(range_cpp::range(0).size(), 0);
    EXPECT_EQ(range_cpp::range(1).size(), 1);
    EXPECT_EQ(range_cpp::range(10).size(), 10);

    // Returns abs(start - stop) elements when step == 1 (default)
    EXPECT_EQ(range_cpp::range( 0,  1).size(), 1);
    EXPECT_EQ(range_cpp::range(-1,  0).size(), 1);

    // Returns empty when start > stop but step == 1 (default)
    EXPECT_EQ(range_cpp::range( 1,  0).size(), 0);
    EXPECT_EQ(range_cpp::range( 0, -1).size(), 0);
}

TEST(range_cpp, HandlesStepOverStop)
{
    EXPECT_EQ(range_cpp::range(0, 5,  2), std::vector<int>({0, 2, 4}));
    EXPECT_EQ(range_cpp::range(5, 0, -2), std::vector<int>({5, 3, 1}));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
