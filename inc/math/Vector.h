#pragma once
#include <cmath>
#include <core/Concepts.h>
#include <core/DefaultOperators.h>
#include <string>

namespace CR::Math {
#pragma region Vector2

	template<Arithmetic T>
	class Vector2 : public CR::Core::DefaultOperatorsArithmetic<Vector2<T>> {
	  public:
		T X{0};
		T Y{0};

		explicit constexpr Vector2(T a_arg) noexcept : X(a_arg), Y(a_arg) {}
		constexpr Vector2(T a_x, T a_y) noexcept : X(a_x), Y(a_y) {}
		constexpr Vector2<T>& operator=(const Vector2<T>& a_arg) noexcept;

		constexpr Vector2<T>& operator+=(const Vector2<T>& a_arg) noexcept;
		constexpr Vector2<T>& operator+=(T a_arg) noexcept;
		constexpr Vector2<T>& operator-=(const Vector2<T>& a_arg) noexcept;
		constexpr Vector2<T>& operator-=(T a_arg) noexcept;
		constexpr Vector2<T>& operator*=(const Vector2<T>& a_arg) noexcept;
		constexpr Vector2<T>& operator*=(T a_arg) noexcept;
		constexpr Vector2<T>& operator/=(const Vector2<T>& a_arg) noexcept;
		constexpr Vector2<T>& operator/=(T a_arg) noexcept;

		constexpr T LengthSquared() const noexcept;
		constexpr T Length() const noexcept;

		operator std::string() const;
		operator std::wstring() const;
	};

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator=(const Vector2<T>& a_arg) noexcept {
		X = a_arg.X;
		Y = a_arg.Y;
		return *this;
	}

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& a_arg) noexcept {
		X += a_arg.X;
		Y += a_arg.Y;
		return *this;
	}

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator+=(T a_arg) noexcept {
		X += a_arg;
		Y += a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& a_arg) noexcept {
		X -= a_arg.X;
		Y -= a_arg.Y;
		return *this;
	}

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator-=(T a_arg) noexcept {
		X -= a_arg;
		Y -= a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& a_arg) noexcept {
		X *= a_arg.X;
		Y *= a_arg.Y;
		return *this;
	}

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator*=(T a_arg) noexcept {
		X *= a_arg;
		Y *= a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& a_arg) noexcept {
		X /= a_arg.X;
		Y /= a_arg.Y;
		return *this;
	}

	template<class T>
	constexpr Vector2<T>& Vector2<T>::operator/=(T a_arg) noexcept {
		X /= a_arg;
		Y /= a_arg;
		return *this;
	}

	template<class T>
	constexpr T Dot(const Vector2<T>& a_vec1, const Vector2<T>& a_vec2) noexcept {
		return a_vec1.X * a_vec2.X + a_vec1.Y * a_vec2.Y;
	}

	template<class T>
	constexpr T DistanceSquared(const Vector2<T>& a_vec1, const Vector2<T>& a_vec2) noexcept {
		return (a_vec1 - a_vec2).LengthSquared();
	}

	template<class T>
	constexpr T Distance(const Vector2<T>& a_vec1, const Vector2<T>& a_vec2) noexcept {
		return sqrt(DistanceSquared(a_vec1, a_vec2));
	}

	template<class T>
	constexpr Vector2<T> Pow(const Vector2<T>& a_vec1, const Vector2<T>& a_vec2) noexcept {
		return Vector2<T>(pow(a_vec1.X, a_vec2.X), pow(a_vec1.Y, a_vec2.Y));
	}

	template<class T>
	constexpr Vector2<T> Pow(const Vector2<T>& a_vec1, T a_arg) noexcept {
		return Vector2<T>(pow(a_vec1.X, a_arg), pow(a_vec1.Y, a_arg));
	}

	template<class T>
	constexpr Vector2<T> Pow(T a_arg, const Vector2<T>& a_vec1) noexcept {
		return Vector2<T>(pow(a_arg, a_vec1.X), pow(a_arg, a_vec1.Y));
	}

	template<class T>
	constexpr bool operator==(const Vector2<T>& a_vec1, const Vector2<T>& a_vec2) noexcept {
		return a_vec1.X == a_vec2.X && a_vec1.Y == a_vec2.Y;
	}

	template<class T>
	constexpr bool operator<(const Vector2<T>& a_vec1, const Vector2<T>& a_vec2) noexcept {
		if(a_vec1.X < a_vec2.X) return true;
		if(a_vec2.X < a_vec1.X) return false;
		return a_vec1.Y < a_vec2.Y;
	}

	template<class T>
	constexpr T Vector2<T>::LengthSquared() const noexcept {
		return Dot(*this, *this);
	}

	template<class T>
	constexpr T Vector2<T>::Length() const noexcept {
		return sqrt(LengthSquared());
	}

	template<class T>
	Vector2<T>::operator std::string() const {
		std::string result("{");
		result.append(std::to_string(X));
		result.append(", ");
		result.append(std::to_string(Y));
		result.append("}");
		return result;
	}

	template<class T>
	Vector2<T>::operator std::wstring() const {
		std::wstring result(L"{");
		result.append(std::to_wstring(X));
		result.append(L", ");
		result.append(std::to_wstring(Y));
		result.append(L"}");
		return result;
	}

#pragma endregion

#pragma region Vector3

	template<class T>
	class Vector3 : public CR::Core::DefaultOperatorsArithmetic<Vector3<T>> {
	  public:
		union {
			T X{0};
			T R;
		};
		union {
			T Y{0};
			T G;
		};
		union {
			T Z{0};
			T B;
		};

		constexpr explicit Vector3(T a_arg) noexcept : X(a_arg), Y(a_arg), Z(a_arg) {}
		constexpr Vector3(T a_x, T a_y, T a_z) noexcept : X(a_x), Y(a_y), Z(a_z) {}
		constexpr Vector3<T>& operator=(const Vector3<T>& a_arg) noexcept;

		constexpr Vector3<T>& operator+=(const Vector3<T>& a_arg) noexcept;
		constexpr Vector3<T>& operator+=(T a_arg) noexcept;
		constexpr Vector3<T>& operator-=(const Vector3<T>& a_arg) noexcept;
		constexpr Vector3<T>& operator-=(T a_arg) noexcept;
		constexpr Vector3<T>& operator*=(const Vector3<T>& a_arg) noexcept;
		constexpr Vector3<T>& operator*=(T a_arg) noexcept;
		constexpr Vector3<T>& operator/=(const Vector3<T>& a_arg) noexcept;
		constexpr Vector3<T>& operator/=(T a_arg) noexcept;

		constexpr T LengthSquared() const noexcept;
		constexpr T Length() const noexcept;

		operator std::string() const;
		operator std::wstring() const;
	};

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator=(const Vector3<T>& a_arg) noexcept {
		X = a_arg.X;
		Y = a_arg.Y;
		Z = a_arg.Z;
		return *this;
	}

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& a_arg) noexcept {
		X += a_arg.X;
		Y += a_arg.Y;
		Z += a_arg.Z;
		return *this;
	}

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator+=(T a_arg) noexcept {
		X += a_arg;
		Y += a_arg;
		Z += a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& a_arg) noexcept {
		X -= a_arg.X;
		Y -= a_arg.Y;
		Z -= a_arg.Z;
		return *this;
	}

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator-=(T a_arg) noexcept {
		X -= a_arg;
		Y -= a_arg;
		Z -= a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& a_arg) noexcept {
		X *= a_arg.X;
		Y *= a_arg.Y;
		Z *= a_arg.Z;
		return *this;
	}

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator*=(T a_arg) noexcept {
		X *= a_arg;
		Y *= a_arg;
		Z *= a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& a_arg) noexcept {
		X /= a_arg.X;
		Y /= a_arg.Y;
		Z /= a_arg.Z;
		return *this;
	}

	template<class T>
	constexpr Vector3<T>& Vector3<T>::operator/=(T a_arg) noexcept {
		X /= a_arg;
		Y /= a_arg;
		Z /= a_arg;
		return *this;
	}

	template<class T>
	constexpr T Dot(const Vector3<T>& a_vec1, const Vector3<T>& a_vec2) noexcept {
		return a_vec1.X * a_vec2.X + a_vec1.Y * a_vec2.Y + a_vec1.Z * a_vec2.Z;
	}

	template<class T>
	constexpr T DistanceSquared(const Vector3<T>& a_vec1, const Vector3<T>& a_vec2) noexcept {
		return (a_vec1 - a_vec2).LengthSquared();
	}

	template<class T>
	constexpr T Distance(const Vector3<T>& a_vec1, const Vector3<T>& a_vec2) noexcept {
		return sqrt(DistanceSquared(a_vec1, a_vec2));
	}

	template<class T>
	constexpr Vector3<T> Pow(const Vector3<T>& a_vec1, const Vector3<T>& a_vec2) noexcept {
		return Vector2<T>(pow(a_vec1.X, a_vec2.X), pow(a_vec1.Y, a_vec2.Y), pow(a_vec1.Z, a_vec2.Z));
	}

	template<class T>
	constexpr Vector3<T> Pow(const Vector3<T>& a_vec1, T a_arg) noexcept {
		return Vector3<T>(pow(a_vec1.X, a_arg), pow(a_vec1.Y, a_arg), pow(a_vec1.Z, a_arg));
	}

	template<class T>
	constexpr Vector3<T> Pow(T a_arg, const Vector3<T>& a_vec1) noexcept {
		return Vector3<T>(pow(a_arg, a_vec1.X), pow(a_arg, a_vec1.Y), pow(a_arg, a_vec1.Z));
	}

	template<class T>
	constexpr bool operator==(const Vector3<T> a_vec1, const Vector3<T>& a_vec2) noexcept {
		return a_vec1.X == a_vec2.X && a_vec1.Y == a_vec2.Y && a_vec1.Z == a_vec2.Z;
	}

	template<class T>
	constexpr bool operator!=(const Vector3<T> a_vec1, const Vector3<T>& a_vec2) noexcept {
		return !(a_vec1 == a_vec2);
	}

	template<class T>
	constexpr T Vector3<T>::LengthSquared() const noexcept {
		return Dot(*this, *this);
	}

	template<class T>
	constexpr T Vector3<T>::Length() const noexcept {
		return sqrt(LengthSquared());
	}

	template<class T>
	Vector3<T>::operator std::string() const {
		std::string result("{");
		result.append(std::to_string(X));
		result.append(", ");
		result.append(std::to_string(Y));
		result.append(", ");
		result.append(std::to_string(Z));
		result.append("}");
		return result;
	}

	template<class T>
	Vector3<T>::operator std::wstring() const {
		std::wstring result(L"{");
		result.append(std::to_wstring(X));
		result.append(L", ");
		result.append(std::to_wstring(Y));
		result.append(", ");
		result.append(std::to_string(Z));
		result.append(L"}");
		return result;
	}

#pragma endregion

#pragma region Vector4

	template<class T>
	class Vector4 : public CR::Core::DefaultOperatorsArithmetic<Vector4<T>> {
	  public:
		union {
			T X{0};
			T R;
		};
		union {
			T Y{0};
			T G;
		};
		union {
			T Z{0};
			T B;
		};
		union {
			T W{0};
			T A;
		};

		constexpr explicit Vector4(T a_arg) noexcept : X(a_arg), Y(a_arg), Z(a_arg), W(a_arg) {}
		constexpr Vector4(T a_x, T a_y, T a_z, T a_w) noexcept : X(a_x), Y(a_y), Z(a_z), W(a_w) {}
		constexpr Vector4<T>& operator=(const Vector4<T>& a_arg) noexcept;

		constexpr Vector4<T>& operator+=(const Vector4<T>& a_arg) noexcept;
		constexpr Vector4<T>& operator+=(T a_arg) noexcept;
		constexpr Vector4<T>& operator-=(const Vector4<T>& a_arg) noexcept;
		constexpr Vector4<T>& operator-=(T a_arg) noexcept;
		constexpr Vector4<T>& operator*=(const Vector4<T>& a_arg) noexcept;
		constexpr Vector4<T>& operator*=(T a_arg) noexcept;
		constexpr Vector4<T>& operator/=(const Vector4<T>& a_arg) noexcept;
		constexpr Vector4<T>& operator/=(T a_arg) noexcept;

		constexpr T LengthSquared() const noexcept;
		constexpr T Length() const noexcept;

		operator std::string() const;
		operator std::wstring() const;
	};

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator=(const Vector4<T>& a_arg) noexcept {
		X = a_arg.X;
		Y = a_arg.Y;
		Z = a_arg.Z;
		W = a_arg.W;
		return *this;
	}

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator+=(const Vector4<T>& a_arg) noexcept {
		X += a_arg.X;
		Y += a_arg.Y;
		Z += a_arg.Z;
		W += a_arg.W;
		return *this;
	}

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator+=(T a_arg) noexcept {
		X += a_arg;
		Y += a_arg;
		Z += a_arg;
		W += a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator-=(const Vector4<T>& a_arg) noexcept {
		X -= a_arg.X;
		Y -= a_arg.Y;
		Z -= a_arg.Z;
		W -= a_arg.W;
		return *this;
	}

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator-=(T a_arg) noexcept {
		X -= a_arg;
		Y -= a_arg;
		Z -= a_arg;
		W -= a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator*=(const Vector4<T>& a_arg) noexcept {
		X *= a_arg.X;
		Y *= a_arg.Y;
		Z *= a_arg.Z;
		W *= a_arg.W;
		return *this;
	}

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator*=(T a_arg) noexcept {
		X *= a_arg;
		Y *= a_arg;
		Z *= a_arg;
		W *= a_arg;
		return *this;
	}

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator/=(const Vector4<T>& a_arg) noexcept {
		X /= a_arg.X;
		Y /= a_arg.Y;
		Z /= a_arg.Z;
		W /= a_arg.W;
		return *this;
	}

	template<class T>
	constexpr Vector4<T>& Vector4<T>::operator/=(T a_arg) noexcept {
		X /= a_arg;
		Y /= a_arg;
		Z /= a_arg;
		W /= a_arg;
		return *this;
	}

	template<class T>
	constexpr T Dot(const Vector4<T>& a_vec1, const Vector4<T>& a_vec2) noexcept {
		return a_vec1.X * a_vec2.X + a_vec1.Y * a_vec2.Y + a_vec1.Z * a_vec2.Z + a_vec1.W * a_vec2.W;
	}

	template<class T>
	constexpr T DistanceSquared(const Vector4<T>& a_vec1, const Vector4<T>& a_vec2) noexcept {
		return (a_vec1 - a_vec2).LengthSquared();
	}

	template<class T>
	constexpr T Distance(const Vector4<T>& a_vec1, const Vector4<T>& a_vec2) noexcept {
		return sqrt(DistanceSquared(a_vec1, a_vec2));
	}

	template<class T>
	constexpr Vector4<T> Pow(const Vector4<T>& a_vec1, const Vector4<T>& a_vec2) noexcept {
		return Vector4<T>(pow(a_vec1.X, a_vec2.X), pow(a_vec1.Y, a_vec2.Y), pow(a_vec1.Z, a_vec2.Z),
		                  pow(a_vec1.W, a_vec2.W));
	}

	template<class T>
	constexpr Vector4<T> Pow(const Vector4<T>& a_vec1, T a_arg) noexcept {
		return Vector4<T>(pow(a_vec1.X, a_arg), pow(a_vec1.Y, a_arg), pow(a_vec1.Z, a_arg), pow(a_Vec1.W, a_arg));
	}

	template<class T>
	constexpr Vector4<T> Pow(T a_arg, const Vector4<T>& a_vec1) noexcept {
		return Vector4<T>(pow(a_arg, a_vec1.X), pow(a_arg, a_vec1.Y), pow(a_arg, a_vec1.Z), pow(a_arg, a_vec1.W));
	}

	template<class T>
	constexpr bool operator==(const Vector4<T> a_vec1, const Vector4<T>& a_vec2) noexcept {
		return a_vec1.X == a_vec2.X && a_vec1.Y == a_vec2.Y && a_vec1.Z == a_vec2.Z && a_vec1.W == a_vec2.W;
	}

	template<class T>
	constexpr bool operator!=(const Vector4<T> a_vec1, const Vector4<T>& a_vec2) noexcept {
		return !(a_vec1 == a_vec2);
	}

	template<class T>
	constexpr T Vector4<T>::LengthSquared() const noexcept {
		return Dot(*this, *this);
	}

	template<class T>
	constexpr T Vector4<T>::Length() const noexcept {
		return sqrt(LengthSquared());
	}

	template<class T>
	Vector4<T>::operator std::string() const {
		std::string result("{");
		result.append(std::to_string(X));
		result.append(", ");
		result.append(std::to_string(Y));
		result.append(", ");
		result.append(std::to_string(Z));
		result.append(", ");
		result.append(std::to_string(W));
		result.append("}");
		return result;
	}

	template<class T>
	Vector4<T>::operator std::wstring() const {
		std::wstring result(L"{");
		result.append(std::to_wstring(X));
		result.append(L", ");
		result.append(std::to_wstring(Y));
		result.append(", ");
		result.append(std::to_string(Z));
		result.append(", ");
		result.append(std::to_string(W));
		result.append(L"}");
		return result;
	}

#pragma endregion
}

template<typename CharT, typename Traits, typename T>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& a_strm,
                                                     const CR::Math::Vector2<T>& a_vec) {
	a_strm << static_cast<std::basic_string<CharT, Traits>>(a_vec);
	return a_strm;
}

template<typename CharT, typename Traits, typename T>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& a_strm,
                                                     const CR::Math::Vector3<T>& a_vec) {
	a_strm << static_cast<std::basic_string<CharT, Traits>>(a_vec);
	return a_strm;
}

template<typename CharT, typename Traits, typename T>
inline std::basic_ostream<CharT, Traits>& operator<<(std::basic_ostream<CharT, Traits>& a_strm,
                                                     const CR::Math::Vector4<T>& a_vec) {
	a_strm << static_cast<std::basic_string<CharT, Traits>>(a_vec);
	return a_strm;
}

namespace std {
	template<typename T>
	struct hash<CR::Math::Vector2<T>> {
		constexpr size_t operator()(const CR::Math::Vector2<T>& a_vec) const noexcept {
			return hash<T>()(a_vec.X) ^ hash<T>()(a_vec.Y);
		}
	};

	template<typename T>
	struct hash<CR::Math::Vector3<T>> {
		constexpr size_t operator()(const CR::Math::Vector3<T>& a_vec) const noexcept {
			return hash<T>()(a_vec.X) ^ hash<T>()(a_vec.Y) ^ hash<T>()(a_vec.Z);
		}
	};

	template<typename T>
	struct hash<CR::Math::Vector4<T>> {
		constexpr size_t operator()(const CR::Math::Vector4<T>& a_vec) const noexcept {
			return hash<T>()(a_vec.X) ^ hash<T>()(a_vec.Y) ^ hash<T>()(a_vec.Z);
		}
	};
}    // namespace std