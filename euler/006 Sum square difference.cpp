#include <iostream>

template <unsigned N, unsigned M, bool E = false>
struct sum_squares {
};

template <unsigned N, unsigned M>
struct sum_squares <N, M, false> {
    static const constexpr unsigned value =
        N * N + sum_squares<N + 1, M, N == M>::value;
};

template <unsigned N, unsigned M>
struct sum_squares <N, M, true> {
    static const constexpr unsigned value = 0;
};

int main(){
	long long s1 = sum_squares<1, 100>::value;
	long long s2 = ((100 * 101) / 2) * ((100 * 101) / 2);
	std::cout << s2 - s1 << std::endl;
	return 0;
}
