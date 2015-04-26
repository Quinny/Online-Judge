#include <iostream>
#include <unordered_set>

#define LIMIT 10000000

int sum_square_digits(int);
bool converges_to_89(int);

int main(void){
    std::unordered_set<int> s;
	// the highest possible value for the sum of the digits squared for
    // values < 10 million is 648
	int ans  = 0;
    for(int i = 1; i <= 648; i++){
		if (converges_to_89(i)) {
            ++ans;
            s.insert(i);
        }
	}
	for(int i = 649; i <= LIMIT; i++){
		if (s.find(sum_square_digits(i)) != s.end())
            ++ans;
	}
	std::cout << ans << std::endl;

	return 0;
}

bool converges_to_89(int i) {
    while (i != 1 && i != 89)
        i = sum_square_digits(i);
    return i == 89;
}

int sum_square_digits(int n) {
	int ans = 0;
	while(n > 0){
		ans += (n % 10) * (n % 10);
		n /= 10;
	}
	return ans;
}
