#include <iostream>
#include "PrimeSieve.hpp"
#define SIEVE_MAX 67000000
#define MAX 100000000

bool prime_generating(int n, pe::PrimeSieve<SIEVE_MAX> const& p);
bool prime_generating(int n);
bool is_prime(int n);

int main() {
    pe::PrimeSieve<SIEVE_MAX> p;
    unsigned long ans = 0;
    for (int i = 1; i < MAX; i++) {
        if (i > SIEVE_MAX) {
            if (prime_generating(i))
                ans += i;
        }
        else {
            if (prime_generating(i, p))
                ans += i;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}

bool is_prime(int n) {
    if (n <= 3) return n > 1;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool prime_generating(int n) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 && !is_prime(i + n/i)) return false;
    }
    return true;
}

bool prime_generating(int n, pe::PrimeSieve<SIEVE_MAX> const& p) {
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0 && !p[i + n/i]) return false;
    }
    return true;
}
