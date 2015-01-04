#include <iostream>
#define MAX 9
#define DIGITS 20

long no_consec_dig_sum(int, int, int, long[10][10][DIGITS + 1]);

int main(){
	long ans = 0;
	long cache[10][10][DIGITS + 1] = {0};
	for(int i = 1; i <= 9; i++)
		ans += no_consec_dig_sum(0, i, DIGITS - 1, cache);
	std::cout << ans << std::endl;
	return 0;
}

long no_consec_dig_sum(int prev_1, int prev_2, int digits, long cache[10][10][DIGITS + 1]){
	if(digits == 0) return 1;
	if(cache[prev_1][prev_2][digits]) return cache[prev_1][prev_2][digits];
	int end = MAX - prev_2 - prev_1;
	long ans = 0;
	for(int i = 0; i <= end; i++)
		ans += no_consec_dig_sum(prev_2, i, digits - 1, cache);
	return cache[prev_1][prev_2][digits] = ans;
}