#pragma once
#include <limits>
#include <algorithm>
#include <type_traits>
#include "core/Concepts.h"
#include "Types.h"

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

		ColorRGBA() noexcept = default;
		ColorRGBA(T a_red, T a_green, T a_blue, T a_alpha = 
				  std::is_floating_point_v<T> ? 1.0f : std::numeric_limits<T>::max()) noexcept {
			Red = a_red;
			Green = a_green;
			Blue = a_blue;
			Alpha = a_alpha;
		}
		ColorRGBA(const ColorRGB<T>& a_color, T a_alpha =
				  std::is_floating_point_v<T> ? 1.0f : std::numeric_limits<T>::max()) noexcept {
			Red = a_color.Red;
			Green = a_color.Green;
			Blue = a_color.Blue;
			Alpha = a_alpha;
		}
	};
	
	template<Arithmetic T>
	class ColorRGB {
	public:
		T Red{0};
		T Green{0};
		T Blue{0};

		ColorRGB() noexcept = default;
		ColorRGB(T _red, T _green, T _blue) noexcept {
			red = _red;
			green = _green;
			blue = _blue;
		}
		ColorRGB(const ColorRGBA<T>& a_color) noexcept {
			Red = a_color.Red;
			Green = a_color.Green;
			Blue = a_color.Blue;
		}
	};

	using ColorRGBA8 = ColorRGBA<uchar>;
	using ColorRGBA32F = ColorRGBA<float>;
	using ColorRGB8 = ColorRGB<uchar>;
	using ColorRGB32F = ColorRGB<float>;
}
