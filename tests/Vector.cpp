#include <unordered_set>
#include "Types.h"
#include "catch.hpp"

using namespace CR::Math;
using namespace std;

TEST_CASE("basics", "[vector]")
{
	int2 point{5, 2};
	REQUIRE(point.X == 5);

	point += {2, 3};
	REQUIRE(point.X == 7);
	point = point * 2;
	REQUIRE(point.Y == 10);
	REQUIRE(Dot(float2{2.0f, 3.0f}, float2{4.0f, 2.0f}) == 14);

	stringstream stream;
	stream << point;
	REQUIRE(stream.str() == string{"{14, 10}"});
	
	unordered_set<int2> testSet;
	testSet.insert(point);
	REQUIRE(testSet.find(point) != testSet.end());
	
	float3 vec{1, 2, 3};
	REQUIRE(vec.Length() == Approx(3.741657f));

	unordered_set<float3> testSet2;

	double4 vecd{1, 2, 3, 4};
	vecd = Pow(vecd, double4{1, 3, 2, 4});
	auto expected = double4{1, 8, 9, 256};
	REQUIRE(expected == vecd);
}