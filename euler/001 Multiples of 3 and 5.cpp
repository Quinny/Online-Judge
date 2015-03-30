#include <iostream>

// Helper function since > cannot be used in template parameters
template <unsigned N, unsigned M>
struct greater_than_equal_to {
    static const constexpr bool value = N >= M;
};

// General case
template <unsigned MULTIPLE, unsigned TO, unsigned CUR = 0, bool OVER = false>
struct sum_multiples {
};

// If we haven't gone over, then continue on
template <unsigned MULTIPLE, unsigned TO, unsigned CUR>
struct sum_multiples<MULTIPLE, TO, CUR, false> {
    static const constexpr unsigned value =
        CUR + sum_multiples<MULTIPLE, TO, CUR + MULTIPLE,
                 greater_than_equal_to<CUR, TO>::value>::value;
};

// If we have gone over, then backtrack
template <unsigned MULTIPLE, unsigned TO, unsigned CUR>
struct sum_multiples<MULTIPLE, TO, CUR, true> {
    static const constexpr unsigned value = (-1 * CUR) + MULTIPLE;
};

int main() {
    auto threes = sum_multiples<3, 1000>::value;
    auto fives = sum_multiples<5, 1000>::value;
    auto commons = sum_multiples<15, 1000>::value;
    std::cout << threes + fives - commons << std::endl;
    return 0;
}
