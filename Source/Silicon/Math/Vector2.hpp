#pragma once
#include <ostream>


namespace se
{
		// +x+x+x+x+x ------------ +x+x+x+x+x
		// +x+x+x+x+x DECLARATIONS +x+x+x+x+x
		// +x+x+x+x+x ------------ +x+x+x+x+x
	

	template<class T>
	class Vector2
	{
	public:
		Vector2<T>();
		Vector2<T>(const T & X, const T & Y);
		template<class U>
		Vector2<T>(const Vector2<U> & vector);
		~Vector2<T>();

		T x;
		T y;

			//---------------
			// LOGIC OPERATORS
			//---------------

		Vector2<T>& operator=(const Vector2<T>& other);
		Vector2<T>& operator+=(const Vector2<T>& other);
		Vector2<T>& operator-=(const Vector2<T>& other);
		Vector2<T>& operator*=(const Vector2<T>& other);
		Vector2<T>& operator/=(const Vector2<T>& other);

		friend Vector2<T> operator+(Vector2<T> left, const Vector2<T>& right);
		friend Vector2<T> operator-(Vector2<T> left, const Vector2<T>& right);
		friend Vector2<T> operator*(Vector2<T> left, const Vector2<T>& right);
		friend Vector2<T> operator/(Vector2<T> left, const Vector2<T>& right);

		friend std::ostream& operator<<(const std::ostream& stream, const Vector2<T>& vector);
		friend bool operator==(const Vector2<T>& left, const Vector2<T>& right);
		friend bool operator!=(const Vector2<T>& left, const Vector2<T>& right);
	};
	
		// +x+x+x+x+x ------------ +x+x+x+x+x
		// +x+x+x+x+x  DEFINITIONS +x+x+x+x+x
		// +x+x+x+x+x ------------ +x+x+x+x+x

	template<class T>
	inline se::Vector2<T>::Vector2() :
		x(0),
		y(0)
	{}

	template<class T>
	inline Vector2<T>::Vector2(const T & X, const T & Y) :
		x(X),
		y(Y)
	{}

	template<class T>
	template<class U>
	inline Vector2<T>::Vector2(const Vector2<U>& vector) :
		x(static_cast<T>(vector.x)),
		y(static_cast<T>(vector.y))
	{}

	template<class T>
	inline Vector2<T>::~Vector2()
	{}

		//---------------
		// LOGIC OPERATORS
		//---------------

	template<class T>
	inline Vector2<T>& Vector2<T>::operator=(const Vector2<T>& other)
	{
		if (this != &other)
		{
			this->x = other.x;
			this->y = other.y;
		}

		return *this;
	}

	template<class T>
	inline Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& other)
	{
		this->x += other.x;
		this->y += other.y;

		return *this;
	}

	template<class T>
	inline Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& other)
	{
		this->x -= other.x;
		this->y -= other.y;

		return *this;
	}

	template<class T>
	inline Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& other)
	{
		this->x *= other.x;
		this->y *= other.y;

		return *this;
	}

	template<class T>
	inline Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& other)
	{
		this->x /= other.x;
		this->y /= other.y;

		return *this;
	}

	template<class T>
	std::ostream & operator<<(std::ostream & stream, const Vector2<T>& vector)
	{
		return stream << "Vector2( " << vector.x << " | " << vector.y << " )";
	}

	//Common Vector2 typedefs
	
	typedef Vector2<int32_t>		Vector2i;
	typedef Vector2<float>		Vector2f;
	typedef Vector2<uint32_t>	Vector2u;

	typedef Vector2<uint16_t> Vector2u16;
}