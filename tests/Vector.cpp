#include <unordered_set>
#include "Types.h"
#include "gtest/gtest.h"

using namespace CR::Math;
using namespace std;

TEST(Vector, Basics)
 {
	int2 point{5, 2};
	EXPECT_EQ(5, point.X);
	point += {2, 3};
	EXPECT_EQ(7, point.X);
	point = point * 2;
	EXPECT_EQ(10, point.Y);
	EXPECT_FLOAT_EQ(14, Dot(float2{2.0f, 3.0f}, float2{4.0f, 2.0f}));

	stringstream stream;
	stream << point;
	EXPECT_EQ(string{"{14, 10}"}, stream.str());

	unordered_set<int2> testSet;
	testSet.insert(point);
	EXPECT_NE(testSet.end(), testSet.find(point));

	float3 vec{1, 2, 3};
	EXPECT_FLOAT_EQ(3.741657f, vec.Length());

	unordered_set<float3> testSet2;
	
	double4 vecd{1, 2, 3, 4};
	vecd = Pow(vecd, double4{1, 3, 2, 4});
	auto expected = double4{1, 8, 9, 256};
	EXPECT_EQ(vecd, expected);
}
