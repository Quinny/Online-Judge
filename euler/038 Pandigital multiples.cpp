#include <iostream>

long concat(long, long);
bool is_pandigital(long);
long consec(long);
int digits(long);

int main(){
	long max = 0;
	for(int i = 1; i < 50000; i++){
		long tmp = consec(i);
		max = max > tmp ? max : tmp;
	}
	std::cout << max << std::endl;
	return 0;
}

long consec(long x){
	int n = 1;
	long ans = 0;
	while(ans < 100000000){
		ans = concat(ans, x * n);
		n++;
	}
	if(is_pandigital(ans))
		return ans;
	else
		return -1;
}

long concat(long x, long y){
	long tmp = y;
	while(tmp > 0){
		x *= 10;
		tmp /= 10;
	}
	return x + y;
}

bool is_pandigital(long x){
	int a[10];
	memset(a, 0, sizeof(a));
	int c = 0;
	while(x > 0){
		if(x % 10 == 0) return false;
		if(a[x % 10] == 0){
			a[x % 10]++;
			c++;
		}
		else
			return false;
		x /= 10;
	}
	return c == 9;
}