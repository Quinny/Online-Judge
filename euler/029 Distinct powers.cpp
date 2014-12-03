#include <iostream>
#include <set>
#include <cmath>

int main(void){
	std::set<double> terms;
	for(int i = 2; i <= 100; i++){
		for(int j = 2; j<= 100; j++){
			double term = pow(i,j);
			terms.insert(term);
		}
	}
	std::cout << terms.size() << std::endl;
	return 0;
}