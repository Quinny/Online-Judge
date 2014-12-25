#include <iostream>
#define DIGITS 100

long non_bouncy_increase(long, long, long[10][DIGITS + 1]);
long non_bouncy_decrease(long, long, long[10][DIGITS + 1]);

int main(){
	long t[10][DIGITS + 1] = {0};
	long increase = non_bouncy_increase(DIGITS, 1, t);
	long decrease = 0;
	for(int i = 1; i <= 9; i++){
		long t[10][DIGITS + 1] = {0};
		decrease += non_bouncy_decrease(DIGITS, i, t);
	}
	std::cout << increase + decrease - (DIGITS * 9) << std::endl;
	return 0;
}

long non_bouncy_increase(long max, long cur, long t[10][DIGITS + 1]){
	if(max == 0) return 0;
	if(t[cur][max]) return t[cur][max];
	long ans = 0;
	for(long i = cur; i <= 9; i++)
		ans += 1 + non_bouncy_increase(max - 1, i, t);
	return t[cur][max] = ans;
}

long non_bouncy_decrease(long max, long cur, long t[10][DIGITS + 1]){
	if(max == 0) return 0;
	if(t[cur][max]) return t[cur][max];
	long ans = 1;
	for(long i = cur; i >= 0; i--)
		ans += non_bouncy_decrease(max - 1, i, t);
	return t[cur][max] = ans;
}