#pragma once
#include <limits>
#include <algorithm>
#include <type_traits>
#include "core/Concepts.h"

namespace CR::Math {
	template<Arithmetic T>
	class ColorRGB;

	template<Arithmetic T>
	class ColorRGBA {
	public:
		T Red{0};
		T Green{0};
		T Blue{0};
		T Alpha{std::is_floating_point_v<T> ? 1.0f : std::numeric_limits<T>::max()};

		ColorRGBA(T a_red, T a_green, T a_blue, T a_alpha = 0) {
			Red = a_red;
			Green = a_green;
			Blue = a_blue;
			Alpha = a_alpha;
		}
		ColorRGBA() = default;
	};

	using ColorRGBA8 = ColorRGBA<unsigned char>;
	using ColorRGBA32F = ColorRGBA<float>;

	template<Arithmetic T>
	class ColorRGB {
	public:
		T Red{0};
		T Green{0};
		T Blue{0};

		ColorRGB(T _red, T _green, T _blue) {
			red = _red;
			green = _green;
			blue = _blue;
		}
		ColorRGB() = default;
	};

	using ColorRGB8 = ColorRGB<unsigned char>;
	using ColorRGB32F = ColorRGB<float>;
}
