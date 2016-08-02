#include "Vector3.hpp"


namespace se
{
	template<class T>
	Vector3<T> se::operator+(Vector3<T> left, const Vector3<T>& right)
	{
		return left += right;
	}

	template<class T>
	Vector3<T> operator-(Vector3<T> left, const Vector3<T>& right)
	{
		return left -= right;
	}

	template<class T>
	Vector3<T> operator*(Vector3<T> left, const Vector3<T>& right)
	{
		return left *= right;
	}

	template<class T>
	Vector3<T> operator/(Vector3<T> left, const Vector3<T>& right)
	{
		return left /= right;
	}
}

