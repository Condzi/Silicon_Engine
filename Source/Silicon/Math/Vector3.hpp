#pragma once
#include <ostream>
#include <string>


namespace se
{		
		// +x+x+x+x+x ------------ +x+x+x+x+x
		// +x+x+x+x+x DECLARATIONS +x+x+x+x+x
		// +x+x+x+x+x ------------ +x+x+x+x+x


	template<class T>
	class Vector3 
	{
	public:
		Vector3<T>();
		Vector3<T>(const T & X, const T & Y, const T & Z);
		template<class U>
		Vector3<T>(const Vector3<U> & vector);
		~Vector3<T>();

		T x;
		T y;
		T z;

		//---------------
		// LOGIC OPERATORS
		//---------------

		Vector3<T>& operator=(const Vector3<T>& other);
		Vector3<T>& operator+=(const Vector3<T>& other);
		Vector3<T>& operator-=(const Vector3<T>& other);
		Vector3<T>& operator*=(const Vector3<T>& other);
		Vector3<T>& operator/=(const Vector3<T>& other);

		friend Vector3<T> operator+(Vector3<T> left, const Vector3<T>& right);
		friend Vector3<T> operator-(Vector3<T> left, const Vector3<T>& right);
		friend Vector3<T> operator*(Vector3<T> left, const Vector3<T>& right);
		friend Vector3<T> operator/(Vector3<T> left, const Vector3<T>& right);

		friend std::ostream& operator<<(const std::ostream& stream, const Vector3<T>& vector);
		friend bool operator==(const Vector3<T>& left, const Vector3<T>& right);
		friend bool operator!=(const Vector3<T>& left, const Vector3<T>& right);

		std::string GetInString();
	};


	// +x+x+x+x+x ------------ +x+x+x+x+x
	// +x+x+x+x+x  DEFINITIONS +x+x+x+x+x
	// +x+x+x+x+x ------------ +x+x+x+x+x

	template<class T>
	inline Vector3<T>& Vector3<T>::operator=(const Vector3<T>& other)
	{
		this->x = other.x;
		this->y = other.y;
		this->z = other.z;

		return *this;
	}

	template<class T>
	inline Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;

		return *this;
	}

	template<class T>
	inline Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;

		return *this;
	}

	template<class T>
	inline Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;

		return *this;
	}

	template<class T>
	inline Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;

		return *this;
	}

	template<class T>
	inline std::string Vector3<T>::GetInString()
	{
		return std::string("Vector3( " + std::to_string(this->x) + " | " + std::to_string(this->y) + " | " + std::to_string(this->z) + " )");
	}

	template<class T>
	std::ostream & operator<<(const std::ostream & stream, const Vector3<T>& vector)
	{
		return stream << "Vector3( " << vector.x << " | " << vector.y << " | " << vector.z << " )";
	}

	template<class T>
	bool operator==(const Vector3<T>& left, const Vector3<T>& right)
	{
		return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
	}

	template<class T>
	bool operator!=(const Vector3<T>& left, const Vector3<T>& right)
	{
		return !(left == right);
	}


	template<class T>
	inline Vector3<T>::Vector3() :
		x(0),
		y(0),
		z(0)
	{}

	template<class T>
	inline Vector3<T>::Vector3(const T & X, const T & Y, const T & Z) :
		x(X),
		y(Y),
		z(Z)
	{}

	template<class T>
	template<class U>
	inline Vector3<T>::Vector3(const Vector3<U>& vector) :
		x(static_cast<T>(vector.x)),
		y(static_cast<T>(vector.y)),
		z(static_cast<T>(vector.z))
	{}

	template<class T>
	inline Vector3<T>::~Vector3()
	{}

	//Common Vectors
	typedef Vector3<int32_t> Vector3i;
	typedef Vector3<uint32_t> Vector3iu;
	typedef Vector3<float> Vector3f;

	typedef Vector3<int16_t> Vector3i16;

}
