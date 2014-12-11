#include <iostream>
#include <cmath>

// shout out to wikipedia http://en.wikipedia.org/wiki/Methods_of_computing_square_roots#Continued_fraction_expansion

int period_length(int);

int main(){
	int ans = 0;
	for(int i = 2; i <= 10000; i++){
		if(period_length(i) % 2 == 1) ans++;
	}
	std::cout << ans << std::endl;
	return 0;
}

int period_length(int n){
	int a0 = sqrt(n);
	if(a0 * a0 == n) return 0;
	int m = 0, d = 1, a = a0;
	int p = 0;
	while(a != 2 * a0){
		p++;
		m = (d * a) - m;
		d = (n - (m * m)) / d;
		a = (a0 + m) / d;
	}
	return p;
}