#include <iostream>

bool isBouncy(int);

int main(void){
	double top = 1;
	double bouncies = 0;
	while(bouncies/top != 0.99){
		top++;
		if(isBouncy(top))
			bouncies++;
	}
	std::cout << ((int)top) << std::endl;
	return 0;
}

bool isBouncy(int n){
	bool increasing = true;
	bool decreasing = true;
	int n1 = n%10;
	n/=10;
	while(n > 0){
		int n2 = n % 10;
		n/=10;
		if(n1 > n2) decreasing = false;
		if(n1 < n2) increasing = false;
		if(increasing == false && decreasing == false)
			return true;
		n1 = n2;
	}
	return decreasing == false && increasing == false;
}