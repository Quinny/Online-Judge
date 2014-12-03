#include <iostream>
#include <cmath>

bool is_pent(int);

int main(){
	int i = 0;
	while(true){
		i++;
		int n = i * (3 * i - 1) / 2;
		for(int j = i - 1; j > 0; j--){
			int m = j * (3 * j - 1) / 2;
			if(is_pent(n + m) && is_pent(n - m)){
				std::cout << n - m << std::endl;
				return 0;
			}
		}
	}
	return 0;
}

bool is_pent(int n) {
    double m = (sqrt(1 + 24 * n) + 1.0) / 6.0;
    return m == ((int)m);
}
