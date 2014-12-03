#include <iostream>
#include <set>

std::set<long> gen_fibs(long lim);

int main(){
	std::set<long> fib = gen_fibs(10000000000L);
	int t;
	std::cin >> t;
	while(t--){
		long n;
		std::cin >> n;
		if(fib.find(n) != fib.end())
			std::cout << "IsFibo" << std::endl;
		else
			std::cout << "IsNotFibo" << std::endl;
	}
}

std::set<long> gen_fibs(long lim){
	std::set<long> fib;
	long n1 = 0, n2 = 1, cur = 0;
	while(cur < lim){
		cur = n1 + n2;
		fib.insert(cur);
		n1 = n2;
		n2 = cur;
	}
	return fib;
}