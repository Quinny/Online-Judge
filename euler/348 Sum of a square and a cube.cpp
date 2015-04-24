#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

const unsigned long MAX = 50000;

unsigned long reverse(unsigned long);
bool palindrome(unsigned long);

int main() {
    std::vector<unsigned long> range;
    for (unsigned long i = 0; i <= MAX; ++i)
        range.push_back(i);

    std::vector<unsigned long> squares(MAX + 1);
    std::transform(range.begin(), range.end(), squares.begin(),
            [] (unsigned long n) { return n * n; });

    std::vector<unsigned long> cubes(MAX + 1);
    std::transform(range.begin(), range.end(), cubes.begin(),
            [] (unsigned long n) { return n * n * n; });
    
    std::unordered_map<unsigned long, int> occurances;
    unsigned long sum = 0;
    int found = 0;
    for (auto i : squares) {
        for (auto j : cubes) {
            if (palindrome(i + j)) {
                occurances[i + j]++;
                if (occurances[i + j] == 4) {
                    ++found;
                    sum += i + j;
                    if (found == 5)
                        break;
                }
            }
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

bool palindrome(unsigned long n) {
    return n == reverse(n);
}

unsigned long reverse(unsigned long n) {
    unsigned long m = 0;
    while (n > 0) {
        m = (10 * m) + (n % 10);
        n /= 10;
    }
    return m;
}
