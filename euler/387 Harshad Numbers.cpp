#include <iostream>

bool prime(long n);
void recurse(long n, long s);
long ans = 0;
const long LIM = 100000000000000L;

int main() {
    for (long i = 1; i <= 9; i++)
        recurse(i, i);
    std::cout << ans << std::endl;
    return 0;
}

void recurse(long n, long s) {
    if (n % s != 0)
        return;
    bool strong = prime(n / s);
    for (long i = 0; i <= 9; i++) {
        long next = n * 10 + i;
        if (next >= LIM)
            break;
        if (strong && prime(next))
            ans += next;
        recurse(next, s + i);
    }
}

bool prime(long n) {
    if (n <= 3)
        return n > 1;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
