#include "Vector2.hpp"


namespace se
{
	template<class T>
	Vector2<T> operator+(Vector2<T> left, const Vector2<T>& right)
	{
		return left += right;
	}

	template<class T>
	Vector2<T> operator-(Vector2<T> left, const Vector2<T>& right)
	{
		return left -= right;
	}

	template<class T>
	Vector2<T> operator*(Vector2<T> left, const Vector2<T>& right)
	{
		return left *= right;
	}

	template<class T>
	Vector2<T> operator/(Vector2<T> left, const Vector2<T>& right)
	{
		return left /= right;
	}

	template<class T>
	bool operator==(const Vector2<T>& left, const Vector2<T>& right)
	{
		return (left.x == right.x) && (left.y == right.y);
	}

	template<class T>
	bool operator!=(const Vector2<T>& left, const Vector2<T>& right)
	{
		return !(left == right);
	}
}
