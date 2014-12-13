#include <iostream>
#define LIMIT 1500000

// Triple generation learned here: http://en.wikipedia.org/wiki/Pythagorean_triple#Generating_a_triple

int gcd(int, int);

int main(){
	int perims[LIMIT + 1]; // faster than using a map since the range is known (tested)
	memset(perims, 0, sizeof(perims));
	for(long m = 2; m * m <= LIMIT / 2; m++){
		for(long n = 1; n <= m; n++){
			if((m + n) % 2 == 1 && gcd(m, n) == 1){
				long a = m * m - n * n;
				long b = 2 * m * n;
				long c = m * m + n * n;
				long p = a + b + c;
				for(int j = 1; p * j < LIMIT ; j++)
					perims[p * j]++;
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= LIMIT; i++){
		if(perims[i] == 1) ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}

int gcd(int a, int b){
	if(a == 0) return b;
	return gcd(b % a, a);
}