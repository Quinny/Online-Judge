#include <iostream>
#include <unordered_set>
#include <numeric>
const long lim = 1000000000000L;

long all_ones(int base, int len);

int main() {
    std::unordered_set<long> s;
    for (int base = 2; base <= 999999; base++) {
        for (long len = 3; ; len++) {
            long x = all_ones(base, len);
            if (x > lim) break;
            s.insert(x);
        }
    }
    std::cout << std::accumulate(s.begin(), s.end(), 0L) << std::endl;
    return 0;
}

long all_ones(int base, int len) {
    long ret = 1, f = 1;
    for (int i = 1; i < len; i++) {
        f *= base;
        ret += f;
    }
    return ret;
}
