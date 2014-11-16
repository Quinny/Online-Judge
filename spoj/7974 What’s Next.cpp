#include <iostream>

bool isAP(int, int, int);

int main(){
	int n1, n2, n3;
	std::cin >> n1 >> n2 >> n3;
	while(n1 != 0 || n2 != 0 || n3 != 0){
		if(isAP(n1, n2, n3))
			std::cout << "AP " << n3 + (n3 - n2) << std::endl;
		else
			std::cout << "GP " << (n3 / n2) * n3 << std::endl;
		std::cin >> n1 >> n2 >> n3;
	}
	return 0;
}

bool isAP(int n1, int n2, int n3){
	return (n2 - n1) == (n3 - n2);
}