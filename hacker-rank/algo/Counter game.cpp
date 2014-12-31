#include <iostream>

bool pow_2(unsigned long);
unsigned long div_2(unsigned long);
unsigned long closest_2(unsigned long);

int main(){
	int t;
	std::cin >> t;
	while(t--){
		unsigned long n;
		std::cin >> n;
		bool louise = false;
		while(n != 1){
			if(pow_2(n)) n = div_2(n);
			else n = closest_2(n);
			louise = !louise;
		}
		if(louise)
			std::cout << "Louise" << std::endl;
		else
			std::cout << "Richard" << std::endl;
	}
	return 0;
}

unsigned long closest_2(unsigned long x){
	while(!pow_2(x))
		x = x & (x - 1);
	return x;
}

unsigned long div_2(unsigned long x){
	return x >> 1;
}

bool pow_2(unsigned long x){
	return (x & (x - 1)) == 0;
}