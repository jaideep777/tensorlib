#ifndef TENSORLIB_VEC3_H_
#define TENSORLIB_VEC3_H_

#include <iostream>
#include <cmath>

template <class T>
class vec3 {
public:
	T x, y, z;

	// Default constructor
	vec3() : x(T()), y(T()), z(T()) {}

	// Parameterized constructor
	vec3(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

	// Copy constructor
	template<class U>
	vec3(const vec3<U>& other) : x(other.x), y(other.y), z(other.z) {}

	// Assignment operator
	vec3& operator=(const vec3& other) {
		if (this != &other) {
			x = other.x;
			y = other.y;
			z = other.z;
		}
		return *this;
	}

	// Equality operator
	bool operator==(const vec3& other) const {
		return 	
			x == other.x &&
			y == other.y &&
			z == other.z;
	}

	// Not equal operator
	bool operator!=(const vec3& other) const {
		return !(*this == other);
	}

	// Addition assignment
	template <class U>
	vec3& operator+=(const vec3<U>& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	// Subtraction assignment
	template <class U>
	vec3& operator-=(const vec3<U>& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	// Scalar multiplication assignment
	template <class U>
	vec3& operator*=(U scalar) {
		x *= scalar;
		y *= scalar;
		z *= scalar;
		return *this;
	}

	// Scalar division assignment
	template <class U>
	vec3& operator/=(U scalar) {
		x /= scalar;
		y /= scalar;
		z /= scalar;
		return *this;
	}

	// Magnitude of the vector
	T magnitude() const {
		return std::sqrt(x * x + y * y + z * z);
	}

	// Output stream operator
	friend std::ostream& operator<<(std::ostream& os, const vec3<T>& v) {
		os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
		return os;
	}
};


// vector addition
template <class T, class U>
vec3<T> operator+(vec3<T> lhs, const vec3<U>& rhs) {
	lhs += rhs;
	return lhs;
}

// vector subtraction
template <class T, class U>
vec3<T> operator-(vec3<T> lhs, const vec3<U>& rhs) {
	lhs -= rhs;
	return lhs;
}

// Scalar multiplication
template <class T, class U>
vec3<T> operator*(vec3<T> lhs, U scalar) {
	lhs *= scalar;
	return lhs;
}

// Scalar multiplication (commutative)
template <class T, class U>
vec3<T> operator*(U scalar, vec3<T> v) {
	return v * scalar;
}

// Scalar division
template <class T, class U>
vec3<T> operator/(vec3<T> lhs, U scalar) {
	lhs /= scalar;
	return lhs;
}

// Normalize vector
template<class T>
vec3<T> normalize(const vec3<T>& v, T tol = 0) {
	T mag = v.magnitude() + tol;
	return vec3<T>(v.x / mag, v.y / mag, v.z / mag);
}

// Normalize vector, but return zero if vector is 0
template<class T>
vec3<T> normalize_zero(const vec3<T>& v) {
	T mag = v.magnitude();
	if (mag <= 0) return vec3<T>(0,0,0);
	return vec3<T>(v.x / mag, v.y / mag, v.z / mag);
}

// vector dot product
template <class T, class U>
T dot(const vec3<T>& lhs, const vec3<U>& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

// Vector cross product
template <class T, class U>
vec3<T> cross(const vec3<T>& lhs, const vec3<U>& rhs) {
    return vec3<T>(
        lhs.y * rhs.z - lhs.z * rhs.y,
        lhs.z * rhs.x - lhs.x * rhs.z,
        lhs.x * rhs.y - lhs.y * rhs.x
    );
}

using float3 = vec3<float>;
using double3 = vec3<double>;

#endif
