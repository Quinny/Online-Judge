#include <iostream>
#include <vector>
#include <unordered_map>

#define LIMIT 10000000

int sumSquareDigits(int);

int main(void){
	std::unordered_map<int, int> cache;
	for(int i = 1; i <= 648; i++){ //the highest possible value for the sum of the digits squared for values < 10 million is 648
		int tmp = i;
		while(tmp!=1 && tmp!=89)
			tmp  = sumSquareDigits(tmp);
		cache[i] = tmp;
	}
	int ans  = 0;
	for(int i = 1; i <= LIMIT; i++){
		if(cache[sumSquareDigits(i)] == 89) ans++;
	}
	std::cout << ans << std::endl;

	return 0;
}

int sumSquareDigits(int n){
	int ans = 0;
	while(n > 0){
		ans+= (n%10) * (n%10);
		n/=10;
	}
	return ans;
}