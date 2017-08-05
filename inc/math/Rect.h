#pragma once
#include <algorithm>
#include "Types.h"

namespace CR::Math {
	template<class T>
	class Rect {
	public:
		T Top{0};
		T Left{0};
		T Width{0};
		T Height{0};

		Rect() = default;
		Rect(T a_top, T a_left, T a_width, T a_height) :
			Top(a_top), Left(a_left), Width(a_width), Height(a_height) {}

		T Bottom() const { return top + height; }
		T Right() const { return left + width; }
		void Clamp(T a_left, T a_top, T a_width, T a_height) {
			Left = max(Left, a_left);
			Top = max(Top, a_top);
			width = min(Left + width, Left + a_width) - Left;
			height = min(Top + height, Top + a_height) - Top;
		}
	};

	typedef Rect<double> RectD;
	typedef Rect<float> RectF;
	typedef Rect<sint> RectSI;
}
