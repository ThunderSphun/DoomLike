#pragma once

#include <type_traits>
#include <ostream>
#include <format>

namespace doomLike::math {
	template<class T, int Dim>
	struct Point {
		union {
			struct {
				T x;
				T y;
				T z;
				T w;
			};
			struct {
				T r;
				T g;
				T b;
				T a;
			};
			T coord[Dim];
		};

		Point() {
			for (int i = 0; i < Dim; i++)
				coord[i] = static_cast<T>(0);
		}

		explicit Point(T x) : x(x), y(static_cast<T>(0)), z(static_cast<T>(0)), w(static_cast<T>(0)) {
			static_assert(Dim == 1, "Point dimension mismatch");
		}

		Point(T x, T y) : x(x), y(y), z(static_cast<T>(0)), w(static_cast<T>(0)) {
			static_assert(Dim == 2, "Point dimension mismatch");
		}

		Point(T x, T y, T z) : x(x), y(y), z(z), w(static_cast<T>(0)) {
			static_assert(Dim == 3, "Point dimension mismatch");
		}

		Point(T x, T y, T z, T w) : x(x), y(y), z(z), w(w) {
			static_assert(Dim == 4, "Point dimension mismatch");
		}

		template <class U>
		auto operator+(const Point<U, Dim>& rhs) {
			Point<decltype(coord[0] + std::declval<U>()), Dim> result;
			for (int i = 0; i < Dim; i++)
				result.coords[i] = coord[i] + rhs.coord[i];

			return result;
		}

		template <class U>
		auto operator+=(const Point<U, Dim>& rhs) {
			for (int i = 0; i < Dim; i++)
				coord[i] += rhs.coord[i];

			return *this;
		}

		template <class U>
		auto operator-(const Point<U, Dim>& rhs) {
			Point<decltype(coord[0] - std::declval<U>()), Dim> result;
			for (int i = 0; i < Dim; i++)
				result.coords[i] = coord[i] + rhs.coord[i];

			return result;
		}

		template <class U>
		auto operator-=(const Point<U, Dim>& rhs) {
			for (int i = 0; i < Dim; i++)
				coord[i] -= rhs.coord[i];

			return *this;
		}
	};
}