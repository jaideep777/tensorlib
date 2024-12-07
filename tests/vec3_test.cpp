#include "../include/vec3.h"
using namespace std;

template<class T, class U>
bool approx_equal(const vec3<T>& v1, const vec3<U>& v2, double tol=1e-6){
	return 
		(fabs(v1.x-v2.x) < tol) &&
		(fabs(v1.y-v2.y) < tol) &&
		(fabs(v1.z-v2.z) < tol);
}

// Example usage
int main() {
    vec3<float> v1(1.0f, 2.0f, 3.0f);
    double3 v2(4.0f, 5.0f, 6.0f);

    auto v3 = v1 + v2; // Vector addition
    auto v4 = v1 - v2; // Vector subtraction
    auto v5 = v1 * 2.0f; // Scalar multiplication
    auto v51 = 2.0f * v1; // Scalar multiplication
    auto v6 = v1 / 2.0f; // Scalar division
    auto dot_product = dot(v1,v2); // Dot product
    auto cross_product = cross(v1,v2); // Cross product
	auto v7 = normalize(v1, 0.f); // normalization

    // Expected answers
    vec3<float> expected_v3(5.0f, 7.0f, 9.0f);
    vec3<float> expected_v4(-3.0f, -3.0f, -3.0f);
    vec3<float> expected_v5(2.0f, 4.0f, 6.0f);
    vec3<float> expected_v6(0.5f, 1.0f, 1.5f);
    float expected_dot_product = 32.0f;
    vec3<float> expected_cross_product(-3.0f, 6.0f, -3.0f);
    vec3<float> expected_v7(0.2672612, 0.5345225, 0.8017837);

    // Testing
	std::cout << "v3: " << v3 << " (Expected: " << expected_v3 << ")\n";
    if (!approx_equal(v3, expected_v3)) return 1;
    std::cout << "v4: " << v4 << " (Expected: " << expected_v4 << ")\n";
    if (!approx_equal(v4, expected_v4)) return 1;
    std::cout << "v5: " << v5 << " (Expected: " << expected_v5 << ")\n";
    if (!approx_equal(v5, expected_v5)) return 1;
    std::cout << "v6: " << v6 << " (Expected: " << expected_v6 << ")\n";
    if (!approx_equal(v6, expected_v6)) return 1;
    std::cout << "v7: " << v7 << " (Expected: " << expected_v7 << ")\n";
    if (!approx_equal(v7, expected_v7)) return 1;
    std::cout << "Dot product: " << dot_product << " (Expected: " << expected_dot_product << ")\n";
    if (dot_product != expected_dot_product) return 1;
    std::cout << "Cross product: " << cross_product << " (Expected: " << expected_cross_product << ")\n";
    if (!approx_equal(cross_product, expected_cross_product)) return 1;



    return 0;
}
