#include <iostream>
#include "BigInteger.hpp"

long sum_digits(BigInteger);

int main(){
	int n = 0;
	for(int i = 2; n < 40; i++){ // 40 and 50 are just arbitrary limits
		BigInteger v = i;
		for(int j = 2; j < 50; j++){
			v *= i;
			if(sum_digits(v) == i)
				n++;
			if(n == 31){
				std::cout << v << std::endl;
				break;
			}
		}
		if(n == 31) break;
	}
	return 0;
}

long sum_digits(BigInteger n){
	long ans = 0;
	for(int i = 0; i < n.size(); i++)
		ans += n[i];
	return ans;
}