#include <iostream>

int sum_multiples(int,int);

int main(){
	int threes = sum_multiples(3,1000);
	int fives = sum_multiples(5,1000);
	int commons = sum_multiples(15,1000);
	std::cout << threes + fives - commons << std::endl;
	return 0;
}

int sum_multiples(int multiple, int to){
	return (to - 1) / multiple * ((to - 1) / multiple + 1) / 2 * multiple;
}