#pragma once
#include "math/Vector.h"

namespace CR::Math {
	template<class T>
	class Ray {
	public:
		Vector2<T> Origin;
		Vector3<T> Direction;
	};
}
