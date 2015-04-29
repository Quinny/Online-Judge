#include <iostream>
#include <set>
#include "BigInteger.hpp"
#include <numeric>

long reverse(long);
bool palindrome(long);

int main(){
	std::set<long> s;
	long lim = 100000000;
	for(int i = 1; i * i < lim; i++){
		long tmp = i * i;
		for (int j = i + 1; j * j < lim; j++) {
			tmp += j * j;
			if(tmp > lim)
                break;
			if(palindrome(tmp))
                s.insert(tmp);
		}
	}
    std::cout <<
        std::accumulate(s.begin(), s.end(), 0UL)
    << std::endl;
	return 0;
}

long reverse(long n){
	int ans = 0;
	while(n > 0){
		ans = (10 * ans) + (n % 10);
		n /= 10;
	}
	return ans;
}

bool palindrome(long n){
	return n == reverse(n);
}
